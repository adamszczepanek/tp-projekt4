// draw.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Resource.h"
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include<windows.h>
#include<windowsx.h>
#include<list>
#include <string>
#include<cmath>
using namespace std;

#define MAX_LOADSTRING 100
#define TMR_1 1

struct winda                      //struktura windy
{
	list <int> pas;
	list < int > kol;
	int masa;
	int polozenie=0;

}winda;                                //osoby na pietrach
list < int > pietro_1;
list < int > pietro_2;
list < int > pietro_3;
list < int > pietro_4;
list < int > pietro_5;

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];	           // the main window class name

RECT drawArea = { 510,539,650,1 };

ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

void MyOnPaint(HDC hdc, HWND hWnd)
{                                                      // funkcja rysujaca winde 
	
	Graphics graphics(hdc);
	Pen pen(Color(150, 42, 12, 130));
	Pen pen1(Color(80, 0, 0, 0));
	graphics.DrawRectangle(&pen, 500, 1, 150, 530);
	graphics.DrawRectangle(&pen, 510, 425 + winda.polozenie, 130, 80);
	graphics.DrawLine(&pen, 210, 500, 499, 500);
	graphics.DrawLine(&pen, 650, 400, 920, 400);
	graphics.DrawLine(&pen, 210, 300, 499, 300);
	graphics.DrawLine(&pen, 650, 200, 920, 200);
	graphics.DrawLine(&pen, 210, 100, 499, 100);


	if (winda.pas.size() == 1) {
		graphics.DrawRectangle(&pen1, 540, 455 + winda.polozenie, 10, 50);

	}
	if (winda.pas.size() == 2) {
		graphics.DrawRectangle(&pen1, 540, 455 + winda.polozenie, 10, 50);
		graphics.DrawRectangle(&pen1, 560, 455 + winda.polozenie, 10, 50);
	}
	if (winda.pas.size() == 3) {
		graphics.DrawRectangle(&pen1, 580, 455 + winda.polozenie, 10, 50);
		graphics.DrawRectangle(&pen1, 560, 455 + winda.polozenie, 10, 50);
		graphics.DrawRectangle(&pen1, 540, 455 + winda.polozenie, 10, 50);
	}
	if (winda.pas.size() == 4){
		graphics.DrawRectangle(&pen1, 580, 455 + winda.polozenie, 10, 50);
		graphics.DrawRectangle(&pen1, 560, 455 + winda.polozenie, 10, 50);
		graphics.DrawRectangle(&pen1, 540, 455 + winda.polozenie, 10, 50);
		graphics.DrawRectangle(&pen1, 600, 455 + winda.polozenie, 10, 50);
	}
	if (winda.pas.size() == 5) {
		graphics.DrawRectangle(&pen1, 600, 455 + winda.polozenie, 10, 50);
		graphics.DrawRectangle(&pen1, 580, 455 + winda.polozenie, 10, 50);
		graphics.DrawRectangle(&pen1, 540, 455 + winda.polozenie, 10, 50);
		graphics.DrawRectangle(&pen1, 560, 455 + winda.polozenie, 10, 50);
		graphics.DrawRectangle(&pen1, 580, 455 + winda.polozenie, 10, 50);
	}
}


int OnCreate(HWND window)
{

	SetTimer(window, TMR_1, 1, 0);
	return 0;

}

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


	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DRAW, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DRAW));

	// Main message loop:

	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	GdiplusShutdown(gdiplusToken);

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
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DRAW));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_DRAW);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}


