/* Student Name: Merve CANDAN
	Student ID: 150160041
*/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Neuron.h"
#include "Layer.h"
#include "Network.h"

using namespace std;

int main(int argc,char** argv)
{
	int layerNum, * funcNum, * neuronNum,j,k=0;
	float* firstInputs;
	string line[4]; //four lines available
	ifstream myfile(argv[1]);
	if (myfile.is_open())
	{
		stringstream keep; // temporary to hold lines
		getline(myfile, line[0]);
		keep << line[0];
		keep >> layerNum;
		funcNum = new int[layerNum]; // free up space for each array
		neuronNum = new int[layerNum];
		firstInputs = new float[layerNum];
		for (int i = 0; i < 3; i++)
		{
			if (i == 0)
			{
				j = 0;
				stringstream keep1;
				getline(myfile, line[1]);
				keep1 << line[1];
				while (!keep1.eof())
				{
					keep1 >> neuronNum[j]; //the process of assigning numbers
					j++;
				}
			}
			else if (i == 1)
			{
				j = 0;
				stringstream keep2;
				getline(myfile, line[2]);
				keep2 << line[2];
				while (!keep2.eof())
				{
					keep2 >> funcNum[j];
					try // error checking
					{
						if(funcNum[j]>2 or funcNum[j]<0)
						{
							throw funcNum[j];
						}
					}
					catch(int type) // If a value other than 0-1-2 is taken
					{
						cout<<"Unidentified activation function!"<<endl;
						return 1;
					}
					j++;
				}
			}
			else
			{
				j = 0;
				stringstream keep3;
				getline(myfile, line[3]);
				keep3 << line[3];
				while (!keep3.eof())
				{
					keep3 >> firstInputs[j];
					j++;
					try
					{
						if(j>layerNum)
						{
							throw firstInputs[j-1]; // if more entries are received than they should be
						}
					}
					catch(float inputs)
					{
						cout<<"Input shape does not match!"<<endl;
						return 1;
					}
					
				}
			}
		}
		Network ArtificialNN; // create network
		Layer layer(firstInputs, neuronNum[k], funcNum[k], k); //create first layer
		ArtificialNN.layer_hire(layer);// add first layer
		while (k<layerNum-1)
		{
			if (k < layerNum - 1)
			{
				float** w, ** b, ** z;// for matrix operation
				w = new float* [neuronNum[k + 1]];
				b = new float* [neuronNum[k + 1]];
				z = new float* [neuronNum[k + 1]];
				for (int m = 0; m < neuronNum[k + 1]; m++)
				{
					w[m] = new float[neuronNum[k]];
					b[m] = new float[1];
					z[m] = new float[1];
					for (int n = 0; n < neuronNum[k]; n++)
					{
						w[m][n] = 0.1;
						if (!n)
						{
							b[m][n] = 0.1;
						}
					}
				}
				float sum = 0;
				for (int a = 0; a < neuronNum[k + 1]; a++)
				{
					for (int c = 0; c < neuronNum[k]; c++)
					{
						sum += w[a][c] * firstInputs[c];
					}
					z[a][0] = sum + b[a][0];
					sum = 0;
				}
				firstInputs = new float[neuronNum[k + 1]];
				for (int d = 0; d < neuronNum[k + 1]; d++)
				{
						firstInputs[d] = z[d][0];
				}
				Layer layer(firstInputs, neuronNum[k+1], funcNum[k+1], k+1);// new layer
				ArtificialNN.layer_hire(layer); // add new layer
				for (int d = 0; d < neuronNum[k + 1]; d++)
				{
						firstInputs[d] = layer.head->GetterA();
				}
			}
			k++;
		}
		ArtificialNN.display(); //screen printing section
	}
	return 0;
}


