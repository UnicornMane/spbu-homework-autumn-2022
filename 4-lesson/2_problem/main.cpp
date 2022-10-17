#include <iostream>
#include <string>

using namespace std;


class Character
{
protected:
    int hp;

    Character(int hp = 0)
    {
        this->hp = hp;
    }

    ~Character()
    {
        hp = 0;
    }

public:
    virtual string power() = 0;

    int remained_hp()
    {
        return hp;
    }
};

class Claudette : public Character
{
public:
    Claudette(int hp = 0) : Character(hp)
    {};

    string power() override
    {
        return "self-healing";
    }
};

class Jake : public Character
{
public:
    Jake(int hp = 0) : Character(hp)
    {};

    string power() override
    {
        return "sabotaging";
    }
};

class Dwight : public Character
{
public:
    Dwight(int hp = 0) : Character(hp)
    {};

    string power() override
    {
        return "increasing interactions speed";
    }
};

class Player
{
public:
    void Use_power(Character *character)
    {
        cout << character->power() << endl;
    }

    void hp(Character *character)
    {
        cout << character->remained_hp() << endl;
    }
};

int main(int argc, char *argv[])
{
    Claudette c(3);
    Jake j(5);
    Dwight d(10);
    Player v;
    v.Use_power(&c);
    v.hp(&c);

    v.Use_power(&j);
    v.hp(&j);

    v.Use_power(&d);
    v.hp(&d);

//    cout << c.power() << endl;
//    cout << c.remained_hp() << endl;
    return EXIT_SUCCESS;
}
