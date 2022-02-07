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
        cout << "position of " << this->name << " is " << this->position << endl;
    }
};

class StaticObject : public BaseObject {
    //Ke thua constructor
    using BaseObject::BaseObject;
};

class Tree : public StaticObject {
    using StaticObject::StaticObject;
};

class DynamicObject : public BaseObject {
    //Ke thua constructor
    using BaseObject::BaseObject;
};

class Car : public DynamicObject {
    using DynamicObject::DynamicObject;
};

template <typename T>
list<T> createListObject() {
    // Create an empty list of object
    list<T> listObj;
    return listObj;
}

int main()
{
    list<Car> listCar = createListObject<Car>();
    Car* lambo = new Car(1, "lambo", 1);
    Car* nexus = new Car(2, "nexus", 3);
    Car* phantom = new Car(3, "phantom", 5);
    listCar.push_back(*lambo);
    listCar.push_back(*nexus);
    listCar.push_back(*phantom);
    for (auto obj : listCar)
    {
        obj.getName();
        obj.move();
        obj.printPostition();
    }

    listCar.clear();

    list<Tree> listTree = createListObject<Tree>();
    Tree* apple = new Tree(4, "Apple", 40);
    Tree* palm = new Tree(5, "palm", 10);

    listTree.push_back(*apple);
    listTree.push_back(*palm);

    for (auto obj : listTree)
    {
        obj.getName();
        obj.move();
        obj.printPostition();
    }
    listTree.clear();
    return 0;
    
}