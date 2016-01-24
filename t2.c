#include <iterator.h>
#include <thunk.h>
#include <stdio.h>

long facts(long n) {
    long f = 1;
    long i = 0;

    while (i <= n) {
         yield(f);
         i ++;
         f = f * i;
    }
    return 0;
}

int main() {
    Iterator* i = newIterator(thunk1(facts,5));
    printf("%ld\n",next(i));
    printf("%ld\n",next(i));
    printf("%ld\n",next(i));
    printf("%ld\n",next(i));
    printf("%ld\n",next(i));
    printf("%ld\n",next(i));
    printf("%ld\n",next(i));
    printf("%ld\n",next(i));
    printf("%ld\n",next(i));
    printf("%ld\n",next(i));
    printf("%ld\n",next(i));
    return 0;
}
