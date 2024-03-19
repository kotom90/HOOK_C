void __declspec(naked) __stdcall AsmRecvHookForever() 	
{
	__asm
	{ 
		cmp eax,0xff
		pop esi
		pop ebp
	}
	if(playerId == 0)
	{
		Sleep(2000);
		SendAction(net,(UINT)sizeof(net));
	}
	CurrentAction[0] = RecvBuffer[2]*256; //action ID
	CurrentAction[0] += RecvBuffer[3]; 
	ActionAddress[0] = 0; //1st action starts at 0
	ActionsSum = 0; //number of actions
	ActionSizeSum = *(WORD*)(RecvBuffer) + 6;
	//printf("Size: %p\n",*(WORD*)(RecvBuffer));
	while(ActionSizeSum < *RecvSize)
	{
		ActionsSum++;
		CurrentAction[ActionsSum] = RecvBuffer[ActionSizeSum+2]*256;
		CurrentAction[ActionsSum] += RecvBuffer[ActionSizeSum+3];
		//printf("Size: %p\n",*(WORD*)(RecvBuffer+ActionSizeSum));
		ActionAddress[ActionsSum] = ActionSizeSum;
		ActionSizeSum = *(WORD*)(RecvBuffer+ActionSizeSum)+6+ActionSizeSum;
	}
	for(curr=0;curr<=ActionsSum;curr++) //check the packet for every action
	{
		//printf("Action: %p\n",CurrentAction[curr]);
		switch(CurrentAction[curr])
		{
			case actionNo:
				if(playerId == 0) //if the player's id is not known yet.
				{
					playerId = *(DWORD*)(RecvBuffer+ActionAddress[curr]+0x06);
				}
			break;
			case actionMove: //when something moved, update its position
				if(*(DWORD*)(RecvBuffer+ActionAddress[curr]+0x06) != playerId && (lastMobIndex != -1))
				{
					for(u_long pos = 0; pos <= lastMobIndex; pos++) //find the disappeared mob in the list
					{
						if(mobIdList[pos] == *(DWORD*)(RecvBuffer+ActionAddress[curr]+0x06))
						{
							foundPos = pos;
							break;
						}
						if(pos == lastMobIndex)
						{
							isInvalidTarget = true;
						}
					}
					if(!isInvalidTarget)
					{
						mobPosXIndex[foundPos] = *(BYTE*)(RecvBuffer+ActionAddress[curr]+0x0B);// - playerPosX < 0x0060
						mobPosYIndex[foundPos] = *(BYTE*)(RecvBuffer+ActionAddress[curr]+0x0C); //- playerPosY < 0x0060
						mobPosX[foundPos] = *(WORD*)(RecvBuffer+ActionAddress[curr]+0x0D);// - playerPosX < 0x0060
						mobPosY[foundPos] = *(WORD*)(RecvBuffer+ActionAddress[curr]+0x11); //- playerPosY < 0x0060
						/*if((mobPosX[foundPos] - playerPosX < targetRange) && (mobPosY[foundPos] - playerPosY < targetRange))
						{
							*(DWORD*)(target+0x06) = mobIdList[foundPos];
							SendAction(target,(UINT)sizeof(target)); //target the mob
							while(target[2] != 0x45) //leave only if targeted
							{
							}
							//sprintf(result, "%X", RecvBuffer[12]);
							//MessageBox(0,result,"",MB_OK);
							//MessageBox(0,"","",MB_OK);
						}*/
					}
					else
						isInvalidTarget = false;
				}
				else if(*(DWORD*)(RecvBuffer+ActionAddress[curr]+0x06) == playerId)
				{
					playerPosXIndex = *(BYTE*)(RecvBuffer+ActionAddress[curr]+0x0B);// - playerPosX < 0x0060
					playerPosYIndex = *(BYTE*)(RecvBuffer+ActionAddress[curr]+0x0C);
					playerPosX = *(WORD*)(RecvBuffer+ActionAddress[curr]+0x0D);
					playerPosY = *(WORD*)(RecvBuffer+ActionAddress[curr]+0x11);
					//printf("X:%p\n",playerPosX);
					//printf("Y:%p\n\n",playerPosY);
				}
			break;
			case actionTarget: //when something targeted
				if(RecvBuffer[12] > 0) // If hp > 0
				{
					SendAction(attack,(UINT)sizeof(attack)); //attack
					//Sleep(8000); //wait for 8 seconds
				}
			break;
			case actionUpdateHPMP: //when there is HP/MP update
				if (RecvBuffer[ActionAddress[curr]+0x0D] == 0 && lastMobIndex != -1)
				{
					for(u_long pos = 0; pos <= lastMobIndex; pos++) //find the disappeared mob in the list
					{
						if(mobIdList[pos] == *(DWORD*)(RecvBuffer+ActionAddress[curr]+0x06))
						{
							foundPos = pos;
							printf("1630 HP/MP: %d: %p gone!!!\n",pos,mobIdList[foundPos]);
							break;
						}
					}
					for(u_long shiftAddress=foundPos; shiftAddress < lastMobIndex; shiftAddress++)
					{
						mobIdList[shiftAddress] = mobIdList[shiftAddress+1];
						mobPosX[shiftAddress] = mobPosX[shiftAddress+1];
						mobPosY[shiftAddress] = mobPosY[shiftAddress+1];
						mobPosXIndex[shiftAddress] = mobPosXIndex[shiftAddress+1];
						mobPosYIndex[shiftAddress] = mobPosYIndex[shiftAddress+1];
					}
					lastMobIndex--;
					for(u_long pos = 0; pos <= lastMobIndex; pos++) //find the closest target
					{
						//find x distance between player - mob
						if(playerPosXIndex == mobPosXIndex[pos])
						{
							if(playerPosX < mobPosX[pos])
								xDist = mobPosX[pos] - playerPosX;
							else
								xDist = playerPosX - mobPosX[pos];
						}
						else if(playerPosXIndex < mobPosXIndex[pos])
							xDist = mobPosX[pos] - playerPosX;
						else
							xDist = playerPosX - mobPosX[pos];
						//find y distance between player - mob
						if(playerPosYIndex == mobPosYIndex[pos])
						{
							if(playerPosY < mobPosY[pos])
								yDist = mobPosY[pos] - playerPosY;
							else
								yDist = playerPosY - mobPosY[pos];
						}
						else if(playerPosYIndex < mobPosYIndex[pos])
							yDist = mobPosY[pos] - playerPosY;
						else
							yDist = playerPosY - mobPosY[pos];

						if((xDist+yDist) < (xMinDist+yMinDist))
						{
							xMinDist = xDist;
							yMinDist = yDist;
							closestMobId = mobIdList[pos];
						}
					}
					xMinDist = 0xFFFF;
					yMinDist = 0xFFFF;
					*(DWORD*)(target+0x06) = closestMobId;
					*(DWORD*)(attack+0x09) = closestMobId;
					SendAction(target,(UINT)sizeof(target)); //target the mob
						//attacking = false;
				}
			break;
			case actionObjComing: //packet 0x1530 //the object appeared in region or got in the region
				//printf("1035:\n");
				targetType = *(WORD*)(RecvBuffer+ActionAddress[curr]);
				if (targetType == 0x35) //if the size is 0x35, it means that what appeared is a mob.
				{
				    lastMobIndex++;
					mobIdList[lastMobIndex] = *(DWORD*)(RecvBuffer+ActionAddress[curr]+0x0A);//get the id and save in the list
					mobPosXIndex[lastMobIndex] = *(BYTE*)(RecvBuffer+ActionAddress[curr]+0x0A+0x04);
					mobPosYIndex[lastMobIndex] = *(BYTE*)(RecvBuffer+ActionAddress[curr]+0x0A+0x05);
					mobPosX[lastMobIndex] = *(WORD*)(RecvBuffer+ActionAddress[curr]+0x0A+0x06);
					mobPosY[lastMobIndex] = *(WORD*)(RecvBuffer+ActionAddress[curr]+0x0A+0x0A);
					printf("%d terata einai gyro\n",lastMobIndex+1);
				}
			break;
			case actionObjDisappeared: //packet 0x1630 //the object dissapeared from the region or left from the region
				if(lastMobIndex != -1)
				{
					for(u_long pos = 0; pos <= lastMobIndex; pos++) //find the disappeared mob in the list
					{
						if(mobIdList[pos] == *(DWORD*)(RecvBuffer+ActionAddress[curr]+0x06))
						{
							foundPos = pos;
							//printf("1630: %d: %p gone!!!\n",pos,mobIdList[foundPos]);
							break;
						}
						if(pos == lastMobIndex)
						{
							//printf("Invalid target: %p\n",*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressDissapear));
							isInvalidTarget = true;
						}
					}
					if(isInvalidTarget)
						isInvalidTarget = false;
					else
					{
						for(u_long shiftAddress=foundPos; shiftAddress < lastMobIndex; shiftAddress++)
						{
							mobIdList[shiftAddress] = mobIdList[shiftAddress+1];
							mobPosX[shiftAddress] = mobPosX[shiftAddress+1];
							mobPosY[shiftAddress] = mobPosY[shiftAddress+1];
							mobPosXIndex[shiftAddress] = mobPosXIndex[shiftAddress+1];
							mobPosYIndex[shiftAddress] = mobPosYIndex[shiftAddress+1];
						}
						lastMobIndex--;
						//printf("%d removed 1630:\n",lastMobIndex);
						printf("%d terata einai gyro\n",lastMobIndex+1);
					}
				}
			break;
			case actionObjAppearedDisappeared: //packet 0x1730 //the objects appear/disappear due to player's movement
				if ((*(BYTE*)(RecvBuffer+ActionAddress[curr]+0x06) == 0x01))//if the object appears
				{
					appearNumber = *(BYTE*)(RecvBuffer+ActionAddress[curr]+0x07); //get how many should appear
					shouldAddToList = true; //the next packet will have data that should be added in the list
				}
				else if((*(BYTE*)(RecvBuffer+ActionAddress[curr]+0x06) == 0x02))//if the object disappears
				{
					disappearNumber = *(BYTE*)(RecvBuffer+ActionAddress[curr]+0x07); //get how many should disappear
					shouldRemoveFromList = true; //the next packet will have data that should be removed from the list
				}
			break;
			case actionObjAppearDisappearInfo: //packet 0x1930 //what are the objects that should appear/disappear?
				//targetType = *(WORD*)(RecvBuffer+ActionAddress[curr]);
				if (shouldAddToList == true)//when appear info is ready and what appeared is a mob
				{
					availPos = lastMobIndex+1;
					while(appearNumber != 0)
 					{
						if(isPlayer()) //if is a player
						{
							nextByte = 0;
							printf("Player id: %p\n",*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear));
							while(*(WORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear+0x60+nextByte) != 0xFF00)
							{
								 nextByte++;
							}
							objectIdAddressAppear += (0x60+nextByte+0x02);
							//printf("pass! next id: %p\n",*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear));
							//appearNumber--;
							//printf("player: next id: %p\n",*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear));
						}
						else if(isNpc())
						{
							printf("Npc id: %p\n",*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear));
							objectIdAddressAppear += *(BYTE*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear+0x2D)*2+0x2E;
							//appearNumber--;
							//printf("Npc: next id: %p\n",*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear));
						}
						else if(isPet())
						{
							printf("Pet id: %p\n",*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear));
							if(*(WORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear+0x33) == 0) //if this word is 0, it means that the pet has no title.
							{
								objectIdAddressAppear += *(WORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear+0x35)+0x35+0x08;
							}
							else
							{
								WORD titleSize = *(WORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear+0x33);
								objectIdAddressAppear += *(WORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear+0x33+titleSize)+titleSize+0x33+0x0A;
							}
							//appearNumber--;
							//printf("Npc: next id: %p\n",*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear));
						}
						else if(isMob())
						{
							mobIdList[availPos] = *(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear+0x04);//get the id and save in the list
							mobPosXIndex[availPos] = *(BYTE*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear+0x08);
							mobPosYIndex[availPos] = *(BYTE*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear+0x09);
							mobPosX[availPos] = *(WORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear+0x0A);
							mobPosY[availPos] = *(WORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear+0x0E);
							objectIdAddressAppear+=0x0034; //if there's another object, its id will be on +0x34
							availPos++; //search for the next mob id
							//appearNumber--; //mob found, -1.
							//printf("%d add: terata einai gyro\n",lastMobIndex);
						}
						else if(isEquipItem())
						{
							objectIdAddressAppear += 0x1B;
						}
						else
						{
							if(*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) == 0x01)
								objectIdAddressAppear += 0x1E;
							else
								objectIdAddressAppear += 0x1A;
							//appearNumber--;
						}
						appearNumber--;
					}
					lastMobIndex = availPos-1; //hold the last index of the list.
					printf("%d added:\n",lastMobIndex+1);
					objectIdAddressAppear = 0x0006; //restore original id position
				}
				else if (shouldRemoveFromList == true && lastMobIndex != -1)//when disappear info is ready and the list is not empty
				{
					while(disappearNumber != 0)
					{
						//printf("     REMOVE REMAINING: %d!!!\n",disappearNumber);
						for(u_long pos = 0; pos <= lastMobIndex; pos++) //find the disappeared mob in the list
						{
							if(mobIdList[pos] == *(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressDissapear))
							{
								foundPos = pos;
								break;
							}
							if(pos == lastMobIndex)
							{
								//printf("Invalid target: %p\n",*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressDissapear));
								isInvalidTarget = true;
							}
						}
						if(isInvalidTarget) //if the mob is not found in the list go to the next one.
						{
							disappearNumber--;
							objectIdAddressDissapear += 0x0004;
							isInvalidTarget = false;
						}
						else //if the mob is found in the list, remove it.
						{
							for(u_long shiftAddress=foundPos; shiftAddress < lastMobIndex; shiftAddress++)
							{
								mobIdList[shiftAddress] = mobIdList[shiftAddress+1];
								mobPosX[shiftAddress] = mobPosX[shiftAddress+1];
								mobPosY[shiftAddress] = mobPosY[shiftAddress+1];
								mobPosXIndex[shiftAddress] = mobPosXIndex[shiftAddress+1];
								mobPosYIndex[shiftAddress] = mobPosYIndex[shiftAddress+1];
							}
							objectIdAddressDissapear += 0x0004;
							disappearNumber--;
							lastMobIndex--;
							//printf("%d removed:\n",lastMobIndex);
							printf("%d terata einai gyro\n",lastMobIndex+1);
						}
					}
					objectIdAddressDissapear = 0x0006;
					//break;
				}
				shouldRemoveFromList = false;
				shouldAddToList = false;
			break;
				/*if (CurrentAction[curr] == 0x74B0 && RecvBuffer[ActionAddress[curr]+0x08] == 0x02)
				{
					attacking = false;
				}*/
			//endcase
		}
	}
	__asm jmp RecvReturnAddress
}