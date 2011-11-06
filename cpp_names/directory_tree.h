#ifndef DIRECTORY_TREE_H
#define DIRECTORY_TREE_H

#include <set>
#include <string>

namespace CppNames
{
  struct FileInfo
  {
    std::string ParentName;
    std::string Name;
    std::string FullPath;
    bool IsDirectory;

    FileInfo(): IsDirectory(false)
    {
    }

    FileInfo(std::string pName)
      : Name(pName), IsDirectory(false)
    {
    }

    FileInfo(std::string pParentName, std::string pName, bool pIsDirectory)
      : ParentName(pParentName), Name(pName), IsDirectory(pIsDirectory)
    {
    }
    
    bool operator<(const FileInfo& other) const
    {
       return Name < other.Name;
    }
  };

  typedef std::set<FileInfo> FileInfoSet;
  typedef std::set<std::string> NameSet;

  namespace UnitTests
  {
    namespace DirectoryTreeOperation
    {
      class Scan;
    }
  }

  class DirectoryTree
  {
  public:
    DirectoryTree();
    virtual ~DirectoryTree();
  
    bool Find(const std::string& databasePath, FileInfo &info);
    void ExcludeDirectories(const std::string& name);
    void IncludeFiles(const std::string& postfix);
    void Scan(std::string directoryPath, std::string databasePath);

    FileInfoSet::iterator Begin();
    FileInfoSet::iterator End();

  private:
    friend class UnitTests::DirectoryTreeOperation::Scan;
    void ScanDirectory(std::string parentDirectoryPath, std::string parentDatabasePath, std::string subdirName = "");

    FileInfoSet Files;
    NameSet Excludes;
    NameSet Includes;
  };

  class MatchFilename
  {
  public:
    MatchFilename(const std::string& Name);
    bool operator()(const std::string& postfix) const;
  private:
    std::string Name;
  };
}

#endif