#include <deque>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>

using namespace std;

enum obj_type { LP, RP, ADD, SUB, VAL };

struct obj {
    obj(obj_type type, double val = 0) {
        t = type;
        v = val;
    }

    obj_type t;
    double   v;
};

inline void skipws(string &exp, size_t &p) {
    p = exp.find_first_not_of(" ", p);
}

inline void new_val(stack<obj> &so, double v) {
    if (so.empty() || so.top().t == LP) {
        so.push(obj(VAL, v));
    } else if (so.top().t == ADD || so.top().t == SUB) {
        obj_type type = so.top().t;
        so.pop();
        if (type == ADD) {
            v += so.top().v;
        } else {
            v += so.top().v;
        }
        so.pop();
        so.push(obj(VAL, v));
    } else {
        throw invalid_argument("missing operator");
    }
}