#include <iostream>

class MyString {
   private:
    char* data_;
    size_t size_;

   public:
    MyString()
        : data_(nullptr), size_(0) {}
};
