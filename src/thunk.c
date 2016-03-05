#include "thunk.h"
#include <sys/mman.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#ifndef MAP_ANONYMOUS
#define MAP_ANONYMOUS MAP_ANON
#endif


/* Too much waste but ... */
static uint8_t* xalloc() {
    size_t pageSize = sysconf(_SC_PAGE_SIZE);

    void* p = mmap(0,pageSize,
                PROT_WRITE | PROT_EXEC | PROT_READ,
                MAP_ANONYMOUS | MAP_PRIVATE,
                -1, 0);
    if (p == MAP_FAILED) {
        perror("mmap");
        exit(-1);
    }

    return (uint8_t*) p;
}
    
    

F0 thunk1(F1 f, long a0) {
    uint8_t* p = xalloc();
    //Machine code for the following instructions
    //mov a0, %rdi
    p[0] = 0x48;
    p[1] = 0xbf;
    *(long*) &(p[2]) = a0;
    //mov f, %rax
    p[0xa] = 0x48;
    p[0xb] = 0xb8;
    *(long*) &(p[0xc]) = (long) f;
    //jmp *%rax
    p[0x14] = 0xff;
    p[0x15] = 0xe0;
    return (F0)p;
}
