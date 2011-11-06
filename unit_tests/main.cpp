#define YAFFUT_MAIN
#include "yaffut.h"
/*
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/TextTestProgressListener.h>
#include <cppunit/Protector.h>

#include <iostream>
#include <fstream>

#include <set>
#include <string>

namespace CppNames
{
  namespace UnitTests
  {
    int RunUnitTests(int argc, char* argv[])
    {
      std::string testPath = (argc > 1) ? std::string(argv[1]) : "";

      // Create the event manager and test controller
      CppUnit::TestResult controller;

      // Add a listener that colllects test result
      CppUnit::TestResultCollector result;
      controller.addListener(&result);

      // Add a listener that print dots as test run.
      CppUnit::TextTestProgressListener progress;
      controller.addListener(&progress);

      // Add the top suite to the test runner
      CppUnit::TestRunner runner;
      runner.addTest( CppUnit::TestFactoryRegistry::getRegistry().makeTest());
      try
      {
        std::cout << "Running tests " << testPath << ":" << std::endl;

        runner.run( controller, testPath );

        std::cout << std::endl;

        // Print test in a compiler compatible format.
        CppUnit::CompilerOutputter outputter(&result, std::cerr);
        outputter.write();
      }
      catch ( std::exception &e )
      {
        std::cerr << std::endl << "ERROR: " << e.what() << std::endl;
        return 0;
      }

      return result.wasSuccessful() ? 0 : 1;
    }
  }
}

int main(int argc, char* argv[])
{
  return CppNames::UnitTests::RunUnitTests(argc, argv);
}


*/