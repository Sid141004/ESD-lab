	AREA RESET, DATA, READONLY ;WRITE AN ASSEMBLY LEVEL program to copy the data from one memory block to another where the memory blocks are overlapping.
	EXPORT __Vectors
__Vectors
	DCD 0X10001001 ;STACK POINTER VALUE WHEN
	DCD Reset_Handler ;reset vector
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
