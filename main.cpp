#include <iostream>
#include <string>
#include <bitset>

using namespace std; 

int main(){

	int x; // inputs to be in binary format
	int y; // x is σ , y is π

	cout << "input first number: " ;
	cin >> x; 

	cout << "input second number: "; 
	cin >> y; 

	// ** FIXME: find value of absPi using .count(); 

	string s = to_string(y); 
	int counter = 0; 

	for(int i = 0; i < s.size(); i++){
		//cout << s.at(i) << " "; 
		if(s.at(i) == 49){
			counter++;
		}
	}

	int absPi = counter; 
	int pi = s.size(); 
	
	cout << "absolute value of Pi : " << absPi << endl;
	cout << "value of pi: " << pi << endl;


	return 0; 
}
