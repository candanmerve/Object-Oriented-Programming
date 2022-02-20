// Merve CANDAN
// 150160041


#include <iostream>




using namespace std;






class Business: public Courier, private Owner{
private:
	Owner *ownerArray;         // owners
	int courierNumber;			// number of courier
	Courier *courierArray; 		// couriers array
	string company;			 // company name
	string location;			// address 		
public:
	Business(string company_n,string location_n,Owner *ownerArray_n,int totalOwner_n);		// constructor with 4 parameter, creating the bussiness
	void list_owners();		// list owners
	Business();	// dafult constructor
	int getOwner();		// getter
	void setOwner(int totalOwners);	// setter
	void hire_courier(Courier courier_n);	// hiring new courier
	void operator() ();		// operator overloading for printing
	void list_couriers();			// listing ocuriers
	void fire_courier(Courier courier_fire);	// firing the given courier, using operator overload == for compare
	Courier operator[] (int index);			// finding the courier with given index
	int calculate_shipment_capacity();		// calculating capacity
	~Business();	// destructroer
};




// destructor, deleting arrays
Business::~Business(){
	delete[] courierArray;
	delete[] ownerArray;
	company = "";
	location = "";
	courierNumber = 0;
}

//setter
void Business::setOwner(int totalOwner){
	ownership = 100 / totalOwner;
}

//getter
int Business::getOwner(){
	return ownership;
}
//default constructor
Business::Business(){
	
}


// creating the bussines with given parameters
Business::Business(string company_n,string location_n,Owner *ownerArray_n,int totalOwner_n){
	setOwner(totalOwner_n);
	ownerArray = ownerArray_n;
	company = company_n;
	location = location_n;
	courierNumber = 0;
}

// finding the courier with given index
Courier Business::operator[](int index){
	Courier temp;
	if(index < 0){		// if invalid index
		cout << "invalid index" << endl;
		return temp;
	}
	else if(index >= courierNumber){		// if index is over of courier number, print error
		cout << "over index number, courier number : " << courierNumber << endl;
	}
	else{	// else, courier is there, copying the object into temp object
		temp.personName = courierArray[index].personName;
		temp.personLastname = courierArray[index].personLastname;
		temp.vehicleType = courierArray[index].vehicleType;
		return temp;
	}
	return temp;
}



// operator overloading, ()
// print all the infos. Company,location,owner list, courier list
void Business::operator() (){
	cout << company << " " << location << endl;
	list_owners();
	list_couriers();
}

//listing owners
void Business::list_owners(){
	int ownerNumber = getOwner();		// getting protected variable
	int ownership_n = ownerNumber;		// set ownership percentage
	ownerNumber = 100 / ownership_n;	// set number of ownership, and iterate over array
 	for(int i = 0;i<ownerNumber;i++){
		cout << ownerArray[i].personName << " " << ownerArray[i].personLastname << "  " << ownership_n << endl;
	}
}



//hire courier, adding new courier
void Business::hire_courier(Courier courier_n){
	if(courierNumber == 0){						// if there is no courier, number++, creating array and adding new one into it
		courierNumber++;
		courierArray = new Courier[courierNumber];
		courierArray[courierNumber-1] = courier_n;
	}
	else{										// if there are couriers already, number++, copying current one into temp array, then creating another with new number
		courierNumber++;						// and copying temp into new one 
		Courier* temp = new Courier[courierNumber];
		for(int i = 0; i< courierNumber-1; i++){
			temp[i] = courierArray[i];
		}
		courierArray = new Courier[courierNumber];
		for(int i = 0; i< courierNumber-1;i++){
			courierArray[i] = temp[i];
		}
		courierArray[courierNumber-1] = courier_n;
	}
}


// listing couriers
void Business::list_couriers(){
	if(courierNumber == 0){
		cout << "No courier" << endl;
	}
	else{
		for(int i = 0; i < courierNumber; i++){
			cout << courierArray[i].personName << " " << courierArray[i].personLastname <<  " " << courierArray[i].vehicleType << endl;
		}
	}
	
}


// firing courier
void Business::fire_courier(Courier courier_fire){
	bool check = false; 	
	int counter = 0;								
	int tempNum;	
	Courier tempCompare;	
	for(int i = 0; i < courierNumber; i++){				
		tempCompare.personName = courierArray[i].personName;
		tempCompare.personLastname = courierArray[i].personLastname;
		tempCompare.vehicleType = courierArray[i].vehicleType;
		if(tempCompare == courier_fire){		// operator overloading, ==
			check = true;				// courier has been found
			tempNum = counter;			// holding the index of the given courier.
		}
		counter++;
	}
	if(check == false){		// if couldnt found the courier
		cout << "error : no courier with given index" << endl;
	}
	else{
		if(tempNum == courierNumber-1){				// if it is the last courier in list
			if(courierNumber == 1){					// if only one courier, then make courier array null
				courierArray = NULL;
				courierNumber--;
			}
			else{					// if there is more than one courier, and the given courier is the last courier
				Courier *temp = new Courier[courierNumber-1];				// creating temp array with number -1, and copy all elements until last one
				for(int i=0;i<courierNumber-1;i++){
					temp[i] = courierArray[i];
				}
				courierArray = new Courier[courierNumber-1];				// creating the array again with size-1, and compying elemtns from temp to array again 
				for(int i = 0; i< courierNumber-1;i++){
					courierArray[i] = temp[i];
				}
				courierNumber--;
			}	
		}
		else{																// if it is not last element
			Courier *temp = new Courier[courierNumber-1];					// copy first elements until given index, pass the index, copy again until finish
			for(int i = 0;i<tempNum;i++){									// then create the array again with size -1
				temp[i] = courierArray[i];									// then copy from temp to array again
			}
			for(int i = tempNum+1;i<courierNumber;i++){
				temp[i-1] = courierArray[i];
			}
			courierArray = new Courier[courierNumber-1];
			for(int i = 0; i< courierNumber-1;i++){
				courierArray[i] = temp[i];
			}
			courierNumber--;
		}
	}
}



// calculates shipment capacity
// car = 200, bicy = 10 kg, motocy = 35 kg
int Business::calculate_shipment_capacity(){
	int total = 0;
	for(int i = 0;i<courierNumber;i++){
		if(courierArray[i].vehicleType == "car"){
			total = total + 200;
		}
		else if(courierArray[i].vehicleType == "motorcycle"){
			total = total + 35;
		}
		else if(courierArray[i].vehicleType == "bicylcle"){
			total = total + 10;
		}
	}
	return total;
}
