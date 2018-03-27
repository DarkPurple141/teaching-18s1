/*
Written by John Shepherd, UNSW
For COMP1521 18s1
*/ 

#define LIFE 42
#define VAL  random()%20
#define sq(x) (x*x)
#define woof(y) (LIFE+y)

int main()
{
   char s[LIFE];
   int  i = woof(5);
   i = VAL;
   return (sq(i) > LIFE) ? 1 : 0;
}
