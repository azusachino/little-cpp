#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string word, line;

    cout << "please choose how to read string: 1. per word, 2. per line" << endl;
    char ch;
    cin >> ch;
    if (ch == '1') {
        cout << "please input: Welcome to C++ family! " << endl;
        cin >> word;
        cout << "valid string are: " << word << " " << endl;
    } else {
        cin.clear();
        cin.sync();
        cout << "please input: Welcome to C++ family! " << endl;
        getline(cin, line);
        cout << "valid string are: " << line << " " << endl;
    }
    return 0;
}

void cmpString() {
    string s1, s2;
    cout << "please input two string: " << endl;
    cin >> s1 >> s2;
    auto len1 = s1.size();
    auto len2 = s2.size();
    if (len1 == len2) {
        cout << "of same length" << endl;
    } else if (len1 > len2) {
        cout << "s1 is larger than s2" << endl;
    } else {
        cout << "s2 is larger than s1" << endl;
    }
}

void replace() {
    string s;
    cout << "please input a string, can include space: " << endl;
    getline(cin, s);
    // 一是利用auto关键字推断字符串中每一个元素的类型；二是c必须定义为引用类型，否则无法修改字符串内容。
    for (auto &c : s) // auto可以换成char
    {
        c = 'X';
    }

    // using while
    int i = 0;
    while (s[i] != '\0') {
        s[i] = 'X';
        ++i;
    }

    // using for original version
    for (unsigned int i = 0; i < s.size(); i++) {
        s[i] = 'X';
    }
    cout << s << endl;
}

void replacePunct() {
    string s;
    getline(cin, s);
    for (auto c : s) {
        if (!ispunct(c)) {
            cout << c;
        }
        cout << endl;
    }
}