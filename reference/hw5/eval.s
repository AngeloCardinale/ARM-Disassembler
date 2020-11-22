	@Michael DiGregorio
	@help from Justin John
	@I pledge my honor that I have abided by the Stevens Honor System


	.global_ ZNK10Polynomial4evalEd
_ZNK10Polynomial4evalEd:
	vpush {d1,d2}
	push {r1 - r3}
	ldr r3, [r0]
	lsl r1, r1, #3
	ldr r2, [r0, #4]
	vldr d1, [r2]
	vldr d2. [r2]

	cmp r1 #0
	beq .end

	mov r3, #8

.loop:
	add r2, r2, #8
	vldr d1, [r2]
	vmul.f64 d2, d2, d0
	vadd.f64 d2, d2, d1
	add r3, r3, #8
	cmp r3, r1
	ble .loop

	vmov.f64 d0, d2
	pop {r1 - r3}
	vpop {d1, d2}
	bx lr
	
