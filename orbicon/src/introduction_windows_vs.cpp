#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/gpu/gpu.hpp>
#include "image_utilities.cpp"

using namespace cv;
using namespace gpu;
using namespace std;

int main(int argc, char** argv)
{
	string image_path         = "..\\orbicon\\resource\\opencv-logo.png";
	string rotated_image_path = "..\\orbicon\\resource\\opencv-logo-rotated.png";

	Mat image		  = read_grayscale_image(image_path);
	Mat rotated_image = read_grayscale_image(rotated_image_path);
	Mat image_desc, rotated_image_desc;

	ORB orb;
	vector <KeyPoint> image_keypoints, rotated_image_keypoints;

	orb(image, cv::Mat(), image_keypoints, image_desc);
	orb(rotated_image, cv::Mat(), rotated_image_keypoints, rotated_image_desc);

	Mat with_keypoints;
	drawKeypoints(image, image_keypoints, with_keypoints, Scalar::all(-1), DrawMatchesFlags::DEFAULT);

	BFMatcher matcher = BFMatcher(NORM_HAMMING);
	vector<DMatch, allocator<DMatch>> matches;
	matcher.match(image_desc, rotated_image_desc, matches);

	Mat img_matches;
	drawMatches(image, image_keypoints, rotated_image, rotated_image_keypoints, matches, img_matches);

	namedWindow("Display window", WINDOW_AUTOSIZE);
	imshow("Display window", img_matches);

	waitKey(0); // Wait for a keystroke in the window
	return 0;
}