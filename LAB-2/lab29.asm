	AREA RESET, DATA, READONLY;division using reptetive subtraction
	EXPORT __Vectors
__Vectors
	DCD 0X10001001;STACK POINTER VALUE WHEN
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	MOV R3, #0
	LDR R0, =N1
	LDR R1, [R0]
	LDR R0, =N2
	LDR R2, [R0]
BACK CMP R1,R2
	BLO EXIT
	SUB R1,R2
	ADD R0, #1
	B BACK
EXIT ;STORE WHERVER.
STOP B STOP
N1 DCD #2000
N2 DCD #3
	END
