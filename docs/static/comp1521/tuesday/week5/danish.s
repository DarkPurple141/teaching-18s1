
        .data
 nrows: .word 6
 ncols: .word 12
 flag:  .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
        .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
        .byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
        .byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'

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

    # while (i < rows)
    outer_loop:
      beq  $t0, $s0, outer_loop_end
      li   $t1, 0

      # while ( j < cols)
      inner_loop:
         beq  $t1, $s1, inner_loop_end
         mul  $t2, $s1, $t0      # row offset
         add  $t2, $t2, $t1      # row + col offset
         lb   $a0, flag($t2)     # proper index
         li   $v0, 11
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
