#include <iostream>
#include <string>
#include <bitset>
#include <math.h> 

using namespace std; 

float spFormat(string, string);
bool densityCheck(string, string);
float scalingUnit(string, string);
string generator(float);
string decTObin(float);

void addition(int xsigma, int ysigma, string xpi_string, string ypi_string, string &zScal, int z[]){
    
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
 
    //z[xpi];
     for(int i = 0; i < xpi;i++){
      z[i] = tmpX[i] | tmpY[i];
      //cout << arrZ[i];
     }
     //cout << ")" <<endl;
}
string decTObin(float input){ //helper function decimal to binary
	int quotient = input * pow(2.0, 8.0); 
	string result = "0."; 
	string str ;

	while(quotient > 0){
		int remainder = quotient % 2; 
		quotient = quotient/2; 
		str = bitset<1>(remainder).to_string(); 
		result.append(str);
	} 
	result.append("0");
	return result; 
}
string generator(float tmp){
	string input = decTObin(tmp);
	cout << input << endl;
	input = input.substr(2,4);
	cout << "input: " << input << endl;

	int counter = 0; 
	string result; 
	int cpycounter = 0; 

	for(int i = input.size() - 1; i >= 1; i--){
		int numOfCopies = pow(2.0 , counter); 
		counter++; 
		while(cpycounter < numOfCopies){
			result = result + input.at(i);
			cpycounter++; 
		}
		cpycounter = 0;
	}
	return result;
}
int main(){
	int userInput; 
	string menu = "\n Menu Options: \n 1. convert SP number to numerical value \n 2. Skewed addition \n 3. Density Check \n 4. exit \n";

	cout << menu;
	cin >> userInput;
	while(userInput != 4){
		if(userInput == 1){
			cout << "input (σ, π): "; 
			string a, b; 
			cin >> a; 
			cin >> b; 
			cout << "numerical value of the SP number: " << spFormat(a,b) << endl;
			cout << "Please input another menu option" << endl;
			cout << menu; 
			cin >> userInput; 
		}else if(userInput == 2){
    		int xSigma, ySigma;
    
    		string zscal;
    		string xpi_String, ypi_String; 
 
		    cout << "input x(σ, π): "; 
		    cin >> xSigma >> xpi_String;
		    cout << "input y(σ, π): " ; 
		    cin >> ySigma >> ypi_String;
		 
		    int z[xpi_String.size()]; 
		 
		    addition(xSigma, ySigma, xpi_String, ypi_String, zscal, z);
		 
		    cout << "Z: (" << zscal << ", ";
		    
		    for(int i = 0; i < xpi_String.size();i++){
		      cout << z[i];
		    }
		    cout << ")" << endl;
		    cout << "Please input another menu option." << endl << menu;
			cin >> userInput; 
	
		}else if(userInput == 3){
			string sigma, pi; 
			cout << "input (σ, π): " ;
			cin >> sigma >> pi; 
			if(densityCheck(sigma, pi) == true){
				cout << "Density is larger 70%." << endl;
			}else{
				cout << "Density less than 70%. Performing Scaling." << endl;
				cout << scalingUnit(sigma, pi) << endl;
			}
			cout << "Please input another menu option." << endl << menu;
			cin >> userInput; 
		}else if(userInput == 4){
			cout << "Exiting program. Have a good day!" << endl;
			return 0; 
		}else{
			cout << "Invalid input. Please try again." << endl << menu;
			cin >> userInput;
		}	
	}
	
	return 0; 
}
float scalingUnit(string a, string b){
	int absPi = 0; 

	for(int i = 0; i < b.size(); i++){
		//cout << s.at(i) << " "; 
		if(b.at(i) == 49){
			absPi++;
		}
	}

	int pi = b.size(); 

	float tmp = float(absPi) /pi ; 

    float beta = 0.7 / tmp; 
	float invBeta = 1 / beta; 

    float x = (log10 (invBeta))/(log10 (2)) ;
	cout << x <<endl; 
	
	float numA = stoi(a, nullptr, 2);
	cout << "numerical A: " << numA << endl;
	
    float sigmaNew;
    int new_pi = absPi * beta;
    cout << new_pi <<endl; 
	
    return sigmaNew; 
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

	float tmp = float(absPi) /pi ; 

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

    return sp;
	
}
