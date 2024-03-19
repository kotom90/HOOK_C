void InstallSendHook()
{
	SendNewAddress = (DWORD*)AsmSendHook;
	HINSTANCE hDll = GetModuleHandle(TEXT("Ws2_32.dll"));
	SendOriginalAddress = (DWORD)GetProcAddress(hDll, "WSASend"); 
	SendReturnAddress = SendOriginalAddress + 5;
	VirtualProtect( (void*)SendOriginalAddress, 0x05, PAGE_READWRITE , &OldProtection );
	*(BYTE *)(SendOriginalAddress) = 0xe9;
	*(int *)(SendOriginalAddress+1) = JMP(SendOriginalAddress, SendNewAddress);
}

void UnHookSend()
{
	*(WORD *)SendOriginalAddress = 0xFF8B;		// mov  edi,edi
	*(BYTE *)(SendOriginalAddress+2) = 0x55;	// push epb
	*(WORD *)(SendOriginalAddress+3) = 0xEC8B;	// mov epb, esp
	VirtualProtect( (void*)SendOriginalAddress, 0x05, OldProtection, &OldProtection );
}

void InstallRecvHook()
{
	RecvNewAddress = (DWORD*)AsmRecvHook;
	HINSTANCE hDll = GetModuleHandle(TEXT("Ws2_32.dll"));
	RecvOriginalAddress = (DWORD)GetProcAddress(hDll, "WSARecv"); 
	RecvReturnAddress = RecvOriginalAddress + 5;
	VirtualProtect( (void*)RecvOriginalAddress, 0x05, PAGE_READWRITE , &OldProtection );
	*(BYTE *)(RecvOriginalAddress) = 0xe9;
	*(int *)(RecvOriginalAddress+1) = JMP(RecvOriginalAddress, RecvNewAddress);
}

void UnHookRecv()
{
	*(WORD *)RecvOriginalAddress = 0xFF8B;		// mov  edi,edi
	*(BYTE *)(RecvOriginalAddress+2) = 0x55;	// push epb
	*(WORD *)(RecvOriginalAddress+3) = 0xEC8B;	// mov epb, esp
	VirtualProtect( (void*)RecvOriginalAddress, 0x05, OldProtection, &OldProtection );
}

void InstallRecvHookForever()
{
	RecvNewAddress = (DWORD*)AsmRecvHookForever;
	//HINSTANCE hDll = GetModuleHandle(TEXT("ws2_32.dll"));
	RecvOriginalAddress = 0x00486643;//(DWORD)GetProcAddress(hDll, "WSARecv"); 
	RecvReturnAddress = RecvOriginalAddress + 5;
	VirtualProtect( (void*)RecvOriginalAddress, 0x05, PAGE_READWRITE , &OldProtection );
	*(BYTE *)(RecvOriginalAddress) = 0xe9;
	*(int *)(RecvOriginalAddress+1) = JMP(RecvOriginalAddress, RecvNewAddress);
}

void UnHookRecvForever()
{
	*(DWORD *)RecvOriginalAddress = 0x5EFFF883;		// mov  edi,edi
	*(BYTE *)(RecvOriginalAddress+4) = 0x5D;	// push epb
	//*(WORD *)(RecvOriginalAddress+3) = 0xEC8B;	// mov epb, esp
	VirtualProtect( (void*)RecvOriginalAddress, 0x05, OldProtection, &OldProtection );
}