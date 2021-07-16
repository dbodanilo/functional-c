#include <stdio.h>
#include <stdlib.h>

#include "BinaryTree.h"

int lookupTest() {
	int arr[] = {1, 3, 7, 8, 10};
	
	Node* tree = TreeFromArr(arr, 5);
	
	int val = 8;
	
	int found = lookup(tree, val);
	
	if(found) printf("%d is in the tree\n", val);
	else printf("%d is not in the tree\n", val);
}

int main() {
	lookupTest();	
	
	return 0;
}

