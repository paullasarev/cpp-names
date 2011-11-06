#ifndef FILE_SCANNER_H
#define FILE_SCANNER_H

#include "directory_tree.h"
#include "name_info.h"

#include <iostream>
#include <memory>

namespace CppNames
{
  class FileScanner
  {
  public:
    virtual bool Scan(std::istream& inputStream, NameInfoSet& names) = 0;
  };

  typedef std::shared_ptr<FileScanner> FileScannerPtr;
}

#endif
