// Expense tracker program that takes item name, price and 
// date of purchases
#include "Header.h"


int main()
{
	std::cout << "Enter \'A\' to add an item or "
		"enter \'V\' to view items: ";

	std::cin >> input;
	if (input == "a")
	{
		addItem();
	}
	else if (input == "v")
	{
		viewItems();
	}
}

void addItem()
{
	std::string name;
	std::string price;
	std::string date;

	std::cout << "Please enter name of item: ";
	std::cin >> name;
	std::cout << "Please enter price of item: ";
	std::cin >> price;
	std::cout << "Please enter date of items purchase: ";
	std::cin >> date;
	std::cout << '\n';

	// Putting all three variables into itemInfo string
	std::string itemInfo = "|Item name: " + name + "|Price: "
		+ price + "|Date of Purchase: " + date + "|";

	// Opens items.txt
	std::ofstream file("items.txt", std::ios::app);
	if (!file.is_open())
	{
		std::cerr << "Error Opening items.txt\n";
	}

	// appends itemInfo to file
	file << itemInfo << std::endl;

	file.close();
	main();
}

void viewItems()
{
	// Opens items.txt
	std::ifstream file("items.txt");
	if (!file.is_open())
	{
		std::cerr << "Error Opening item.txt\n";
	}

	std::string line;
	while (!file.eof()) // While not at end of file
	{
		getline(file, line);
		std::cout << line << "\n";
	}

	file.close();
	main();
}

