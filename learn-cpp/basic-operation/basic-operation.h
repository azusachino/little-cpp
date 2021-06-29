#ifndef LEARN_CPP_BASIC_OPERATE_H
#define LEARN_CPP_BASIC_OPERATE_H

/*class Obj{
public:
    // 构造函数
    Obj() {puts("Obj()");}
    // 析构函数
    ~Obj(){
     puts("~Obj()");
    }
};*/
enum class shape_type { circle, triangle, rectangle, square, oval };

class shape {};

class circle : public shape {};

class triangle : public shape {};

class oval : public shape {};

shape *create_shape(shape_type type) {
    switch (type) {
        case shape_type::square:
            return new circle();
        case shape_type::triangle:
            return new triangle();
        case shape_type::oval:
            return new oval();
        default:
            return nullptr;
    }
}

class shape_wrapper {
public:
    explicit shape_wrapper(shape *ptr = nullptr) : ptr_(ptr) {}

    ~shape_wrapper() { delete ptr_; }

    shape *get() const { return ptr_; }

private:
    shape *ptr_;
};

class BasicOperate {
private:
    char a;
    int  b;

public:
    double c;
    float  d;

    int print(char sth[]) {
        this->a = 'A';

        return a;
    }
};

#endif  // LEARN_CPP_BASICOPERATE_H
