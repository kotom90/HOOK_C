void __declspec(naked) __stdcall AsmRecvHook() 	
{
	__asm
	{ 
				mov  edi,edi
				push ebp
				mov ebp, esp
				mov RecvBufferPtr, edx
				mov RecvSize, esi
				jmp RecvReturnAddress
	}		
}