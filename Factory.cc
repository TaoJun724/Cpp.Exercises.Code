#include <iostream>
#include <string>

using namespace std;
// 抽象车类
class Car 
{
    public:
        virtual void Run() = 0;
};
// 具体的宝马类(实现)
class BMWCar : public Car
{
    public:
        virtual void Run()
        {
            cout << " i am bmw" << endl;
        }
};
// 具体的奥迪类(实现)
class AoDiCar : public Car
{
    public:
        virtual void Run()
        {
            cout << " i am aodi" << endl;
        }
};
// 抽象工厂类
class CarFactory
{
    public:
        virtual Car* ProductCar() = 0;
};
// 具体生产宝马的工厂(实现)
class BMWFactory : public CarFactory
{
    public:
        virtual Car* ProductCar()
        {
            return new BMWCar;
        }
};
// 具体生产奥迪的工厂(实现)
class AoDiFactory : public CarFactory
{
    public:
        virtual Car* ProductCar()
        {
            return new AoDiCar;
        }
};

int main()
{
    // 客户端
    CarFactory* carA = new AoDiFactory;
    carA->ProductCar()->Run();
    CarFactory* carB = new BMWFactory;
    carB->ProductCar()->Run();

    // 释放堆上的内存
    return 0;
}

