// -- Node --
typedef struct node Node;

struct node {
    void* val;
    Node* tail;
};

// generic single-argument function
typedef void* (*F)(void*);

// -- Persistent List --
Node* cons(void* val, Node* tail);

int length(Node* list);

void* head(Node* list);

Node* tail(Node* list);

void* nth(int n, Node* list);

Node* last(Node* list);

Node* copyList(Node* lst);

Node* append(Node* fstList, Node* sndList);

Node* makeList(int n);

Node* listFromArray(void* arr[], int n);

Node* map(F f, Node* list);
