#ifndef NAME_INFO_H
#define NAME_INFO_H

#include <set>
#include <string>
#include <iostream>
#include <vector>
#include <list>

namespace CppNames
{
  struct NameInfo
  {
    std::string Name;
    enum NameType
    {
      NAME_SYMBOL,
      NAME_NAMESPACE,
      NAME_FUNCTION,
      NAME_TYPE,
      NAME_CLASS,
      NAME_STRUCT,
      NAME_ENUM,
      NAME_UNION
    } 
    Type;

    bool Qualified;
    bool IsConst;
    bool IsVirtual;
    bool IsAbstract;

    enum NameAccess
    {
      ACCESS_PUBLIC,
      ACCESS_PRIVATE,
      ACCESS_PROTECTED
    } Access;
    
    std::list<NameInfo> Parents;

    NameInfo(): Type(NAME_SYMBOL), Qualified(false), Access(ACCESS_PUBLIC)
      , IsConst(false), IsVirtual(false), IsAbstract(false)
    {
    }

    NameInfo(const std::string pName)
      : Name(pName), Type(NAME_SYMBOL), Qualified(false), Access(ACCESS_PUBLIC)
      , IsConst(false), IsVirtual(false), IsAbstract(false)
    {
    }

    NameInfo(const std::string pName, NameType type)
      : Name(pName), Type(type), Qualified(false), Access(ACCESS_PUBLIC)
      , IsConst(false), IsVirtual(false), IsAbstract(false)
    {
    }

    bool operator<(const NameInfo& other) const
    {
       return Name < other.Name;
    }

    bool operator==(const NameInfo& other) const
    {
       return Name == other.Name;
    }
  };

  typedef std::set<NameInfo> NameInfoSet;
  typedef std::list<NameInfo> NameInfoList;

  bool FindNameInfo(NameInfoSet& names, const std::string name, NameInfo &info);
  bool FindNameInfo(NameInfoList& names, const std::string name, NameInfo &info);

  struct NameToCSV
  {
    NameToCSV(std::ostream& out);
    void operator()(const NameInfo& info);

  private:
    std::ostream& Out;
  };

}

#endif