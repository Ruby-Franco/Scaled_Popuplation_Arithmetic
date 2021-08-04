#include <iostream>
#include <string>

using namespace std; 

int getVar(double);

int main(){

	double x; 
	double y; 

	cout << "input first number: " ;
	cin >> x; 
	cout << "input second number: "; 
	cin >> y; 


	cout << getVar(x) << endl; 
	cout << getVar(y) << endl;

	return 0; 
}

double getVar(double num){ //not done yet 
	return num; 
}