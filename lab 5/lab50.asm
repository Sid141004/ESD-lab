	AREA RESET, DATA, READONLY;factorial without recursion
	EXPORT __Vectors

__Vectors
	DCD 0X40001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	MOV R0, #5
	MOV R3, #1
	MOV R4, R0
loop  
	CMP R0,#1
	MULGT R3, R0, R3
	SUBGT R0, #1
	BGT loop
STOP B STOP
	END
