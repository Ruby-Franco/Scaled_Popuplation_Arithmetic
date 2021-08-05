#include <iostream>
#include <string>
#include <bitset>
#include <math.h> 

using namespace std; 

int main(){

	int x; // inputs to be in binary format
	int y; // x is σ , y is π

	cout << "input first number: " ;
	cin >> x; 

	cout << "input second number: "; 
	cin >> y; 
	
	// finding absPi(# of 1s in y input) and Pi(# of binary length of y input)
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
	
	//finding lower(decimal form of x input) and upper(# of binary length of x) sigma
	string t = to_string(x); 
	
	int upperSigma = t.size(); 
	int lowerSigma = stoi(t, nullptr, 2);

	cout << "σ value: " << lowerSigma << endl;
	cout << "Σ value: " << upperSigma << endl;
	
	//finding Σ0 

	int upperSigma0 = pow (2.0, (upperSigma - 1));

	cout << "Σ0 value: " << upperSigma0 << endl;

	//finding scaling term: 2^(σ-Σ0)
    int scalingTerm = pow (2.0, (lowerSigma - upperSigma0));
    
    cout << "scaling term: " << scalingTerm << endl;
    
    //finding SP Number 
    
    float sp  = (float(absPi)/pi) * scalingTerm; 
    
    cout << "numerical value of the SP number x: " << sp << endl;
	
	return 0; 
}

