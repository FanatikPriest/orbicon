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

using namespace cv;
using namespace gpu;
using namespace orbicon;
using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	string image_path         = "..\\orbicon\\resource\\opencv-logo.png";
	string rotated_image_path = "..\\orbicon\\resource\\opencv-logo-rotated.png";

	Image image(image_path), rotated_image(rotated_image_path);

	ImageMatcher matcher(image, rotated_image);

	namedWindow("Display window", WINDOW_AUTOSIZE);
	imshow("Display window", matcher.get_matches_drawing());

	waitKey(0); // Wait for a keystroke in the window
	return 0;
}