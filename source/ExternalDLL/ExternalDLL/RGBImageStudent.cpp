/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software,
* Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {}

RGBImageStudent::RGBImageStudent(const RGBImageStudent& other) : RGBImage(other.getWidth(), other.getHeight()), rgb(new RGB[other.getWidth() * other.getHeight()]) {
	for (int i = 0; i < getWidth() * getHeight(); i++) {
		rgb[i] = other.rgb[i];
	}
}

RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height), rgb(new RGB[width * height]) {}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	delete[] rgb;
	this->rgb = new RGB[width * height];
}

void RGBImageStudent::set(const RGBImageStudent& other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	delete[] rgb;

	this->rgb = new RGB[getWidth() * getHeight()];

	for (int i = 0; i < getWidth() * getHeight(); i++) {
		rgb[i] = other.rgb[i];
	}
}

RGBImageStudent::~RGBImageStudent() {
	delete[] rgb;
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	rgb[y * getWidth() + x] = pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	rgb[i] = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	return rgb[y * getWidth() + x];
}

RGB RGBImageStudent::getPixel(int i) const {
	return rgb[i];
}