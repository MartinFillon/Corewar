	.name "Abel"
	.comment "L'amer noir."

	sti r1, %:hi, %1 # useless comment

hi:	live %234
	ld %0, r3
	zjmp %:hi
