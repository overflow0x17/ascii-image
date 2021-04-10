#include "3rd_party"
#include <fstream>
#include <string>
namespace overflow0x17
{ 
	using namespace cimg_library;
	class ImageManager
	{
	public:
		explicit ImageManager(const std::string input_file) : image_file(std::move(input_file)) {}
		void  print_image_to_ascii(const std::string out_file, int new_width, int new_height);
		
	private:
		CImg<> rgb_to_grayscale(CImg<> rgb_img);
		std::string image_file{};
		CImg<> main_image{ ("resource//" + image_file).c_str() };
		const std::string gradient{"@%#*+=-:. "};
	};

}