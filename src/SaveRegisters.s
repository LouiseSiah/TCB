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
								str  		sp, [r4]					; Store R13 to where R4 is pointing to
								
								BX			lr									; Return to caller
                ENDP
									
;//saveRegs  			PROC
;//                EXPORT  saveRegs
;//                ;IMPORT  currentSP
;//								IMPORT  nextSP;

;//								;mov			r4, 0x444
;//								;mov			r5, 0x55
;//								;mov			r11, 0x011
;//								ldr			r0, =currentSP			; Let R4 points to 'currentSP'
;//								mov     sp, r0
;//								push		{r4-r11, lr}
;//								ldr			r4, =nextSP			; Let R4 points to 'nextSP'
;//								mov     sp, r4
;//								;str  		r13, [r4]						; Store R13 to where R4 is pointing to
;//								
;//								BX			lr									; Return to caller
;//                ENDP
;//									
popSpToTcb  		PROC
                EXPORT  popSpToTcb

								;mov			r4, 0x444
								;mov			r5, 0x55
								;mov			r11, 0x011
								pop 		{r4-r11,lr}
								BX			lr									; Return to caller
                ENDP				
									
								END