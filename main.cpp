#include <iostream>
#include <string>
#include <bitset>
#include <math.h> 

using namespace std; 

int main(){
//SP-based Skewed Addition

	int xsigma, ysigma;
	string xpi_string, ypi_string; 

	cout << "input x: "; 
	cin >> xsigma >> xpi_string;

	cout << "input y: " ; 
	cin >> ysigma >> ypi_string;

	int xpi = xpi_string.size(); 
	int ypi = ypi_string.size();

	int arrX[xpi];
	int tmp; 
	//cout << "x: ";

	for(int i = 0; i < xpi; i++){
		tmp = (int)xpi_string.at(i) - 48;
		arrX[i] = tmp;
		//cout << arrX[i];
	}

	int arrY[ypi];
	int temp;
	//cout << endl << "y: ";  

	for(int i = 0; i < ypi; i++){
		temp = (int)ypi_string.at(i) - 48;
		arrY[i] = temp;
		//cout << arrY[i];
	}

	int mxArr[xpi];
	int myArr[ypi];

	for(int i = 0; i < (xpi/2);i++){
		mxArr[i] = 1;
	}

	for(int i = xpi/2; i < xpi;i++){
		mxArr[i] = 0;
	}

	for(int i = 0; i < (ypi/2);i++){
		myArr[i] = 0;
	}

	for(int i = (ypi/2); i < ypi;i++){
		myArr[i] = 1;
	}
	
	// cout << "results: " ; 
	// for(int i = 0; i < xpi; i++){
	// 	cout << mxArr[i]; 
	// }
	// cout << endl;
	// for(int i = 0; i < xpi; i++){
	// 	cout << myArr[i]; 
	// }
	// cout << endl;

	// int arrResult[PI];
	// cout << endl << "result: " ; 
	// for(int i = 0; i < PI; i++){
	// 	arrResult[i] = arrX[i] | arrY[i];
	// 	cout << arrResult[i];
	// }
	// cout << endl;
	
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

