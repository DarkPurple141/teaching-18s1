
#int main(void) {
#
#   int x = 2;
#   if (x > 1) {
#      printf("%d", x);
#   }
#
#   return 0;
#}

.data
x: .word 0

# mips runs straight down the page
.text
.globl main
main:

   # int x = 2
   li $t0, 2

   sw $t0, x

   li $t1, 1

   # if x > 1 actually if 1 <= x
   bge $t1, $t0, end_if
   if_x:
      lw $a0, x
      li $v0 1
      syscall
   end_if:

   # return 0
   li  $v0 0
   jr  $ra
