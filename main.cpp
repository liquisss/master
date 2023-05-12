#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

class Person {
private:
    std::string Name;
    int Year;
    std::string Position;
    std::string Group;
public:
    Person(std::string name, int year, std::string position, std::string group) :
        Name(name), Year(year), Position(position), Group(group) {}

    std::string GetName() { return Name; }
    int GetYear() { return Year; }
    std::string GetPosition() { return Position; }
    std::string GetGroup() { return Group; }
    void print() {
        std::cout << Name << ", " << Year << ", " << Position << ", " << Group << std::endl;
    }
};

class DB {
private:
    std::vector<Person*> Employees;
public:
    void AddPerson(Person* p) {
        Employees.push_back(p);
    }
    void PrintEnergy() const {
        for (const auto& p : Employees) {
            if (p->GetPosition() == "инженер") {
                p->print();
            }
        }
    }

    void PrintNoPredsedatel() {
        std::sort(Employees.begin(), Employees.end(), [](Person* p1, Person* p2) {
            return p1->GetYear() < p2->GetYear();
        });
        for (const auto& p : Employees) {
            if (p->GetPosition() != "председатель") {
                p->print();
            }
        }
    }

    ~DB() {
        for (const auto& p : Employees) {
            delete p;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    DB db;
    std::ifstream fl("Info.txt");
    if (!fl.is_open()) {
        std::cout << "Error opening file!" << std::endl;
    }
    else {
        std::string line;
        std::string name, position, group;
        int year;
        while (std::getline(fl, line)) {
            std::stringstream ss(line);
            std::getline(ss, name, ',');
            ss >> year >> std::ws;
            std::getline(ss, position, ',');
            std::getline(ss >> std::ws, group);
            db.AddPerson(new Person(name, year, position, group));
        }
    }

    db.PrintEnergy();
    std::cout << "------------------------------------" << std::endl;
    db.PrintNoPredsedatel();
    fl.close();
    return 0;
}
