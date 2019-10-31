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

void* head(Node* list) {
    void* val = NULL;

    if(list != NULL) {
        val = list->val;
    }

    return val;
}

Node* tail(Node* list) {
    Node* tail = NULL;

    if(list != NULL) {
        tail = list->tail;
    }

    return tail;
}

void* nth(int n, Node* list) {
    void* val = NULL;

    if(list != NULL && n >= 0) {
        if (n == 0) {
            val = list->val;
        }
        else val = nth(n - 1, list->tail);        
    }

    return val;
}

Node* last(Node* list) {
    Node* lastCons = NULL;

    if(list != NULL) {
        if(list->tail == NULL) lastCons = list;
        else lastCons = last(list->tail);
    }

    return lastCons;
}

Node* copyList(Node* lst) {
    Node* newLst = NULL;

    if(lst != NULL) {
        newLst = newNode(lst->val, copyList(lst->tail));
    }

    return newLst;
}

Node* append(Node* fstList, Node* sndList) {
    Node* appended = NULL;

    if(fstList != NULL) {
        appended = copyList(fstList);
        // surely won't be a null reference, 
        // as fstList has at least one element
        last(appended)->tail = sndList;
    }
    else appended = sndList;

    return appended;
}

Node* makeList(int n) {
    Node* newList = NULL;

    if(n > 0) {
        newList = newNode(NULL, makeList(n - 1));
    }

    return newList;
}

Node* listFromArray(void* arr[], int n) {
    Node* list = NULL;

    if(arr != NULL && n > 0) {
        list = cons(arr[0], listFromArray(arr + 1, n - 1));
    }

    return list;
}

Node* map(F f, Node* list) {
    Node* newList = NULL;

    if(list != NULL) {
        newList = cons(f(list->val), map(f, list->tail));
    }

    return newList;
}
