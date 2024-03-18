#pragma once
#include "CakeRecipe.h"
using namespace std;
class CakeMaker
{
public:
	CakeMaker() {}
	Cake takeCommand(CakeRecipe _recipe)
	{
		string _string = _recipe.getName();
		int _time = _recipe.getTime();
		Cake aux = Cake(_string);
		cout << "Baking...\n";
		delay(5000);
		cout << "Cake ready!\n";
		delay(200);
		return aux;
	}
};