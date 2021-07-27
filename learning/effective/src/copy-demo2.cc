#include <string>

void logCall(const std::string& funcName);

class Date{};
class Customer {
public:
    Customer(const Customer& rhs);
    Customer& operator=(const Customer& rhs);
private:
    std::string name;
    Date lastTransaction;
};

Customer::Customer(const Customer& rhs): name(rhs.name) {
    logCall("Customer copy constructor");
}

Customer& Customer::operator=(const Customer& rhs) {
    logCall("Customer copy assignment operator");
    name = rhs.name;
    return *this;
}

class PriorityCustomer : public Customer {
public:
    PriorityCustomer(const PriorityCustomer& rhs);
    PriorityCustomer& operator=(const PriorityCustomer& rhs);
private:
    int priority;
};

// no default constructor for class Customer
PriorityCustomer::PriorityCustomer(const PriorityCustomer& rhs): priority(rhs.priority), Customer(rhs) {
    logCall("PriorityCustomer copy constructor");
}

PriorityCustomer& PriorityCustomer::operator=(const PriorityCustomer& rhs) {
    logCall("PriorityCustomer copy assignment operator");
    Customer::operator=(rhs); // assign base class
    priority = rhs.priority;
    return *this;
}
