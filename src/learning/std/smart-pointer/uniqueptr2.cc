#include <dirent.h>

#include <cerrno>
#include <cstring>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class DirCloser {
public:
    void operator()(DIR *dp) {
        if (closedir(dp) != 0) {
            cerr << "OOPS: closedir() failed" << endl;
        }
    }
};

int main() {
    unique_ptr<DIR, DirCloser> pDir(opendir("."));
    struct dirent *dp;
    while ((dp = readdir(pDir.get())) != nullptr) {
        string filename(dp->d_name);
        cout << "process " << filename << endl;
    }
    return 0;
}