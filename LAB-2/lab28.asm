	AREA RESET, DATA, READONLY;SUBTRACT 2 128 BIT NUMBERS
	EXPORT __Vectors
__Vectors
	DCD 0X10001001;STACK POINTER VALUE WHEN
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler