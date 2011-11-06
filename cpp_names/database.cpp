#include "cppnames.h"
#include "cpp_scanner.h"

#include <algorithm>
#include <fstream>
#include <map>

namespace CppNames
{
  Database::Database()
  {
    Files.ExcludeDirectories(".svn");
    Files.IncludeFiles(".cpp");
    Files.IncludeFiles(".h");
  }

  Database::~Database()
  {
  }

  void Database::Scan(std::string directoryPath)
  {
    Files.Scan(directoryPath, "/");
    ScanFile scanner(Names);
    scanner.Register(".cpp", FileScannerPtr(new CppScanner()));

    for_each(Files.Begin(), Files.End(), scanner);
  }

  void Database::Save(std::string databaseName)
  {
    std::ofstream out(databaseName);

    for_each(Names.begin(), Names.end(), NameToCSV(out));
  }

  void Database::AddNameInfo(const NameInfo& info)
  {
    Names.insert(info);
  }

  bool Database::FindName(const std::string& name, NameInfo &info)
  {
    NameInfo key(name);
    NameInfoSet::iterator found = Names.find(key);
    if (found == Names.end())
    {
      return false;
    }
    else
    {
      info = *found;
      return true;
    }
  }

  bool Database::FindFile(const std::string& name, FileInfo &info)
  {
    return Files.Find(name, info);
  }
}

namespace CppNames
{
  ScanFile::ScanFile(NameInfoSet& names)
    : Names(names)
  {
  }

  void ScanFile::Register(const std::string& postfix, FileScannerPtr scanner)
  {
    Scanners[postfix] = scanner;
  }

  struct MatchScanner
  {
    MatchFilename Match;

    MatchScanner(const std::string& filename): Match(filename)
    {
    }

    bool operator()(ScanFile::ScannerMap::value_type& scanner)
    {
      return Match(scanner.first);
    }
  };

  void ScanFile::operator()(const FileInfo& info)
  {
    ScannerMap::iterator scannerValue = find_if(Scanners.begin(), Scanners.end(), MatchScanner(info.Name));
    if (scannerValue == Scanners.end())
    {
      return;
    }

    std::ifstream inputStream(info.FullPath);
    if (!inputStream)
    {
      return;
    }

    scannerValue->second->Scan(inputStream, Names);
  }
}

namespace CppNames
{
  CommandLine::CommandLine(CppNames::Database& database)
    : Database(database)
  {
  }

  int CommandLine::Run(int argc, char** argv_c, std::ostream& out)
  {
    std::vector<std::string> argv;
    for(int i = 0; i < argc; ++i)
    {
      argv.push_back(argv_c[i]);
    }

    return Run(argv, out);
  }

  int CommandLine::Run(std::vector<std::string> argv, std::ostream& out)
  {
    if(argv.size() == 3)
    {
      Database.Scan(argv[1]);
      Database.Save(argv[2]);
      return 0;
    }

    out << "Usage: \n" 
      << "\t" << argv[0] << "<path>  <filename>" << std::endl
      ;
    return 1;
  }
}

namespace CppNames
{
  bool FindNameInfo(NameInfoSet& names, const std::string name, NameInfo &info)
  {
    NameInfo key;
    key.Name = name;
    NameInfoSet::iterator found = names.find(key);
    if (found == names.end())
    {
      return false;
    }
    else
    {
      info = *found;
      return true;
    }
  }

  NameToCSV::NameToCSV(std::ostream& out)
    : Out(out)
  {
  }
  
  void NameToCSV::operator()(const NameInfo& info)
  {
    Out << '\"' << info.Name << '\"' << std::endl;
  }
}