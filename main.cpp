#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Car {
public:
    Car(const std::string& model, const std::string& brand) : _model(model), _brand(brand) {}

    ~Car() {}

    const std::string& getModel() const {
        return _model;
    }
    const std::string& get_Brand() const {
        return _brand;
    }

    virtual void Print() = 0;

private:
    const std::string _model;
    const std::string _brand;
};

class Kia : public Car {
public:
    Kia(const std::string& model, const std::string& brand) : Car(model, brand) {}

    virtual ~Kia() { }
    void Print() override {
        std::cout << get_Brand() << ": " << getModel() << std::endl;
    }

};

class BMW : public Car {
public:
    BMW(const std::string& model, const std::string& brand) : Car(model, brand) {}

    virtual ~BMW() {}
    void Print() override {
        std::cout << get_Brand() << ": " << getModel() << std::endl;
    }

};

class Honda : public Car {
public:
    Honda(const std::string& model, const std::string& brand) : Car(model, brand) {}
    virtual ~Honda() {}
    void Print() override {
        std::cout << get_Brand() << ": " << getModel() << std::endl;
    }

};

int main() {
    std::vector<Car*> cars;
    std::ifstream fl("Cars.txt");

    if (!fl.is_open()) {
        std::cout << "Error opening file" << std::endl;
    }
    else {
        std::string brand;
        std::string model;

        while (fl >> brand >> model) {
            if (brand == "Honda") {
                cars.push_back(new Honda(model, brand));
            }
            else if (brand == "Kia") {
                cars.push_back(new Kia(model, brand));
            }
            else if (brand == "BMW") {
                cars.push_back(new BMW(model, brand));
            }
            else {
                std::cout << "Unknown brand " << std::endl;
            }
        }

    }
    fl.close();

    for (auto car : cars) {
        car->Print();
    }

    for (auto car : cars) {
        delete car;
    }

    return 0;
}
