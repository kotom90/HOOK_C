//winsock send hook
//#include <ostream>
#define EDITID 1000

#include <stdio.h>
#include "botIncludes.h"

#include "bot_funcs.h"
#include "RecvThread.h"
#include "SendFunction.h"
#include "AsmSendHook.h"
#include "AsmRecvHook.h"
#include "InstallUninstallHook.h"
#include "WindowProcedure.h"

//BYTE actionBuffer_[] = {0x04,0x00,0x45,0x70,0x00,0x00,0x00,0x00,0x00,0x02};

//BYTE actionBuffer_[] = {0x00,0x00,0x02,0x20,0x00,0x00};


int BotCreate()
{
//------######HOOK INSTALL/UNISTALL######------//
	FreeConsole();
	AllocConsole();
	GetStdHandle(STD_OUTPUT_HANDLE);
	InstallSendHook(); //install the hook to send function
	while(send_s == INVALID_SOCKET) // loop until a valid socket has found
	{
		Sleep(1000);
	}
	UnHookSend();
	printf("Send hooked successfully!\n");
	InstallRecvHook();
	while(RecvBufferPtr == NULL)
	{
		Sleep(1000);
	}
	UnHookRecv();
	printf("Recv hooked successfully!\n");
//------######FIND ADDRESSES######------//
	DWORD* encPtr = (DWORD*)0x010260CC; //pointer to address of the encryption space
	encPtr = (DWORD*)(*encPtr + 0x08);
	encPtr = (DWORD*)(*encPtr + 0x28);
	encAddr = (BYTE*)*encPtr+0x16c; //1st byte enc address
	encAddr2 = (BYTE*)*encPtr+0x164; //2nd byte enc address

	RecvBufferPtr = (DWORD*)RecvBufferPtr + 0x01;
	RecvBuffer = (u_char*)(*RecvBufferPtr);
	//RecvBufferPtrWord = (WORD*)RecvBuffer;
	RecvSize = (DWORD*)RecvSize+0x01;
	//sprintf(result, "%X", *RecvSize);
	//MessageBox(0,result,"",MB_OK);

	InstallRecvHookForever();
	//HANDLE popothread = CreateThread(0,0,(LPTHREAD_START_ROUTINE)&RecvThread,0,0,0);







//------######CREATE WINDOW######------//
	HANDLE hInstance = GetModuleHandle("sro_client.exe");
	WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;
	//Step 1: Registering the Window Class
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.style		 = 0;
	wc.lpfnWndProc	 = WndProc;
	wc.cbClsExtra	 = 0;
	wc.cbWndExtra	 = 0;
	wc.hInstance	 = (HINSTANCE)hInstance;
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszMenuName  = NULL;
	wc.lpszClassName = g_szClassName;
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION);

	if(!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Window Registration Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	// Step 2: Creating the Window
	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		g_szClassName,
		"SR0 b0T bY //+-KoT+-_\\\\",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 240, 120,
		NULL, NULL, (HINSTANCE)hInstance, NULL);

	hButton = CreateWindow ("BUTTON", "wear",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        10, 10, 100, 20, hwnd, NULL, (HINSTANCE)hInstance, NULL);
	DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_HSCROLL | WS_VSCROLL | 
                WS_BORDER | ES_LEFT | ES_MULTILINE | ES_NOHIDESEL | 
                ES_AUTOHSCROLL | ES_AUTOVSCROLL;
	/*CreateWindow ("EDIT", NULL,
		dwStyle,
        60, 70, 150, 20, hwnd, (HMENU)EDITID, (HINSTANCE)hInstance, NULL);*/

	if(hwnd == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}
	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);
	while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
	UnregisterClass(g_szClassName,(HINSTANCE)hInstance);
	//TerminateThread(popothread,1);
	UnHookRecvForever();
	FreeLibraryAndExitThread(dahak,0);
	//ExitThread(0);
}


//------######DLL ENTRY######------//


BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)

{
	dahak = hModule;
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
		CreateThread(0,0,(LPTHREAD_START_ROUTINE)&BotCreate,0,0,0);
		//send(100,"fata",12,0);
		//HookSend();
		//send(100,"fata",12,0);
	//if (ul_reason_for_call == DLL_THREAD_DETACH)
		//UnHookSend();
    return TRUE;
}