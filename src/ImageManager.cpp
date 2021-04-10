#pragma once
#include "src/ImageManager.h"

namespace overflow0x17
{
	CImg<> ImageManager::rgb_to_grayscale(CImg<> rgb_img)
	{
		CImg<> grayscale_img(rgb_img.width(), rgb_img.height(), 1, 1, 0);
		cimg_forXY(rgb_img, x, y)
		{
			int R = static_cast<int>(rgb_img(x, y, 0, 0));
			int G = static_cast<int>(rgb_img(x, y, 0, 1));
			int B = static_cast<int>(rgb_img(x, y, 0, 2));
			int grayscale = static_cast<int>((0.299 * R + 0.587 * G + 0.114 * B));
			grayscale_img(x, y, 0, 0) = grayscale;
		}
		grayscale_img.normalize(0, 255);
		return grayscale_img;
	}

	void ImageManager::print_image_to_ascii(std::string out_file, int new_width, int new_height)
	{
		main_image = rgb_to_grayscale(main_image);
		std::ofstream out(out_file);
		main_image.resize(new_width, new_height);

		cimg_forY(main_image, y) {
			cimg_forX(main_image, x) {
				int val = main_image(x, y, 0, 0) / sizeof(gradient);
				out << gradient.at(val);
			}
			out << std::endl;
		}
		out.close();
	}
}