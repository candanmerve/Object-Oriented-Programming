/* Student Name: Merve CANDAN
	Student ID: 150160041
*/
#include <iostream>
using namespace std;

class Network
{
public:
	Layer* Head; // head of the layers list
	Network() { Head = NULL; }
	~Network()
	{
		while(Head)
		{
			Layer* temp=Head;
			Head=Head->next;
			delete temp;
		}
		delete[] Head;
	}
	void layer_hire(Layer layer) // add a new layer to layers list
	{
		Layer* cur = Head;
		Layer* newLayer = new Layer();
		newLayer->head = layer.head;
		newLayer->next = NULL;
		if (cur == NULL)
		{
			Head = newLayer; // assign to head
		}
		else
		{
			while (cur->next)
				cur = cur->next;
			cur->next = newLayer;
		}

	}
	void display() // print layers
	{
		Layer* keep = Head;
		int i = 0;
		while (keep)
		{
			cout << "Layer " << i << ":" << endl;
			keep->display(); // for the print neurons
			keep = keep->next;
			i++;
		}
	}
};
