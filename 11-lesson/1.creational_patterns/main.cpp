#include <iostream>
#include <string>

using namespace std;


class ChairOnePrice
{
protected:
    string design;
    double chair_height = 0;
public:
    virtual void setDesign() = 0;
    void showInfo()
    {
        cout << "your chair parameters:\n";
        cout << "design of your chair: " << design << endl << "chair's area: " << chair_height << " meters" << endl;
    }
};


class VictorianChair : public  ChairOnePrice
{
public:
    void setDesign() override
    {
        design = "victorian";
        chair_height = 2;
    }
};

class ModernChair : public  ChairOnePrice
{
public:
    void setDesign() override
    {
        design = "modern";
        chair_height = 1.5;
    }
};

namespace ChairOnePriceFactory
{

    ChairOnePrice* createChair(int type)
    {
        ChairOnePrice *chair = nullptr;

        switch(type)
        {
            case 1:
            {
                chair = new VictorianChair;
                break;
            }
            case 2:
            {
                chair = new ModernChair;
                break;
            }
            default:
            {
                throw out_of_range("you've entered the wrong number\n");
            }
        }
        chair->setDesign();
        return chair;
    }
};


int main()
{
    int type = 0;
    cout << "Hello, you are in the ChairOnePrice store.\n"
            << "What kind of chair do you want to buy?\n"
            << "Enter one of the following numbers to make decision:\n"
            << "1 -- Victorian design\n2 -- Modern design\n";

    cin >> type;

    ChairOnePrice *chair = ChairOnePriceFactory::createChair(type);
    chair->showInfo();



    return 0;
}
