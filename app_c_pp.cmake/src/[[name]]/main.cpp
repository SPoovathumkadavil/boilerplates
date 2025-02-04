
#include "main.hpp"

#include <fetalib/cli/arguments.hpp>

void print_help(library *lib, feta::ArgumentParser *arg_parser) {
  for (std::string s : arg_parser->get_help_message(lib->_name, true, 80)) std::printf("%s\n", s.c_str());
}

auto main(int argc, char **argv) -> int
{
  library lib = library {};

  feta::ArgumentParser argparser(argc, argv);
  feta::Argument a_test = feta::get_blank_argument()
                            .withKey("-t")
                            .withAlternateKey("--test")
                            .withHelpMessage("Enables test mode.")
                            .withFlag();
  feta::ArgumentDependency c_help = feta::get_blank_argument_dependency()
                            .withKey("help")
                            .withHelpMessage("Prints the help message.");
  argparser.add(&a_test);
  argparser.add(&c_help);

  if (argparser.get<bool>("-t").value()) lib._test = true;
  if (argparser.get_command()->key == "help") print_help(&lib, &argparser);

  return 0;
}

