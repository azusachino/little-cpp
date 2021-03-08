//
// Created by ycpang on 2021/1/12.
//

#include "say.h"

int main_(int argc, char *argv[]) {
    extern Say librarysay;
    char something[] = {'a', 'b'};
    auto localSay = Say(something);
    sayHello();
    librarysay.sayThis("howdy");
    librarysay.sayString();
    localSay.sayString();
    return (0);
}
