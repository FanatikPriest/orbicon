#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/gpu/gpu.hpp>
#include "image.h"

using namespace cv;
using namespace gpu;
using namespace orbicon;
using namespace std;

int main(int argc, char** argv)
{
	string image_path         = "..\\orbicon\\resource\\opencv-logo.png";
	string rotated_image_path = "..\\orbicon\\resource\\opencv-logo-rotated.png";

	Image image(image_path), rotated_image(rotated_image_path);

	BFMatcher matcher = BFMatcher(NORM_HAMMING);
	vector<DMatch, allocator<DMatch>> matches;

	matcher.match(image.get_descriptors(),rotated_image.get_descriptors(), matches);

	Mat img_matches;
	drawMatches(image.get_grayscale_image(), image.get_keypoints(), 
				rotated_image.get_grayscale_image(), rotated_image.get_keypoints(),
				matches, img_matches);

	namedWindow("Display window", WINDOW_AUTOSIZE);
	imshow("Display window", img_matches);

	waitKey(0); // Wait for a keystroke in the window
	return 0;
}