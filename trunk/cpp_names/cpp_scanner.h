#ifndef CPP_SCANNER_H
#define CPP_SCANNER_H

#include "file_scanner.h"

namespace CppNames
{
  class CppScanner: public FileScanner
  {
  public:
    CppScanner();
    virtual bool Scan(std::istream& inputStream, NameInfoSet& names);
    int ErrorCount() const;
  private:
    int error_count_;
  };
}

#endif