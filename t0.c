#include <iterator.h>
#include <stdio.h>

long func() {
    int i = 0;
    printf("    func: %d\n",i++);
    yield(10);
    printf("    func: %d\n",i++);
    yield(20);
    printf("    func: %d\n",i++);
    yield(30);
    printf("    func: %d\n",i++);
    yield(40);
    printf("    func: %d\n",i++);
    return 0;
}

int main() {
    Iterator* iter = newIterator(func);

    for (int i=0; i<10; i++) {
        printf("main: before\n");
        long x = next(iter);
        printf("main: after %ld\n",x);
    }
    return 0;
}
