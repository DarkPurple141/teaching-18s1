#include <stdio.h>
#include <stdlib.h>

void count(int n) {
	if (n == 0) {
		printf("%d\n", n);
	} else {
		printf("%d ", n);
		count(n -1);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter n: ");
	scanf("%d", &n);
	count(n);
	return 0;
}
