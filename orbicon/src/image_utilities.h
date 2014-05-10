#pragma once

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

namespace orbicon {
	static Mat read_image(const string& image_path, const int mode)
	{
		Mat image = imread(image_path, mode);

		if (!image.data)
		{
			throw runtime_error("Could not open or find the image");
		}

		return image;
	}

	static Mat read_color_image(const string& image_path)
	{
		return read_image(image_path, IMREAD_COLOR);
	}

	static Mat read_grayscale_image(const string& image_path)
	{
		return read_image(image_path, IMREAD_GRAYSCALE);
	}
}