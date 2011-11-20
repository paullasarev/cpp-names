#include "cpp_scanner.h"
#include "cpp_scanner_y.hpp"
#include "cpp_scanner_flex.h"

namespace CppNames
{
  CppScanner::CppScanner(): error_count_(0)
  {
  }

  bool CppScanner::Scan(std::istream& inputStream, NameInfoSet& names)
  {
    error_count_ = 0;
    CppFlexScanner scanner(&inputStream);
    CppBisonParserContext context(names);
    CppBisonParser parser(scanner, context);
    int result = parser.parse();
    error_count_ = context.error_count;  
    return result == 0 && error_count_ == 0;
  }

  int CppScanner::ErrorCount() const
  {
    return error_count_;
  }
}