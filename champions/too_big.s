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
    sub r8, r10, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %100, r4
    ld %2, r5

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
	aff	r9
	add	r6, r6, r7
	sti	r8, r7, r1
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
    aff r8
    lfork %:hi
    ld %0, r3
    or r1, %0, r3

    and r2, %0, r7
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
    sub r5, r14, r3
    zjmp %:yur
    sti r1, %:live, %1
    fork %:ok
    ld %100, r4
    ld %2, r5

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
	aff r16
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
    lfork %:po
    ld %0, r3
    or r1, %4, r3

    and r2, %0, r7
    ld %0, r3
    st r2, r6
    zjmp %:pompes

pompes: ldi r12, r4, r5
    xor r3, r2, r6

    ld %0, r3
    sti r9, %:pompes, r1
    fork %:wsh
    ld %0, r3
    live %1
    ld %0, r3
    zjmp %:attack
    ld %0, r3
    aff r12
    lfork %:hi
    ld %0, r3
    or r1, %0, r3
    and r2, %5, r3
    ld %0, r3

    live %234
    ld %0, r3
    zjmp %:pompes

    ld %0, r3
    aff r9
    lfork %:bro
    ld %0, r3
    zjmp	%:begin
    ld	%0, r4

    live %234
	ld %0, r3
	zjmp %:po

    ld %0, r3
    aff r14
    lfork %:lol
    ld %0, r3
    or r1, %0, r3

    and r2, %22, r8
    ld %0, r3
    live %233
    st r2, r5
    zjmp %:full

lol: ldi r12, r4, r5

    ld %0, r3
    aff r5
    lfork %:bro
    ld %0, r3
    zjmp	%:begin
    ld	%0, r4

    live %234
	ld %0, r3
	zjmp %:full

    aff r10
    lfork %:bro
    ld %0, r3
    zjmp	%:begin
    ld	%0, r4
    or r1, %0, r3
    and r2, %5, r5
    ld %0, r3

    live %234
    ld %0, r3
    zjmp %:pompes

    ld %0, r3
    aff r9
    lfork %:bro
    ld %0, r3
    zjmp	%:begin
    ld	%0, r4

    live %234
	ld %0, r3
    xor r3, r2, r13
    zjmp %:po

    and r2, %23, r8
    ld %0, r3
	sti r1, %:go, %1
	fork %:man
	ld %13, r4
	ld %2, r5
full: sti r5, r4, r1
	add r4, r5, r4
	ld %0, r8
	zjmp %:begin

mm:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm

m1:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm

m2:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm

m3:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm

m4:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm


m5:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm


m6:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm


m7:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm


m8:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm


m9:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm


m10:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm


m11:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm


m12:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm


m13:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm


m14:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm


m15:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm


m16:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm


m17:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm


m18:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm


m19:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm


m20:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm


m010:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm


m011:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm


m012:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm


m013:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm


m014:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm


m015:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm


m016:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm


m017:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm


m018:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm


m019:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm


m020:    ld %0, r8
    zjmp %:live
    sub r9, r13, r3
    zjmp %:dude
    sti r1, %:live, %1
    fork %:ok
    ld %13, r4
    ld %2, r5
    lfork %:mm

p1:	ld	%65, r8
	st	r8, 100
	aff r16
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
    lfork %:po
    ld %0, r3
    or r1, %4, r3

    and r2, %0, r7
    ld %0, r3
    st r2, r6
    zjmp %:pompes

p2:	ld	%65, r8
	st	r8, 100
	aff r16
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
    lfork %:po
    ld %0, r3
    or r1, %4, r3

    and r2, %0, r7
    ld %0, r3
    st r2, r6
    zjmp %:pompes
