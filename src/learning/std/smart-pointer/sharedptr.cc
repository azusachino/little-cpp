#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

// basic usage of shared_ptr
void basic() {
    // nina  nina  Nico  nina  Nico
    // nina  nina  Nicole  nina  Nicole
    // use_count: 4
    shared_ptr<string> pNico(new string("nico"));
    shared_ptr<string> pNina(new string("nina"));

    (*pNico)[0] = 'N';

    vector<shared_ptr<string>> people;
    people.push_back(pNina);
    people.push_back(pNina);
    people.push_back(pNico);
    people.push_back(pNina);
    people.push_back(pNico);

    for (auto ptr: people) {
        cout << *ptr << "  ";
    }
    cout << endl;

    *pNico = "Nicole";

    for (auto ptr: people) {
        cout << *ptr << "  ";
    }
    cout << endl;

    // print the pointer usage count
    cout << "use_count: " << people[0].use_count() << endl;
}

// reset a shared_ptr
void reset() {
    shared_ptr<string> pico;
    // pico = new string("nico"); // Error: no assignment for ordinary pointers
    pico.reset(new string("pico"));
    (*pico)[0] = 'N';
    // -> for pointer
    pico->replace(0, 1, "J");

    string a("hello");
    // . for origin obj
    a.replace(0, 1, "H");
}

// hook before destroy
void deleter() {
    // source obj & deleter
    shared_ptr<string> pNico(new string("nico"), [](string *p) {
        cout << "delete " << *p << endl;
        delete p;
    });
    // before destroy, trigger deleter()
    pNico = nullptr;
}

void deleteArray() {
    // error
    shared_ptr<int> p(new int[10]);

    shared_ptr<int> p1(new int[10], [](int *p) { delete[] p; });
    shared_ptr<int> p2(new int[10], std::default_delete<int[]>());
}

// g++ xx.cc -o yy
int main() {
    deleter();
    return 0;
}
