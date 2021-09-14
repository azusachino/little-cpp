class Shape {
public:
    enum ShapeColor { Red, Green, Blue };
    virtual void draw(ShapeColor color = Red) const = 0;
};

class Rectangle : public Shape {
public:
    virtual void draw(ShapeColor color = Green) const;
};

class Circle : public Shape {
public:
    virtual void draw(ShapeColor color) const;
};

int main() {
    Shape* ps;
    Shape* pc = new Circle;
    Shape* pr = new Rectangle;

    pc->draw(Shape::Red);
    pr->draw(Shape::Red);

    pr->draw();  // call Rectangle::draw(Shape::Red);
}

namespace demo {
class Shape {
public:
    enum ShapeColor { Red, Green, Blue };
    // non-virtual, must not override
    void draw(ShapeColor color = Red) { doDraw(color); }

private:
    virtual void doDraw(ShapeColor color) const = 0;
};

class Rectangle : public Shape {
private:
    virtual void doDraw(ShapeColor color) const;
};
}  // namespace demo