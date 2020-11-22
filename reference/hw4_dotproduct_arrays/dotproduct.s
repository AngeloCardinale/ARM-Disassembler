	.global _Z10dotproductPdS_
_Z10dotproductPdS_:
	.fnstart
	@r0 has the first array
	@r1 has the second array
	@each inde is 8 bytes
	@D0 holds the answer
	@D3 has a copy ofr0
	@D4 has a copy of r1

	vpush.f64{D2, D3, D4}


	VLDR.64 D3, [r0]
	VLDR.64 D4, [r1]
	VMUL.f64 D0, D3, D4

	VLDR.64 D3, [r0, #8]
	VLDR.64 D4, [r1, #8]
	VMLA.f64 D0, D3, D4


	VLDR.64 D3, [r0, #16]
	VLDR.64 D4, [r1, #16]
	VMLA.f64 D0, D3, D4

	


	vpop.f64{D2, D3, D4}

	BX	LR
