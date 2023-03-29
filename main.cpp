#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Car {
public:
    Car(const std::string& model) : _model(model) {}

    virtual ~Car() {}

    std::string& getModel() {
        return _model;
    }

private:
    std::string _model;
};

class Kia : public Car {
public:
    Kia(const std::string& model) : Car(model) {}

    virtual ~Kia() {
        std::cout << "Kia " << getModel() << std::endl;
    }

};

class BMW : public Car {
public:
    BMW(const std::string& model) : Car(model) {}

    virtual ~BMW() {
        std::cout << "BMW " << getModel() << std::endl;
    }

};

class Honda : public Car {
public:
    Honda(const std::string& model) : Car(model) {}

    virtual ~Honda() {
        std::cout << "Honda " << getModel() << std::endl;
    }

};

int main() {
    std::vector<Car*> cars;
    std::ifstream fl("Cars.txt");

    if (!fl.is_open()) {
        std::cout << "Error opening file" << std::endl;
    }
    else {
            std::string mark;
            std::string model;

            while (fl >> mark >> model) {
                if (mark == "Honda") {
                    cars.push_back(new Honda(model));
                }
                else if (mark == "Kia") {
                    cars.push_back(new Kia(model));
                }
                else if (mark == "BMW") {
                    cars.push_back(new BMW(model));
                }
                else {
                    std::cout << "Unknown car brand" << std::endl;
                }
            }
 
    }
    fl.close();

    for (auto car : cars) {
        delete car;
    }

    return 0;
}
