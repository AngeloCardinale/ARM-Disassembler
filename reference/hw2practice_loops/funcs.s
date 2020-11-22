	.global _Z5counti
_Z5counti:	

.loop:
	ADD R1, #1

	CMP R1, R0

	BLT .loop
	
	
	bx lr 

	.global _Z9countDowni
_Z9countDowni:

	MOV R1, #1

	MOV R3, #0

.loop2:
	
	SUB R0, R0, R1
	
	CMP R0, R3 

	BGT .loop2
	
	bx lr



	.global _Z3sumii
	
_Z3sumii:

	MOV R2, R0

	MOV R3, R0

.loop3:

	ADD R3, R3, #1

	ADD R2, R3, R2

	CMP R3, R1

	BLT .loop3

	MOV R0, R2

	BX LR
	
	.global _Z4facti
_Z4facti:

	MOV R1, R0
	CMP R0, #2
	SUBGE R1, #1
	CMP R0, #0
	CMP R1, #0
	MOVEQ R1, #1
	CMP R0, #0
	ADDEQ R0, #1



.loop4:

	MUL R0, R0, R1
	CMP R1, #2
	SUBGE R1, #1
	BGE .loop4
	

	
	
	BX LR
	


	
