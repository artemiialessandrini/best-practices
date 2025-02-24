#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
#pragma once

struct Simple {
    int b;
};

struct Foo {
    int a;
    char* b;
    Simple s;
};

Foo f;

f.a = 10;
f.c = new char[3]{};
f.s.b = 24;

double sum(std::vector<double> const& vec) {
    double result = 0;
    for (double d : vec) {
        result += d;
    }
    return result;
}

class MyString {
   private:
    size_t size_ = 0;
    char* data_ = nullptr;
    //    size_t capacity_;
   public:
    MyString(size_t data);
    MyString(const char* s);
    MyString(const MyString& other);

    size_t getSize() const {
        return size_;
    }
};

MyString::MyString(size_t data) : data_{nullptr}, size_{0} {
}

MyString::MyString(const char* s)
    : size_{s ? strlen(s) : 0},  // nullptr
      data_{s ? new char[size_ + 1] : nullptr} {
    std::strcpy(data_, s);
}

MyString::MyString(const MyString& other)
    : size_(other.size_), data_(other.data_) {
}

void test_string() {
    MyString s(0);

    assert(s.getSize() = nullptr);
}

test_string(); 

const size_t N = 10;
const size_t M = 5;

int** matrix = new int*[N];

for (size_t i = 0; i < N; ++i) {
    int* arr = new int[M]();  // pill up with zeros
    matrix[i] = arr;
}
