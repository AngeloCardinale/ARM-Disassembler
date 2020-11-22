	.global  _Z6add128R6BigNumRKS_S2_
_Z6add128R6BigNumRKS_S2_:
	PUSH {R3,R4,R5}
	
	LDR R3, [R1, #12]
	LDR R4, [R2, #12]
	ADDS R5 ,R3, R4
	STR R5, [R0, #12]

	LDR R3, [R1, #8]
	LDR R4, [R2, #8]
	ADDCS R5 ,R3, R4
	STR R5, [R0, #8]

	LDR R3, [R1, #4]
	LDR R4, [R2, #4]
	ADDCS R5 ,R3, R4
	STR R5, [R0, #4]

	LDR R3, [R1]
	LDR R4, [R2]
	ADDCS R5 ,R3, R4
	STR R5, [R0]
	POP {R3,R4,R5}
	bx lr
