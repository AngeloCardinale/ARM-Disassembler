@	.globl _Z12eratosthenesk
@_Z12eratosthenesk:
@	movl	#3, %r11	
@.L1:
@	movl	%r11, %r10
@	and	#$3F, %r10
@	movl	%rll, %r9
@	lsr	#6, %r9
@	movl	(%ecx,%r9), %r8
@	lsll	%r10, ????
@	add	#2, %r11
@	cmp	%r11, %edx
	@	jlt	.L1

	.global _Z7displayi
_Z7displayi:	
@	.global _Z12eratosthenesPjj
@_Z12eratosthenes:
	@R0 is the address of the first bit of the first integer in the array
	@r1 is the top value we have to go to
	@setting all words to 0xAAAA removes all even bits and makes our lives
	@computationally easier
	@R2 = i
	@R3 = j
	@r4 = sqrt(n)
	@R5  = R0 copy
	@R6 = step point




	@R0 is the start
	@r1 is the number of words
	@R2 is 0xAAAA
	
	@R4 is a counter
	@R5 is a stepper
	MOV r2, #0xAA
	lsl r2, #8
	ORR r2, #0xAA	@r2 = 0xAAAA

	MOV R4, #0
	MOV R5, #0
.initial:
	CMP R4, R1
	AND [R0, R5], R2
	ADD R4, R4, #1
	ADD R5, R5, #4
	BLT .initial

.outerLoop:
	for i = 3, i < sqrtn	; i+=2

.innerLoop:
	for int j = I*I		; j<n, j+= 2i
	make thhat bit false

	


	
	b	.innerLoop


	b	.outerLoop
	
	
