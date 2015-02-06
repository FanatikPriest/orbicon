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

	static Mat shrink_image(Mat image, double fx = 0.5, double fy = 0.5)
	{
		Mat ouput_image;

		resize(image, ouput_image, Size(), fx, fy, CV_INTER_AREA);

		return ouput_image;
	}

	static Mat expand_image(Mat image, Size size = Size(2, 2))
	{
		Mat ouput_image;

		resize(image, ouput_image, size, 0, 0, CV_INTER_CUBIC);

		return ouput_image;
	}

	static Mat shrink_to_fit_in_box(Mat image, const int box_size)
	{
		Size size = image.size();

		int max = (size.width >= size.height) ? size.width : size.height;

		if (max <= box_size)
		{
			return image;
		}

		double coef = box_size / (double)max;

		return shrink_image(image, coef, coef);
	}
}