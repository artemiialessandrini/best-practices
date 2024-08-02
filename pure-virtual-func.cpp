#include <iostream>
#include <string>

class Printable {
public:
    virtual std::string GetClassName() = 0;
};

class Entity : public Printable
{
public:
    /*
     * by = 0 we make an Interface so lower by hierarchy
     * classes have to reimplement this function for us
     */
    virtual std::string GetName() { return "Entity"; };
    std::string GetClassName () override { return "Entity"; }
};

class Person : public Entity
{
private:
    std::string m_Name;

public:
    Person(const std::string& name)
        : m_Name(name) {}

    std::string GetName() override { return m_Name; }
    std::string GetClassName () override { return "Person"; }

};

void GetName (Entity* entity) {
    std::cout << entity->GetName() << std::endl;
}

void Print (Printable* obj) {
    std::cout << obj->GetClassName() << std::endl;
}
int main() {
    Entity* e = new Entity();
//    GetName(e);


    auto* p = new Person("Artemii");
//    GetName(p);

    Print(e);
    Print(p);

    return 0;
}