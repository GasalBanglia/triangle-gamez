/*
 * @file
 * 	trianglegamez.c
 * @description
 * 	Triangle game where two players will be able to shoot at each other 
 * 	and possibly lose lives or gain points? It will be my first game. 
 * 	Very excite.
 * @date
 * 	7-10-16
 * @version
 * 	1.0 -> babbby started from triangle-keypress.c though so a lot of 
 * 		work has already been done 
 * 		and just needs to be modified/added to.
 *	2.0 -> Implementing a library of operations to declutter the code.  
 *		Works with a memory DC.
 *		maybe we'll get this thing off the ground now.
 *		I DID IT!!!
 */
#include "..\lib\triangleOperations.h"

const char className[] = "mainClass";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hprev, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wc = {
		sizeof(WNDCLASSEX),
		0,
		WndProc,
		0, 0,
		hInstance,
		LoadIcon(NULL, IDI_APPLICATION),
		LoadCursor(NULL, IDC_ARROW),
		(HBRUSH) (COLOR_WINDOW+1),
		NULL,
		className,
		LoadIcon(NULL, IDI_APPLICATION) };

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, TEXT("Window registration failed."), TEXT("Error"), MB_OK | MB_ICONEXCLAMATION);
		return 0;
	}

	HWND hWnd = CreateWindowEx(
			WS_EX_CLIENTEDGE,
			className,
			TEXT("Triangle Gamez 4 Lyfe"),
			WS_OVERLAPPEDWINDOW,
			50, 10, 960, 797,
			NULL, NULL, hInstance, NULL);

	if (hWnd == NULL)
	{
		MessageBox(NULL, TEXT("Window creation failed"), TEXT("Error"), MB_OK | MB_ICONEXCLAMATION);
		return 0;
	}


	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);


	MSG message;

	while (GetMessage(&message, NULL, 0, 0) > 0)
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	return 0;
}
