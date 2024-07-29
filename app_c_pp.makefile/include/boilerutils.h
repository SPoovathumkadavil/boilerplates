#ifndef boilerutils_h
#define boilerutils_h

#include <string>
#include "fileutils.h"

const std::string HOME_DIR = get_home_dir();
const std::string PROJECT_NAME = "Boilerman";
std::string DEPENDENCIES_DIR = HOME_DIR + "/dev/.dependencies/" + PROJECT_NAME;
std::string CONFIG_DIR = HOME_DIR + "/dev/.config/" + PROJECT_NAME;

#endif