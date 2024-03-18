#pragma once
#include "Cake.h"
using namespace std;
class CakeRecipe
{
private:
	string name;
	int time;
public:
	CakeRecipe()
	{
		name = "n/a"; time = -1;
	}
	CakeRecipe(string _name, int _time)
	{
		name = _name; time = _time;
	}
	string getName()
	{
		return name;
	}
	int getTime()
	{
		return time;
	}

};