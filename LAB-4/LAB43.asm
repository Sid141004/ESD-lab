	AREA RESET, DATA, READONLY;HEXADECIMAL TO BCD
	EXPORT __Vectors

__Vectors
	DCD 0X40001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	MOV R1, #81;TAKING HEXADECIMAL VALUE OF 51
	
UP2	CMP R1, #0
	BEQ EXIT2
	MOV R3,#0
	
UP1	CMP R1,#0XA
	BLO EXIT1
	SUB R1,#0XA
	ADD R3,#1
	B UP1
	
EXIT1 LSL R1,R2
	ADD R0,R1;FINAL ANSWER 81 STORED IN R0
	ADD R2,#4
	MOV R1,R3
	B UP2
EXIT2 
STOP B STOP
	END
