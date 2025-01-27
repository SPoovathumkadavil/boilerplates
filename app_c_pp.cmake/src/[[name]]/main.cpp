
#include "main.hpp"

#include <fetalib/cli/arguments.hpp>

int main(int argc, char **argv)
{
  library lib = library {};

  feta::ArgumentParser argparser(argc, argv);
  feta::Argument a_test = feta::get_blank_argument()
                            .withKey("-t")
                            .withAlternateKey("--test")
                            .withFlag();
  argparser.add(&a_test);

  if (argparser.get<bool>("-t").value()) lib._test = true;

  std::cout << "is test: " << lib._test << '\n';

  return 0;
}
