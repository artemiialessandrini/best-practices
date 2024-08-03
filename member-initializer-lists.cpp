#include <iostream>
#include <string>

class Example
{
public:
    Example()
    {
        std::cout << "Created Entity" << std::endl;
    }

    Example(int x)
    {
        std::cout << "Created Entity with " << x << "!" << std::endl;
    }
};
class Enitity
{
private:
    std::string m_Name;
    int m_Score;
    Example m_Example;
public:
    /*
     * Use member initializer lists because it created two object of the class instance without it
     **/
    Enitity()
        : m_Name("Unknown"), m_Score(0), m_Example(8)
    {
    }
    Enitity(const std::string& name)
        : m_Name(name)
    {
    }

    const std::string& GetName() const { return  m_Name; }
};

int main() {


    Enitity e0;

//    std::cout << e0.GetName() << std::endl;
//    Enitity e1("hah");
//    std::cout << e1.GetName() << std::endl;
    return 0;
}