#include "cppnames.h"

#include <iostream>

int main(int argc, char* argv[])
{
  CppNames::Database database;
  CppNames::CommandLine command(database);

  return command.Run(argc, argv, std::cout);
}
