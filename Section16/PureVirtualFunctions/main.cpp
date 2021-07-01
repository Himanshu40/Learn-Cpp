// Pure virtual functions and abstract base classes
#include <iostream>
#include <vector>

// Abstract Shape Class
class Shape {
    public:
        virtual void draw() = 0;        // pure virtual function
        virtual void rotate() = 0;      // pure virtual function
        virtual ~Shape() { }
};

// Abstract OpenShape Class because no method overriding
class OpenShape : public Shape {
    public:
        virtual ~OpenShape() { }
};

// Abstract ClosedShape Class because no method overriding
class ClosedShape : public Shape {
    public:
        virtual ~ClosedShape() {}
};

// Concrete Line Class
class Line : public OpenShape {
    public:
        virtual void draw() override {
            std::cout << "Drawing a line" << std::endl;
        }

        virtual void rotate() override {
            std::cout << "Rotating a line" << std::endl;
        }

        virtual ~Line() { }
};

// Concrete Circle Class
class Circle : public ClosedShape {
    public:
        virtual void draw() override {
            std::cout << "Drawing a circle" << std::endl;
        }

        virtual void rotate() override {
            std::cout << "Rotating a circle" << std::endl;
        }

        virtual ~Circle() { }
};

// Concrete Square Class
class Square : public ClosedShape {
    public:
        virtual void draw() override {
            std::cout << "Drawing a square" << std::endl;
        }

        virtual void rotate() override {
            std::cout << "Rotating a square" << std::endl;
        }

        virtual ~Square() {}
};

void screenRefresh(std::vector<Shape *> &shapes) {
    std::cout << "Refreshing" << std::endl;

    for (const auto p : shapes) {
        p->draw();
    }
}

int main() {
    // Shape s;                                 // Can't instantiate object of abstract class
    // Shape *p = new Shape();                  // Can't instantiate object of abstract class
    // OpenShape s1;                            // Can't instantiate object of abstract class
    // OpenShape *ptr = new OpenShape();        // Can't instantiate object of abstract class
    // ClosedShape s2;                          // Can't instantiate object of abstract class
    // ClosedShape *ptr1 = new ClosedShape();   // Can't instantiate object of abstract class

    // Circle c;
    // c.draw();            // Statically bound

    Shape *ptr = new Circle();
    ptr->draw();            // Dynamically bound
    ptr->rotate();          // Dynamically bound

    Shape *s1 = new Circle();
    Shape *s2 = new Square();
    Shape *s3 = new Line();

    std::vector<Shape *> shapes {s1, s2, s3};

    screenRefresh(shapes);

    delete s1;
    delete s2;
    delete s3;

    return 0;
}
