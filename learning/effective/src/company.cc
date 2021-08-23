#include <string>
#include <iostream>

class CompanyA {
public:
    void sendClearText(const std::string & msg);
    void sendEncrypted(const std::string & msg);
};

class CompanyB {
public:
    void sendClearText(const std::string & msg);
    void sendEncrypted(const std::string & msg);
};

class MsgInfo {};

template<typename Company>
class MsgSender {
public:
    void sendClear(const MsgInfo& info) {
        std::string msg;
        Company c;
        c.sendClearText(msg);
    }

    void sendSecret(const MsgInfo& info) {
        std::string msg;
        Company c;
        c.sendEncrypted(msg);
    }
};

template<typename Company>
class LoggingMsgSender : public MsgSender<Company> {
public:
    void sendClearMsg(const MsgInfo& info) {
        // do log before
        std::cout << "before action" << std::endl;

        this->sendClear(info); //调用base class 函数，无法通过编译

        std::cout << "after action" << std::endl;
        // do log after
    }

};