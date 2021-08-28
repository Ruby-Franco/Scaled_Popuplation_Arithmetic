#include <iostream>
#include <string>
#include <bitset>
#include <math.h> 

using namespace std; 

float spFormat(string, string);
bool densityCheck(string, string);
float scalingUnit(string, string , int);
int shuffleUnit(int);

void addition(int xsigma, int ysigma, string xpi_string, string ypi_string,   string &zScal){
    
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
    
    cout << endl << "mx: " ; 
    for(int i = 0; i < xpi; i++){
        cout << mxArr[i]; 
    }
    cout << endl << "my: ";
    for(int i = 0; i < xpi; i++){
        cout << myArr[i]; 
    }
    cout << endl;
 
    int tmpX[xpi];
    cout << "results of x & mx: "; 
 
    for(int i = 0; i < xpi; i++){
        tmpX[i] = arrX[i] & mxArr[i];
        cout << tmpX[i]; 
    }
 
    int tmpY[ypi];
    cout << endl << "results of y & my: "; 
 
    for(int i = 0; i < ypi; i++){
        tmpY[i] = arrY[i] & myArr[i];
        cout << tmpY[i];
    }   
    cout << endl << endl;
 
    int scalingTerm = xsigma + ysigma; 
 
    zScal = bitset<2>(scalingTerm).to_string(); 
 
    // //int arrZ[xpi];
    // for(int i = 0; i < xpi;i++){
    //  Z[i] = tmpX[i] | tmpY[i];
    //  //cout << arrZ[i];
    // }
    // //cout << ")" <<endl;
}


int main(){
	 //SP-based Skewed Addition
    int xSigma, ySigma;
    
    string zscal;
    string xpi_String, ypi_String; 
 
    cout << "input x: "; 
    cin >> xSigma >> xpi_String;
    cout << "input y: " ; 
    cin >> ySigma >> ypi_String;
 
    int z[xpi_String.size()]; 
 
    
    addition(xSigma, ySigma, xpi_String, ypi_String, zscal);
 
    cout << "Z: (" << zscal << ", ";
    
    //for(int i = 0; i < xpi_String.size();i++){
    //  cout << z[i];
    // }
    // cout << ")" <<endl;

	
	//SP-format testing
	
	string a, b;
	cout << endl << "converting SP Format to numerical value " << endl;
	cout << "input scalingTerm: " ;
	cin >> a; 

	cout << "input second number: "; 
	cin >> b; 

	cout << endl << spFormat(a,b);
	/// menu
	int userInput; 

	cout << endl << endl << "Menu Options: " << endl << "1. convert SP number to numerical value " << endl;
	cout << "2. Skewed addition " << endl << "3. Multiplication " << endl << "4. exit" << endl; 
	
	while(cin >> userInput){
		if(userInput == 1){
			cout << "input (σ, π): "; 
			string a, b; 
			cin >> a; 
			cin >> b; 
			cout << "numerical value of the SP number: " << spFormat(a,b);
		}else if(userInput == 2){
			cout << "input int xsigma, int ysigma, string xpi, string ypi, string zScal: "; 
			// call addition function; 

		}else if(userInput == 3){

		}else if(userInput == 4){
			return 0; 
		}else{
			cout << "Invalid input. Please try again " << endl;
			cin >> userInput;
		}	
	}
	
	return 0; 
}
int shuffleUnit(int input){
	return input; 
}
float scalingUnit(string a, string b, int beta){
	int pi[b.size()];
	int temp; 

	for(int i = 0; i < b.size(); i++){
		temp = (int)b.at(i) - 48;
		pi[i] = temp;
		cout << pi[i];
	}


	if( 0 < beta && beta <= 1){
		// implement mask M
		// pi AND M 
		// shuffle
		//increase σ by 1/β
		//When β = 1, the density of the population vector π doesn’t change

	}else if(1 < beta && beta < 2){
		//scale down π by β2 by using the mask Mβ with density of 1’s being β/2, 
		// this = pi prime
		//pi' = pi&Mb/2
		//double the density of π′ by using the following equation:
		//πd = (π′|π′s)|(π′&π′s)
	}else if (beta == 2){
		//cout << shuffleUnit(pi);
		//πd = (π′|π′s)|(π′&π′s)

	}else if(beta > 2){
		// repeatedly double |π| until the remaining adjustment ratio is less than 2. 
		//Then we can use the methods mentioned above to compute π · β.
	}

	float tmp = 2.0; 
	return tmp; 
}
bool densityCheck(string a, string b){ // a is σ , b is π
	int absPi = 0; 

	for(int i = 0; i < b.size(); i++){
		//cout << s.at(i) << " "; 
		if(b.at(i) == 49){
			absPi++;
		}
	}

	int pi = b.size(); 

	int tmp = absPi /pi ; 

	if(tmp > 0.7){
		return true;
	}
	
	return false; 
}

float spFormat(string a, string b){ // a is σ , b is π

	// finding absPi(# of 1s in b) and Pi(length of b)
	int counter = 0; 

	for(int i = 0; i < b.size(); i++){
		//cout << s.at(i) << " "; 
		if(b.at(i) == 49){
			counter++;
		}
	}

	int absPi = counter; 
	int pi = b.size(); 
	
	cout << endl << "absolute value of Pi : " << absPi << endl;
	cout << "value of pi: " << pi << endl;
	
	//finding lower(decimal form of a) and upper(length of a) sigma
	
	int upperSigma = a.size(); 
	int lowerSigma = stoi(a, nullptr, 2);

	cout << "σ value: " << lowerSigma << endl;
	cout << "Σ value: " << upperSigma << endl;
	
	//finding Σ0 

	int upperSigma0 = pow (2.0, (upperSigma - 1));

	cout << "Σ0 value: " << upperSigma0 << endl;

	//finding scaling term: 2^(σ-Σ0)
    float scalingTerm = pow (2.0, (lowerSigma - upperSigma0));
    
    cout << "scaling term: " << scalingTerm << endl;
    
    //finding SP Number 
    
    float sp  = (float(absPi)/pi) * scalingTerm; 
    
    cout << endl << "numerical value of the SP number: " << sp << endl;

    return sp;
	
}
