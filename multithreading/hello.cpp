#include <iostream>
#include <thread>

void print(int n, const std::string &str) {
    std::cout << n << std::endl;
    std::cout << str << std::endl;
}

int main() {
    std::thread t1(print, 10, "hi");
    return 0;
}