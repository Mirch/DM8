#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <FreeImage.h>


namespace DM8 {
	namespace utils {
     	static std::string ReadFile(const std::string& filepath)
		{
			FILE* file = fopen(filepath.c_str(), "rt");
			if (file == nullptr)
				std::cout << "The file could not be loaded." << std::endl;
			fseek(file, 0, SEEK_END);
			long length = ftell(file);
			char* data = new char[length + 1];
			memset(data, 0, length + 1);
			fseek(file, 0, SEEK_SET);
			fread(data, 1, length, file);
			fclose(file);
			std::string result(data);
		
			delete[] data;
			return result;
		}

		static BYTE* LoadImage(const char* filename, unsigned int* width, unsigned int* height, unsigned int* bits)
		{
			FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
			FIBITMAP* dib = nullptr;
			fif = FreeImage_GetFileType(filename, 0);
			if (fif == FIF_UNKNOWN)
				fif = FreeImage_GetFIFFromFilename(filename);
			if (fif == FIF_UNKNOWN)
				return nullptr;

			if (FreeImage_FIFSupportsReading(fif))
				dib = FreeImage_Load(fif, filename);

			BYTE* pixels = FreeImage_GetBits(dib);
			*width = FreeImage_GetWidth(dib);
			*height = FreeImage_GetHeight(dib);
			*bits = FreeImage_GetBPP(dib);

			int size = *width * *height * (*bits / 8);
			BYTE* result = new BYTE[size];
			memcpy(result, pixels, size);
			FreeImage_Unload(dib);
			return result;
		}

	}
	

}