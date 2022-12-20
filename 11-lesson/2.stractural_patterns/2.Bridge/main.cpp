#include <iostream>

using namespace std;

class Color
{
public:
    virtual void colorInfo() = 0;
};

class RedColor : public Color
{
    void colorInfo() override
    {
        cout << "Red ";
    }
};

class GreenColor : public Color
{
    void colorInfo() override
    {
        cout << "Green ";
    }
};

class FlyingThing
{
protected:
    Color* color;
public:
    FlyingThing(Color* cl) : color(cl) {}

    void setColor(Color* cl)
    {
        color = cl;
    }

    virtual void fly() = 0;
};

class Butterfly : public FlyingThing
{
public:
    Butterfly(Color *cl) : FlyingThing(cl){}

    void fly() override
    {
        color->colorInfo();
        cout << "butterfly is flying now\n";
    }
};

class Bird : public FlyingThing
{
public:
    Bird(Color *cl) : FlyingThing(cl){}

    void fly() override
    {
        color->colorInfo();
        cout << "bird is flying now\n";
    }
};

int main()
{
    FlyingThing* thing = new Butterfly(new RedColor);
    thing->fly();

    thing->setColor(new GreenColor);
    thing->fly();

    thing = new Bird(new RedColor);
    thing->fly();

    thing->setColor(new RedColor);
    thing->fly();

    return 0;
}
