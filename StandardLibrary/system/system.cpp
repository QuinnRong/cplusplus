#include <string>
#include <iostream>
#include <cstdlib>		/* system */
#include <unistd.h>		/* access */

#define SPT "\\"		// for windows
// #define SPT "/"		// for linux

void make_directory(const std::string &path)
{
    // path not exist
    if (access(path.c_str(), 0) == -1)
    {
        std::string cmd = "mkdir " + path;
        std::cout << cmd << std::endl;
        system(cmd.c_str());
    }
    else
    {
    	std::cout << path << " already exists" << std::endl;
    }
}

void delete_directory(const std::string &path)
{
    // path exist
    if (access(path.c_str(), 0) == 0)
    {
        std::string cmd = "rm -rf " + path;
        std::cout << cmd << std::endl;
        system(cmd.c_str());
    }
    else
    {
    	std::cout << path << " not exists" << std::endl;
    }
}

int main()
{
	std::string root = ".";
	std::string subdir = root + SPT + "test";
	std::string path = subdir + SPT + std::to_string(0);
	delete_directory(subdir);
	make_directory(path);
	delete_directory(subdir);
}