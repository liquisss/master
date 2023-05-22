#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <string>
#include <iostream>
#include <vector>
#include <list>

struct Leaks {
    ~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;

class A{
public:
    std::string s;
    A() {
        std::cout << "Конструктор по умолчанию класса А" << std::endl;
    }

    A(const char*a) {
        s=a;
        std::cout << "Пользовательский Конструктор класса A" << std::endl;
        std::cout << s << std::endl;
    }
    virtual ~A() {
        std::cout << "Деструктор класса A" << std::endl;
        std::cout << typeid(*this).name() << std::endl;
    }
};

class B : public A{
public:
    B() {
        std::cout << "Конструктор класса B" << std::endl;
    }
    B(const char* a) : A(a) {
        std::cout << "Пользовательский Конструктор класса B" << std::endl;
        std::cout << a << std::endl;
    }
    ~B() {
        std::cout << "Деструктор класса B" << std::endl;
        std::cout << typeid(*this).name() << std::endl;
    }
};

void del(vector<A*>& v){
    for (int i = 0; i < v.size(); i++)
        delete v[i];
}

std::vector<A*>v;
std::list <A*> l;

int main(){
    l.push_back(new A("first"));
    l.push_back(new B("second"));
    // скопировать из списка в вектор
    v.resize(l.size());
    std::copy(l.begin(), l.end(), std::back_inserter(v));
    
    del(v);
    return 0;
}
