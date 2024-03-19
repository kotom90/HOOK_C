#include <string>
#include "windows.h"
#include "winsock.h"

#pragma comment ( lib, "Ws2_32.lib" )
#define JMP(frm, to) (int)(((int)to - (int)frm) - 5);

void InstallHook();
void UnHookSend();
void SendAction(BYTE*,UINT);

HMODULE dahak; //the dll

char* send_buffer;
int send_sizeofdata = 0;
SOCKET send_s = INVALID_SOCKET; //game's socket
int send_flags = 0;

DWORD SendReturnAddress = 0;
DWORD* SendNewAddress = 0;
DWORD OldProtection = 0;
DWORD SendOriginalAddress = 0;

DWORD RecvReturnAddress = 0;
DWORD* RecvNewAddress = 0;
//DWORD OldProtection = 0;
DWORD RecvOriginalAddress = 0;
DWORD* RecvBufferPtr = NULL;
//WORD* RecvBufferPtrWord = NULL;
DWORD* RecvSize;
u_char* RecvBuffer;


BYTE* encAddr; //Address of the 1st encrypted byte.
BYTE* encAddr2; //Address of the 2nd encrypted byte.

char result[100]; //test msgbox

const char g_szClassName[] = "myWindowClass";
HWND hButton;













//-------------------------------------###### BOT VARIABLES ######--------------------------------------
//#### ACTIONS CONSTRUCTION####

WORD ActionSizeSum;
DWORD ActionsSum;
WORD CurrentAction[100];
DWORD ActionAddress[100];
u_long curr=0; //the current action

// #### ACTION CHECKS #### 

BOOL attacking = false;
BOOL shouldAddToList = false;
BOOL shouldRemoveFromList = false;
BOOL isInvalidTarget = false;

//#### ACTIONS (SERVER PACKETS)####

#define actionNo 0x9130
#define actionMove 0x21B0
#define actionTarget 0x45B0
#define actionUpdateHPMP 0x5730
#define actionObjComing 0x1530
#define actionObjAppearedDisappeared 0x1730
#define actionObjAppearDisappearInfo 0x1930
#define actionObjDisappeared 0x1630

//// #### CLIENT PACKETS #### 
//BYTE actionBuffer_[] = {0x05,0x00,0x34,0x70,0x00,0x00,0x00,0x10,0x01,0x00,0x00}; //77 32
BYTE target[] = {0x04,0x00,0x45,0x70,0x00,0x00,0x00,0x00,0x00,0x00}; //target
BYTE attack[] = {0x07,0x00,0x74,0x70,0x00,0x00,0x01,0x01,0x01,0x00,0x00,0x00,0x00}; //attack
BYTE net[] = {0x01,0x00,0x91,0x30,0x00,0x00,0x04};

//// #### IDS ####
DWORD playerId = 0;
BYTE playerClothesEndAddr = 0;
BYTE playerNameSize = 0;
DWORD mobIdList[100];
char lastMobIndex = -1;
BYTE nextByte = 0;
BYTE appearNumber = 0;
BYTE disappearNumber = 0;
WORD objectIdAddressAppear = 0x0006;
WORD objectIdAddressDissapear = 0x0006;
WORD targetType;
u_long availPos;
u_long foundPos;

//// #### ITEM IDS ####
//EtcItem 

//// #### POSITIONS & RANGES####
WORD mobPosX[100];
WORD mobPosY[100];
BYTE mobPosXIndex[100];
BYTE mobPosYIndex[100];

WORD targetRange = 0x0040;
WORD playerPosX = 0;
WORD playerPosY = 0;
BYTE playerPosXIndex = 0;
BYTE playerPosYIndex = 0;

WORD xDist = 0;
WORD yDist = 0;
WORD xMinDist = 0xFFFF;
WORD yMinDist = 0xFFFF;

DWORD closestMobId = 0;