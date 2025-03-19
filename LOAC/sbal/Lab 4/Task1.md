## TASK 1

MOV AX 3d ; comma is not implemented after 1st operand
MOV 23, AX ; immediate number can not be on destination
MOV CX, CH ; two different size operands are not allowed
MOVE AX, 1h ; mov spelling is not correct
ADD 2, CX ; immediate number can not be on destination
ADD 3, 6 ; both operands can not be immediate numbers
INC AX, 2 ; inc directive have only one operand
