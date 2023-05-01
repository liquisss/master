#include <iostream>
#include <vector>

class Detail {
protected:
	Detail() {}
  
public:
	virtual ~Detail() {}
	template <typename T>friend void Add(std::vector<Detail*>& v);
};

class Assembly :public Detail {
protected:
	Assembly() {}
  
public:
	virtual ~Assembly() {}
	template <typename T>friend void Add(std::vector<Detail*>& v);
};

template<typename T>
void Add(std::vector<Detail*>& v)
{
	v.push_back(new T());
}

int main()
{
	std::vector<Detail*> v;
	Add<Detail>(v);
	Add<Assembly>(v);

	for (auto obj : v) {
		delete obj;
	}
	
	return 0;
}
