int everyKth(int *src, int n, int k, int *dest)
{
   int i, j = 0;
   for (i = 0; i < n; i++) {
      if (i%k == 0) {
         int *p = src;
         p = p + i*sizeof(int);
         int value = *p;

         int *q = dest;
         q = q + j*sizeof(int);
         *q = value;
         j++;
      }
   }
   return j;
}
