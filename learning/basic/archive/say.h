//
// Created by ycpang on 2021/1/12.
//

#ifndef LITTLE_CPP_SAY_H
#define LITTLE_CPP_SAY_H

#include <iostream>

void sayHello();

class Say {
private:
    char *string;

public:
    Say(char *str) { string = str; }

    void sayThis(const char *str) {
        std::cout << str << " from a static library\n";
    }

    void sayString();
};

#endif  // LITTLE_CPP_SAY_H
