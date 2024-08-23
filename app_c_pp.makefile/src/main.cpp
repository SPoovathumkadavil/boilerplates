#include "main.h"

#include <iostream>
#include "boilerutils.h"

void handle_test_args(int argc, char *argv[])
{
	for (int i = 1; i < argc; i++)
	{
		// flags -d and -c to change dependencies and config directories
		if (std::string(argv[i]) == "-d")
		{
			if (i + 1 < argc)
			{
				LIBRARY_DIR = argv[i + 1];
			}
		}
		if (std::string(argv[i]) == "-c")
		{
			if (i + 1 < argc)
			{
				CONFIG_DIR = argv[i + 1];
			}
		}
		// alternatively use -t to set test mode and change dirs automatically
		if (std::string(argv[i]) == "-t")
		{
			LIBRARY_DIR = "dependencies";
			CONFIG_DIR = "config";
		}
	}
}

int main(int argc, char *argv[])
{

	handle_test_args(argc, argv);

	return 0;
}
