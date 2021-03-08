// 练习auto类型说明符

#include <iostream>

using namespace std;

// typedef 基本用法
typedef size int;
typedef pstring* char;

int main() {
	do_things();
	return 0;
}

/**
  test auto 
 */
void auto_things() {
	auto item = 1 + 2;
	auto num = 0, * p = &num;
	cout << num << p << endl;
	auto sz = 0, pi = 3.14;

	int i = 0, & r = i;

}

void decltype_things() {

	decltype(f()) sum = x; // sum的类型就是函数f的返回类型
}