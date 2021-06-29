//
// 头文件定义（声明，不需要实现具体逻辑）
// Created by ycpang on 2021/1/12.
//

#ifndef LITTLE_CPP_CIRCLE_H
#define LITTLE_CPP_CIRCLE_H

class Circle {
private:
    double r;  //半径
public:
    Circle();          //构造函数
    Circle(double R);  //构造函数
    double Area();     //求面积函数
};

#endif  // LITTLE_CPP_CIRCLE_H
