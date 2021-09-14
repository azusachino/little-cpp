// Template
class GameCharacter {
public:
    int healthValue() const {
        // do works before
        int retVal = doHealthValue();
        // do works after
        return retVal;
    }
private:
    // 直接在class定义式内呈现成员函数本体 => inline
    virtual int doHealthValue() const {
        return 0;
    }
};

// forward declaration
class GameCharacter;

int defaultHealthCalc(const GameCharacter& gc);

// Strategy
class GameCharacter {
public:
    typedef int (*HealthCalcFunc) (const GameCharacter&);

    explicit GameCharacter(HealthCalcFunc hcf = defaultHealthCalc) : healthFunc(hcf) {}

    int healthValue() {
        return healthFunc(*this);
    }
private:
    HealthCalcFunc healthFunc;
};

class EvilBadGuy : public GameCharacter {
public:
    explicit EvilBadGuy(HealthCalcFunc hcf = defaultHealthCalc) : GameCharacter(hcf) {}
};

int loseHealthQuickly(const GameCharacter&);
int loseHealthSlowly(const GameCharacter&);

EvilBadGuy softEnemy(loseHealthQuickly);
EvilBadGuy toughEnemy(loseHealthSlowly);
