#include "cpp_scanner.h"
#include "cpp_scanner_y.hpp"
#include "cpp_scanner_flex.h"

namespace CppNames
{
  CppScanner::CppScanner()
  {
  }

  bool CppScanner::Scan(std::istream& inputStream, NameInfoSet& names)
  {
    CppFlexScanner scanner(&inputStream);
    CppBisonParserContext context(names);
    CppBisonParser parser(scanner, context);
    return parser.parse() == 0;
  }
}