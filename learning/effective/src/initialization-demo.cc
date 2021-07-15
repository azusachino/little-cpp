#include <list>
#include <string>

class PhoneNumber
{
};

class AddressEntry
{
public:
    AddressEntry(const std::string &name, const std::string &address,
                 const std::list<PhoneNumber> &phones);

private:
    std::string name;
    std::string address;
    std::list<PhoneNumber> phones;
    int numTimesConsulted;
};

// assignment
AddressEntry::AddressEntry(const std::string &name, const std::string &address,
                           const std::list<PhoneNumber> &phones)
{
    this->name = name;
    this->address = address;
    this->phones = phones;
    this->numTimesConsulted = 0;
}

// initialization (member initialization list) 效率更高
AddressEntry::AddressEntry(const std::string &name, const std::string &address,
                           const std::list<PhoneNumber> &phones)
    : name(name), address(address), phones(phones), numTimesConsulted(0) {}

// 文件系统API定义
class FileSystem
{
public:
    std::size_t numDisks() const;
};

extern FileSystem tfs; // 给外界使用的对象

// 用户使用
class Directory
{
public:
    Directory();
};
// 两个源文件中的对象，不确定哪一个先行初始化
Directory::Directory()
{
    std::size_t disks = tfs.numDisks(); // 使用tfs对象
}

class FileSystemNew
{
public:
    FileSystemNew &ntfs()
    {
        static FileSystemNew fs;
        return fs;
    }
    std::size_t numDisks() const;
};

// 用户使用
class DirectoryNew
{
public:
    DirectoryNew();
};
// 两个源文件中的对象，不确定哪一个先行初始化
DirectoryNew::DirectoryNew()
{
    // std::size_t disks = ntfs().numDisks(); // 使用tfs对象
}
DirectoryNew &tempDir()
{
    static DirectoryNew dir;
    return dir;
}