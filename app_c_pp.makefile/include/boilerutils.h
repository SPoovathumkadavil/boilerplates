#ifndef boilerutils_h
#define boilerutils_h

#include <string>
#include "fileutils.h"

const std::string HOME_DIR = get_home_dir();
const std::string PROJECT_NAME = "project";
const std::string LOC_FILE = HOME_DIR + "/dev/.loc.json";
std::string DEPENDENCIES_DIR = read_json_string(LOC_FILE, "dependencies");
std::string CONFIG_DIR = read_json_string(LOC_FILE, "config");

#endif