#include <stdio.h>
#include <stdlib.h>

void count(int n) {
	if (n == 0) {
		printf("%d\n", n);
	} else {
		printf("%d ", n);
		count(n-1);
	}
}

/*
1 1 2 3 5 8...
n = (n-1) + (n-2)
*/
unsigned int array[201] = {0};

unsigned int fib(unsigned int n) {
	if (array[n]) {
		return array[n];
	}

	if (n == 1 || n == 0) {
		return 1;
	} else {
		array[n-1] = fib(n-1);
		array[n-2] = fib(n-2);
		return array[n-1] + array[n-2];
	}
}

void changeVowels(char *str) {
	if (*str == '\0') {
		return;
	} else {
		char c = *str;
		if (c == 'a' || c == 'e' || c == 'i') {
			*str = c - 32;
		}
		changeVowels(str + 1);
	}

}

int main(int argc, char const *argv[])
{
	char str[] = "Mary had a little lamb";
	changeVowels(str);
	printf("%s\n", str);
	return 0;
}
