#include "../cpp_names/cpp_scanner.h"
#include "../cpp_names/cpp_scanner_y.hpp"
#include "../cpp_names/cpp_scanner_flex.h"

#include "yaffut.h"

#include <algorithm>
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

        void CheckAccess(NameInfoSet& names, const std::string& name, NameInfo::NameAccess access, const char *at, const char *expr)
        {
          NameInfo info;
          yaffut::check(FindNameInfo(names, name, info), at, expr);
          yaffut::equal(access, info.Access, at, expr);
        }
      };

#define CHECK_NAME(names, name, type) \
  CheckName(names, name, type, __YAFFUT_AT__, "CHECK_NAME(" #name ", " #type ") failed ")

#define CHECK_CONST(names, name, isConst) \
  CheckConst(names, name, isConst, __YAFFUT_AT__, "CHECK_CONST(" #name ", " #isConst ") failed ")

#define CHECK_ACCESS(names, name, access) \
  CheckAccess(names, name, access, __YAFFUT_AT__, "CHECK_CONST(" #name ", " #access ") failed ")

      struct CppBisonParserWrapper
      {
        CppBisonParserWrapper(std::istream& arg_yyin)
          : scanner(&arg_yyin)
          , context(names)
          , parser(scanner, context)
        {
        }

        int parse()
        {
          return parser.parse();
        }

        CppFlexScanner scanner;
        NameInfoSet names;
        CppBisonParserContext context;
        CppBisonParser parser;
      };

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
        CppFlexScanner scanner;
        NameInfoSet names;
        CppBisonParserContext context(names);
        CppBisonParser parser(scanner, context);
      }

      TESTCASE(Scan, BisonEmpty)
      {
        std::stringstream content("");
        NameInfoSet names;
        CppFlexScanner scanner(&content);
        CppBisonParserWrapper parser(content);
        EQUAL(0, parser.parse());
        EQUAL(size_t(0), names.size());
      }

      TESTCASE(Scan, BisonNamespace)
      {
        std::stringstream content(
          "\n"
          "namespace First\n"
          "{\n"
          "}\n"
          );
        CppBisonParserWrapper parser(content);
        EQUAL(0, parser.parse());
        CHECK(parser.names.size() == 1);

        CHECK_NAME(parser.names, "First", NameInfo::NAME_NAMESPACE);
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
          "const char* Function(double name);\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
        CHECK(names.size() == 1);
        CHECK(scanner.ErrorCount() == 0);

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

      TESTCASE(Scan, ClassMethodDefisnition)
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

      union Pack
      {
        int count;
        const char *name;
      };

      TESTCASE(Scan, UnionDeclaration)
      {
        std::stringstream content(
          "union Pack\n"
          "{\n"
          "  int count;\n"
          "  const char *name;\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));

        CHECK_NAME(names, "Pack", NameInfo::NAME_UNION);
      }

      TESTCASE(Scan, DefaultClassAccess)
      {
        std::stringstream content(
          "class First{\n"
          "  int Function(double name);\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));

        CHECK_ACCESS(names, "First::Function", NameInfo::ACCESS_PRIVATE);
      }

      TESTCASE(Scan, DefaultStructAccess)
      {
        std::stringstream content(
          "struct First{\n"
          "  int Function(double name);\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));

        CHECK_ACCESS(names, "First::Function", NameInfo::ACCESS_PUBLIC);
      }

      TESTCASE(Scan, DefaultInnerStructAccess)
      {
        std::stringstream content(
          "class First{\n"
          "  int Function(double name);\n"
          "  struct Second\n"
          "  {\n"
          "    int Function(double name);\n"
          "  };\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));

        CHECK_ACCESS(names, "First::Function", NameInfo::ACCESS_PRIVATE);
        CHECK_ACCESS(names, "First::Second::Function", NameInfo::ACCESS_PUBLIC);
      }

      TESTCASE(Scan, PublicPrivateProtected)
      {
        std::stringstream content(
          "class First{\n"
          "  public:\n"
          "  int PublicFunction(double name);\n"
          "  private:\n"
          "  int PrivateFunction(double name);\n"
          "  protected:\n"
          "  int ProtectedFunction(double name);\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));

        CHECK_ACCESS(names, "First::PublicFunction", NameInfo::ACCESS_PUBLIC);
        CHECK_ACCESS(names, "First::PrivateFunction", NameInfo::ACCESS_PRIVATE);
        CHECK_ACCESS(names, "First::ProtectedFunction", NameInfo::ACCESS_PROTECTED);
      }

      TESTCASE(Scan, PublicPrivateProtectedWithSpaces)
      {
        std::stringstream content(
          "class First{\n"
          "  public :\n"
          "  int PublicFunction(double name);\n"
          "  private\n:\n"
          "  int PrivateFunction(double name);\n"
          "  protected\t:\n"
          "  int ProtectedFunction(double name);\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));

        CHECK_ACCESS(names, "First::PublicFunction", NameInfo::ACCESS_PUBLIC);
        CHECK_ACCESS(names, "First::PrivateFunction", NameInfo::ACCESS_PRIVATE);
        CHECK_ACCESS(names, "First::ProtectedFunction", NameInfo::ACCESS_PROTECTED);
      }

      TESTCASE(Scan, ClassInheritance)
      {
        std::stringstream content(
          "class Second: First\n"
          "{\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));

        NameInfo info;
        CHECK(FindNameInfo(names, "Second", info));
        EQUAL(NameInfo::NAME_CLASS, info.Type);

        NameInfo parent;
        CHECK(FindNameInfo(info.Parents, "First", parent));
        EQUAL(NameInfo::NAME_CLASS, parent.Type);
        EQUAL(NameInfo::ACCESS_PRIVATE, parent.Access);
      }

      TESTCASE(Scan, ClassPublicInheritance)
      {
        std::stringstream content(
          "class Second: public First\n"
          "{\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));

        NameInfo info;
        CHECK(FindNameInfo(names, "Second", info));
        EQUAL(NameInfo::NAME_CLASS, info.Type);

        NameInfo parent;
        CHECK(FindNameInfo(info.Parents, "First", parent));
        EQUAL(NameInfo::NAME_CLASS, parent.Type);
        EQUAL(NameInfo::ACCESS_PUBLIC, parent.Access);
        CHECK(false == parent.IsVirtual);
      }

      TESTCASE(Scan, StructInheritance)
      {
        std::stringstream content(
          "struct Second: First\n"
          "{\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));

        NameInfo info;
        CHECK(FindNameInfo(names, "Second", info));
        EQUAL(NameInfo::NAME_STRUCT, info.Type);

        NameInfo parent;
        CHECK(FindNameInfo(info.Parents, "First", parent));
        EQUAL(NameInfo::NAME_CLASS, parent.Type);
        EQUAL(NameInfo::ACCESS_PUBLIC, parent.Access);
      }

      TESTCASE(Scan, StructPrivateInheritance)
      {
        std::stringstream content(
          "struct Second: private First\n"
          "{\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));

        NameInfo info;
        CHECK(FindNameInfo(names, "Second", info));
        EQUAL(NameInfo::NAME_STRUCT, info.Type);

        NameInfo parent;
        CHECK(FindNameInfo(info.Parents, "First", parent));
        EQUAL(NameInfo::NAME_CLASS, parent.Type);
        EQUAL(NameInfo::ACCESS_PRIVATE, parent.Access);

      }

      TESTCASE(Scan, VirtualClassMethod)
      {
        std::stringstream content(
          "class First{\n"
          "  virtual int Function(double name);\n"
          "  int NonVirtualFunction(double name);\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));

        NameInfo info;
        CHECK(FindNameInfo(names, "First::NonVirtualFunction", info));
        EQUAL(NameInfo::NAME_FUNCTION, info.Type);
        CHECK(false == info.IsVirtual);

        CHECK(FindNameInfo(names, "First::Function", info));
        EQUAL(NameInfo::NAME_FUNCTION, info.Type);
        CHECK(true == info.IsVirtual);
      }

      TESTCASE(Scan, ClassVirtualInheritance)
      {
        std::stringstream content(
          "class Second: virtual public First\n"
          "{\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));

        NameInfo info;
        CHECK(FindNameInfo(names, "Second", info));
        EQUAL(NameInfo::NAME_CLASS, info.Type);

        NameInfo parent;
        CHECK(FindNameInfo(info.Parents, "First", parent));
        EQUAL(NameInfo::NAME_CLASS, parent.Type);
        EQUAL(NameInfo::ACCESS_PUBLIC, parent.Access);
        CHECK(true == parent.IsVirtual);
      }

      TESTCASE(Scan, AbstractClassMethod)
      {
        std::stringstream content(
          "class Second\n"
          "{\n"
          "  virtual int Function(double name) = 0;\n"
          "  int NonVirtualFunction(double name);\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));

        NameInfo info;
        CHECK(FindNameInfo(names, "Second::Function", info));
        EQUAL(NameInfo::NAME_FUNCTION, info.Type);
        CHECK(true == info.IsAbstract);
        CHECK(true == info.IsVirtual);

        CHECK(FindNameInfo(names, "Second::NonVirtualFunction", info));
        EQUAL(NameInfo::NAME_FUNCTION, info.Type);
        CHECK(false == info.IsAbstract);
        CHECK(false == info.IsVirtual);
      }

      TESTCASE(Scan, FuctionLevelException)
      {
        std::stringstream content(
          "class First\n"
          "{\n"
          "  int Function(double name) {} catch (excepton& ex) {}\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));

        CHECK_NAME(names, "First::Function", NameInfo::NAME_FUNCTION);
      }

      TESTCASE(Scan, FriendClassDeclaration)
      {
        std::stringstream content(
          "class First\n"
          "{\n"
          "  friend class Second;\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));

        NameInfo info;
        CHECK(FindNameInfo(names, "First::Second", info));
        EQUAL(NameInfo::NAME_CLASS, info.Type);
        CHECK(true == info.IsFriend);
      }

      TESTCASE(Scan, FriendFunctionDeclaration)
      {
        std::stringstream content(
          "class First\n"
          "{\n"
          "  friend int Function(double par);\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));

        NameInfo info;
        CHECK(FindNameInfo(names, "First::Function", info));
        EQUAL(NameInfo::NAME_FUNCTION, info.Type);
        CHECK(true == info.IsFriend);
      }
      
      TESTCASE(Scan, TypedefDeclaration)
      {
        std::stringstream content(
          "typedef int First;\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));

        NameInfo info;
        CHECK(FindNameInfo(names, "First", info));
        EQUAL(NameInfo::NAME_TYPE, info.Type);
        EQUAL(std::string("int"), info.Alias);
      }
      
      TESTCASE(Scan, FunctionTemplate)
      {
        std::stringstream content(
          "template <class T1, class T2>\n"
          "T1 First(T2 t)\n"
          "{\n"
          "  return T1.T2;\n"
          "}\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));

        NameInfo info;
        CHECK(FindNameInfo(names, "First", info));
        EQUAL(NameInfo::NAME_FUNCTION, info.Type);
        EQUAL(true, info.IsTemplate);
      }
      
      TESTCASE(Scan, ClassTemplate)
      {
        std::stringstream content(
          "template <class T1, typename T2, int i>\n"
          "class First\n"
          "{\n"
          "  T1 Function(T2 t);\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));

        NameInfo info;
        CHECK(FindNameInfo(names, "First", info));
        EQUAL(NameInfo::NAME_CLASS, info.Type);
        EQUAL(true, info.IsTemplate);
      }

      TESTCASE(Scan, ClassTemplateDefault)
      {
        std::stringstream content(
          "template <class T1 = int, class T2 = First::Second&>\n"
          "class First\n"
          "{\n"
          "  T1 Function(T2 t);\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));

        NameInfo info;
        CHECK(FindNameInfo(names, "First", info));
        EQUAL(NameInfo::NAME_CLASS, info.Type);
        EQUAL(true, info.IsTemplate);
      }
      
      TESTCASE(Scan, TemplatedType)
      {
        std::stringstream content(
          "vector<int> Function()\n"
          "{\n"
          "}\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));

        CHECK_NAME(names, "Function", NameInfo::NAME_FUNCTION);
      }

      TESTCASE(Scan, TemplateTemplateParameter)
      {
        std::stringstream content(
          "template < template <class A> class T>\n"
          "class First\n"
          "{\n"
          "  T Function(T2 t);\n"
          "};\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));

        NameInfo info;
        CHECK(FindNameInfo(names, "First", info));
        EQUAL(NameInfo::NAME_CLASS, info.Type);
        EQUAL(true, info.IsTemplate);
      }
      
      TESTCASE(Scan, NestedTemplatedType)
      {
        std::stringstream content(
          "vector<list<int> > Function()\n"
          "{\n"
          "}\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));

        CHECK_NAME(names, "Function", NameInfo::NAME_FUNCTION);
      }

      TESTCASE(Scan, PreprocessorDirective)
      {
        std::stringstream content(
          "#define MIN(x,y) ((x)<(y)?(x):(y))\n"
          "\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));
      }

      TESTCASE(Scan, PreprocessorMultilineDirective)
      {
        std::stringstream content(
          "#define MIN(x,y) \\\n"
          "     ((x)<(y)?(x):(y))\n"
          "int Function(double name);\n"
          );
        NameInfoSet names;
        CppScanner scanner;
        CHECK(scanner.Scan(content, names));

        CHECK_NAME(names, "Function", NameInfo::NAME_FUNCTION);
      }
    }
  }
}

