
#include "directory_tree.h"

#include "dirent_wrapper.h"

#include <algorithm>

namespace CppNames
{
  DirectoryTree::DirectoryTree()
  {
    Excludes.insert(".");
    Excludes.insert("..");
  }

  DirectoryTree::~DirectoryTree()
  {
  }

  void  DirectoryTree::ExcludeDirectories(const std::string& name)
  {
    Excludes.insert(name);
  }

  void  DirectoryTree::IncludeFiles(const std::string& postfix)
  {
    Includes.insert(postfix);
  }

  bool DirectoryTree::Find(const std::string& databasePath, FileInfo &info)
  {
    FileInfo key(databasePath);
    FileInfoSet::iterator found = Files.find(key);
    if (found == Files.end())
    {
      return false;
    }
    else
    {
      info = *found;
      return true;
    }
  }

  FileInfoSet::iterator DirectoryTree::Begin()
  {
    return Files.begin();
  }

  FileInfoSet::iterator DirectoryTree::End()
  {
    return Files.end();
  }

  MatchFilename::MatchFilename(const std::string& aName): Name(aName)
  {
  }

  bool MatchFilename::operator()(const std::string& postfix) const
  {
    return postfix.size() < Name.size() &&
      Name.substr(Name.size() - postfix.size(), postfix.size()) == postfix;
  }

  void  DirectoryTree::Scan(std::string directoryPath, std::string databasePath)
  {
    ScanDirectory(directoryPath, databasePath, "");
  }

  void DirectoryTree::ScanDirectory(std::string parentDirectoryPath, std::string parentDatabasePath, std::string subdirName)
  {
    const std::string pathDelimiter("/");
    std::string directoryPath(parentDirectoryPath);
    std::string databasePath(parentDatabasePath); 

    if (!subdirName.empty())
    {
      directoryPath.append(pathDelimiter).append(subdirName);
      databasePath.append(subdirName).append(pathDelimiter);
    }

    DIR* dir = opendir(directoryPath.c_str());
    if (dir == NULL)
    {
      return;
    }

    FileInfo info(subdirName.empty() ? std::string() : parentDatabasePath, databasePath, true);
    info.FullPath = directoryPath;
    Files.insert(info);

    struct dirent *dirEntry;
    while ((dirEntry = readdir (dir)) != NULL) 
    {
      if (dirEntry->d_type == DT_REG) 
      {
        if(find_if(Includes.begin(), Includes.end(), MatchFilename(dirEntry->d_name)) != Includes.end())
        {
          info.IsDirectory = false;
          info.Name = databasePath + std::string(dirEntry->d_name);
          info.FullPath = directoryPath + pathDelimiter + info.Name;
          Files.insert(info);
        }
      }
      else if (dirEntry->d_type == DT_DIR)
      {
        if (Excludes.find(std::string(dirEntry->d_name)) == Excludes.end())
        {
          ScanDirectory(directoryPath, databasePath, std::string(dirEntry->d_name));
        }
      }
    }

    closedir(dir); 
  }


}
