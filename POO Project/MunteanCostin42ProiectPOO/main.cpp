#include"CommandPanel.h"
using namespace std;
int main()
{
	CommandPanel menu = CommandPanel();
	int input, n;
	string buffer;
	do
	{
		cout << "Bine ati venit la Caruselul cu Prajituri!\n1.Afisati Produse\n2.Alegeti o Prajitura\n3.Comanda Multipla\n4.Carusel\n0.Iesire\n";
		delay(500);
		cin >> input;
		if (!std::cin)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cout << "Va rugam introduceti input valid.";
			input = -1;
		}
		switch (input)
		{
		case 1:
			menu.ShowProducts();
			break;
		case 2:cout << "Ce prajitura ati dori sa comandati?\n";
			getchar();
			getline(cin, buffer);
			menu.SelectProduct(buffer);
			break;
		case 3:cout << "Ce prajitura ati dori sa comandati?\n";
			getchar();
			getline(cin, buffer);
			cout << "Cate bucati ati dori sa comandati?\n";
			cin >> n;
			if (!cin)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Va rugam introduceti input valid.";
			}
			else
				menu.SelectProduct(buffer, n);
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
			break;
		case 4:menu.showProductsInCarousel();
			break;
		case 0:cout << "Mai veniti pe la noi!\n";
			break;
		default:cout << "Alegeti o optiune valida.\n";
			break;
		}
	} while (input != 0);
	return 0;
}