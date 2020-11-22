	.global _Z12eratosthenesPjjj
_Z12eratosthenesPjjj:

	PUSH {R3-R11}

	@R0 is the start of the array
	@R1 is the number of numbers
	@R2 is the square root of the number of numbers
	@R11 = counter

	MOV R11, #1


	@for(int i = 2, i <= sqrt(n), i++)
	   @for(int j = i * i, j <= (n), j+=i)
	      @isPrime[j] = false


	@first we must asume all numbers are prime
	@Need to find out how many words we need, = (R+31)/32
	@R3 = 0xFFFFFFFF
	@R4 = (R1+31)/32 = number of words

	LDR R3, =#0xFFFFFFFF	@r3 = 0xFFFFFFFF
	ADD R4, R1, #31		@R4 = R1+31
	LSR R4, #5		@R4 = (R1 + 31) / 32

	@Need to find a maximum offset
	@max offset = 4*Number of words - 4
	@Max offset = 4*R4 - 4

	LSL R4, #2
	SUB R4, R4, #4

	@R4 is now the maximum offset
	@R5 is the current offset
	@While the current offset is <= to the max offset
	MOV R5, #0
.setPrime:
	STR R3, [R0, R5]	@Set the word at the current offset to be 0xFFFFFFFF
	ADD R5, R5, #4		@increment the offset
	CMP R5,R4		@Compare the current offset to the max offset 
	BLE .setPrime


	@At this point
	@R0 = array
	@R1 = number of numbers
	@R2 = sqrt(number of numbers)
	@R3 = 0xFFFFFFFF
	@R4 = Max offset = 4*Number of words - 4
	@R5 = Max offset (was current offset but of course it reaches the max after the .setPrime loop)

	@R3, R4, and R5 can be overwritten

	@Registers R3 - R11 are free to be used in the next section
	@The algorithm followed is this:


	@for(int i = 2, i < sqrt(n), i++)
	   @for(int j = i * i, j < (n), j+=i)
	      @isPrime[j] = false

	@R1 = n
	@R2 = sqrt(n)
	@R3 = i
	@R4 = j
	MOV R3, #2	@i = 2 in the beginning

.outer:
	
	MUL R4, R3, R3  @every time we hit the outer loop we reinitialize j to be i ^ 2


.inner:	


	@We need to get the word that we are on
	@Word = number / 32 = number LSR 5
	@Word = j / 32
	
	LSR R5, R4, #5	@R5 = word we are on

	@We need to get which bit in that word we are on
	@J mod 32 = bit number
	@R4 AND 31 = R4 mod 32

	AND R6, R4, #31

	@R5 = R4 >> 5
	@R6 = R4 AND 31

	@R5 = word
	@R6 = bit position
	@R7 = offset = R5 * 4

	LSL R7, R5, #2

	@R8 = the bit wiper
	@R8 =  ~(R8 << R6)
	MOV R8, #1
	LSL R8, R6
	MVN R8, R8

	@Grab the word from the specified offset
	@Copy it into R10
	@clear the bit
	LDR R9, [R0, R7]
	MOV R10, R9
	AND R9, R8
	STR R9, [R0, R7]

	@R1 = n
	@R2 = sqrt (n)
	@R3 = i
	@R4 = J
	@R5 = Word = j / 32 = R4 >> 5
	@R6 = bit position = j MOD 32 = R4 AND 32
	@R7 = Offset = R5 * 4 = word * 4
	@R8 = 11101111 with the 0 in the right place
	@R9 = modified word
	@R10 = original word
	


	


	b .counter	@branch to the counter
.return:		@return from the counter
	
	ADD R4, R4, R3
	CMP R4, R1	@j < n


	BLE .inner

	ADD R3, R3, #1
	CMP R3, R2	@i < SQRT(n)


	BLE .outer	@Branch back to outer
 


	SUB R0, R1, R11	@# of bits - # of bits changed = number of set bits remaining = number of primes
	POP {R3-R11}
	BX LR



.counter:		@This counter tells us how many bits we changed
			@If the original word and the modified word are different then count

	CMP R9, R10
	ADDNE R11, R11, #1
	b .return
	
	
