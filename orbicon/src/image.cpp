#include "image.h"
#include "image_utilities.h"
#include "global_settings.h"

using namespace orbicon;

Image::Image() {}

Image::Image(const string image_path)
{
	this->image_path = image_path;

	generate_grayscale_image();
	generate_descriptors_and_keypoints();
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
	image = read_color_image(image_path);
}

void Image::generate_grayscale_image()
{
	grayscale_image = read_grayscale_image(image_path);
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