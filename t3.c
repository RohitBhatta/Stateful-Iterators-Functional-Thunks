#include <iterator.h>
#include <thunk.h>
#include <stdio.h>


Iterator* common = 0;

long wrap(long v) {
    while (1) {
        long x = next(common);
        if (x == 0) return 0;
        yield(v + x);
    }
    return 0;
}


long gen(long n) {
    for (long i=1; i<n; i++) {
        yield(i);
    }
    return 0;
}

int main() {
    common = newIterator(thunk1(gen,8));

    Iterator* w0 = newIterator(thunk1(wrap,10));    
    Iterator* w1 = newIterator(thunk1(wrap,100));    

    while (1) {
        long x = next(w0);
        printf("%ld\n",x);
        long y = next(w1);
        printf("%ld\n",y);
        long z = next(common);
        printf("%ld\n",z);

        if ((x + y + z) == 0) break;
    }
    return 0;
}


