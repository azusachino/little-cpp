#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream in("data");
    if (!in) {
        cerr << "can not open the file" << endl;
        return -1;
    }
    string         line;
    vector<string> words;

    while (getline(in, line)) {
        words.push_back(line);
    }

    in.close();

    vector<string>::const_iterator it = words.begin();
    while (it != words.end()) {
        cout << *it << endl;
        ++it;
    }
    return 0;
}

istream &f(istream &in) {
    string v;

    while (in >> v, !in.eof()) {
        if (in.bad()) {
            throw runtime_error("io exception");
        }
        if (in.fail()) {
            cerr << "data wrong" << endl;
            in.clear();
            in.ignore(100, '\n');
            continue;
        }
        cout << v << endl;
    }
    in.clear();
    return in;
}