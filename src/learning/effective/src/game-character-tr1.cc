#include <tr1/functional>

class GameCharacter;
int defaultHealthCalc(const GameCharacter&);

// tr1::function & Strategy
class GameCharacter {

public:
    typedef std::tr1::function<int (const GameCharacter&)> HealthCalcFunc;

    explicit GameCharacter(HealthCalcFunc hcf = defaultHealthCalc) : healthFunc(hcf) {}

    int healthValue() {
        return healthFunc(*this);
    }
private:
    HealthCalcFunc healthFunc;
};

short calcHealth(const GameCharacter&);
struct HealthCalculator {
    int operator() (const GameCharacter&) const {}
};
class GameLevel {
public:
    float health(const GameCharacter&) const;
};

class EvilBadGuy : public GameCharacter {};
class EyeCandyCharacter : public GameCharacter {};

// using function
EvilBadGuy ebg(calcHealth);

// using function object
EyeCandyCharacter ecc(HealthCalculator());

// using member function
GameLevel gameLevel;
EvilBadGuy ee(std::tr1::bind(&GameLevel::health, gameLevel, _1));