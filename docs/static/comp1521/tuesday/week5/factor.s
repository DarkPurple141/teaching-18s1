.data
nrows: .word 3
ncols: .word 4
M:  .word 1, 2, 3, 4
    .word 3, 4, 5, 6
    .word 5, 6, 7, 8


.text
.globl main
main:
   # prologue
   addi $sp, $sp, -4
   sw   $fp, ($sp)
   move $fp, $sp
   addi $sp, $sp, -4
   sw   $ra, ($sp)

   lw   $s0, nrows #rows
   lw   $s1, ncols #cols
   li   $t0, 0
   li   $t1, 0
   li   $v0, 5
   syscall
   move  $s2, $v0
   # while (i < rows)
   outer_loop:
     beq  $t0, $s0, outer_loop_end
     li   $t1, 0

     # while ( j < cols)
     inner_loop:
        beq  $t1, $s1, inner_loop_end
        mul  $t2, $s1, $t0    # row offset
        mul  $t2, $t2, 4      # row offset
        mul  $t3, $t1, 4
        add  $t2, $t2, $t3      # row + col offset
        lw   $a0, M($t2)        # proper index
        mul  $a0, $a0, $s2
        li   $v0, 1
        syscall
        addi $t1, $t1, 1
        j inner_loop

     inner_loop_end:
     # print new line
     li   $a0, 10
     li   $v0, 11
     syscall

     # i ++
     addi $t0, $t0, 1
     j outer_loop
   outer_loop_end:


   # epilogue
   lw   $ra, ($sp)
   addi $sp, $sp, 4
   lw   $fp, ($sp)
   addi $sp, $sp, 4
   jr   $ra
