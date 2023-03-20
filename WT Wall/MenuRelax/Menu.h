void  cVisualEngine::Class_Engine(LPDIRECT3DDEVICE9 pDevice)
{

	lm = GetAsyncKeyState(VK_LBUTTON) & 1;
	rm = GetAsyncKeyState(VK_RBUTTON) & 1;
	flm = GetAsyncKeyState(VK_LBUTTON);
	frm = GetAsyncKeyState(VK_RBUTTON);

	   DrawMenu("King Reborn", pDevice);

	   Add_Folder(2,"Aimbot Folder", Fun.AimbotFolder,  pDevice);
	   Add_Folder(3,"Esp Folder", Fun.EspFolder,  pDevice);
	   Add_Folder(4,"Weapon Folder", Fun.WeaponFolder,  pDevice);

	if(Fun.AimbotFolder ==1)
	{
		 Add_Folder_Menu(3,1,110,"         AIMBOT FOLDER", pDevice);

		 Check_Box(2,2,"Cross Aimbot", Fun.ChamsMenu, pDevice);
		 Check_Box(2,3,"Aim Head", Fun.w0, pDevice);
		 Check_Box(2,4,"Aim Body", Fun.w1, pDevice);
		 Check_Box(2,5,"Key Shift ", Fun.w2, pDevice);
		 Check_Box(2,6,"Key Ctrl ", Fun.w2, pDevice);


	}

		if(Fun.EspFolder==1)
	{
		
		 Add_Folder_Menu(4,1,110,"         ESP FOLDER", pDevice);

		 Check_Box(3,2,"ESP Name", Fun.e1, pDevice);
		 Check_Box(3,3,"ESP Box", Fun.e2, pDevice);
		 Check_Box(3,4,"ESP Skeleton", Fun.e3, pDevice);
		 Check_Box(3,5,"ESP Line", Fun.e4, pDevice);
		 Check_Box(3,6,"ESP Health", Fun.e4, pDevice);

	}

			if(Fun.WeaponFolder==1)
	{
		
		 Add_Folder_Menu(4,1,110,"         WEAPON FOLDER", pDevice);

		 Check_Box(4,2,"Rapid-Fire", Fun.e1, pDevice);
		 Check_Box(4,3,"No-Reload", Fun.e2, pDevice);
		 Check_Box(4,4,"Fast-Knife", Fun.e3, pDevice);
		 Check_Box(4,5,"Fast-Shot", Fun.e4, pDevice);
		 Check_Box(4,6,"Shadown-Cat", Fun.e4, pDevice);

	}

}



