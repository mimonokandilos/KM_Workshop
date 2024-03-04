#include <iostream>

class Shape {
public:
    virtual void draw() {
        std::cout << "Drawing a shape" << std::endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle" << std::endl;
    }
};

int main() {
    Shape* shape = new Circle();
    shape->draw();

    delete shape;

    return 0;
}

