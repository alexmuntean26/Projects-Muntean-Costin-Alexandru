#include "Carousel.h"
using namespace std;
Cake CarouselOfCakes::getCake(std::string _name)
{
	int i = 0;
	while (i < maxCapacity)
	{
		if (storage[i] != nullptr)
		{
			if ((*storage[i]).getName().compare(_name) != 1)
			{
				Cake takeCake = *storage[i];
				delete storage[i];
				storage[i] = nullptr;
				return takeCake;
			}
		}
		i++;
	}
	return Cake("");
}
bool CarouselOfCakes::addCake(Cake cake)
{
	int j = 0;
	while (j < maxCapacity)
	{
		if (storage[j] != nullptr)
		{

		}
		else {
			storage[j] = new Cake(cake.getName());
			return 1;
		}
		j++;
	}
	return 0;
}
int CarouselOfCakes::getCurrentCapacity()
{
	int size = 0, h = 0;
	while (h < maxCapacity)
	{
		if (storage[h] != nullptr)
		{
			size++;
		}
		h++;
	}
	return size;
}
void CarouselOfCakes::getCakesFromCarousel()
{
	int i = 0, size = getCurrentCapacity();
	while (i < size)
	{
		cout << storage[i]->getName() << " ";
		i++;
	}
	cout << '\n';
}