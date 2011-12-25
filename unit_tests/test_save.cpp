
#include "../cpp_names/cppnames.h"

#include "yaffut.h"

#include <sstream>
#include <fstream>
#include <stdio.h>

namespace CppNames
{
  namespace UnitTests
  {
    const std::string DataDir("../../../unit_tests/data/");

    TESTSUITE(SaveDatabase)
    {
    protected:
      bool fexists(const std::string& filename);
    };

    TESTSUITE(ToCSV)
    {
    };

    bool SaveDatabase::fexists(const std::string& filename)
    {
      std::ifstream ifile(filename.c_str());
      return !(!ifile);
    }

    TESTCASE(SaveDatabase, DatabaseSave)
    {
      std::string databaseName(DataDir + "database1.csv");
      Database database;

      std::remove(databaseName.c_str());
      database.Scan(DataDir + "dir_with_files");
      database.Save(databaseName);
      
      CHECK(fexists(databaseName));
    }

    TESTCASE(ToCSV, Name)
    {
      std::stringstream out;
      NameToCSV save(out);

      NameInfo info("Namespace1");
      save(info);

      CHECK(out.str().find("\"Namespace1\"") != std::string::npos);
    }

  }
}

