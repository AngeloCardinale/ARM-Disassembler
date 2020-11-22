/*def power(x, n):
  prod = 1
  while n > 0:
    if (n & 1) == 1:
      prod = prod * x
    x = x * x
    n = n / 2    --> LSR 
*/
	.global _Z5powerjj
_Z5powerjj:	
	PUSH {R2, R3, R4}

	@R0 is the base of exponentiation
	@R1 is the power you have to go to
	@R2 is prod
	@R3 is a copy of the exponent

	MOV R2, #1
	
.loop:
	AND R3, R1, #1
	CMP R3, #1
	MULEQ R2, R2, R0
	MUL R0, R0, R0
	LSR R1, R1, #1
	CMP R1, #0
	BNE .loop

	
	MOV R0, R2
	POP {R2, R3, R4}
	BX LR
