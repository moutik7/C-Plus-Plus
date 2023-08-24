
#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include <iostream>
namespace sdds
{
	class Menu;
	const int MAX_MENU_ITEMS = 20;
	class MenuItem
	{
		char* m_content{};
		MenuItem();
		MenuItem(const char* content);
		void display() const;
		MenuItem(const MenuItem& item) = delete;
		MenuItem& operator=(const MenuItem& item) = delete;
		operator bool() const;
		operator const char* ()const;
		~MenuItem();
		friend class Menu;
	};
	class Menu
	{
		MenuItem m_title{};
		MenuItem* m_items[MAX_MENU_ITEMS]{};
		int m_numOfItems{};
	public:
		Menu();
		Menu(const char* title);
		Menu(const Menu& menu) = delete;
		Menu& operator=(const Menu& menu) = delete;
		void display() const;
		std::ostream& display(std::ostream& os) const;
		void printTitle(std::ostream& os) const;
		int run() const;
		Menu& operator<<(const char* menuitemConent);
		int operator~() const;
		operator int() const;
		operator unsigned int() const;
		operator bool() const;
		const char* operator[](int index) const;
		void setEmpty();
		bool isEmpty() const;
		~Menu();
	};
	std::ostream& operator<<(std::ostream& ostr, const Menu& menu);

}
#endif 