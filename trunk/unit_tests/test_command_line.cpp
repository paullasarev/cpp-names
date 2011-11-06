#include "../cpp_names/cppnames.h"
#include "yaffut.h"
#include "hippomocks.h"

#include <strstream>

namespace CppNames
{
  namespace UnitTests
  {
    TESTSUITE(CommandLineTests)
    {
    };

    TESTCASE(CommandLineTests, Usage)
    {
      MockRepository mocks;
      Database *database = mocks.Mock<Database>();

      CommandLine command(*database);
      std::vector<std::string> argv;
      argv.push_back("command");

      std::stringstream out;
      command.Run(argv, out);

      CHECK(out.str().find("Usage:") != std::string::npos);
    }

    TESTCASE(CommandLineTests, Scan)
    {
      std::string path("path/dir/");
      std::string databaseName("database.csv");
      MockRepository mocks;
      Database *database = mocks.Mock<Database>();

      CommandLine command(*database);
      std::vector<std::string> argv;
      argv.push_back("command");
      argv.push_back(path);
      argv.push_back(databaseName);
      std::stringstream out;

      mocks.ExpectCall(database, Database::Scan).With(path);
      mocks.ExpectCall(database, Database::Save).With(databaseName);

      command.Run(argv, out);
    }

    TESTCASE(CommandLineTests, WrongArgsNumber)
    {
      MockRepository mocks;
      Database *database = mocks.Mock<Database>();
      CommandLine command(*database);
      std::stringstream out;
      std::vector<std::string> argv;
      argv.push_back("command");
      argv.push_back("asdf");

      command.Run(argv, out);
      CHECK(out.str().find("Usage:") != std::string::npos);

      out.clear();
      argv.push_back("qwer");
      argv.push_back("asdf");

      command.Run(argv, out);
      CHECK(out.str().find("Usage:") != std::string::npos);
    }
  }
}
