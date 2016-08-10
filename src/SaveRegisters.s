								PRESERVE8
                THUMB

; Global data
                AREA    MyData, DATA, READWRITE, ALIGN=2
								AREA    MyCode, CODE, READONLY
;								EXPORT  taskSp
;								taskSp		DCD     1
								
loadCurrentSP  	PROC
                EXPORT  loadCurrentSP
                IMPORT  currentSP
				
								ldr			r4, =currentSP			; Let R4 points to 'variableInC'
								str  		r13, [r4]						; Store R13 to where R4 is pointing to
								
								BX			lr									; Return to caller
                ENDP
									
								END
									