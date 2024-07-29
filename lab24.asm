	AREA RESET, DATA, READONLY ;WRITE AN ASSEMBLY LEVEL program to copy 5 32 bit numbers from 1 array to another and the arrays are defined in the data memory
	EXPORT __Vectors
__Vectors
	DCD 0X10001001 ;STACK POINTER VALUE WHEN
	DCD Reset_Handler ;reset vector
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	MOV R3, #5
	LDR R0, =N;R0 = 0X000014?
	LDR R1, =DST
BACK LDR R2, [R0];R2=R0
	STR R2, [R1];OPPOSITE TO LDR
	LDR R2, [R0], #4
	STR R2, [R1], #4
	SUB R3, #1
	CMP R3, #0
	BNE BACK 
STOP B STOP
	AREA mydata, DATA, READWRITE
N DCD 0X12345678,0X6A,0X234,0X49C,0XA13BC;you cant assign data memory directly , enter it manually and it will copy below.
DST DCD 0,0,0,0,0
	END
