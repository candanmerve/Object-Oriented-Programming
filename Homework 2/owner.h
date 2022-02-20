// Merve CANDAN
// 150160041

#include <iostream>
#include <string>
using namespace std;





class Owner: public Person{
protected:
	int ownership;  // ownership percentages of the owners
public:
	Owner(string name_n,string surname_n);	// const with 2 parameter
	Owner();
	~Owner();
};	
//destructor
Owner::~Owner(){

}

//default const
Owner::Owner(){
}

// constructorwith 2 parameters
// adding the owner
Owner::Owner(string name_n,string surname_n){
	personName = name_n;
	personLastname = surname_n;

}
