#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Person : public std::enable_shared_from_this<Person> {
public:
    string             name;
    shared_ptr<Person> mother;
    shared_ptr<Person> father;

    vector<weak_ptr<Person>> kids;
    void setParentsAndTheirKids(shared_ptr<Person> m = nullptr,
                                shared_ptr<Person> f = nullptr) {
        mother = m;
        father = f;
        if (m != nullptr) {
            // without extends enable_shared_from_this, cannot create new
            // shared_ptr from *this*
            // m->kids.push_back(shared_ptr<Person>(this)); // ERROR
            m->kids.push_back(shared_from_this());  // OK
        }
        if (f != nullptr) {
            f->kids.push_back(shared_from_this());
        }
    }
};