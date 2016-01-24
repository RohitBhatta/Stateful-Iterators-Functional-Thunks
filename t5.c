#include <iterator.h>
#include <thunk.h>
#include <stdio.h>

int isPrime(long x) {
    if (x < 2) return 0;
    if (x == 2) return 1;
    if ((x % 2) == 0) return 0;

    for (long d = 3; (d*d) <= x; d += 2) {
        if ((x % d) == 0) return 0;
    }
    return 1;
}

/* produce all odd numbers */
long odds(void) {
    long x = 1;
    while (1) {
        yield(x);
        x += 2;
    }
    return 0;
}

/* produce all primes */
long primes(void) {
    yield(2);
    Iterator* oddsIter = newIterator(odds);
    while (1) {
        long x = next(oddsIter);
        if (isPrime(x)) yield(x);
    }
    return 0;
}

int main() {
    Iterator* primesIter = newIterator(primes);

    for (int i=0; i<20; i++) {
        printf("%ld\n",next(primesIter));
    }
    return 0;
}
