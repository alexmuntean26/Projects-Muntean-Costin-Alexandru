#pragma once
#include "Carousel.h"
using namespace std;
class CommandTaker
{
private:
	CakeRecipe CarouselRecipe;
	CakeMaker maker;
	CarouselOfCakes carousel;
public:
	CommandTaker() {}
	CommandTaker(CakeRecipe _recipe)
	{
		CarouselRecipe = _recipe;
	}
	Cake TakeCommand(CakeRecipe _recipe);
	Cake* TakeCommand(CakeRecipe _recipe, int amount);
	Cake TakeCommand(string _name);
	void getCakesFromCarousel();
	bool checkCarouselOfCakes();
	bool refillCarousel();
};