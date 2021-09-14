template <typename T>
class Rational {
public:
    Rational(const T& numerator = 0, const T& denominator = 1);
    const T numerator() const;
    const T denominator() const;
};

template<typename T>
const Rational<T> operator*(const Rational<T>& lhs, const Rational<T>& rhs) {

}

template <typename T>
class Rational {
public:
    Rational(const T& numerator = 0, const T& denominator = 1);
    const T numerator() const;
    const T denominator() const;
    friend 
    const Rational<T> operator*(const Rational<T>& lhs, const Rational<T>& rhs) {
        return nullptr;
    }
};

int main() {
    Rational<int> oneHalf(1,2);
    Rational<int> result = oneHalf * 2; // can't compile
}