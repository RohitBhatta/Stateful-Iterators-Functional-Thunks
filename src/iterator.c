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

static Iterator* current = 0;
static Iterator* caller = 0;
static long res = 0;
//static int count = 0;
 
static void deadlock(void) {
    printf("deadlock\n");
    exit(0);
}

//Store return value of F0
//Original argument was void
static void entry(void) {
    //MISSING(4);
    long funcRet = (current -> func)();
    while (1) {
        yield(funcRet);
    }
}

Iterator* newIterator(F0 func) {
    //MISSING(7);
    Iterator* iter = (Iterator*) malloc(sizeof(Iterator));
    iter -> func = func;
    iter -> waiting = 0;
    iter -> stack[STACK_LONGS - 1] = (long) &(entry);
    iter -> sp = (long*) (STACK_LONGS - 7);
    return iter;
}

long next(Iterator* p) {
    //MISSING(20);
    //Have dummy iterator
    /*if (!count) {
        count++;
        Iterator* currentFirst = (Iterator*) malloc(sizeof(Iterator));
        //How to set current sp???
        current = currentFirst;
    }*/

    if (p -> waiting == 0) {
        p -> waiting = 1;
        Iterator* callerTemp = caller;
        Iterator* currentTemp = current;
        caller = current;
        current = p;
        doSomething(current -> sp, &(caller -> sp));
        caller = callerTemp;
        current = currentTemp;
    }
    else {
        deadlock();
    }

    return res;
}

void yield(long v) {
    //MISSING(2);
    res = v;
    doSomething(caller -> sp, &(current -> sp));
}
