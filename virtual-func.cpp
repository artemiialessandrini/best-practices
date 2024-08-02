#include <iostream>
#include <string>

class Enitity {
public:
    /*
     * virtual = generate a V-Table for this function
     * so if it's overridden you can point to correct function
    **/
    virtual std::string GetName(){ return "Entity"; }
};

class Player : public Enitity {
private:
    std::string m_Name;
public:
    Player(const std::string& name)
        : m_Name(name) {}

        /*
         * override mark so no spelling mistakes + to emphasise that we override
         */
        std::string GetName() override { return m_Name; }
};

void PrintName(Enitity* entity) {
    std::cout << entity-> GetName() << std::endl;
}

int main() {

    Enitity* e = new Enitity();
    PrintName(e);
//    std::cout << e->GetName() << std::endl;

    Player* p = new Player("Artemii");
//    std::cout << p->GetName() << std::endl;
    PrintName(p);

//    Enitity* enitity = p;
//    std::cout << enitity->GetName() << std::endl;

    std::cin.get();
}
