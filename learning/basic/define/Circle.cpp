//
// 对头文件的定义进行实例化
// Created by ycpang on 2021/1/12.
//

#include "Circle.h"

Circle::Circle() { this->r = 5.0; }

Circle::Circle(double R) { this->r = R; }

double Circle::Area() { return 3.14 * r * r; }