#pragma once

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

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

	static Mat shrink_image(Mat image)
	{
		Mat ouput_image;

		resize(image, ouput_image, Size(), 0.5, 0.5, CV_INTER_AREA);

		return ouput_image;
	}

	static Mat expand_image(Mat image, Size size = Size(2, 2))
	{
		Mat ouput_image;

		resize(image, ouput_image, size, 0, 0, CV_INTER_CUBIC);

		return ouput_image;
	}
}