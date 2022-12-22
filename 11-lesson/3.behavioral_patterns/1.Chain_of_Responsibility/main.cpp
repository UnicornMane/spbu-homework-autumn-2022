#include <iostream>
#include <string>

using namespace std;

class Object
{
public:
    virtual Object* setNextObject(Object* object) = 0;
    virtual string interact(string command) = 0;
};

class AbstractObject : public Object
{
private:
    Object* nextObject;
public:
    AbstractObject() : nextObject(nullptr) {}
    Object* setNextObject(Object* object) override
    {
        nextObject = object;
        return object;
    }
    string interact(string command) override
    {
        if(nextObject)
        {
            return nextObject->interact(command);
        }
        return "";
    }
};

class Teapot : public AbstractObject
{
public:
    string interact(string command) override
    {
        if (command == "boil water")
        {
            return "the teapot boiled water";
        }
        return AbstractObject::interact(command);
    }
};

class FryingPan : public AbstractObject
{
public:
    string interact(string command) override
    {
        if (command == "fry potatoes")
        {
            return "the frying pan fried potatoes";
        }
        return AbstractObject::interact(command);
    }
};

class Mixer : public AbstractObject
{
public:
    string interact(string command) override
    {
        if (command == "make a smoothie")
        {
            return "the mixer made a smoothie";
        }
        return AbstractObject::interact(command);
    }
};

void giveCommand(Object* object, string command)
{
    string str = object->interact(command);
    if (str.empty())
    {
        cout << command << " - we have nothing to do this:(\n";
    }
    else
    {
        cout << str << endl;
    }
}

int main()
{
    Mixer* mixer = new Mixer();
    FryingPan* fryingPan = new FryingPan();
    Teapot* teapot = new Teapot();

    mixer->setNextObject(fryingPan)->setNextObject(teapot);


    giveCommand(mixer, "boil water");
    giveCommand(mixer, "make a smoothie");
    giveCommand(mixer, "fry potatoes");

    giveCommand(mixer, "squish a cat");
    return 0;
}
