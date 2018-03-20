# an example layout for a function

# mips runs straight down the page
.text
.globl main
main:

   # save the return address
   move $s0, $ra
   jal function

   # return the return address
   move $ra, $s0

   # print the number returned by func
   move $a0, $v0
   li $v0, 1
   syscall

   li  $v0, 0
   jr  $ra

# function
function:

# prologue
# reset stack and frame pointers here in real func
function_prologue:

# do something
   li $v0, 22

# reset stack and frame pointers here in real func
function_epilogue:


end_function:
   jr $ra
# return
