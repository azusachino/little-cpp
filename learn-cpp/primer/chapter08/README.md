# C++ Primer Chapter08

- stream（输入流）类型，提供输入操作。
- ostream（输出流）类型，提供输出操作。
- cin，一个istream对象，从标准输入读取数据
- cout，一个ostream对象，向标准输出写入数据
- cerr，一个ostream对象，通常用于输出程序错误消息，写入到标准错误。
- `>>`运算符，用来从一个istream对象读取输入数据。
- `<<`运算符，用来向一个ostream对象写入输出数据。
- getline函数（参见3.3.2节，第78页），从一个给定的istream读取一行数据，存入一个给定的string对象中。

## IO类

- iostream：iostream定义了用于读写流的基本类型
- fstream：fstream定义了读写命名文件的类型
- sstream：sstream定义了读写内存string对象的类型

### IO对象无拷贝或赋值

```c++
ofstream out1, out2;
out1 = out2; // 错误，不能对流对象赋值
ofstream print(ofstream); // 错误，不能初始化ofstream参数
out2 = print(out2); // 错误，不能拷贝流对象
```

### 条件状态

![.](../../../resources/istream-status.png)

### 管理输出缓冲

导致缓冲刷新的原因：

- 程序正常结束，作为main函数的return操作的一部分，缓冲刷新被执行。
- 缓冲区满时，需要刷新缓冲，而后新的数据才能继续写入缓冲区。
- 我们可以使用操纵符如endl来显式刷新缓冲区。
- 在每个输出操作之后，我们可以用操纵符unitbuf设置流的内部状态，来清空缓冲区。默认情况下，对cerr是设置unitbuf的，因此写到cerr的内容都是立即刷新的。
- 一个输出流可能被关联到另一个流。在这种情况下，当读写被关联的流时，关联到的流的缓冲区会被刷新。例如，默认情况下，cin和cerr都关联到cout。因此，读cin或写cerr都会导致cout的缓冲区被刷新。

```c++
cout << "Hi" << endl; // 输出hi和换行，然后刷新缓冲区
cout << "hi" << flush; // 输出hi，然后刷新缓冲区
cout << "hi" << ends; // 输出hi和一个空字符串，然后刷新缓冲区

cout << unitbuf; //所有输出操作后都会立即刷新缓冲区
cout << nounitbuf; // 回到正常的缓冲方式
```

## 文件输入输出

头文件fstream定义了三个类型来支持文件IO：ifstream从一个给定文件读取数据，ofstream向一个给定文件写入数据，以及fstream可以读写给定文件

### 使用文件流对象

```c++
ifstream input(argv[1]);
ofstream output(argv[2]);

Sales_data total;

if (read(input, total)) {
    Sales_data trans;
    while(read(input, trans)) {
        if (total.isbn() == trans.isbn()) {
            total.combine(trans);
        } else {
            print(output, total) << endl; 
            total = trans;
        }
    }
    print(output, total) << endl;
} else {
    cerr << "no data" << endl;
}
```

### 文件模式

- in：只读
- out：只写
- app：append
- ate：打开文件后立即定位到文件末尾
- trunc：截断文件
- binary：以二进制方式进行IO

## string流

istringstream从string读取数据，ostringstream向string写入数据，而头文件stringstream既可从string读数据也可向string写数据。

### 使用istringstream

```c++
struct PersonInfo{
    string name;
    vector<string> phones;
}

string line, word;
vector<PersonInfo> people;
while(getline(cin, line)) {
    PersonInfo pi;
    istringstream record(line);
    record >> info.name;
    while (record >> word) {
        info.phones.push_back(word);
    }
    people.push_back(info);
}
```

### 使用ostringstream

```c++
for (const auto &entry : people) {
    ostringstream formatted, badNums;
    for (const auto &nums: entry.phones) {
        if (!valid(nums)) {
            badNums << "" << nums;
        } else {
            formatted << "" << format(nums);
        }
    }
    if (badNums.str().empty()) {
        os << entry.name << "" << formatted.str() << endl;
    } else {
        cerr << "input error: " << entry.name << badNums.str() << endl;
    }
}
```
