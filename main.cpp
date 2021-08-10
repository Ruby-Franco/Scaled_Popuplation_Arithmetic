#include <iostream>
#include <string>
#include <bitset>
#include <math.h> 

using namespace std; 

int main(){
	//SP-based Skewed Addition

	int xσ, xπ;
	int yσ, yπ; 

	cout << "input x: "; 
	cin >> xσ >> xπ;

	cout << "input y: " ; 
	cin >> yσ >> yπ ;

	string x = to_string(xπ);  // FIXME: drops beginning 0s 
	string y = to_string(yπ);

	int xpi = x.size();
	int ypi = y.size();

	string mxString, myString; 

	cout << xpi << " " << ypi << endl;

	for(int i = 0; i < (xpi/2);i++){
		mxString.append("1");
	}
	for(int i = xpi/2; i < xpi; i++){
		mxString.append("0");
	}

	int mx = stoi(mxString);
	cout << "mx: " << mx << endl;

	for(int i = 0; i < (ypi/2);i++){
		myString.append("0");
	}
	for(int i = ypi/2; i < ypi; i++){
		myString.append("1");
	}

	int my = stoi(myString); 	//  FIXME: drops beginning 0's
	cout << "my: " << my << endl;
	
	// turning into SP-format
	
	int a, b; // a is σ , b is π

	cout << "input first number: " ;
	cin >> a; 

	cout << "input second number: "; 
	cin >> b; 
	
	// finding absPi(# of 1s in b) and Pi(length of b)
	string s = to_string(b); 
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
	
	//finding lower(decimal form of a) and upper(length of a) sigma
	string t = to_string(a); 
	
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

