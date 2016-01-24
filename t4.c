#include <iterator.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int v;
    struct Node* left;
    struct Node* right;
} Node;

long traverse(Node* n) {
    if (n == 0) return 0;
    traverse(n->left);
    yield(n->v);
    traverse(n->right);
    return 0;
}

Node* make(int i, int n) {
    if (n <= 0) return 0;
    Node* node = (Node*) malloc(sizeof(*node));
    node->v = i++;
    int left = (n-1)/2;
    node->left = make(i,left);
    int right = n-1 - left;
    node->right = make(i+left,right);
    return node;
}
    
int main() {
    Node* n = make(1,10);
    Iterator* i = newIterator(thunk1((F1)traverse,(long) n));

    while (1) {
        long x = next(i);
        printf("%ld\n",x);
        if (x == 0) break;
    }
    return 0;
}
    


