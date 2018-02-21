/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software,
* Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/
#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent& other) : 
		IntensityImage(other.getWidth(), other.getHeight()), intensity(new Intensity[other.getWidth() * other.getHeight()]) {
	for (int i = 0; i < getWidth() * getHeight(); i++) {
		intensity[i] = other.intensity[i];
	}
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) :IntensityImage(width, height), intensity(new Intensity[width * height]) {}

IntensityImageStudent::~IntensityImageStudent() {
	delete[] intensity;
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	delete[] intensity;
	this->intensity = new Intensity[width * height];
}

void IntensityImageStudent::set(const IntensityImageStudent& other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	delete[] intensity;
	this->intensity = new Intensity[getWidth() * getHeight()];

	for (int i = 0; i < getWidth() * getHeight(); i++) {
		intensity[i] = other.intensity[i];
	}
}

void IntensityImageStudent::setPixel(int x,	int y, Intensity pixel) {
	intensity[y * getWidth() + x] = pixel;
}

void IntensityImageStudent::setPixel(int i,	Intensity pixel) {
	intensity[i] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return intensity[y * getWidth() + x];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	return intensity[i];
}