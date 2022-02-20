/* Student Name: Merve CANDAN
***Student ID: 150160041    */

#include <iostream>
#include <string>

#define drink_size 4

using namespace std;

class order
{
private:
	order* next;
	string customer;
	Pizza* pizza;
	int *drink;
public:
	~order();
	order();
	order(string, Pizza*, int*);
	order(string, Pizza*);
	friend class Pizza;
	friend class orderlist;
	void printOrder();
	double getPrice(string,int,int *);
};

order::~order()
{
	
}

order::order()
{
	// empty constructor
}

order::order(string customer_name, Pizza* pizzas, int* drink)
{
	this->customer = customer_name;
	this->pizza = new Pizza;
	this->pizza = pizzas;
	this->drink = new int[drink_size];
	this->drink = NULL;
	this->drink = drink;
	printOrder();
}

order::order(string customer_name, Pizza* pizzas)
{
	this->pizza = pizzas;
	this->customer = customer_name;
	this->drink = new int[drink_size];
	for(int i=0;i<drink_size;i++)
	{
		drink[i] = NULL; // to print function 
	}
	printOrder(); // to print order from customer
}

void order::printOrder()
{
	cout << "------------" << endl;
	cout << "Name: " << customer << "\n" << endl;
	Pizza* temp = new Pizza;
	temp = pizza; // to keep head of the pizza list
	while (temp)
	{
		cout << temp->name << "(" << temp->ingredients << ")" << endl;
		cout << "size: " << temp->size << ", crust: " << temp->crust_type << endl;
		temp = temp->next;
		cout << endl;
	}
	for (int i = 0; i < drink_size; i++)
		{
		if (drink[i] != NULL)
		{
			cout << drink[i];
			switch (i)
			{
			case 0:
				cout << " cola,";
				break;
			case 1:
				cout << " soda,";
				break;
			case 2:
				cout << " ice tea,";
				break;
			case 3:
				cout << " fruit juice,";
				break;
			default:
				break;
			}
		}
	}
	cout << "\n------------" << endl;
	delete temp; // to prevent memory invasion
}

double order::getPrice(string size, int amount, int* drink)
{
	double pizza_price = 1;
	if(size=="small")
	{
		pizza_price = pizza_price * 15 * amount; // to multiply the price by the number of pizzas
	}
	else if(size=="normal")
	{
		pizza_price = pizza_price * 20 * amount; // to multiply the price by the number of pizzas
	}
	else
	{
		pizza_price = pizza_price * 25 * amount; // to multiply the price by the number of pizzas
	}
	double drink_price = 0.0;
	drink_price = (drink[0] * 4) + (drink[1] * 2) + (drink[2] * 3) + (drink[3] * 3.5); // to include drinks in the price

	return pizza_price + drink_price;
}
