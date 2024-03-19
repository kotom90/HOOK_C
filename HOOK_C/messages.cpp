//#include <windows.h>
//#include <cstdlib>
//#include <iostream>
//
//using namespace std;
//
//int main(int argc, char *argv[])
//{
//    HWND cheat = FindWindow(0,"SRO_Client");
//    if(cheat == 0)
//    {
//             cout <<"Game not runninga!\n";
//    }
//    else
//    {
//		Sleep(4000);
//
//		/*INPUT Input={0};
//		Input.type = INPUT_MOUSE;
//		Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;
//		::SendInput(1,&Input,sizeof(INPUT));
//
//		::ZeroMemory(&Input,sizeof(INPUT));
//		Input.type      = INPUT_MOUSE;
//		Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;
//		::SendInput(1,&Input,sizeof(INPUT));*/
//
//
//		//SendInput(
//		//DWORD ID;
//        //GetWindowThreadProcessId(cheat,&ID);
//        //HANDLE hProcess = OpenProcess(PROCESS_VM_OPERATION | PROCESS_VM_READ, FALSE, ID);
//        //if(!hProcess)
//        //{
//                    //cout <<"Game not running!\n";
//        //}
//            //else
//            //{
//                   //int v1 = 5000;
//                   //DWORD new_v1 = sizeof(v1);
//                   //if(WriteProcessMemory(hProcess, (LPVOID)0x009CA46C, &v1, new_v1, NULL))
//                   //{
//                   //                                cout <<"             Hack successful injected!\n";
//                   //}
//	}
//} 