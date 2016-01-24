#ifndef _THUNK_H_
#define _THUNK_H_

#define MISSING(cnt) do { \
    printf("about %d lines missing %s:%d\n",(cnt),__FILE__,__LINE__); \
    exit(0); \
} while (0)

typedef long (*F0)();
typedef long (*F1)(long a0);
typedef long (*F2)(long a0, long a1);
//typedef long (*F3)(long a0, long a1, long a2);
//typedef long (*F4)(long a0, long a1, long a2, long a3);
//typedef long (*F5)(long a0, long a1, long a2, long a3, long a4);
//typedef long (*F6)(long a0, long a1, long a2, long a3, long a4, long a5);

extern F0 thunk1(F1 f, long a0);
extern F0 thunk2(F2 f, long a0, long a1);

#endif
