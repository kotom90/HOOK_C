void SendAction(BYTE* actionBuffer,UINT size)
{
	BYTE _byte1; //the 1st encrypted byte to be sent.
	BYTE _byte2; //the 2nd encrypted byte to be sent.
	UINT size_ = size;
	__asm 
	{
		//byte1
		push esi
		mov esi, encAddr
		mov al,[esi]
		not al
        add al,[esi+1]
		imul byte ptr [esi+2]
		mov cl,al
		shr cl,04
		xor cl,al
		mov _byte1, cl
		mov [esi],cl
		pop esi
		//mov eax,[edi]
		//mov eax,[eax+00001058]
	}
	actionBuffer[4] = _byte1;
	__asm
	{
		push ecx
		push esi
		push edi
		push edx

		mov edx, size_ //bufferSize loops
		push edx
		mov ecx,encAddr2 //to meros tou encryption
		mov esi,actionBuffer //buffer location

		mov eax,0xffffffff
		mov edi,[ecx]
		shl edi,0x08

jump:	movzx edx,byte ptr [esi] //jump here
		xor edx,eax
		and edx,0x000000ff
		add edx,edi
		shr eax,0x08
		xor eax,[edx*0x4+0x00fe2fd0]
		add esi,0x01
		pop edx
		sub edx,0x01
		push edx
		jne jump
		
		mov [ecx+0x04],eax
		pop edx
		pop edx
		pop edi
		pop esi
		pop ecx
		
		//byte 2
		push esi
		mov esi,encAddr2
		mov edx,[esi+0x06]
		mov ecx,[esi+0x04]
		mov bl,dh
		mov al,ch
		add al,bl
		add al,dl
		add al,cl
		mov _byte2,al
		pop esi
	}
	actionBuffer[5] = _byte2;

	send(send_s,(LPCSTR)actionBuffer,size,0);
	actionBuffer[4] = 0x00;
	actionBuffer[5] = 0x00;
	//sprintf( result, "%X", _byte1);
	//MessageBox(0,result,"",MB_OK);
	//sprintf( result, "%X", _byte2);
	//MessageBox(0,result,"",MB_OK);
}
