// Dusk.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Dusk.h"
//#include "atlstr.h" // added cause of cstring
#include "GraphicsObject.h"
#include "PlayerObject.h"
#include "BackgroundObject.h"

//enemies
#include "GreenRiderEnemy.h"
#include "FlowerEnemy.h"
#include "RedBatEnemy.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
void setScreen();
void drawScreen(HWND hWnd);

PlayerObject victor;
GraphicsObject block("../pics/platform2.png", 200, 350, 280, 49);
//GraphicsObject block("../pics/platform2.png", 200, 350, 280, 49);
GraphicsObject block2("../pics/platform2.png", 600, 250, 280, 49);
GraphicsObject tree("../pics/tree.png", 50, 130, 121, 370);
GraphicsObject tree2("../pics/tree.png", 500, 130, 121, 370);
BackgroundObject background("../pics/w1test.bmp", 0, -90, 2520, 640, 0.2); //1 png
//BackgroundObject ground("../pics/Ground2.png", 0, GROUND, 280, 196, 1);
BackgroundObject ground("../pics/ground3.jpg", 0, GROUND, 2464, 196, 1); //ground3.jpg
////////////////////////////////////////////////////////////////
//enemy//
int numEn = 0;
Enemyobject* enemies[100];

////////////////////////////////////////////////////////////////

int mapPosition = 0;
//int mapPositionY = 0;
HDC offScreenDC;

int APIENTRY _tWinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR    lpCmdLine,
	int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DUSK, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DUSK));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DUSK));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_DUSK);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hInst = hInstance; // Store instance handle in our global variable

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, 960, 640, NULL, NULL, hInstance, NULL);
	if (!hWnd)
	{
		return FALSE;
	}

	SetTimer(hWnd, 1, 50, NULL);
	setScreen();


	//enemy//
	enemies[numEn++] = new GreenRiderEnemy;
	enemies[numEn++] = new FlowerEnemy;
	enemies[numEn++] = new RedBatEnemy;



	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{

	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_RIGHT:
			if (victor.isJumping() == true)
			{
				victor.picY = 126;
				victor.xspeed = 15;
				victor.state = JUMPRIGHT;
			}
			else
			{
				victor.setMoveRight();
			}
			victor.stoppedRight = false;
			break;
		case VK_LEFT:
			if (victor.isJumping() == true)
			{
				victor.picY = 189;
				victor.xspeed = -15;
				victor.state = JUMPLEFT;
			}
			else
			{
				victor.setMoveLeft();
			}
			victor.stoppedLeft = false;
			break;
		case VK_UP:
			if (victor.state == MOVELEFT || victor.state == STANDLEFT)
			{
				victor.setJumpLeft();
			}
			else if (victor.state == MOVERIGHT || victor.state == STANDRIGHT)
			{
				victor.setJumpRight();
			}
			break;
		case VK_SPACE:
			if (victor.state == STANDLEFT)
			{
				victor.setShootLeft();
			}
			else if (victor.state == STANDRIGHT)
			{
				victor.setShootRight();
			}
			if (victor.state == SHOOTLEFT || victor.state == MOVELEFT || victor.state == JUMPLEFT || victor.state == STANDLEFT)
			{
				victor.fireBullet(victor.x, victor.y + 28, -20 + victor.xspeed, 0);
			}
			else
			{
				victor.fireBullet(victor.x + victor.width - 15, victor.y + 28, 20 + victor.xspeed, 0);
			}
			break;
		}
		break;
	case WM_KEYUP:
		switch (wParam)
		{
		case VK_RIGHT:
			if (victor.isJumping() == false)
			{
				victor.setStandRight();
			}
			victor.stoppedRight = true;
			break;
		case VK_LEFT:
			if (victor.isJumping() == false)
			{
				victor.setStandLeft();
			}
			victor.stoppedLeft = true;
			break;
		case VK_SPACE:
			if (victor.state == SHOOTLEFT)
			{
				victor.setStandLeft();
			}
			else if (victor.state == SHOOTRIGHT)
			{
				victor.setStandRight();
			}
			break;
		}
		break;
	case WM_TIMER:
		victor.move();
		victor.checkPlayerBlock(&block);
		/*victor.checkPlayerBlock(&block2);*/
		victor.moveBullets();
		victor.checkBulletBlock(&block);
		victor.checkBulletBlock(&block2);

		for (int i = 0; i < numEn; i++){
			if (enemies[i]->enemyhealth > 0) {
				enemies[i]->move();
				victor.checkBulletEntity(enemies[i]);
			}
			enemies[i]->moveBullets();
			enemies[i]->checkBulletEntity(&victor);
		}

		PostMessage(hWnd, WM_PAINT, 0, 0);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		background.draw(offScreenDC);
		ground.draw(offScreenDC);
		//tree.draw(offScreenDC);
		//tree2.draw(offScreenDC);
		victor.draw(offScreenDC);

		block.draw(offScreenDC);
		//block2.draw(offScreenDC);

		for (int i = 0; i < numEn; i++){
			if (enemies[i]->enemyhealth > 0) {
				enemies[i]->draw(offScreenDC);
				enemies[i]->drawBullets(offScreenDC);
			}

		}
		victor.drawBullets(offScreenDC);

		drawScreen(hWnd);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

void setScreen()
{
	HDC hTempDC;
	HBITMAP offScreenBMP;
	hTempDC = GetDC(0);
	// Initialize buffer image
	offScreenDC = CreateCompatibleDC(hTempDC);
	offScreenBMP = CreateCompatibleBitmap(hTempDC, 960, 640);
	SelectObject(offScreenDC, offScreenBMP);
	ReleaseDC(0, hTempDC);
}

void drawScreen(HWND hWnd)
{
	HDC ScreenDC;
	ScreenDC = GetDC(hWnd);
	TransparentBlt(ScreenDC, 0, 0, 960, 640, offScreenDC, 0, 0, 960, 640, RGB(255, 174, 201));
	DeleteDC(ScreenDC);
}
