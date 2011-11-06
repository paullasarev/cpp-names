#ifndef CPPNAMES_H
#define CPPNAMES_H

#include "directory_tree.h"
#include "file_scanner.h"
#include "name_info.h"

#include <set>
#include <string>
#include <map>
#include <vector>
#include <iostream>

namespace CppNames
{
  namespace UnitTests
  {
    class DatabaseOperation;
  }

  class Database
  {
  public:
    Database();
    virtual ~Database();
    virtual void Scan(std::string directoryPath);
    virtual void Save(std::string databaseName);
    virtual bool FindName(const std::string& name, NameInfo &info);
    virtual bool FindFile(const std::string& name, FileInfo &info);
    virtual void AddNameInfo(const NameInfo& info);

  protected:
    friend class CppNames::UnitTests::DatabaseOperation;

    DirectoryTree Files;
    NameInfoSet Names;
  };

  class ScanFile
  {
  public:
    ScanFile(NameInfoSet& names);
    void Register(const std::string& postfix, FileScannerPtr scanner);
    void operator()(const FileInfo& info);
    typedef std::map<std::string, FileScannerPtr> ScannerMap;

  private:
    NameInfoSet& Names;
    ScannerMap Scanners;
  };

  class CommandLine
  {
  public:
    CommandLine(Database& database);
    int Run(int argc, char** argv, std::ostream& out);
    int Run(std::vector<std::string> agrv, std::ostream& out);
  
  private:
    Database& Database;
  };
}

#endif
