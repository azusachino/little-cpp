#include <cstdio>
#include <fstream>
#include <memory>
#include <string>

using namespace std;

class FileDeleter {
private:
    string filename;

public:
    FileDeleter(const string& fn) : filename(fn) {}

    void operator()(ofstream* fp) {
        fp->close();               // close file
        remove(filename.c_str());  // delete file
    }
};

// g++ xx.cc -o yy
int main() {
    shared_ptr<ofstream> fp(new ofstream("tmp.txt"), FileDeleter("tmp.txt"));
    return 0;
}
