.SUFFIXES: .$(EXT) .asm
COMP=../diy # compiler
EXT=diy # file extension: .$(EXT)
LIB=diy # runtime library: lib$(LIB).a
RUN=../run # runtime directory
AS=nasm -felf32 # assembler command
LD=ld -melf_i386 # loader command

SRC=ack.diy factorial.diy hello.diy iter.diy mean.diy rand.diy recurs.diy string.diy
EXE=$(SRC:%.diy=%)

all:: compiler $(EXE)

compiler::
	make -C ..

runtime::
	make -C $(RUN)

%:%.$(EXT)
	$(COMP) $<

clean::
	rm -f *.o *.asm *.s *~ $(EXE)
