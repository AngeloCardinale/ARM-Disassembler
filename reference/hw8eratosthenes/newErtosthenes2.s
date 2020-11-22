	.global _Z12eratosthenesPjjj
_Z12eratosthenesPjjj:

	PUSH {R4-R11}

	LDR R3, =#0xFFFFFFFF

	ADD R4, R1, #31 
	LSR R4, #5         @R4 = R1 + 31 / 32
	LSL R4, #2
	SUB R4, R4, #4

	@time t0 make all of r0 0xFFFFFFFF

	@R5 = offset (0, 4, 8, 12)
	@R6 is the word in the array
	@R3 = 0xFFFFFFFF
	@R4 is the max offset
	
	MOV R5, #0
	MOV R11, #0
.fOut:
	LDR R6, [R0, R5]
	ORR R6, R3
	STR R6, [R0, R5]
	ADD R5, R5, #4
	CMP R5, R4 
	BLE .fOut

	@To count, every time you kill a number subtract one from the total
	@The kill code is as follows
@	for(int i = 3)(i < n)(i++)
@		for(int j = i*i)(i<sqrt(n))(j += i)
@			isPrime[j] = false
	

 	@Can reuse R5 - R10
	MOV R5, #2
.outer:


	MUL R6, R5, R5
	CMP R5, R2
	BGT .skip
.inner:


	@Can use R7 R8, R9, R10

	@R7 is the word we have to go to
	@R8 is the Bit in that word
	@R6 is j and the bit we have to wipe
	LSR R7, R6, #5
	AND R8, R6, #31

	@R9 is the offset in R0 we have to mess with
	LSL R9, R7, #2
	LDR R10, [R0, R9]

	@Overwrite R7
	@Overwrite R8 after its first use
	MOV R7, #1
	LSL R7, R8       @shift 1 over to the position
	MVN R7, R7       @invert bits to get a 0 there
	AND R10, R7	 @change the word pulled from the array
	LDR R8, [R0, R9] @copy of the old word
	STR R10, [R0, R9] @put it back
	CMP R10, R8
	BNE .addCtr
.resume:


	CMP R6, R1
	ADDLT R6, R6, R5
	BLT .inner




	CMP R5, R2
	ADDLT R5, R5, #1
	BLT .outer

.skip:
	
	MOV R0, R11
	ADD R0, R0, #2
	SUB R0, R1, R0
	POP {R4-R11}

	BX LR
	
.addCtr:
	CMP R6, R1
	ADDLT R11, #1
	b .resume
