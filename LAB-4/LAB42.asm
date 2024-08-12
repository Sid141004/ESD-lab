	AREA RESET, DATA, READONLY
	EXPORT __Vectors

__Vectors
	DCD 0X40001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	MOV R0, #81;taking it as hexademical for some reason
	LSR R1, R0, #04
	AND R2, R0, #0X0F
	MOV R3, #0XA
	MLA R2,R1,R3,R2
STOP B STOP
	END