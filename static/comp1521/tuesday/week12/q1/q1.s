# COMP1521 Practice Prac Exam #1
# int everyKth(int *src, int n, int k, int*dest)

   .text
   .globl everyKth

# params: src=$a0, n=$a1, k=$a2, dest=$a3
everyKth:
# prologue
   addi $sp, $sp, -4
   sw   $fp, ($sp)
   la   $fp, ($sp)
   addi $sp, $sp, -4
   sw   $ra, ($sp)
   addi $sp, $sp, -4
   sw   $s0, ($sp)
   addi $sp, $sp, -4
   sw   $s1, ($sp)
   # if you need to save more $s? registers
   # add the code to save them here
#   int everyKth(int *src, int n, int k, int *dest)
#   {
#      int i, j = 0;
#      for (i = 0; i < n; i++) {
#         if (i%k == 0) {
#            dest[j] = src[i];
#            j++;
#         }
#      }
#      return j;
#   }
# function body
# locals: ...
   li    $t0, 0 # i = 0
   li    $v0, 0 # j = 0

start_for:
   beq   $t0, $a1, end
   rem   $t2, $t0, $a2

   bnez  $t2, end_for
   mul   $t1, $t0, 4     # get 4 byte offset ie index*4
   add   $t1, $t1, $a0   # get address (ie add ptr+offset)
   lw    $t2, ($t1)      # get the value for *src (deref)

   mul   $t3, $v0, 4
   add   $t3, $t3, $a3   # now at the correct dest address

   sw    $t2, ($t3)      # *dest[j] = src[i]

   addi  $v0, $v0, 1

end_for:
   addi  $t0, $t0, 1
   j     start_for

end:
   # epilogue
   # if you saved more than two $s? registers
   # add the code to restore them here
   lw   $s1, ($sp)
   addi $sp, $sp, 4
   lw   $s0, ($sp)
   addi $sp, $sp, 4
   lw   $ra, ($sp)
   addi $sp, $sp, 4
   lw   $fp, ($sp)
   addi $sp, $sp, 4
   j    $ra
