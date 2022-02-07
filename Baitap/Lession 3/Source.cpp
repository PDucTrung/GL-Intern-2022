#include <iostream>
#include <list>
using namespace std;

class BaseObject {
    int id;
    string name;
    int position;
public:
    BaseObject() {
        this->id = 0;
        this->name = "";
        this->position = 0;
    }

    BaseObject(int id, string name, int position) {
        this->id = id;
        this->name = name;
        this->position = position;
    }

    string getName() {
        return this->name;
    }

    void move() {
        this->position++;
    }

    void printPostition() {
        cout << "position: " << this->position << endl;
    }
};

class dynamicObject : public BaseObject {
    //Ke thua constructor
    using BaseObject::BaseObject;
};

class Car : public dynamicObject {
    using dynamicObject::dynamicObject;
};

void createListCar() {
    list<Car> listCar;
    Car* car1 = new Car(1, "lambo", 1);
    Car* car2 = new Car(2, "nexus", 3);
    Car* car3 = new Car(3, "phanto", 5);
    listCar.push_back(*car1);
    listCar.push_back(*car2);
    listCar.push_back(*car3);

    for (auto obj : listCar)
    {
        obj.getName();
        obj.move();
        obj.printPostition();
    }
}

int main()
{
    createListCar();
    return 0;

}