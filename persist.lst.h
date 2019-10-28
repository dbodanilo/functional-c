// -- Node --
typedef struct node Node;

struct node {
    void* val;
    Node* tail;
};

Node* newNode(void* val, Node* tail);

// -- Persistent List --
Node* cons(void* val, Node* tail);

int length(Node* list);

void* head(Node* list);

Node* tail(Node* list);

Node* copyList(Node* lst);

Node* append(Node* fstList, Node* sndList);

Node* makeList(int n);

void* nth(int n, Node* list);
