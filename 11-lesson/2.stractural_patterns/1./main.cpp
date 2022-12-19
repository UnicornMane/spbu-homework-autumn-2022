#include <iostream>
#include <string>

class Englishman
{
private:
    std::string lang = "eu";
public:
    virtual std::string myLanguage() = 0;
};

class Russianman
{
private:
    std::string lang = "ru";
public:
    std::string myLanguage()
    {
        return lang;
    }
};

class RusAdaptor : public Englishman
{
    std::string myLanguage() override
    {
        return "ru";
    }
};

int main()
{
    Russianman *russian = new Russianman;
    Englishman *english = new RusAdaptor;

    if (russian->myLanguage() == english->myLanguage())
    {
        std::cout << "they understand each other\n";
    }

    return 0;
}
