#include "../cpp_names/cpp_scanner.h"
#include "../cpp_names/cpp_scanner_y.hpp"
#include "../cpp_names/cpp_scanner_flex.h"

#include "yaffut.h"

#include <strstream>

namespace CppNames
{
  namespace UnitTests
  {
    namespace CppScannerTests
    {
      TESTSUITE(Scan)
      {
      protected:
        void CheckName(NameInfoSet& names, const std::string& name, NameInfo::NameType type, const char *at, const char *expr)
        {
          NameInfo info;
          yaffut::check(FindNameInfo(names, name, info), at, expr);
          yaffut::equal(info.Name, name, at, expr);
          yaffut::equal(info.Type,  type, at, expr);
        }

        void CheckConst(NameInfoSet& names, const std::string& name, bool isConst, const char *at, const char *expr)
        {
          NameInfo info;
          yaffut::check(FindNameInfo(names, name, info), at, expr);
          yaffut::equal(isConst, info.IsConst, at, expr);
        }
      };

      #define CHECK_NAME(names, name, type) \
        CheckName(names, name, type, __YAFFUT_AT__, "CHECK_NAME(" #name ", " #type ") failed ")
     
      #define CHECK_CONST(names, name, isConst) \
        CheckConst(names, name, isConst, __YAFFUT_AT__, "CHECK_CONST(" #name ", " #isConst ") failed ")

      TESTCASE(Scan, EmptyContent)
      {
        std::stringstream content("");
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        EQUAL(size_t(0), names.size());
      }

      TESTCASE(Scan, OneNamespace)
      {
        std::stringstream content(
          ""
          "namespace First\n"
          "{\n"
          "}\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        CHECK(names.size() == 1);
        
        CHECK_NAME(names, "First", NameInfo::NAME_NAMESPACE);
      }

      TESTCASE(Scan, BisonParser)
      {
        NameInfoSet names;
        CppFlexScanner scanner;
        CppBisonParser parser(scanner, names);
      }

      TESTCASE(Scan, BisonEmpty)
      {
        std::stringstream content("");
        NameInfoSet names;
        CppFlexScanner scanner(&content);
        CppBisonParser parser(scanner, names);
        EQUAL(0, parser.parse());
        EQUAL(size_t(0), names.size());
     }

      TESTCASE(Scan, BisonNamespace)
      {
        NameInfoSet names;
        std::stringstream content(
          "\n"
          "namespace First\n"
          "{\n"
          "}\n"
          );
        CppFlexScanner scanner(&content);
        CppBisonParser parser(scanner, names);
        EQUAL(0, parser.parse());
        CHECK(names.size() == 1);

        CHECK_NAME(names, "First", NameInfo::NAME_NAMESPACE);
      }

      TESTCASE(Scan, NestedNamespace)
      {
        std::stringstream content(
          ""
          "namespace First\n"
          "{\n"
          "\tnamespace Second\n"
          "\t{\n"
          "\t}\n"
          "}\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        CHECK(names.size() == 2);
        
        CHECK_NAME(names, "First", NameInfo::NAME_NAMESPACE);
        CHECK_NAME(names, "First::Second", NameInfo::NAME_NAMESPACE);
      }

      TESTCASE(Scan, AnonymouseNamespace)
      {
        std::stringstream content(
          ""
          "namespace\n"
          "{\n"
          "}\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        CHECK(names.size() == 1);
        
        CHECK_NAME(names, "anonymous", NameInfo::NAME_NAMESPACE);
      }

      TESTCASE(Scan, FunctionDeclaration)
      {
        std::stringstream content(
          ""
          "int Function(double name);\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        CHECK(names.size() == 1);
        
        CHECK_NAME(names, "Function", NameInfo::NAME_FUNCTION);
      }

      TESTCASE(Scan, FunctionInNamespace)
      {
        std::stringstream content(
          ""
          "namespace First\n"
          "{\n"
          "int Function(double name);\n"
          "}\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        CHECK(names.size() == 2);
        
        CHECK_NAME(names, "First::Function", NameInfo::NAME_FUNCTION);
      }

      TESTCASE(Scan, QualifiedFunction)
      {
        std::stringstream content(
          ""
          "int Second::Function(double name);\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        
        CHECK_NAME(names, "Second::Function", NameInfo::NAME_FUNCTION);
      }

      TESTCASE(Scan, UnQualifiedFunction)
      {
        std::stringstream content(
          ""
          "int ::Function(double name);\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        
        CHECK_NAME(names, "Function", NameInfo::NAME_FUNCTION);
      }

      TESTCASE(Scan, UnQualifiedNamespaceFunction)
      {
        std::stringstream content(
          ""
          "namespace First\n"
          "{\n"
          "\tint ::Function(double name);\n"
          "}\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        
        CHECK_NAME(names, "Function", NameInfo::NAME_FUNCTION);
      }

      TESTCASE(Scan, QualifiedParameter)
      {
        std::stringstream content(
          "\n"
          "int Function(First::Type name);\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        CHECK(names.size() == 1);
        
        CHECK_NAME(names, "Function", NameInfo::NAME_FUNCTION);
      }

      TESTCASE(Scan, QualifiedReturnType)
      {
        std::stringstream content(
          "\n"
          "First::Type ::Function(string name);\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        CHECK(names.size() == 1);
        
        CHECK_NAME(names, "Function", NameInfo::NAME_FUNCTION);
      }

      TESTCASE(Scan, PointerReturnType)
      {
        std::stringstream content(
          "int* Function(double name);\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        CHECK(names.size() == 1);
        
        CHECK_NAME(names, "Function", NameInfo::NAME_FUNCTION);
      }

      TESTCASE(Scan, ReferenceType)
      {
        std::stringstream content(
          "int Function(double** & name);\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        CHECK(names.size() == 1);
        
        CHECK_NAME(names, "Function", NameInfo::NAME_FUNCTION);
      }

      TESTCASE(Scan, ConstType)
      {
        std::stringstream content(
          "const int* Function(double name);\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        CHECK(names.size() == 1);
        
        CHECK_NAME(names, "Function", NameInfo::NAME_FUNCTION);
      }

      TESTCASE(Scan, ConstPointerType)
      {
        std::stringstream content(
          "int const * Function(double name);\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        CHECK(names.size() == 1);
        
        CHECK_NAME(names, "Function", NameInfo::NAME_FUNCTION);
      }

     TESTCASE(Scan, FunctionDefinition)
      {
        std::stringstream content(
          ""
          "\tint ::Function(double name)\n"
          "{\n"
          "}\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        
        CHECK_NAME(names, "Function", NameInfo::NAME_FUNCTION);
      }

     TESTCASE(Scan, FunctionBrackets)
      {
        std::stringstream content(
          ""
          "\tint ::Function(double name)\n"
          "{\n"
          "\twhile(true)\n"
          "\t{\n"
          "\t}\n"
          "}\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        
        CHECK_NAME(names, "Function", NameInfo::NAME_FUNCTION);
      }

      TESTCASE(Scan, LineComment)
      {
        std::stringstream content(
          "//int Function(double name);\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        CHECK(names.size() == 0);
      }

     TESTCASE(Scan, LineCommentInFunction)
      {
        std::stringstream content(
          ""
          "\tint ::Function(double name)\n"
          "{\n"
          "\twhile(true)\n"
          "\t//{\n"
          "\t\n"
          "}\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        
        CHECK_NAME(names, "Function", NameInfo::NAME_FUNCTION);
      }

      TESTCASE(Scan, StreamComment)
      {
        std::stringstream content(
          "/*int Function(double name);\n"
          "int Function(double name);\n"
          "int Function(double name);*/\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        CHECK(names.size() == 0);
      }

     TESTCASE(Scan, StreamCommentInFunction)
      {
        std::stringstream content(
          ""
          "\tint ::Function(double name)\n"
          "{\n"
          "\twhile(true)\n"
          "\t/*{\n"
          "\t*/\n"
          "}\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        
        CHECK_NAME(names, "Function", NameInfo::NAME_FUNCTION);
      }

      TESTCASE(Scan, ClassForwardDeclaration)
      {
        std::stringstream content(
          "class First;\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        
        CHECK_NAME(names, "First", NameInfo::NAME_CLASS);
      }

      TESTCASE(Scan, StructForwardDeclaration)
      {
        std::stringstream content(
          "struct First;\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        
        CHECK_NAME(names, "First", NameInfo::NAME_STRUCT);
      }

      TESTCASE(Scan, NamespaceForwardDeclaration)
      {
        std::stringstream content(
          "namespace Main{\n"
          "class First;\n"
          "struct Second;\n"
          "}\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        
        CHECK_NAME(names, "Main", NameInfo::NAME_NAMESPACE);
        CHECK_NAME(names, "Main::First", NameInfo::NAME_CLASS);
        CHECK_NAME(names, "Main::Second", NameInfo::NAME_STRUCT);
      }

      TESTCASE(Scan, EmptyClassDefinition)
      {
        std::stringstream content(
          "class First{\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        
        CHECK_NAME(names, "First", NameInfo::NAME_CLASS);
      }

      TESTCASE(Scan, ClassMethodDefinition)
      {
        std::stringstream content(
          "class First{\n"
          "  int Function(double name);\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        
        CHECK_NAME(names, "First", NameInfo::NAME_CLASS);
        CHECK_NAME(names, "First::Function", NameInfo::NAME_FUNCTION);
      }

      TESTCASE(Scan, ClassMethodDeclaration)
      {
        std::stringstream content(
          "class First{\n"
          "  int Function(double name)\n"
          "  {\n"
          "  }\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        
        CHECK_NAME(names, "First", NameInfo::NAME_CLASS);
        CHECK_NAME(names, "First::Function", NameInfo::NAME_FUNCTION);
      }

      TESTCASE(Scan, InnerClassDeclaration)
      {
        std::stringstream content(
          "class First{\n"
          "  struct Second\n"
          "  {\n"
          "    int Function(double name)\n"
          "    {\n"
          "    }\n"
          "  };\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        
        CHECK_NAME(names, "First", NameInfo::NAME_CLASS);
        CHECK_NAME(names, "First::Second", NameInfo::NAME_STRUCT);
        CHECK_NAME(names, "First::Second::Function", NameInfo::NAME_FUNCTION);
      }

      TESTCASE(Scan, ConstClassMethodDeclaration)
      {
        std::stringstream content(
          "class First{\n"
          "  int Function(double name) const\n"
          "  {\n"
          "  }\n"
          "  int Method(double name) const;\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        
        CHECK_NAME(names, "First", NameInfo::NAME_CLASS);
        CHECK_NAME(names, "First::Function", NameInfo::NAME_FUNCTION);
        CHECK_NAME(names, "First::Method", NameInfo::NAME_FUNCTION);
        CHECK_CONST(names, "First::Function", true);
        CHECK_CONST(names, "First::Method", true);
      }

      TESTCASE(Scan, EnumEmpty)
      {
        std::stringstream content(
          "enum State{\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        
        CHECK_NAME(names, "State", NameInfo::NAME_ENUM);
      }

      TESTCASE(Scan, EnumField)
      {
        std::stringstream content(
          "enum State{\n"
          "  INITIAL\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        
        CHECK_NAME(names, "State", NameInfo::NAME_ENUM);
      }

      TESTCASE(Scan, EnumCommaEnded)
      {
        std::stringstream content(
          "enum State{\n"
          "  INITIAL,\n"
          "  FIRST,\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        
        CHECK_NAME(names, "State", NameInfo::NAME_ENUM);
      }

      TESTCASE(Scan, EnumInitialized)
      {
        std::stringstream content(
          "enum State{\n"
          "  INITIAL = 0,\n"
          "  FIRST = 1\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        
        CHECK_NAME(names, "State", NameInfo::NAME_ENUM);
      }

    }
  }
}

