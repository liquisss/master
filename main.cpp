#include <iostream>
#include <vector>
#include <string>

enum class Type {
	Art, Tech
};

class Book
{
public:
	Book(const std::string& avtor, const std::string& title, Type bookType) :
		_avtor(avtor), _title(title), _bookType(bookType)
	{}
	Type GetType() const
	{
		return _bookType;
	}

private:
	const std::string _avtor;
	const std::string _title;
	const Type _bookType;
};

class Library
{

public:
	bool addbook(const std::string& author, const std::string& title, Type bookType)
	{
		if (author.empty() || title.empty()) {

			std::cout << "error" << std::endl;
		}
		else {
			book.emplace_back(title, author, bookType);
		}
	}
	void CountSwitch() {
		int ArtCount = 0;
		int TechCount = 0;
		for (Book i : book) {
			switch (i.GetType())
			{
			case Type::Art:
				++ArtCount;
				break;
			default:
				++TechCount;
				break;
			}
		}
		std::cout << "Art: " << ArtCount << std::endl;
		std::cout << "Tech: " << TechCount << std::endl;
	}
	void CountFor() {
		int ArtCount = 0;
		int TechCount = 0;
		for (Book i : book)
		{
			if (i.GetType() == Type::Art)
			{
				++ArtCount;
			}
			else
			{
				++TechCount;
			}
		}
		std::cout << "Art: " << ArtCount << std::endl;
		std::cout << "Tech: " << TechCount << std::endl;
	}

private:
	std::vector <Book> book;
};

int main()
{
	Library library;

	library.addbook("Bulgakov", "Master and Margarita", Type::Art);
	library.addbook("Haung B.", "Arduino", Type::Tech);
	library.addbook("John Fauls", "Collector", Type::Art);
	library.addbook("Slingerland E.", "electrical engineering", Type::Tech);

	std::cout << "Count Art and Tech books (with switch): " << std::endl;

	library.CountSwitch();

	std::cout << "Count Art and Tech books :" << std::endl;

	library.CountFor();

	return 0;
}
