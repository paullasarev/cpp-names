#include "../cpp_names/cppnames.h"

#include "yaffut.h"

namespace CppNames
{
  namespace UnitTests
  {
    TESTSUITE(DatabaseOperation)
    {
    };

    TESTCASE(DatabaseOperation, EmptyCppInDirectory)
    {
      Database database;
      database.Scan("../data/dir_with_files");
      FileInfo info;
      CHECK(database.FindFile("/file.cpp", info));
    }

    TESTCASE(DatabaseOperation, NamescpaceInDirectory)
    {
      Database database;
      database.Scan("../data/dir_with_files");

      NameInfo info;
      CHECK(database.FindName("First", info));
      EQUAL(info.Name, std::string("First"));
    }
 }
}
