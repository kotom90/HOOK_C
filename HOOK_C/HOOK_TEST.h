//#include <windows.h>
//#include <stdio.h>
//
//#define JMP(frm, to) (int)(((int)to - (int)frm) - 5); 
//
//DWORD SendOriginalAddress = 0;
//DWORD SendReturnAddress = 0;
//DWORD* SendNewAddress = 0;
//DWORD OldProtection = 0;
//
//char* send_buffer;
//int send_sizeofdata = 0;
//SOCKET send_s;
//int send_flags = 0; 
//
//int kot()
//{
//	return 5;
//}
//
//void __declspec(naked) __stdcall  SendHookFunc()    
//{
//   __asm
//   {
//            mov  edi,edi
//            push ebp
//            mov ebp, esp
//            mov eax, [ebp+0x08] /* Param 1 : Socket */
//            mov send_s, eax
//            mov eax, [ebp+0x0C] /* Param 2 : buffer */
//            mov [send_buffer], eax
//            mov eax, [ebp+0x10] /*Param 3 : Size*/
//            mov send_sizeofdata, eax
//            mov eax, [ebp+0x14] /*Param 4 : flags*/
//            mov send_flags, eax
//            jmp SendReturnAddress
//   }
//} 
//
//int main()
//{
//	SendNewAddress = (DWORD*)SendHookFunc; 
//	HINSTANCE hDll = LoadLibrary((LPCTSTR) "Ws2_32.dll");
//	SendOriginalAddress = (DWORD)GetProcAddress(hDll, "send");
//	SendReturnAddress = SendOriginalAddress + 5; 
//	VirtualProtect( (void*)SendOriginalAddress, 0x05, PAGE_READWRITE , &OldProtection );
//	getchar();
//	*(BYTE *)(SendOriginalAddress) = 0xe9;
//	getchar();
//	*(int *)(SendOriginalAddress+1) = JMP(SendOriginalAddress, SendNewAddress);
//
//	printf("%X\n",SendOriginalAddress);
//	printf("%X\n",SendHookFunc);
//	printf("%d",kot());
//	getchar();
//}