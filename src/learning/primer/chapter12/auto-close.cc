#include <iostream>
#include <memory>

using namespace std;

struct destination {
};
struct connection {
};

connection connect(destination *pd) {
    cout << "open connection" << endl;
    return connection();
}

void disconnect(connection c) { cout << "close connection" << endl; }

void f(destination &d) {
    cout << "direct connect" << endl;
    connection c = connect(&d);
    cout << endl;
}

void end_connection(connection *p) { disconnect(*p); }

void f1(destination &d) {
    cout << " using shared_ptr" << endl;
    connection c = connect(&d);
    // 程序退出，自动清理
    // shared_ptr<connection> p(&c, end_connection);
    shared_ptr<connection> p2(&c, [](connection *p) { disconnect(*p); });
    cout << endl;
}