
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <ctime>

using namespace std;

// 声明
class test;

string Get_Current_Date();

void ioRelate();

void book();

void printBook(struct Books book);

void printBookRef(struct Books *book);

struct Books {
    char title[50];
    char author[50];
    char subject[100];
    int book_id;
};

typedef struct {
    char name[50];
    int age;
    char from[50];
} Student;

int main() {
    std::cout << "" << std::endl;
//    auto ptr = new shape;
//    delete ptr; // help gc
//    for (;;)
//        break;
    [] {}; // 最简单的lambda
    auto basicLambda = [] { cout << "Hello Lambda!" << endl; };

    basicLambda();

    std::vector<int> v = {1, 2, 3, 4, 5};
    int even_count = 0;
    std::count_if(v.begin(), v.end(), [&even_count](int val) {
        if (!(val & 1)) {
            ++even_count;
        }
    });
    // 数字定义
    short s = 10;
    int i = -1000;
    long l = 100000;
    float f = 230.47;
    double d = 200.374;

    // 数学运算
    cout << "sin(d) :" << sin(d) << endl;
    cout << "abs(i)  :" << abs(i) << endl;
    cout << "floor(d) :" << floor(f) << endl;
    cout << "sqrt(f) :" << sqrt(l) << endl;
    cout << "pow( d, 2) :" << pow(s, 2) << endl;

    // 数组
    double balance[10];
    double another[] = {1.2, 3, 2, 3};

    // 字符串
    char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char greet[] = "Hello";

    char str1[11] = "Hello";
    string string1 = "Hello";
    char str2[11] = "World";
    char str3[11];
    int len;

    // 复制 str1 到 str3
    strcpy(str3, str1);
    cout << "strcpy( str3, str1) : " << str3 << endl;

    // 连接 str1 和 str2
    strcat(str1, str2);
    cout << "strcat( str1, str2): " << str1 << endl;

    // 连接后，str1 的总长度
    len = strlen(str1);
    cout << "strlen(str1) : " << len << endl;

    int var = 10;
    int *varPtr;

    varPtr = &var;

    cout << varPtr << endl;
    // 基于当前系统的当前日期/时间
    time_t now = time(0);

    // 把 now 转换为字符串形式
    char *dt = ctime(&now);

    cout << "本地日期和时间：" << dt << endl;

    // 把 now 转换为 tm 结构
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    cout << "UTC 日期和时间：" << dt << endl;

    char name[50];
    cout << "请输入您的名字: ";
    cin >> name;
    cout << "您的名字是 " << name << endl;
}

class test {
public:
    test() = default;

    ~test() = default;

    void hello() {

        int *ptr = nullptr;
        cout << "test hello!\n";
    };

    void lambda() {
        auto fun = [this] { // 捕获了 this 指针
            this->hello(); // 这里 this 调用的就是 class test 的对象了
        };
        fun();
    }
};


string Get_Current_Date() {
    time_t nowtime;
    nowtime = time(nullptr); //获取日历时间
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&nowtime));
    return tmp;
};

void ioRelate() {

    // setiosflags(ios::fixed) 固定的浮点显示
    // setiosflags(ios::scientific) 指数表示
    // setiosflags(ios::left) 左对齐
    // setiosflags(ios::right) 右对齐
    // setiosflags(ios::skipws 忽略前导空白
    // setiosflags(ios::uppercase) 16进制数大写输出
    // setiosflags(ios::lowercase) 16进制小写输出
    // setiosflags(ios::showpoint) 强制显示小数点
    // setiosflags(ios::showpos) 强制显示符号
    cout << setiosflags(ios::left | ios::showpoint);  // 设左对齐，以一般实数方式显示
    cout.precision(5);       // 设置除小数点外有五位有效数字
    cout << 123.456789 << endl;
    cout.width(10);          // 设置显示域宽10
    cout.fill('*');          // 在显示区域空白处用*填充
    cout << resetiosflags(ios::left);  // 清除状态左对齐
    cout << setiosflags(ios::right);   // 设置右对齐
    cout << 123.456789 << endl;
    cout << setiosflags(ios::left | ios::fixed);    // 设左对齐，以固定小数位显示
    cout.precision(3);    // 设置实数显示三位小数
    cout << 999.123456 << endl;
    cout << resetiosflags(ios::left | ios::fixed);  //清除状态左对齐和定点格式
    cout << setiosflags(ios::left | ios::scientific);    //设置左对齐，以科学技术法显示
    cout.precision(3);   //设置保留三位小数
    cout << 123.45678 << endl;
}

void book() {
    Books Book1{};        // 定义结构体类型 Books 的变量 Book1
    Books Book2{};        // 定义结构体类型 Books 的变量 Book2

    // Book1 详述
    strcpy(Book1.title, "C++ 教程");
    strcpy(Book1.author, "Runoob");
    strcpy(Book1.subject, "编程语言");
    Book1.book_id = 12345;

    // Book2 详述
    strcpy(Book2.title, "CSS 教程");
    strcpy(Book2.author, "Runoob");
    strcpy(Book2.subject, "前端技术");
    Book2.book_id = 12346;

    // 输出 Book1 信息
    cout << "第一本书标题 : " << Book1.title << endl;
    cout << "第一本书作者 : " << Book1.author << endl;
    cout << "第一本书类目 : " << Book1.subject << endl;
    cout << "第一本书 ID : " << Book1.book_id << endl;

    // 输出 Book2 信息
    cout << "第二本书标题 : " << Book2.title << endl;
    cout << "第二本书作者 : " << Book2.author << endl;
    cout << "第二本书类目 : " << Book2.subject << endl;
    cout << "第二本书 ID : " << Book2.book_id << endl;

    printBook(Book1);
    printBook(Book2);

    printBookRef(&Book1);
    printBookRef(&Book2);

    Student student{
            .name="aaa",
            .age=20,
            .from = "hefei"
    };
    Student *studentPtr = &student;
    cout << studentPtr->age;
    cout << student.age;

}

void printBook(struct Books books) {
    cout << "第二本书标题 : " << books.title << endl;
    cout << "第二本书作者 : " << books.author << endl;
    cout << "第二本书类目 : " << books.subject << endl;
    cout << "第二本书 ID : " << books.book_id << endl;
}

void printBookRef(struct Books *book) {
    cout << "书标题  : " << book->title << endl;
    cout << "书作者 : " << book->author << endl;
    cout << "书类目 : " << book->subject << endl;
    cout << "书 ID : " << book->book_id << endl;
}