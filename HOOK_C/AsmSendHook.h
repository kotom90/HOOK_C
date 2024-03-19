void __declspec(naked) __stdcall  AsmSendHook() 	
{
	__asm
	{ 
				mov  edi,edi
				push ebp
				mov ebp, esp
				mov eax, [ebp+0x08] /* Param 1 : Socket */
				mov send_s, eax
				mov eax, [ebp+0x0C] /* Param 2 : buffer */
				mov [send_buffer], eax
				mov eax, [ebp+0x10] /*Param 3 : Size*/
				mov send_sizeofdata, eax
				mov eax, [ebp+0x14] /*Param 4 : flags*/
				mov send_flags, eax
				jmp SendReturnAddress
	}
}