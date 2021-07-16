#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int (*sumCurry(int a))(int) {
	int sumA(int b) {
		return a+b;
	}
	
	return sumA;
}

int main(int argc, char *argv[]) {
	int a = 15;
	int b = 20;
	
	// curried function
	int sumAB = sumCurry(a)(b);
	
	printf("%d\n", sumAB);
	
	return 0;
}

