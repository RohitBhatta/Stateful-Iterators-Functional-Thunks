#include "iterator.h"
#include "thunk.h"
#include <stdlib.h>
#include <stdio.h>

#define STACK_LONGS 1024

extern void doSomething(long *newSp, long **oldSp);

struct Iterator {
    long stack[STACK_LONGS];
    long* sp;
    F0 func;
    int waiting;
};

//static Iterator* current = 0;
//static Iterator* caller = 0;
//static long res = 0;
    
/*static*/ void deadlock(void) {
    printf("deadlock\n");
    exit(0);
}

/*static*/ void entry(void) {
    MISSING(4);
}

Iterator* newIterator(F0 func) {
    MISSING(7);
}

long next(Iterator* p) {
    MISSING(20);
}

void yield(long v) {
    MISSING(2);
}
