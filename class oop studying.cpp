#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class car {
    public: 
    int speed;
    int price;
    string merk;
    
    car(int s, int p, int m) {
        speed = s;
        price = p;
        merk = m;
    }

};
    class carlist {
    
    std::vector<car> listofcars = {
    {300, 100, "Audi R8"},
    {280, 90, "BMW M4"},
    {320, 120, "Mercedes AMG GT"},
    {350, 150, "Lamborghini Huracan"},
    {340, 140, "Ferrari F8"},
    {310, 110, "Porsche 911"},
    {270, 85, "Jaguar F-Type"},
    {260, 80, "Chevrolet Camaro"},
    {290, 95, "Ford Mustang"},
    {250, 75, "Dodge Challenger"},
    {240, 70, "Subaru WRX"},
    {230, 65, "Nissan 370Z"},
    {220, 60, "Toyota Supra"},
    {210, 55, "Mazda RX-7"},
    {200, 50, "Honda NSX"},
    {190, 45, "Hyundai Genesis Coupe"},
    {180, 40, "Kia Stinger"},
    {170, 35, "Peugeot RCZ"},
    {160, 30, "Renault Megane RS"},
    {150, 25, "Volkswagen Golf R"}
    };
    void show( ) {
        for (int i = 0; i<= listofcars.size()-1; i++) {
            cout<<i+1<<". "<<listofcars[i].merk<<endl;
        }
    }		
};


// we'll made a class contain three members. color, speed, price
//we put three as a single unit in list car car1, car car2...with loop.

int main ()
{
string choice;
    cout<<"pick your car: "
   carlist thecar;
   thecar.show();
   
    
    return 0;
}













