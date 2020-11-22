	.global _Z5powerjj
_Z5powerjj:

	push {R2}
	@R0 is the base of exponentiation
	@R1 is the number of times we multiply (counter)
	@R2 is a copy of R0
	MOV R2, R0

.loop:
	CMP R1, #1
	BEQ .end
	SUB R1, R1, #1
	MUL R0, R0, R2
	BGT .loop
	
.end:

	pop {R2}
	BX LR
