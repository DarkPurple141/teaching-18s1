int  a;
char b[100];

int fun1() { int c, d; ... }

double e;

int fun2() { int f; static int ff; ... fun1() ... }

unsigned int g;

int main(void) { char h[10]; int i; ... fun2() ... }
