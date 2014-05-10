#pragma once

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

Mat read_image(const string& image_path, const int mode)
{
	Mat image = imread(image_path, mode);

	if (!image.data)
	{
		throw runtime_error("Could not open or find the image");
	}

	return image;
}

Mat read_color_image(const string& image_path)
{
	return read_image(image_path, IMREAD_COLOR);
}

Mat read_grayscale_image(const string& image_path)
{
	return read_image(image_path, IMREAD_GRAYSCALE);
}
