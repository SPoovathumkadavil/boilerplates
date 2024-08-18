#ifndef boilerutils_h
#define boilerutils_h

#include <string>
#include "fileutils.h"

const std::string HOME_DIR = get_home_dir();
const std::string PROJECT_NAME = "[[name]]";
const std::string LOC_FILE = HOME_DIR + "/.loc.json";
std::string LIBRARY_DIR = read_json_string(LOC_FILE, "library") + "/" + PROJECT_NAME;
std::string CONFIG_DIR = read_json_string(LOC_FILE, "config") + "/" + PROJECT_NAME;

#endif