// Merve CANDAN
// 150160041


#include <iostream>



using namespace std;





class Courier: public Person{
public:
	string vehicleType;	// vehicle type, car bicycle or motorcycle
	Courier();		// dafult const
	Courier(string personName_n,string personLastname_n,string vehicleType_n);	// constructror	
	int operator== (Courier temp);		// operator == loading
	~Courier();		// destructor
};

//destructor
Courier::~Courier(){

}
//dafult constructor
Courier::Courier(){

}

//Constructor with 3 parameter
Courier::Courier(string personName_n,string personLastname_n,string vehicleType_n){
	if(vehicleType_n == "bicycle" || vehicleType_n == "motorcycle" || vehicleType_n == "car"){			// check if the vehicle is proper, if yes then initialize the constructor, if no print error
		personName = personName_n;
		personLastname = personLastname_n;
		vehicleType = vehicleType_n;
	}
	else{
		cout << "Error: Name of vehicle does not exist." << endl;
	}
}

// operator overloading, ==, for compare, if equals, reutnr 1, otherwise reutnr 0
int Courier::operator== (Courier temp){
	if(temp.personName == personName){
		if(temp.personLastname == personLastname){
			if(temp.vehicleType == vehicleType){
				return 1;
			}
		}
	}
	else{
		return 0;
	}
	return 0;
}
