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
 
static void deadlock(void) {
    printf("deadlock\n");
    exit(0);
}

static void entry(void) {
    //Store return value
    long funcRet = (current -> func)();

    //Yield and infinite stream of the function's return value
    while (1) {
        yield(funcRet);
    }
}

Iterator* newIterator(F0 func) {
    Iterator* iter = (Iterator*) malloc(sizeof(Iterator));
    iter -> func = func;
    iter -> waiting = 0;
    //Pass control over to entry
    iter -> stack[STACK_LONGS - 1] = (long) &(entry);
    //Point the stack pointer to 6 above the last element
    iter -> sp = &(iter -> stack[STACK_LONGS - 1]) - 6;
    return iter;
}

long next(Iterator* p) {
    //Checks if the function has a caller
    if (current == NULL) {
        current = newIterator(0);
    }

    //Check for deadlock
    if (p -> waiting == 0) {
        p -> waiting = 1;
        //Set temporary iterators
        Iterator* callerTemp = caller;
        Iterator* currentTemp = current;
        caller = current;
        current = p;
        doSomething(current -> sp, &(caller -> sp));
        p -> waiting = 0;
        //Reset original iterators
        caller = callerTemp;
        current = currentTemp;
    }
    else {
        deadlock();
    }

    return res;
}

void yield(long v) {
    res = v;
    doSomething(caller -> sp, &(current -> sp));
}
