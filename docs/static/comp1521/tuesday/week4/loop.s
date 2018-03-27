
# loops
# program prints 0 - 9

# mips runs straight down the page
.text
.globl main
main:

   li $s0, 0
   li $t1, 10

   loop:
      beq $s0, $t1, end_loop   # if s0 == t1 then

      li   $v0, 1
      move $a0, $s0
      syscall # print int

      li  $v0, 11
      li  $a0, 10
      syscall # print char ('\n')

      addi $s0, $s0, 1          # $s0 = s0 + 1
      j loop
   end_loop:

   jr  $ra
