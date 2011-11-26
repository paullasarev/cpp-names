#include "../cpp_names/cppnames.h"

#include "yaffut.h"

namespace CppNames
{
  namespace UnitTests
  {
    const std::string DataDir("../../../unit_tests/data/");

    TESTSUITE(DatabaseOperation)
    {
    };

    TESTCASE(DatabaseOperation, EmptyCppInDirectory)
    {
      Database database;
      database.Scan(DataDir + "dir_with_files");
      FileInfo info;
      CHECK(database.FindFile("/file.cpp", info));
    }

    TESTCASE(DatabaseOperation, NamescpaceInDirectory)
    {
      Database database;
      database.Scan(DataDir + "dir_with_files");

      NameInfo info;
      CHECK(database.FindName("First", info));
      EQUAL(info.Name, std::string("First"));
    }
 }
}
