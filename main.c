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

char* stringFromInt(int* intRef) {
    // assuming a maximum of 15 digit integers
    char temp[16];
    char* str = NULL;

    if(intRef != NULL) {
        sprintf(temp, "%d", *intRef);

        int len = strlen(temp);
        str = malloc((len + 1)*sizeof(char));
        strcpy(str, temp);
    }

    return str;
}

char* stringFromList(Node* list) {
    char* str = "";

    if(list != NULL) {
        char* valStr = stringFromInt(list->val);
        int valSize = valStr != NULL ? strlen(valStr) : 0;

        char* tailStr = stringFromList(list->tail);
        int tailSize = tailStr != NULL ? strlen(tailStr) : 0;

        str = malloc((valSize + tailSize + 2)*sizeof(char));

        sprintf(str, "%s %s", valStr, tailStr);
    }

    return str;
}

void show(Node* list) {
    printf("%s\n", stringFromList(list));
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

    Node* newList = cons(newInt(4), NULL);
    Node* appended = append(list, newList);
    Node* list2 = append(NULL, list);

    show(list);
    show(newList);
    show(appended);
    show(list2);
    show(makeList(5));

    return 0;
}
