#include <iostream>
#include <any>
#include <variant>

int main() {
    std::any data;
//    std::variant <int, std::string> data;
    data = 2;
    data = std::string("Chat");

//    std::string string = std::get<std::string>(data);
    auto& string = std::any_cast<std::string&>(data);

    std::cin.get();
}