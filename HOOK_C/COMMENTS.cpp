//HANDLE hInstance = GetModuleHandle("sro_client.exe");
//	//MessageBox(0,LPCSTR(hInstance),"",MB_OK);
//	
//	WNDCLASSEX wc;
//	HWND hwnd;
//	MSG Msg;
//
//	//Step 1: Registering the Window Class
//	wc.cbSize		 = sizeof(WNDCLASSEX);
//	wc.style		 = 0;
//	wc.lpfnWndProc	 = WndProc;
//	wc.cbClsExtra	 = 0;
//	wc.cbWndExtra	 = 0;
//	wc.hInstance	 = (HINSTANCE)hInstance;
//	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION);
//	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
//	wc.lpszMenuName  = NULL;
//	wc.lpszClassName = g_szClassName;
//	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION);
//
//	if(!RegisterClassEx(&wc))
//	{
//		MessageBox(NULL, "Window Registration Failed!", "Error!",
//			MB_ICONEXCLAMATION | MB_OK);
//		return 0;
//	}
//
//	// Step 2: Creating the Window
//	hwnd = CreateWindowEx(
//		WS_EX_CLIENTEDGE,
//		g_szClassName,
//		"CATCH ME!!!",
//		WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT, CW_USEDEFAULT, 240, 120,
//		NULL, NULL, (HINSTANCE)hInstance, NULL);
//
//	if(hwnd == NULL)
//	{
//		MessageBox(NULL, "Window Creation Failed!", "Error!",
//			MB_ICONEXCLAMATION | MB_OK);
//		return 0;
//	}
//	ShowWindow(hwnd, SW_SHOW);
//	UpdateWindow(hwnd);
//	Sleep(10000);