#include <iterator.h>
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

long facts5(void) {
    return facts(5);
}

int main() {
    Iterator* i = newIterator(facts5);
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
