/* Student Name: Merve CANDAN
	Student ID: 150160041
*/
#include <iostream>
using namespace std;

class Layer
{
public:
	Layer* next;
	Neuron* head; // head of the neurons list for every layer
	Layer(){}
	~Layer()
	{
		while(head)
		{
			Neuron *temp=head;
			head=head->next;
			temp=NULL;
		}
	}
	Layer(float *neuron,int num,int f,int k)
	{
		head = NULL;
		for (int i = 0; i < num; i++) // will turn up the number of noron
		{
			if (f == 0) // for neurons types
			{
				Neuron* temp = head;
				if (temp == NULL)
				{
					temp = new SigmoidNeuron(neuron[i], k);
					head = temp;
					temp->next=NULL;
				}
				else
				{
					while (temp->next)
						temp = temp->next;
					temp->next = new SigmoidNeuron(neuron[i], k);
					temp->next->next=NULL;
				}
			}
			else if (f == 1)
			{
				Neuron* temp = head;
				if (temp == NULL)
				{
					temp = new LReluNeuron(neuron[i], k);
					head = temp;
					temp->next=NULL;
				}
				else
				{
					while (temp->next)
					{
						temp = temp->next;
					}
					temp->next = new LReluNeuron(neuron[i], k);
					temp->next->next=NULL;
				}
			}
			else
			{
				Neuron* temp = head;
				if (temp == NULL)
				{
					temp = new ReluNeuron(neuron[i], k);
					head = temp;
					temp->next=NULL;
				}
				else
				{
					while (temp->next)
						temp = temp->next;
					temp->next = new ReluNeuron(neuron[i], k);
					temp->next->next=NULL;
				}
			}
		}
		
	}
	void display() // to print neurons
	{
		Neuron* keep = head;
		while (keep)
		{
			cout << keep->GetterA() << endl;
			keep = keep->next;
		}
	}
};
