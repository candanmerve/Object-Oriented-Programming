/* Student Name: Merve CANDAN
***Student ID: 150160041    */

#include <iostream>
#include <string>

using namespace std; 
class Pizza 
{
private:
	Pizza* next;
	string name;
	string size;
	string ingredients;
	string crust_type;
public:
	Pizza();
	Pizza(string, string, int);
	Pizza(Pizza*);
	friend class order;
	friend class orderlist;
	~Pizza();
};

Pizza::~Pizza()
{
	
}

Pizza::Pizza() // default pizza feaatures
{
	this->size = "medium";
	this->ingredients = "mozarella";
	this->crust_type = "normal";
}

Pizza::Pizza(Pizza* pizza)  
{
	string erase;
	int choice,length=0,start=0,end=0;
	bool check = true;
	this->name = pizza->name;
	this->crust_type = pizza->crust_type;
	this->ingredients = pizza->ingredients;
	this->size = pizza->size;
	cout << "Please enter the number of the ingredient you want to remove from your pizza." << endl;
	if (pizza->name == "Chicken Pizza")
	{
		cout << "1. mozarella\n2. chicken\n3. mushroom\n4. corn\n5. olive\n6. onion\n7. tomato" << endl;
		cout << "Press 0 to save it." << endl;
		while (check)
		{
			cin >> choice;
			switch (choice)
			{
			case 0:
				check = false; // to save the final ingredients
				break;
			case 1:
				start = this->ingredients.find("mozarella");  // to find location
				erase = "mozarella";	
				end = erase.length()+2;	// to delete until comma
				this->ingredients.erase(start, end); // to delete ingredient
				break;

			case 2:
				start = this->ingredients.find("chicken");
				erase = "chicken";
				end = erase.length()+2;
				this->ingredients.erase(start, end);
				break;

			case 3:
				start = this->ingredients.find("mushroom");
				erase = "mushroom";
				end = erase.length()+2;
				this->ingredients.erase(start, end);
				break;

			case 4:
				start = this->ingredients.find("corn");
				erase = "corn";
				end = erase.length()+2;
				this->ingredients.erase(start, end);
				break;
			case 5:
				start = this->ingredients.find("olive");
				erase = "olive";
				end = erase.length() + 2;
				this->ingredients.erase(start, end);
				break;
			case 6:
				start = this->ingredients.find("onion");
				erase = "onion";
				end = erase.length()+2;
				this->ingredients.erase(start, end);
				break;

			case 7:
				start = this->ingredients.find("tomato");
				erase = "tomato";
				end = erase.length()+2;
				this->ingredients.erase(start, end);
				break;

			default:
				cout << "incorrect entry!" << endl;
				break;
			}
		}
	} 
	else if (pizza->name == "Broccoli Pizza")
	{
		cout << "1. mozarella\n2. broccoli\n3. pepperoni\n4. olive\n5. corn\n6. onion" << endl;
		cout << "Press 0 to save it." << endl;
		while (check)
		{
			cin >> choice;
			switch (choice)
			{
			case 0:
				check = false;
				break;
			case 1:
				start = this->ingredients.find("mozarella");
				erase = "mozarella";
				end = erase.length()+2;
				this->ingredients.erase(start, end);
				break;

			case 2:
				start = this->ingredients.find("broccoli");
				erase = "broccoli";
				end = erase.length() + 2;
				this->ingredients.erase(start, end);
				break;

			case 3:
				start = this->ingredients.find("pepperoni");
				erase = "pepperoni";
				end = erase.length() + 2;
				this->ingredients.erase(start, end);
				break;

			case 4:
				start = this->ingredients.find("olive");
				erase = "olive";
				end = erase.length() + 2;
				this->ingredients.erase(start, end);
				break;

			case 5:
				start = this->ingredients.find("corn");
				erase = "corn";
				end = erase.length() + 2;
				this->ingredients.erase(start, end);
				break;

			case 6:
				start = this->ingredients.find("onion");
				erase = "onion";
				end = erase.length() + 2;
				this->ingredients.erase(start, end);
				break;
			default:
				cout << "incorrect entry!" << endl;
				break;
			}
		}

	}
	else
	{
		cout << "1. mozarella\n2. sausage\n3. tomato\n4. olive\n5. mushroom\n6. corn" << endl;
		cout << "Press 0 to save it." << endl;
		while (check)
		{
			cin >> choice;
			switch (choice)
			{
			case 0:
				check = false;
				break;
			case 1:
				start = this->ingredients.find("mozarella");
				erase = "mozarella";
				end = erase.length() + 2;
				this->ingredients.erase(start, end);
				break;

			case 2:
				start = this->ingredients.find("sausage");
				erase = "sausage";
				end = erase.length() + 2;
				this->ingredients.erase(start, end);
				break;

			case 3:
				start = this->ingredients.find("tomato");
				erase = "tomato";
				end = erase.length() + 2;
				this->ingredients.erase(start, end);
				break;

			case 4:
				start = this->ingredients.find("olive");
				erase = "olive";
				end = erase.length() + 2;
				this->ingredients.erase(start, end);
				break;

			case 5:
				start = this->ingredients.find("mushroom");
				erase = "mushroom";
				end = erase.length() + 2;
				this->ingredients.erase(start, end);
				break;

			case 6:
				start = this->ingredients.find("corn");
				erase = "corn";
				end = erase.length() + 2;
				this->ingredients.erase(start, end);
				break;
			default:
				cout << "incorrect entry!" << endl;
				break;
			}
		}
	}
}

Pizza::Pizza(string size, string crust_type, int pizzaType)
{
	if (pizzaType == 1)
	{
		this->name = "Chicken Pizza";
		this->ingredients = "mozarella, chicken, mushroom, corn, olive, onion, tomato";
	}
	else if (pizzaType == 2)
	{
		this->name = "Broccoli Pizza";
		this->ingredients = "mozarella, broccoli, pepperoni, olive, corn, onion";
	}
	else
	{
		this->name = "Sausage Pizza";
		this->ingredients = "mozarella, sausage, tomato, olive, mushroom, corn";
	}
	this->size = size;
	this->crust_type = crust_type;
}

