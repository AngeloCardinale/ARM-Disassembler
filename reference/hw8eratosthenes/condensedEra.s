	.global _Z12eratosthenesPjjj
_Z12eratosthenesPjjj:
	PUSH {R3-R11}
	MOV R11, #0
	LDR R3, =#0xFFFFFFFF	@r3 = 0xFFFFFFFF
	ADD R4, R1, #31		@R4 = R1+31
	LSR R4, #5		@R4 = (R1 + 31) / 32
	LSL R4, #2
	SUB R4, R4, #4
	MOV R5, #0
.setPrime:
	STR R3, [R0, R5]	@Set the word at the current offset to be 0xFFFFFFFF
	ADD R5, R5, #4		@increment the offset
	CMP R5,R4		@Compare the current offset to the max offset 
	BLE .setPrime
	MOV R3, #2	@i = 2 in the beginning
.outer:
	MUL R4, R3, R3 every time we hit the outer loop we reinitialize j to be i ^ 2
.inner:	
	LSR R5, R4, #5	@R5 = word we are on
	AND R6, R4, #31
	LSL R7, R5, #2
	MOV R8, #1
	LSL R8, R6
	MVN R8, R8
	LDR R9, [R0, R7]
	MOV R10, R9
	AND R9, R8
	STR R9, [R0, R7]	
	B .counter	@branch to the counter
.return:		@return from the counter
	ADD R4, R4, R3
	CMP R4, R1	@j < n
	BLT .inner
	ADD R3, R3, #1
	CMP R3, R2	@i < SQRT(n)
	BLT .outer	@Branch back to outer
	SUB R0, R1, R11	@# of bits - # of bits changed = number of set bits remaining = number of primes
	POP {R3-R11}
	BX LR
.counter:		@This counter tells us how many bits we changed
	CMP R9, R10
	ADDNE R11, R11, #1
	b .return
	
	
