# ZERO: Making the Common Case Slow

######### Register Usage ###########
# t0-t9: zero loading range

# s0: loop start variable
# s1: loop end variable
# s5: timer start value
# s7: arbitrary arithmetic operand
###################################
				
	.text
	
	li $s7, 123
	
	# set loop range
	li $s0, 0
	li $s1, 262144  # 2^18
	#li $s1, 16777216 # 2^24
	#li $s1, 2147483647 # 2^31 - 1
	
	# Timer start
	li $v0, 30
	syscall
	
loop:	
	# Here you choose which method to load zero.
	# Only uncomment one method at a time.
	# Repeat multiple times for more accuracy.
	
#	move $t0, $zero		#1
#	move $t1, $zero
#	move $t2, $zero
#	move $t3, $zero
#	move $t4, $zero
#	move $t5, $zero
#	move $t6, $zero
#	move $t7, $zero
#	move $t8, $zero
#	move $t9, $zero
		
#	li $t0, 0		#2
#	li $t1, 0
#	li $t2, 0
#	li $t3, 0
#	li $t4, 0
#	li $t5, 0
#	li $t6, 0
#	li $t7, 0
#	li $t8, 0
#	li $t9, 0
	
#	xor $t0, $t0, $t0	#3
#	xor $t1, $t1, $t1
#	xor $t2, $t2, $t2
#	xor $t3, $t3, $t3
#	xor $t4, $t4, $t4
#	xor $t5, $t5, $t5
#	xor $t6, $t6, $t6
#	xor $t7, $t7, $t7
#	xor $t8, $t8, $t8
#	xor $t9, $t9, $t9
	
#	sub $t0, $s7, $s7	#4
#	sub $t1, $s7, $s7
#	sub $t2, $s7, $s7
#	sub $t3, $s7, $s7
#	sub $t4, $s7, $s7
#	sub $t5, $s7, $s7
#	sub $t6, $s7, $s7
#	sub $t7, $s7, $s7
#	sub $t8, $s7, $s7
#	sub $t9, $s7, $s7
	
	mul $t0, $s7, $zero	#5
	mul $t1, $s7, $zero
	mul $t2, $s7, $zero
	mul $t3, $s7, $zero
	mul $t4, $s7, $zero
	mul $t5, $s7, $zero
	mul $t6, $s7, $zero
	mul $t7, $s7, $zero
	mul $t8, $s7, $zero
	mul $t9, $s7, $zero

	# increment loop
	addi $s0, $s0, 1
	blt $s0, $s1, loop
	
	# stop timer and print difference (ms)
	move $s5, $a0
	syscall
	subu $a0, $a0, $s5
	li $v0, 1
	syscall
	
	# Beep when done
	li $v0, 31
	li $a2, 0
	li $a3, 127
	li $a0, 67
	li $a1, 350
	syscall
	
	# exit
	li $v0, 10
	syscall
