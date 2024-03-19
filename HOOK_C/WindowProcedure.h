LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
		case WM_COMMAND:
			if ((HWND)lParam == hButton)
				//sprintf( result, "%X", sizeof(actionBuffer_));
				//MessageBox(0,result,"",MB_OK);
				*(DWORD*)(target + 0x06) = (DWORD)0x00866FD5;
				SendAction(target,(UINT)sizeof(target));
				//0x05 0x00 0x34 0x70 0x00 0x00 0x00 0x01 0x14 0x00 0x00
		break;
		case WM_CLOSE:
			//SendAction(actionBuffer_,(UINT)sizeof(actionBuffer_));
			DestroyWindow(hwnd);
		break;
		case WM_DESTROY:
			PostQuitMessage(0);
		break;
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}