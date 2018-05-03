
static int error;

int getInt() {
   if (isChar()) {
      error = 5;
      return -1;
   }

   return number;
}
