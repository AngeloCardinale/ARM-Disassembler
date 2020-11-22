	_Z12eratosthenesPjj
_Z12eratosthenesPjj:

	PUSH {R2, R3, R4, R5, R6, R7, R8, R9, R10}
	@R0 = start of array
	@R1 = number of numbers

	@R2 = NUMBER OF WORDS
	MOV R2, R1
	ADD R2, R2, #31
	LSL R2, #5

	
	@R3 = 0xAAAAAAAA, i.e we dont need to eliminate even bits anymore
	MOV R3, #0xAA
	LSL R3, #8
	ORR R3, #0xAA
	LSL R3, #8
	ORR R3, #0xAA
	LSL R3, #8
	ORR R3, #0xAA

	@ R4 = 4*number of words in array - 4
	@ R4 = max offset from R0
	MUL R4, R2, #4
	SUB R4, R4, #4

	@this loop should go through all of the offsets of R0 and AND in 0xAAAA
.killEvens:
	MOV R5, #0
	MOV R6, #4
	@R7 is the offset from R0
	MUL R7, R5, R6
	CMP R7, R4
	ANDLT [R0, R7], R3
	BLT .killEvens

	@All registers used up until this point except for R0, R1, R2 can be wiped
	
	@R4 = outer counter
.outer:
	MOV R4, #3
@	CMP R4, R1
.inner:
	@R5 = inner counter
	MUL R5, R4, R4
@	CMP R5, SQRT(R1)			@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	@The bit at position R5 will become 0
.wordCount:
	@R6 = 32
	@R7 is the word counter
	@if the index is less than 32 then add 32 until it's greater and keep track of how many 32s you add
	@the number of 32s you add is the word number starting at 0
	MOV R6, #32
	MOV R7, #0
	CMP R6, R5
	ADDLT R6, R6, #32
	ADDLT R7, R7, #1
	BLT .wordCount

	@R8 is offset multiplier
	MUL R8, R7, #4

	@R9 is the bit position in that word
	@R10 is a copy of the word at that offset

	AND R9, R5, #31
	LDR R10, [R0, R8]

	@at this point we have the word and the position we need to wipe
	@R3 is also unused since its purpose was served
	@R10 = R10 & ~(1 << R9)
	MOV R3, #1
	LSL R3, R9
	NOT R3, R3
	AND R10, R10, R3

	@Replace the old word at that offset with the modified word at that offset
	@AND [R0, R8], R10
	LDR R11, [R0, R8]
	AND R11, R10
	STR R11, [R0, R8]


	CMP R5, SQRT R1       @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	ADD R5, R5, R4
	BLT .inner


	CMP R4, R1            
	ADD R4, R4, #1
	BLT .outer
	
@	PUSH { R3, R4, R5, R6, R7, R8, R9, R10}
.count:
	@now that everything is nice an set we have to count how many one bits are in all of the words
	
@	v = v - ((v >> 1) & 0x55555555);                    // reuse input as temporary
@	v = (v & 0x33333333) + ((v >> 2) & 0x33333333);     // temp
@	c = ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; // count
	@V is the word
	@C is the count
	@R2 is still the number of words
	MOV R3, #0
	MOV R9, #0
.stepThrough:
	CMP R3, R2
	MUL R4, R3, #4
	ADD R3, R3, #1
	@R3 is the word counter
	@ R4 is the offset

	LDR R5, [R0, R4]

	@R5 is the word we are counting

	MOV R6, R5

	@R6 is a copy of R5

	@ R7 is 0x55555555
@	MOV R7, #0x55
@	LSL R7, #8
@	AND R7, #0x55
@	LSL R7, #8
@	AND R7, #0x55
@	LSL R7, #8
@	AND R7, #0x55

	LDR R7, =#0x55555555
	
	@R5 = R5 - ((R6 >> 1) & R7)
	LSR R6, #1
	AND R6, R7
	SUB R5, R5, R6

	@R6 and R5 match again
	MOV R6, R5

	@ R7 is 0x33333333
@	MOV R7, #0x33
@	LSL R7, #8
@	AND R7, #0x33
@	LSL R7, #8
@	AND R7, #0x33
@	LSL R7, #8
@	AND R7, #0x33

	LDR R7, =#0x33333333
	
@	v = (v & 0x33333333) + ((v >> 2) & 0x33333333);     // temp
	AND R5, R7
	LSR R6, #2
	AND R6, R7

	ADD R5, R5, R6

	MOV R6, R5
	@R6 and R5 are the same again
@	c = ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; // count

@	@ R7 is 0xF0F0F0F0
@	MOV R7, #0xF0
@	LSL R7, #8
@	AND R7, #0xF0
@	LSL R7, #8
@	AND R7, #0xF0
@	LSL R7, #8
@	AND R7, #0xF0

	LDR R7, =#0xF0F0F0F0
	
	@ R8 is 0x10101010
	MOV R8, #0x10
	LSL R8, #8
	AND R8, #0x10
	LSL R8, #8
	AND R8, #0x10
	LSL R8, #8
	AND R8, #0x10

	@R9 will be c and store the number of set bits in the word
	
	LSR R6, #4
	AND R6, R7
	ADD R5, R5, R6
	MUL R5, R5, R8
	LSR R5, #24

	ADD R9, R9, R5
	
	BLT .stepThrough

	@store the final count in r0
	MOV R0, R9
	POP { R3, R4, R5, R6, R7, R8, R9, R10}

	BX LR
	

	
	
