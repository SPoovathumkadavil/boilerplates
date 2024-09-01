#include "lib.hpp"

library::library()
    : name {"[[name]]"}
{
    feta::directories fetadir(name);
    project_directories = fetadir.proj_dirs();
}
