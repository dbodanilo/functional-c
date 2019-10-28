#include <stdio.h>
#include <stdlib.h>

#include "persist.lst.h"

Node* newNode(void* val, Node* tail) {
    Node* newRef = malloc(sizeof(Node));
    newRef->val = val;
    newRef->tail = tail;

    return newRef;
}

// persistent list functions
Node* cons(void* val, Node* tail) {
    Node* newHead = newNode(val, tail);

    return newHead;
}

int length(Node* list) {
    int len = 0;
    if(list != NULL) {
        len = length(list->tail) + 1;
    }

    return len;
}
