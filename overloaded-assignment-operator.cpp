#include <iostream>
#include <string>
#include <utility>

/*
 * Assignment Operator
 */
class IntHolder {
public:
    IntHolder(int x)
        : x_(x) {}

    IntHolder(const IntHolder& other) : x_(other.x_) {}  // copy constructor

    void swap(IntHolder& other) {
        std::swap(x_, other.x_);
    }

    IntHolder& operator=(const IntHolder& other) {
        if (this == &other) return *this; // check if not the same instance
        x_ = other.x_;
        return *this;
    }

//    IntHolder& operator=(IntHolder other) { // checking is done by the swap func
//        swap(other);
//        return *this;
//    }

    int value() const { return x_; }
private:
    int x_ = 0;
};

int main() {

    IntHolder a(10);
    IntHolder b(20);

    a = b;

    b.operator=(a);
    std::cout << "a: " << a.value() << ", b: " << b.value() << std::endl;

    return 0;
}
