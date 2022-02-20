/* Student Name: Merve CANDAN
***Student ID: 150160041    */

#include <iostream>
#include <cstring>
#include <string.h>

#include "pizza.h" // to create new pizza
#include "order.h" // to keep created pizza and add drink
#include "orderlist.h" // connect to customers and keep the order list and deliver them

using namespace std;

void Welcome(); // to print start menu

int main() {
	orderlist obje;
	int i=1;
	while (i != 4)
	{
		Welcome();
		cin >> i;
		if (i == 1)
		{
			obje.takeOrder();
		}
		else if (i == 2)
		{
			obje.listOrder();
		}
		else if (i == 3)
		{
			obje.deliverOrder();
		}
		else if (i == 4)
		{
			cout << "Goodbye..." << endl; // to exit program
		}
		else
		{
			cout << "incorrect entry" << endl; // wrong input
		}
	}
	return 0;
}

void Welcome() // start menu
{
	cout << "Welcome to Unicorn Pizza!" << endl;
	cout << "1. Add an order" << endl;
	cout << "2. List orders" << endl;
	cout << "3. Deliver order" << endl;
	cout << "4. Exit" << endl;
	cout << "Choose what to do: ";
}
