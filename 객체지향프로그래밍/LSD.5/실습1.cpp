#include <iostream>
#include <string>
using namespace std;

class Car{
public:
    int speed;
    int gear;
    string color;

    void speedup(){
        speed += 10;
    }

    void speedDown(){
        speed -= 10;
    }
};

int main(void){
    Car myCar;

    myCar.speed = 100;
    myCar.gear = 3;
    myCar.color = "red";

    myCar.speedup();
    myCar.speedDown();

    return 0;
}