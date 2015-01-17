#include "file_reader.h"
#include <iostream>

namespace chrisHit
{
	file_reader::file_reader(const char *path)
	{
		std::ifstream file(path);
		std::stringstream file_stream;
		file_stream << file.rdbuf();

		file.close();

		file_src = file_stream.str();
		
	}
	const char *file_reader::c_str()
	{
		return file_src.c_str();
	}
}