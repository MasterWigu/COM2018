EXT=.diy
EXE=../diy
LIB=../libdiy.a

.SUFFIXES: .asm $(EXT)

ALONE=ack add args bissect break call chrindex cont continue div downto entry factorial fib gcd gt hello histograma if intindex local mul pi printi real ret simple testval tri upto while
ALL= $(ALONE) strtest mean

simple: simple.o
	ld -m elf_i386 -o $@ $^ $(LIB)
strtest: strtest.o # string.o
	ld -m elf_i386 -o $@ $^ $(LIB)
mean: mean.o rand.o
	ld -m elf_i386 -o $@ $^ $(LIB)

all:
	for i in $(ALL); do $(MAKE) $(MFLAGS) $$i; done

$(EXT).o:
	$(EXE) $< $*.asm
	nasm -felf32 $*.asm
	
%: %$(EXT)
	$(EXE) $< $*.asm
	nasm -felf32 $*.asm
	ld -m elf_i386 -o $@ $*.o $(LIB)

clean:
	rm -f *.asm *.o $(ALL)

IN=.
DIR=.
out: ack.out add2.out add.out args.out bissect.out break.out call.out chrindex.out com.out cont.out continue.out div.out downto.out eng.out factorial.out fib.out forward.out funcptr.out gcd.out gt.out hanoi.out hello.out histograma.out horner.out if.out intindex.out itoa.out local.out logic.out novrfl.out pi.out printi.out rank.out real.out ret.out simple.out smooth.out strhash.out testval.out touro.out tri.out upto.out while.out decl.out extern.out strtest.out mean.out sort.out recurs.out iter.out

ack.out: ack
	$(DIR)/ack 3 9
add2.out: add2
	echo 12 | $(DIR)/add2
add.out: add
	echo 12 | $(DIR)/add
args.out: args
	$(DIR)/args um dois tres
bissect.out: bissect
	$(DIR)/bissect 0.2 3.1 20
break.out: break
	echo 12 | $(DIR)/break
call.out: call
	$(DIR)/call
chrindex.out: chrindex
	echo 5 | $(DIR)/chrindex
com.out: com
	$(DIR)/com
cont.out: cont
	echo 12 | $(DIR)/cont
continue.out: continue
	$(DIR)/continue
div.out: div
	echo 144 | $(DIR)/div
downto.out: downto
	$(DIR)/downto
eng.out: eng
	echo 1200 | $(DIR)/eng
factorial.out: factorial
	$(DIR)/factorial 7
fib.out: fib
	echo 12 | $(DIR)/fib
forward.out: forward
	$(DIR)/forward
funcptr.out: funcptr
	$(DIR)/funcptr um dois
gcd.out: gcd
	$(DIR)/gcd < $(IN)/gcd.in
gt.out: gt
	$(DIR)/gt < $(IN)/gt.in
hanoi.out: hanoi
	$(DIR)/hanoi
hello.out: hello
	$(DIR)/hello
histograma.out: histograma
	$(DIR)/histograma 0 20 3 100
horner.out: horner
	$(DIR)/horner 2.1 1.5 3.4 7.2 -12.3
if.out: if
	echo -12 | $(DIR)/if
intindex.out: intindex
	echo 4 | $(DIR)/intindex
itoa.out: itoa
	echo 144 | $(DIR)/itoa
local.out: local
	$(DIR)/local
logic.out: logic
	$(DIR)/logic < $(IN)/logic.in
novrfl.out: novrfl
	$(DIR)/novrfl
pi.out: pi
	echo 200 | $(DIR)/pi
printi.out: printi
	$(DIR)/printi
rank.out: rank
	$(DIR)/rank 3 1 2
real.out: real
	$(DIR)/real
ret.out: ret
	$(DIR)/ret
simple.out: simple
	$(DIR)/simple
smooth.out: smooth
	$(DIR)/smooth 3 20 28 23 18 20 26 29 23 19 17 21 25 28 32 32 32
strhash.out: strhash
	$(DIR)/strhash compiladores
testval.out: testval
	$(DIR)/testval
touro.out: touro
	$(DIR)/touro
tri.out: tri
	$(DIR)/tri < $(IN)/tri.in
upto.out: upto
	$(DIR)/upto
while.out: while
	$(DIR)/while
decl.out: decl
	$(DIR)/decl
extern.out: extern
	$(DIR)/extern
strtest.out: strtest
	$(DIR)/strtest factorial compilador
mean.out: mean
	echo 20 | $(DIR)/mean
sort.out: sort
	$(DIR)/sort < $(IN)/sort.in
recurs.out: recurs
	$(DIR)/recurs
iter.out: iter
	$(DIR)/iter 6
