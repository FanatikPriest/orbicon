#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/gpu/gpu.hpp>

#include "image.h"
#include "image_matcher.h"
#include "global_settings.h"

using namespace cv;
using namespace gpu;
using namespace orbicon;
using namespace std;

// The main window class name.
static TCHAR szWindowClass[] = _T("Orbicon");

// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("Orbicon: ORB powered image laboratory");
HINSTANCE hInst;


// Forward declarations of functions included in this code module:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void logic(string subject_path, string scene_path)
{
	Image subject(subject_path), scene(scene_path);

	GlobalSettings::use_knn_match = true;

	ImageMatcher matcher(subject, scene);

	namedWindow("KNN matching", WINDOW_AUTOSIZE);
	imshow("KNN matching", matcher.get_matches_drawing());

	GlobalSettings::use_knn_match = false;

	matcher.match();

	namedWindow("Simple matching", WINDOW_AUTOSIZE);
	imshow("Simple matching", matcher.get_matches_drawing());

	waitKey(0); // Wait for a keystroke in the window
}

string open_file()
{
	OPENFILENAME ofn;
	char szFileName[MAX_PATH] = "";

	ZeroMemory(&ofn, sizeof(ofn));

	ofn.lStructSize = sizeof (ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFile = szFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFilter = "Image (*.bmp, *.jpg, *.jpeg, *.png)\0*.BMP;*.JPG;*.JPEG;*.PNG\0";
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;

	if (!GetOpenFileName(&ofn))
	{
		return "";
	}

	return szFileName;
}

WNDCLASSEX create_win_class()
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInst;
	wcex.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	return wcex;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	string subject_file_name = open_file();
	string scene_file_name = open_file();

	if (subject_file_name.empty() || scene_file_name.empty())
	{
		MessageBox(NULL,
			_T("You must select scene and subject images!"),
			_T(szWindowClass),
			NULL);

		return 0;
	}

	logic(subject_file_name, scene_file_name);


	hInst = hInstance; // Store instance handle in our global variable

	WNDCLASSEX wcex = create_win_class();

	if (!RegisterClassEx(&wcex))
	{
		// TODO review message strings
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T(szWindowClass),
			NULL);

		return 1;
	}

	// The parameters to CreateWindow explained:
	// szWindowClass: the name of the application
	// szTitle: the text that appears in the title bar
	// WS_OVERLAPPEDWINDOW: the type of window to create
	// CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
	// 500, 100: initial size (width, length)
	// NULL: the parent of this window
	// NULL: this application does not have a menu bar
	// hInstance: the first parameter from WinMain
	// NULL: not used in this application
	HWND hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		500, 100,
		NULL,
		NULL,
		hInstance,
		NULL
		);

	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Win32 Guided Tour"),
			NULL);

		return 1;
	}

	// The parameters to ShowWindow explained:
	// hWnd: the value returned from CreateWindow
	// nCmdShow: the fourth parameter from WinMain
	ShowWindow(hWnd, nCmdShow);

	UpdateWindow(hWnd);

	// Main message loop:
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

/*
Using Window Procedures: http://msdn.microsoft.com/en-us/library/ms633570.aspx
*/
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("Hello, World!");

	switch (uMsg)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		// Here your application is laid out.
		// For this introduction, we just print out "Hello, World!"
		// in the top left corner.
		TextOut(hdc,
			5, 5,
			greeting, _tcslen(greeting));
		// End application-specific layout section.

		EndPaint(hWnd, &ps);

		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
		break;
	}

	return 0;
}