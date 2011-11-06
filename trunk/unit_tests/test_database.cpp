#include "../cpp_names/cppnames.h"

#include "yaffut.h"

namespace CppNames
{
  namespace UnitTests
  {
    TESTSUITE(DatabaseOperation)
    {
    };

    TESTCASE(DatabaseOperation, EmptyCpp)
    {
      Database database;
      database.Scan("../unit_tests/data/dir_with_files");
      FileInfo info;
      CHECK(database.FindFile("/file.cpp", info));
    }

    TESTCASE(DatabaseOperation, NamescpaceFirst)
    {
      Database database;
      database.Scan("../unit_tests/data/dir_with_files");

      NameInfo info;
      CHECK(database.FindName("First", info));
      EQUAL(info.Name, std::string("First"));
    }
 }
}
