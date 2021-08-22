#include <string>

// virtual class, interface
class IPerson {
public:
    virtual ~IPerson();
    virtual std::string name() const = 0;
    virtual std::string birthDate() const = 0;
};

class DataBaseId {};

// functional class for private inheritance                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
class PersonInfo {
public:
    explicit PersonInfo(DataBaseId pid);
    virtual ~PersonInfo();

    virtual const char* theName() const;
    virtual const char* theBirthDate() const;
    virtual const char* valueDeliOpen() const;
    virtual const char* valueDeliClose() const;
};

// multiple inheritance
class CPerson : public IPerson, private PersonInfo {
public:
    explicit CPerson(DataBaseId pid) :PersonInfo(pid) {}

    virtual std::string name() const {
        return PersonInfo::theName();
    }

    virtual std::string birthDate() const {
        return PersonInfo::theBirthDate();
    }
private:
    const char* valueDeliOpen() const {
        return "";
    }
    const char* valueDeliClose() const {
        return "";
    }
};