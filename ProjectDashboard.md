

# Realised features #

Infrastructure classes:
  * **Database** facade
  * **DirectoryTree** file system traverser
  * **FileScanner** interface
  * **NameToCsv** trivial realisation
  * **CommandLine** string argument vector processor
  * **CppFlexScanner** adapter
  * **CppBisonParser** adapter
  * **CppScanner** realisation of FileScanner interface


---

For each subsystem here is a list of unit tests.

Database:
  * EmptyCppInDirectory
  * NamescpaceInDirectory

DirectoryTree:
  * EmptyDirectory
  * NonExistentDirectory
  * Subdir
  * DirWithSVN
  * DirWithCpp
  * DirWithTxt
  * ParentDir
  * FullName

CommandLine:
  * Usage
  * Scan
  * WrongArgsNumber

SaveDatabase
  * DatabaseSave

ToCSV
  * Name

Cpp parser :
  * EmptyContent
  * OneNamespace
  * NestedNamespace
  * AnonymouseNamespace
  * FunctionDeclaration
  * FunctionInNamespace
  * QualifiedFunction
  * UnQualifiedFunction
  * UnQualifiedNamespaceFunction
  * QualifiedParameter
  * QualifiedReturnType
  * PointerReturnType
  * ReferenceType
  * ConstType
  * ConstPointerType
  * FunctionDefinition (body is not parsed and is recognized lexycally, as one token)
  * FunctionBrackets
  * LineComment
  * LineCommentInFunction
  * StreamComment
  * StreamCommentInFunction
  * ClassForwardDeclaration
  * StructForwardDeclaration
  * NamespaceForwardDeclaration
  * EmptyClassDefinition
  * ClassMethodDefinition (body is not parsed and is recognized lexycally, as one token)
  * ClassMethodDeclaration
  * InnerClassDeclaration
  * ConstClassMethodDeclaration
  * EnumDeclaration (body is not parsed and is recognized lexycally, as one token)
  * UnionDeclaration (body is not parsed and is recognized lexycally, as one token)
  * DefaultClassAccess
  * DefaultStructAccess
  * DefaultInnerStructAccess
  * PublicPrivateProtected
  * PublicPrivateProtectedWithSpaces
  * ClassInheritance
  * ClassPublicInheritance
  * StructInheritance
  * StructPrivateInheritance
  * VirtualClassMethod
  * ClassVirtualInheritance
  * AbstractClassMethod
  * FuctionLevelException
  * FriendClassDeclaration
  * FriendFunctionDeclaration
  * TypedefDeclaration
  * FunctionTemplate
  * ClassTemplate
  * ClassTemplateDefault
  * TemplatedType
  * TemplateTemplateParameter
  * NestedTemplatedType
  * PreprocessorDirective
  * PreprocessorMultilineDirective
  * FileVariable
  * InitIntConstant
  * InitFloatConstant
  * InitStringConstant
  * InitAssign
  * InitBlock
  * ArrayType
  * UnspecifiedArrayType
  * ArrayTypeInit
  * UnspecifiedArrayTypeInit

**Unit tests: Passed/Total: 86/86**

  * switch build system to [cmake](http://en.wikipedia.org/wiki/Cmake)

# Planned  features #

Refactoring:
  * test in [cygwin](http://en.wikipedia.org/wiki/Cygwin), [mingw/msys](http://en.wikipedia.org/wiki/Mingw) and [linux](http://en.wikipedia.org/wiki/Linux) environment
  * switch CPP parser design from recogintion-and-action to syntax-tree-and-visitors

Infrastructure:
  * Add version numbering
  * package distribution with [cpack](http://en.wikipedia.org/wiki/Cpack)

CommandLine:
  * Version

CppParser:

FileScanner:
  * FixDeclarationPlace
  * FixDefinitionPlace