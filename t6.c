#include <iterator.h>
#include <stdio.h>

Iterator* me = 0;

long gen(void) {
    printf("start\n");
    yield(next(me));
    printf("finish\n");
    return 0;
}

int main() {
    me = newIterator(gen);
    printf("%ld\n",next(me));
    return 0;
}
