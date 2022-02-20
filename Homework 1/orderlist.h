/* Student Name: Merve CANDAN
***Student ID: 150160041    */

#include <iostream>
#include <string>
#include <stdio.h>

#define drink_size 4

using namespace std;
class orderlist
{
private:
	int n;
	order* head; // head of the orders list
public:
	~orderlist();
	orderlist();
	void takeOrder();
	void listOrder();
	void deliverOrder();
	void flush();
	friend class Pizza;
	friend class order;
};

orderlist::~orderlist()
{
	while (head) // to free memory 
	{
		order* temp = head;
		head = head->next;
		delete temp;
	}
	delete head;
}

orderlist::orderlist()
{
	n = 0;
	head = NULL;
}

void orderlist::takeOrder()
{
	string piz_size, crust_type;
	int choice_pizza = 4, amount;
	while (choice_pizza < 0 || choice_pizza>3) // pizza menu
	{
		cout << "Pizza Menu" << endl;
		cout << "1. Chicken Pizza (mozarella,chicken,mushroom,corn,onion,tomato)" << endl;
		cout << "2. Broccoli Pizza (mozarella,broccoli,pepperoni,olive,corn,onion)" << endl;
		cout << "3. Sausage Pizza  (mozarella,sausage,tomato,olive,mushroom,corn)" << endl;
		cout << "0. Back to main menu" << endl;
		cin >> choice_pizza;
		if (choice_pizza < 0 || choice_pizza>3)
		{
			cout << "incorrect entry" << endl;
		}
	}
	if (!choice_pizza)
	{
		return;
	}
	cout << "Select size: small (15 TL), medium (20 TL), big (25 TL)" << endl;
	cin >> piz_size;
	cout << "Select crust type: thin, normal, thick" << endl;
	cin >> crust_type;
	Pizza* first_pizza = new Pizza(piz_size, crust_type, choice_pizza);
	Pizza* onlyCopy = new Pizza(piz_size, crust_type, choice_pizza); // to copy first pizza beacuse 
	first_pizza->next = NULL;
	cout << "Enter the amount" << endl;
	cin >> amount;
	if (amount) // if amount 0 error message 
	{
		amount--; // amount -1 question to customer 
		Pizza* temp = first_pizza;
		while (amount)
		{
			if (temp->next)
			{
				temp = temp->next;
			}
			else
			{
				Pizza* morePiz = new Pizza(onlyCopy); // copy consturctor
				morePiz->next = NULL;
				temp->next = morePiz;
				amount--;
			}
		}
	}
	else
	{
		cout << "incorrect entry" << endl;
		return;
	}
	cout << "Please choose a drink:" << endl;
	cout << "0. no drink1" << endl;
	cout << "1. cola 4 TL" << endl;
	cout << "2. soda 2TL" << endl;
	cout << "3. ice tea 3TL" << endl;
	cout << "4. fruit juice 3.5 TL" << endl;
	cout << "Press -1 for save your order" << endl;
	int* drink = new int[drink_size];
	for (int i = 0; i < drink_size; i++)
	{
		drink[i] = NULL;
	}
	bool check = true;
	int choice_drink;
	while (check) // drink selection process
	{
		cin >> choice_drink;
		switch (choice_drink)  // only the selected amount of drink increases
		{
		case 0:
			check = false;
			drink = NULL;
			break;
		case 1:
			drink[choice_drink - 1]++;
			break;
		case 2:
			drink[choice_drink - 1]++;
			break;
		case 3:
			drink[choice_drink - 1]++;
			break;
		case 4:
			drink[choice_drink - 1]++;
			break;
		case -1:
			check = false;
			break;
		default:
			cout << "incorrect entry! Try again..." << endl;
			break;
		}
	}
	string name;
	cout << "Please enter your name:" << endl;
	cin >> name;
	cout << "Your order is saved, it will be delivered when it is ready..." << endl;
	order* order1;
	if (drink != NULL)
	{
		order1 = new order(name, first_pizza, drink); // with drink 
	}
	else
	{
		order1 = new order(name, first_pizza); // witthout drink
	}
	if (!head) // first order
	{
		head = order1;
		head->next = NULL;
		n++;
	}
	else
	{
		order* temp = head;
		while (temp)
		{
			if (temp->next)
			{
				temp = temp->next;
			}
			else
			{
				temp->next = order1;
				order1->next = NULL;
				temp = order1->next;
				n++;
			}
		}
		delete temp; // to free memory
	}
}

