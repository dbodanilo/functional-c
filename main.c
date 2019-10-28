#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "persist.lst.h"

// integer lists only
// utilities
int* newInt(int val) {
    int* newRef = malloc(sizeof(int));
    *newRef = val;

    return newRef;
}

int main() {
    Node* list = cons(newInt(1), cons(newInt(2), cons(newInt(3), NULL)));

    int idx = 1;
    int* idxRef = nth(idx, list);
    int* headRef = head(list);

    int sentinel = 80085;
    int headVal = headRef != NULL ? *headRef : sentinel;
    int val = idxRef != NULL ? *idxRef : sentinel;

    printf("list[head] = %d\t(sentinel = %d)\n", headVal, sentinel);
    printf("list[%d] = %d\t(sentinel = %d)\n", idx, val, sentinel);

    return 0;
}