HWND hWnd;
HINSTANCE hInstance;

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	
	hInst = hInstance; // Store instance handle in our global variable

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);                //przyciski

	HWND hwndButton1 = CreateWindow(L"BUTTON", L"4", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 210, 0, 25, 25, hWnd, (HMENU)IDBUTTON1, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
	HWND hwndButton2 = CreateWindow(L"BUTTON", L"3", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 210, 25, 25, 25, hWnd, (HMENU)IDBUTTON2, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
	HWND hwndButton3 = CreateWindow(L"BUTTON", L"2", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 210, 50, 25, 25, hWnd, (HMENU)IDBUTTON3, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
	HWND hwndButton4 = CreateWindow(L"BUTTON", L"1", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 210, 75, 25, 25, hWnd, (HMENU)IDBUTTON4, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);

	HWND hwndButton5 = CreateWindow(L"BUTTON", L"5", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 210, 200, 25, 25, hWnd, (HMENU)IDBUTTON5, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
	HWND hwndButton6 = CreateWindow(L"BUTTON", L"4", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 210, 225, 25, 25, hWnd, (HMENU)IDBUTTON6, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
	HWND hwndButton7 = CreateWindow(L"BUTTON", L"2", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 210, 250, 25, 25, hWnd, (HMENU)IDBUTTON7, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
	HWND hwndButton8 = CreateWindow(L"BUTTON", L"1", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 210, 275, 25, 25, hWnd, (HMENU)IDBUTTON8, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);

	HWND hwndButton9 = CreateWindow(L"BUTTON", L"5", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 210, 400, 25, 25, hWnd, (HMENU)IDBUTTON9, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
	HWND hwndButton10 = CreateWindow(L"BUTTON", L"4", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 210, 425, 25, 25, hWnd, (HMENU)IDBUTTON10, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
	HWND hwndButton11 = CreateWindow(L"BUTTON", L"3", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 210, 450, 25, 25, hWnd, (HMENU)IDBUTTON11, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
	HWND hwndButton12 = CreateWindow(L"BUTTON", L"2", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 210, 475, 25, 25, hWnd, (HMENU)IDBUTTON12, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);

	HWND hwndButton13 = CreateWindow(L"BUTTON", L"5", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 900, 100, 25, 25, hWnd, (HMENU)IDBUTTON13, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
	HWND hwndButton14 = CreateWindow(L"BUTTON", L"3", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 900, 125, 25, 25, hWnd, (HMENU)IDBUTTON14, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
	HWND hwndButton15 = CreateWindow(L"BUTTON", L"2", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 900, 150, 25, 25, hWnd, (HMENU)IDBUTTON15, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
	HWND hwndButton16 = CreateWindow(L"BUTTON", L"1", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 900, 175, 25, 25, hWnd, (HMENU)IDBUTTON16, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);

	HWND hwndButton17 = CreateWindow(L"BUTTON", L"5", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 900, 300, 25, 25, hWnd, (HMENU)IDBUTTON17, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
	HWND hwndButton18 = CreateWindow(L"BUTTON", L"4", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 900, 325, 25, 25, hWnd, (HMENU)IDBUTTON18, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
	HWND hwndButton19 = CreateWindow(L"BUTTON", L"3", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 900, 350, 25, 25, hWnd, (HMENU)IDBUTTON19, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
	HWND hwndButton20 = CreateWindow(L"BUTTON", L"1", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 900, 375, 25, 25, hWnd, (HMENU)IDBUTTON20, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);


	OnCreate(hWnd);

	if (!hWnd)
	{
		return FALSE;
	}
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

void dodaj(int skad, int dokad)
{                                              //dodanie do kolejki
			winda.kol.push_back(skad);
			winda.kol.push_back(dokad);
}

void masa()              //pokazanie masy pasazerow
{
	HWND hStatic = CreateWindowEx(0, L"STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_CENTER, 750, 60, 60, 50, hWnd, NULL, hInstance, NULL);
	char tab[100];
	wchar_t wtext[20];
	sprintf(tab, " %d ", winda.pas.size() * 70);
	mbstowcs(wtext, tab, strlen(tab) + 1);//Plus null
	LPWSTR ptr = wtext;
	SetWindowText(hStatic, ptr);
}

void pasazerowie(int pol, int kol) {
	if (winda.polozenie == pol && winda.kol.front() == kol)
	{
		for (int i = 0; i < winda.pas.size(); i++)
		{
			if (winda.pas.front() == kol)
				winda.pas.pop_front();

		}
		switch (kol)
		{

		case 1:

			for (int i = 0; i < pietro_1.size(); i++)
			{
				winda.pas.push_back(pietro_1.front());
				pietro_1.pop_front();
			}

			masa();
			break;

		case 2:

			for (int i = 0; i < pietro_2.size(); i++)
			{
				winda.pas.push_back(pietro_2.front());
				pietro_2.pop_front();
			}

			masa();
			break;

		case 3:

			for (int i = 0; i < pietro_3.size(); i++)
			{
				winda.pas.push_back(pietro_3.front());
				pietro_3.pop_front();
			}

			masa();
			break;

		case 4:
	
			for (int i = 0; i < pietro_4.size(); i++)
			{
				winda.pas.push_back(pietro_4.front());
				pietro_4.pop_front();
			}

			masa();
			break;
		case 5:

			for (int i = 0; i < pietro_5.size(); i++)
			{
				winda.pas.push_back(pietro_5.front());
				pietro_5.pop_front();
			}
			masa();
			break;
		}
	}
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	HDC hdc;
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	OnCreate(hWnd);
	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);

		// Parse the menu selections:

		switch (wmId)         
		{
		case IDBUTTON1:
			dodaj(5, 4);
			pietro_5.push_back(4);
			break;	
		case IDBUTTON2:
			dodaj(5, 3);
			pietro_5.push_back(3);
			break;
		case IDBUTTON3:
			dodaj(5, 2);
			pietro_5.push_back(2);
			break;
		case IDBUTTON4:
			dodaj(5, 1);
			pietro_5.push_back(1);
			break;
		case IDBUTTON5:
			dodaj(3, 5);
			pietro_3.push_back(5);
			break;
		case IDBUTTON6:
			dodaj(3, 4);
			pietro_3.push_back(4);
			break;
		case IDBUTTON7:
			dodaj(3, 2);
			pietro_3.push_back(2);
			break;
		case IDBUTTON8:
			dodaj(3, 1);
			pietro_3.push_back(1);
			break;
		case IDBUTTON9:
			dodaj(1, 5);
			pietro_1.push_back(5);
			break;
		case IDBUTTON10:
			dodaj(1, 4);
			pietro_1.push_back(4);
			break;
		case IDBUTTON11:
			dodaj(1, 3);
			pietro_1.push_back(3);
			break;
		case IDBUTTON12:
			dodaj(1, 2);
			pietro_1.push_back(2);
			break;
		case IDBUTTON13:
			dodaj(4, 5);
			pietro_4.push_back(5);
			break;
		case IDBUTTON14:
			dodaj(4, 3);
			pietro_4.push_back(3);
			break;
		case IDBUTTON15:
			dodaj(4, 2);
			pietro_4.push_back(2);
			break;
		case IDBUTTON16:
			dodaj(4, 1);
			pietro_4.push_back(1);
			break;
		case IDBUTTON17:
			dodaj(2, 5);
			pietro_2.push_back(5);
			break;
		case IDBUTTON18:
			dodaj(2, 4);
			pietro_2.push_back(4);
			break;
		case IDBUTTON19:
			dodaj(2, 3);
			pietro_2.push_back(3);
			break;
		case IDBUTTON20:
			dodaj(2, 1);
			pietro_2.push_back(1);
			break;

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
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		MyOnPaint(hdc, hWnd);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_TIMER:
		switch (wParam)
		{
		case TMR_1:
			//force window to repaint

			if (!winda.kol.empty())       //winda gora dol
			{
				int  z= -winda.kol.front()*100+100;
				if (winda.polozenie != z)
				{
					if (z<winda.polozenie )
						winda.polozenie--;
					else
						winda.polozenie++;
					InvalidateRect(hWnd, &drawArea, TRUE);
					hdc = BeginPaint(hWnd, &ps);
					MyOnPaint(hdc, hWnd);
					EndPaint(hWnd, &ps);
				}
				else
				{
					pasazerowie(-400, 5);
					pasazerowie(-300, 4);
					pasazerowie(-200, 3);
					pasazerowie(-100, 2);
					pasazerowie(0, 1);
					winda.kol.pop_front();                       //usuwa z kolejki pietro na ktore winda wjechala
					Sleep(500);

				}

				break;
			}
		}
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;

}

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