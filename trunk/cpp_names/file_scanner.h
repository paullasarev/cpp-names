#ifndef FILE_SCANNER_H
#define FILE_SCANNER_H

#include "directory_tree.h"
#include "name_info.h"

#include <iostream>
#include <memory>
#include <boost/tr1/memory.hpp>

namespace CppNames
{
  class FileScanner
  {
  public:
    virtual bool Scan(std::istream& inputStream, NameInfoSet& names) = 0;
  };

  typedef std::tr1::shared_ptr<FileScanner> FileScannerPtr;
}

#endif
