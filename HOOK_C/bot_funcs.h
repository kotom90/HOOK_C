BOOL isPlayer()
{
	if
	(  (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 0x0773 //0x0773 - 0x078C <-- chinese chars
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 0x078C)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 0x397D //0x397D - 0x3996 <-- european chars
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 0x3996)
	)
		return true;
	else
		return false;
}

BOOL isNpc()
{
	if
	(  (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 2003
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 2093)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 2019
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 2020)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 2177
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 2182)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 3824
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 3861)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 5901
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 5911)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 7495
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 7549)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 7565
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 7569)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 9273
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 9274)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 19070
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 19072)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 19515
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 19519)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 23258
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 23265)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 24135
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 24144)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 24369
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 24609)
	  ||*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) == 3656
	  ||*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) == 10122
	  ||*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) == 23267
	)
		return true;
	else
		return false;
}

BOOL isPet()
{
	if
	(  (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 2183
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 2196)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 3912
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 3920)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 6106
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 6245)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 9282
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 10121)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 10149
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 10288)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 17668
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 19069)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 22486
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 23257)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 23640
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 24126)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 10149
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 10288)
	  ||*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) == 7493
	  ||*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) == 9266
	  ||*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) == 23266
	  ||*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) == 24354
	)
		return true;
	else
		return false;
}

BOOL isMob()
{
	if
	(  (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 1933
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 2118)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 2097
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 2118)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 2124
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 2127)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 3666
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 3816)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 3863
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 3875)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 3921
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 3954)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 5850
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 5879)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 5949
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 6105)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 7550
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 7564)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 10146
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 10147)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 14743
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 14790)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 23484
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 23488)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 23638
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 23639)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 24344
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 24349)
	  ||*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) == 7063
	  ||*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) == 19224
	  ||*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) == 25595
	  ||*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) == 25596
	  ||*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) == 26650
	  ||*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) == 26651
	  ||*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) == 26917
	)
		return true;
	else
		return false;
}

BOOL isThief()
{
	if
	(  (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 2222 //thiefs
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 3621)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 7585 //hunters
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 8984)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 14868 //eu thiefs
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 16267)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 16268 //eu hunters
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 17667)
	)
		return true;
	else
		return false;
}

BOOL isEquipItem()
{
	if
	(  (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 71
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 1897)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 2160
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 2176)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 3632
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 3654)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 3726
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 3735)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 3888
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 3899)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 4014
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 5840)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 8986
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 9153)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 10294
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 10317)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 10728
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 14707)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 19611
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 19640)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 23382
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 23435)
	  ||
	   (*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) >= 24818
	  &&*(DWORD*)(RecvBuffer+ActionAddress[curr]+objectIdAddressAppear) <= 24833)
	)
		return true;
	else
		return false;
}