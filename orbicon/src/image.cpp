#include "image.h"
#include "image_utilities.h"
#include "global_settings.h"

using namespace orbicon;

Image::Image() {}

Image::Image(const string image_path)
{
	this->image_path = image_path;

	reset();
}

Image::Image(const string image_path, Mat descriptors)
{
	this->image_path  = image_path;
	this->descriptors = descriptors;

	generate_grayscale_image();
}

Image::Image(const string image_path, Mat descriptors, vector<KeyPoint> keypoints)
{
	this->image_path  = image_path;
	this->descriptors = descriptors;
	this->keypoints   = keypoints;

	generate_grayscale_image();
}

void Image::reset()
{
	generate_grayscale_image();
	generate_descriptors_and_keypoints();
}

const string Image::get_image_path() const
{
	return image_path;
}

Mat& Image::get_image()
{
	if (image.empty())
	{
		generate_image();
	}

	return image;
}

Mat& Image::get_grayscale_image()
{
	if (grayscale_image.empty())
	{
		generate_grayscale_image();
	}

	return grayscale_image;
}

Mat& Image::get_descriptors()
{
	if (descriptors.empty())
	{
		generate_descriptors_and_keypoints();
	}

	return descriptors;
}

vector<KeyPoint>& Image::get_keypoints()
{
	if (keypoints.empty())
	{
		generate_descriptors_and_keypoints();
	}

	return keypoints;
}

Mat Image::grayscale_with_keypoints()
{
	Mat with_keypoints;

	drawKeypoints(get_grayscale_image(), get_keypoints(), with_keypoints, Scalar::all(-1), DrawMatchesFlags::DEFAULT);

	return with_keypoints;
}

void Image::generate_image()
{
	Mat input_image = read_color_image(image_path);

	image = shrink_to_fit_in_box(input_image, GlobalSettings::input_image_max_dimmesion_size);
}

void Image::generate_grayscale_image()
{
	Mat temp_image = read_grayscale_image(image_path);

	if (GlobalSettings::crop_image)
	{
		temp_image = crop_image(temp_image);
	}

	if (GlobalSettings::resize_input_image)
	{
		temp_image = shrink_to_fit_in_box(temp_image, GlobalSettings::input_image_max_dimmesion_size);
	}

	grayscale_image = resize_grayscale_image(temp_image);
}

void Image::generate_descriptors_and_keypoints()
{
	ORB orb(GlobalSettings::features_number);

	vector<KeyPoint> keypoints;
	Mat descriptors;

	orb(get_grayscale_image(), Mat(), keypoints, descriptors);

	this->keypoints   = keypoints;
	this->descriptors = descriptors;
}

Mat Image::resize_grayscale_image(const Mat some_image)
{
	switch (GlobalSettings::grayscale_resize_mode)
	{
	case GlobalSettings::Original:
		return some_image;
	case GlobalSettings::Shrink:
		return shrink_image(some_image);
	case GlobalSettings::BlurByResizing:
		Mat shrinked = shrink_image(some_image);
		return expand_image(shrinked, some_image.size());
	}
}

Mat Image::crop_image(const Mat some_image)
{
	int padding_percents  = GlobalSettings::crop_padding;

	int x_offset = some_image.cols * padding_percents / 100;
	int y_offset = some_image.rows * padding_percents / 100;
	int width    = some_image.cols * (100 - 2 * padding_percents) / 100;
	int height   = some_image.rows * (100 - 2 * padding_percents) / 100;

	Rect region_of_interest = Rect(x_offset, y_offset, width, height);

	return some_image(region_of_interest);
}