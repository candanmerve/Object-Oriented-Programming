/* Student Name: Merve CANDAN
	Student ID: 150160041
*/
#include <iostream>
#include <math.h>
using namespace std;

class Neuron // abstract base class
{
protected:
	float zValue, aValue; // noron values
public:
	virtual void activate(float,int) = 0; // common function
	Neuron* next;
	void SetterZ(float z)
	{
		zValue = z;
	}
	void SetterA(float A)
	{
		aValue = A;
	}
	float GetterZ()
	{
		return zValue;
	}
	float GetterA()
	{
		return aValue;
	}
	Neuron(){}
};

			//noron types 

class   SigmoidNeuron :public Neuron
{
public:
	void activate(float Z,int k)
	{
		if (!k)
			SetterA(Z);
		else 
			SetterA(1 / (1 + exp(-Z)));
	}
	SigmoidNeuron(float I,int k)
	{
		SetterZ(I);
		activate(I, k);
	}
};

class  LReluNeuron :public Neuron
{
public:
	void activate(float Z, int k)
	{
		if (!k)
			SetterA(Z);
		else
		{
			if (Z * 0.1 < Z)
				SetterA(Z);
			else
				SetterA(Z * 0.1);
		}
	}
	LReluNeuron(float I, int k)
	{
		SetterZ(I);
		activate(I, k);
	}
};

class  ReluNeuron :public Neuron
{
public:
	void activate(float Z, int k)
	{
		if (!k)
			SetterA(Z);
		else
		{
			if (Z < 0)
				SetterA(0);
			else
				SetterA(Z);
		}
	}
	ReluNeuron(float I, int k)
	{
		SetterZ(I);
		activate(I, k);
	}
};
