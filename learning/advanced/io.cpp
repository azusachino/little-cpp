//
// Created by ycpang on 2021-02-01.
//

// void open(const char *filename, ios::openmode mode);

#include <fstream>
#include <iostream>

using namespace std;

int main() {
    char data[100];

    // 以写模式打开文件
    ofstream outfile;
    outfile.open("afile.dat");

    cout << "Writing to the file" << endl;
    cout << "Enter your name: ";
    cin.getline(data, 100);

    // 向文件写入用户输入的数据
    outfile << data << endl;

    cout << "Enter your age: ";
    cin >> data;
    cin.ignore();

    // 再次向文件写入用户输入的数据
    outfile << data << endl;

    // 关闭打开的文件
    outfile.close();

    // 以读模式打开文件
    ifstream infile;
    infile.open("afile.dat");

    cout << "Reading from the file" << endl;
    infile >> data;

    // 在屏幕上写入数据
    cout << data << endl;

    // 再次从文件读取数据，并显示它
    infile >> data;
    cout << data << endl;

    // 关闭打开的文件
    infile.close();

    return 0;
}

//向文件内部写入数据，并将数据读出
void file_wr(void) {
    char data[100];
    //向文件写入数据
    ofstream outfile;
    outfile.open("test.txt");
    cout << "Write to the file" << endl;
    cout << "Enter your name:" << endl;
    cin.getline(data, 100);
    outfile << data << endl;
    cout << "Enter your age:" << endl;
    cin >> data;
    cin.ignore();
    outfile << data << endl;
    outfile.close();
    //从文件读取数据
    ifstream infile;
    infile.open("test.txt");
    cout << "Read from the file" << endl;
    infile >> data;
    cout << data << endl;
    infile >> data;
    cout << data << endl;
    infile.close();
}

//将数据从一文件复制到另一文件中
void file_copy(void) {
    char     data[100];
    ifstream infile;
    ofstream outfile;
    infile.open("test.txt");
    outfile.open("test_1.txt");
    cout << "copy from test.txt to test_1.txt" << endl;
    while (!infile.eof()) {
        infile >> data;
        cout << data << endl;
        outfile << data << endl;
    }
    infile.close();
    outfile.close();
}

//测试上述读写文件，与文件数据复制
int _tmain(int argc, char32_t *argv[]) {
    file_wr();
    file_copy();
    return 0;
}