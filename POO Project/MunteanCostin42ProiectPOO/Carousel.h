#pragma once
#include"CakeMaker.h"
using namespace std;
class CarouselOfCakes
{
private:
	Cake *storage[10];
	int maxCapacity = 10;
	int lowLimit = 3;
public:
	CarouselOfCakes() {
		for (int k = 0; k < maxCapacity; k++) {
			storage[k] = nullptr;
		}
	}
	bool addCake(Cake cake);
	Cake getCake(std::string _name);
	int getCurrentCapacity();
	void getCakesFromCarousel();
};