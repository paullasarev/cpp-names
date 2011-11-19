#ifndef NAME_INFO_H
#define NAME_INFO_H

#include <set>
#include <string>
#include <iostream>

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
      NAME_UNION,
    } Type;
    bool Qualified;
    bool IsConst;
    enum NameAccess
    {
      ACCESS_PUBLIC,
      ACCESS_PRIVATE,
      ACCESS_PROTECTED,
    } Access;

    NameInfo(): Type(NAME_SYMBOL), Qualified(false), Access(ACCESS_PUBLIC)
    {
    }

    NameInfo(const std::string pName)
      : Name(pName), Type(NAME_SYMBOL), Qualified(false), Access(ACCESS_PUBLIC)
    {
    }

    NameInfo(const std::string pName, NameType type)
      : Name(pName), Type(type), Qualified(false), Access(ACCESS_PUBLIC)
    {
    }

    //NameInfo(const NameInfo& info)
    //  : Name(info.Name), Type(info.Type), Qualified(info.Qualified), IsConst(info.IsConst)
    //{
    //}

    bool operator<(const NameInfo& other) const
    {
       return Name < other.Name;
    }
  };

  typedef std::set<NameInfo> NameInfoSet;

  bool FindNameInfo(NameInfoSet& names, const std::string name, NameInfo &info);

  struct NameToCSV
  {
    NameToCSV(std::ostream& out);
    void operator()(const NameInfo& info);

  private:
    std::ostream& Out;
  };

}

#endif