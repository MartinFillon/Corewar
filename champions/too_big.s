	.name "Bill"
	.comment "Equilibre"

	sti r1, %:live, %1
	fork %:man
	ld %100, r4
	ld %2, r5

live:	live %1

ok: sti r5, r4, r1
	add r4, r5, r4
	ld %0, r8
	zjmp %:begin

yur:    ld %0, r8
    zjmp %:live
    sub r9, r100, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %-100, r4
    ld %-2, r5

	sti	r1, %:begin, %1
	fork	%:begin
begin:	ld	%76, r1
	ld	%40, r6
	ld	%1, r7
	ld	%15, r4
	ld	%15, r5
	sub	r4, r5, r3
	zjmp	%:attack
go:	live	%2
	ld	%0, r4
	zjmp	%:live
attack:	ld	%65, r8
	st	r8, 100
	aff	r1
	add	r6, r7, r7
	sti	r7, r7, r1
	ld	%15, r4
	ld	%15, r5
	sub	r4, r5, r3
	zjmp	%:attack
    ld	%0, r4
    zjmp	%:begin
    ld	%0, r4

hi:	live %234
	ld %0, r3
	zjmp %:hi

    ld %0, r3
    aff r-1000
    lfork %:hi
    ld %0, r3
    or r1, %0, r3

    and r2, %200, r800
    ld %0, r3
	sti r1, %:go, %1
	fork %:man
	ld %100, r4
	ld %2, r5

bro:	live %1

man: sti r5, r4, r1
	add r4, r5, r4
	ld %0, r8
	zjmp %:bro

dude:    ld %0, r8
    zjmp %:bro
    sub r9, r100, r3
    zjmp %:yur
    sti r1, %:live, %1
    fork %:ok
    ld %-100, r4
    ld %-2, r5

	sti	r1, %:live, %1
	fork	%:wsh
wsh:	ld	%76, r1
	ld	%40, r6
	ld	%1, r7
	ld	%15, r4
	ld	%15, r5
	sub	r4, r5, r3
	zjmp	%:attack
crow:	live	%2
	ld	%0, r4
	zjmp	%:wsh
po:	ld	%65, r8
	st	r8, 100
	aff	r1
	add	r6, r7, r7
	sti	r7, r7, r1
	ld	%:crow, r4
	ld	%15, r5
	sub	r4, r5, r3
	zjmp	%:attack
    ld	%0, r4
    zjmp	%:begin
    ld	%0, r4

    live %234
	ld %0, r3
	zjmp %:po

    ld %0, r3
    aff r-1000
    lfork %:po
    ld %0, r3
    or r1, %0, r3

    and r2, %200, r800
    ld %0, r3
    live %-233
    st r2, r99
    zjmp %:pompes

pompes: ldi r12, r-4, r5
    xor r-3, r2, r100

    ld %0, r3
    sti r9, %:pompes, r-1
    fork %:wsh
    ld %0, r3
    live %1
    ld %0, r3
    zjmp %:attack
    ld %0, r3
    aff r-1000
    lfork %:hi
    ld %0, r3
    or r1, %0, r3
    and r2, %200, r800
    ld %0, r3

    live %234
    ld %0, r3
    zjmp %:pompes

    ld %0, r3
    aff r-1000
    lfork %:bro
    ld %0, r3
    zjmp	%:begin
    ld	%0, r4

    live %234
	ld %0, r3
	zjmp %:po

    ld %0, r3
    aff r-1000
    lfork %:lol
    ld %0, r3
    or r1, %0, r3

    and r2, %200, r800
    ld %0, r3
    live %-233
    st r2, r99
    zjmp %:full

lol: ldi r12, r-4, r5

    ld %0, r3
    aff r-1000
    lfork %:bro
    ld %0, r3
    zjmp	%:begin
    ld	%0, r4

    live %234
	ld %0, r3
	zjmp %:full

    aff r-143
    lfork %:bro
    ld %0, r3
    zjmp	%:begin
    ld	%0, r4
    or r1, %0, r3
    and r2, %200, r800
    ld %0, r3

    live %234
    ld %0, r3
    zjmp %:pompes

    ld %0, r3
    aff r-1000
    lfork %:bro
    ld %0, r3
    zjmp	%:begin
    ld	%0, r4

    live %234
	ld %0, r3
    xor r-3, r2, r100
    zjmp %:po

    and r2, %200, r800
    ld %0, r3
	sti r1, %:go, %1
	fork %:man
	ld %100, r4
	ld %2, r5
full: sti r5, r4, r1
	add r4, r5, r4
	ld %0, r8
	zjmp %:begin

mm:    ld %0, r8
    zjmp %:live
    sub r9, r100, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %-100, r4
    ld %-2, r5
    lfork %:mm