void orderlist::listOrder()
{
	int list_number = 1;
	order* temp = head;
	if (!head)
	{
		cout << "empty" << endl;
	}
	else
	{
		while (temp)
		{
			cout << list_number << "\n------------" << endl;
			cout << "Name :" << temp->customer << "\n" << endl;
			Pizza* travel = new Pizza; // to keep head of the pizza list 
			travel = temp->pizza;
			while (travel)
			{
				cout << travel->name << "(" << travel->ingredients << ")" << endl;
				cout << "size: " << travel->size << ", crust: " << travel->crust_type << endl;
				travel = travel->next;
				cout << endl;
			}
			delete travel; // to free memory
			for (int i = 0; i < drink_size; i++)
			{
				if (temp->drink[i])
				{
					cout << temp->drink[i];
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
			temp = temp->next; // next order
			list_number++;
		}
	}
	delete temp; // // to free memory
}

void orderlist::deliverOrder()
{
	listOrder(); // print the list of the orders
	if (!head)
	{
		return;
	}
	int number_pizza = 0;
	string name;
	cout << "Please write the customer name in order to deliver his/her order: ";
	cin >> name;
	order* temp = head;
	bool check = true;  // for wrong name
	while (temp)
	{
		if (name == temp->customer)
		{
			cout << "Following order is delivering..." << endl;
			cout << "-------------" << endl;
			cout << "Name: " << name << endl;
			Pizza* travel = new Pizza;
			travel = temp->pizza;
			while (travel)
			{
				number_pizza++;
				cout << travel->name << "(" << travel->ingredients << ")" << endl;
				cout << "size: " << travel->size << ", crust: " << travel->crust_type << endl;
				travel = travel->next;
				cout << endl;
			}
			delete travel; // to free memory
			for (int i = 0; i < drink_size; i++)
			{
				if (temp->drink[i])
				{
					cout << temp->drink[i];
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
			order price;
			double price1 = price.getPrice(temp->pizza->size, number_pizza, temp->drink);
			cout << "Total price: " << price.getPrice(temp->pizza->size, number_pizza, temp->drink) << endl;
			cout << "Do you have promotion code? (y/n)" << endl;
			char P;
			cin >> P;
			if (P == 'y')
			{
				string pCode;
				cout << "Please enter the promotion code: ";
				flush();
				getline(cin, pCode); // to enter string with spaces
				if (pCode == "I am a student")
				{
					price1 = price1 * 0.9;
					cout << "discounted price: " << price1 << endl;
				}
				else // for wrong code
				{
					while (P == 'y')
					{
						cout << "Promotion code is not accepted" << endl;
						cout << "Do you have promotion code? (y/n)" << endl;
						cin >> P;
						if (P == 'y')
						{
							cout << "Please enter the promotion code: ";
							flush();
							getline(cin, pCode);
							if (pCode == "I am a student")
							{
								price1 = price1 * 0.9;
								cout << "discounted price: " << price1 << endl;
								P = 'n';
							}
							else
							{
								cout << "Promotion code is not accepted" << endl;
								cout << "Do you have promotion code? (y/n)" << endl;
								cin >> P;
							}
						}
					}
				}
			}
			if (temp == head)
			{
				head = head->next;
				delete temp;
				cout << "The order is delivered succesfully!\n" << endl;
				return;
			}
			else
			{
				order* del = head;
				while (del)
				{
					if (del->next == temp)
					{
						del->next = temp->next;
						delete temp; // delete node and re-build list
						cout << "The order is delivered succesfully!\n" << endl;
						return;
					}
					else
					{
						del = del->next;
					}
				}
				delete del;
			}
			check = false;
		}
		else
		{
			temp = temp->next;
		}
		if (!check)
		{
			return;
		}
		else
		{
			cout << "Wrong name" << endl;
			return;
		}
	}
	delete temp;
}


void orderlist::flush()
{
	int c;
	while ((c = cin.get()) != '\n' && c != EOF); // to clear input
}
