//
// Created by ycpang on 2021/1/12.
//

#include "say.h"

int main(int argc, char *argv[]) {
    extern Say librarysay;
    auto localSay = Say("Local instance of Say");
    sayHello();
    librarysay.sayThis("howdy");
    librarysay.sayString();
    localSay.sayString();
    return (0);
}
