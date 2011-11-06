#include "../cpp_names/cppnames.h"
#include "yaffut.h"

namespace CppNames
{
  namespace UnitTests
  {
    namespace DirectoryTreeOperation
    {
      TESTSUITE(Scan)
      {
      public:
      protected:
        DirectoryTree tree;
        FileInfoSet& TreeFiles()
        {
          return tree.Files;
        }
      };

      TESTCASE(Scan, EmptyDirectory)
      {
        tree.ExcludeDirectories(".svn");
        tree.Scan("../unit_tests/data/empty_dir", "/");

        CHECK(TreeFiles().size() == 1);
        FileInfo info;
        CHECK(tree.Find("/", info));
        CHECK(info.IsDirectory);
      }

      TESTCASE(Scan, NonExistentDirectory)
      {
        tree.Scan("../unit_tests/data/non_existent_dir", "/");

        CHECK(TreeFiles().size() == 0);
      }

      TESTCASE(Scan, Subdir)
      {
        tree.ExcludeDirectories(".svn");
        tree.Scan("../unit_tests/data/dir_with_subdir", "/");

        EQUAL(size_t(2), TreeFiles().size());

        FileInfo info;
        CHECK(tree.Find("/", info));
        CHECK(tree.Find("/subdir/", info));
      }

      TESTCASE(Scan, DirWithSVN)
      {
        tree.ExcludeDirectories(".svn");
        tree.Scan("../unit_tests/data/dir_with_svn", "/");

        EQUAL(size_t(1), TreeFiles().size());

        FileInfo info;
        CHECK(tree.Find("/", info));
      }

      TESTCASE(Scan, DirWithCpp)
      {
        tree.IncludeFiles(".cpp");
        tree.Scan("../unit_tests/data/dir_with_files", "/");

        CHECK(TreeFiles().size() > 1);

        FileInfo info;
        CHECK(tree.Find("/file.cpp", info));
        EQUAL(false, info.IsDirectory);
      }

      TESTCASE(Scan, DirWithTxt)
      {
        tree.IncludeFiles(".cpp");
        tree.Scan("../unit_tests/data/dir_with_files", "/");

        CHECK(TreeFiles().size() > 1);

        FileInfo info;
        CHECK(!tree.Find("file.txt", info));
      }

      TESTCASE(Scan, ParentDir)
      {
        tree.Scan("../unit_tests/data/dir_with_subdir", "/");

        FileInfo info;
        CHECK(tree.Find("/", info));
        CHECK(info.ParentName.empty());

        CHECK(tree.Find("/subdir/", info));
        EQUAL(info.ParentName, std::string("/"));
      }

      TESTCASE(Scan, FullName)
      {
        tree.Scan("../unit_tests/data/dir_with_subdir", "/");

        FileInfo info;
        CHECK(tree.Find("/subdir/", info));
        EQUAL(std::string("../unit_tests/data/dir_with_subdir/subdir"), info.FullPath);
      }
    }
  }
}
