#include <iostream>
#include<memory>

using namespace std;


struct Widget {
    shared_ptr<Widget> otherWidget;
};

void foo() {
    shared_ptr<Widget> a(new Widget);
    shared_ptr<Widget> b(new Widget);
    a->otherWidget = b;
    // В этой точке у второго объекта счетчик ссылок = 2
    b->otherWidget = a;
    // В этой точке у обоих объектов счетчик ссылок = 2
}
/*Что произойдет при выходе объектов a и b из области определения?
 * В деструкторе уменьшатся ссылки на объекты.
 * У каждого объекта будет счетчик = 1 (ведь a все еще указывает на b, а b — на a).
 * Объекты “держат” друг друга и у нашего приложения нет возможности получить к ним доступ — эти объекты “потеряны”.*/

int main()
{
    setlocale(LC_ALL, "ru");
    //ссылка на источник: https://habr.com/ru/post/191018/
}