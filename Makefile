TESTS=$(sort $(wildcard *.c))
PROGS=$(subst .c,,$(TESTS))
OUTS=$(patsubst %.c,%.out,$(TESTS))
DIFFS=$(patsubst %.c,%.diff,$(TESTS))
RESULTS=$(patsubst %.c,%.result,$(TESTS))

#CFILES=$(sort $(wildcard *.c))

.SECONDARY:

.PROCIOUS : %.o %.S %.out

CFLAGS=-g -std=gnu99 -O0 -Werror -Wall

all : ${PROGS}

${PROGS} : % : Makefile %.c ${wildcard src/*}
	gcc -Isrc $(CFLAGS) -o $@ $*.c src/*.c src/*.S
	
outs : $(OUTS)

$(OUTS) : %.out : Makefile %
	(./$* > $*.out) || touch $@

diffs : $(DIFFS)

%.ok:
	touch $@

$(DIFFS) : %.diff : all Makefile %.out %.ok
	@(((diff -b $*.ok $*.out > /dev/null 2>&1) && (echo "===> $* ... pass")) || (echo "===> $* ... fail" ; echo "----- test -----"; cat $*.c; echo "----- expected ------"; cat $*.ok ; echo "----- found -----"; cat $*.out)) > $*.diff 2>&1

$(RESULTS) : %.result : all Makefile %.diff
	@cat $*.diff

test : all Makefile $(DIFFS)
	@cat $(DIFFS)

clean :
	rm -f $(PROGS)
	rm -f *.out
	rm -f *.d
	rm -f *.o
	rm -f *.diff

-include *.d
