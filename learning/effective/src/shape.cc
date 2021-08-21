class Shape {
public:
    enum ShapeColor {Red, Green, Blue};
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

int main() 
{
Shape* ps;
Shape* pc = new Circle;
Shape* pr = new Rectangle;

pc->draw(Shape::Red);
pr->draw(Shape::Red);

pr->draw(); // call Rectangle::draw(Shape::Red);
}
