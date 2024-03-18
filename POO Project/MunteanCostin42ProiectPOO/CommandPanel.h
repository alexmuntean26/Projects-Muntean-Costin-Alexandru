#pragma once
#include "CommandTaker.h"
#include<list>
using namespace std;
class CommandPanel
{
private:
	list<CakeRecipe> menu;
	CommandTaker commandTaker;
public:
	CommandPanel() {
		CakeRecipe c0 = CakeRecipe("Tiramisu", 5);
		CakeRecipe c1 = CakeRecipe("Amandina", 5);
		CakeRecipe c2 = CakeRecipe("Savarina", 5);
		menu.push_back(c0);
		menu.push_back(c1);
		menu.push_back(c2);
		commandTaker = CommandTaker(c0);
		if (commandTaker.checkCarouselOfCakes() == 0)
			commandTaker.refillCarousel();
	}
	void ShowProducts();
	void SelectProduct(string _name);
	void SelectProduct(string _name, int _amount);
	void showProductsInCarousel();
};