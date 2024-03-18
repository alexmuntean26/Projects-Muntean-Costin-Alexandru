#include"CommandTaker.h"
using namespace std;
Cake CommandTaker::TakeCommand(CakeRecipe _recipe) {
	Cake aux = carousel.getCake(_recipe.getName());
	if (aux.getName() != "")
		return aux;
	else
		aux = maker.takeCommand(_recipe);
	return aux;
}
Cake* CommandTaker::TakeCommand(CakeRecipe _recipe, int amount) {
	int i = 0;
	Cake a[20];

	while (amount) {
		cout << "Pregatim prajitura: " << _recipe.getName() << " numarul " << i + 1 << ".\nPrajituri ramase: " << amount - 1 << "\n";
		a[i] = maker.takeCommand(_recipe);
		amount--;
		i++;
	}
	return a;
}
Cake CommandTaker::TakeCommand(std::string _name) {
	CakeRecipe a = CakeRecipe(_name, 5);
	Cake aux = carousel.getCake(a.getName());
	if (aux.getName() != "")
		return aux;
	else
		aux = maker.takeCommand(a);
	return aux;
}
bool CommandTaker::checkCarouselOfCakes() {//
	if (carousel.getCurrentCapacity() < 3)
		return 0;
	return 1;
}
bool CommandTaker::refillCarousel() {
	int size = carousel.getCurrentCapacity();
	bool check;
	Cake cake = Cake(CarouselRecipe.getName());
	while (size < 10) {
		check = carousel.addCake(cake);
		size++;
	}
	return check;
}
void CommandTaker::getCakesFromCarousel() {
	carousel.getCakesFromCarousel();
}