#ifndef FILE_READER_H
#define FILE_READER_H

#include <fstream>
#include <sstream>

namespace chrisHit
{
	class file_reader
	{
	private:
		std::string file_src;
	public:
		file_reader(const char *path);
		const char *c_str();
	};
}

#endif