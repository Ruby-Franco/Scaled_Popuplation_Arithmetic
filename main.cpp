#include <iostream>
#include <string>
#include <bitset>
#include <math.h> 
#include <stdlib.h>
#include <fstream>

using namespace std; 

float numFormat(string, string);
bool densityCheck(string, string);
void scalingUnit(string, string, string& , string&);
string generator(float);
string decTObin(float);
string multiplicationPi(string, string);
string multiplicationSigma(string, string);

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
string multiplicationPi(string piA, string piB){
	// πz = πx&πy

	int arrSize = piA.size(); 

	int arrA[arrSize];
	for(int i = 0; i < piA.size(); i++){
		arrA[i] = piA.at(i);
	} 

	int arrB[arrSize];
	for(int i = 0; i < piB.size(); i++){
		arrB[i] = piB.at(i);
	} 

	int arrResult[arrSize];
	for(int i = 0; i < piA.size(); i++){
		arrResult[i] = arrA[i] & arrB[i];
	}

	string result;
	for(int i = 0; i < arrSize; i++){
		string tmp = bitset<1>(arrResult[i]).to_string();
		result.append(tmp);
	}

	return result; 
}
string multiplicationSigma(string sigmaA, string sigmaB){

	int numA = stoi(sigmaA, nullptr, 2);;
	int numB = stoi(sigmaB, nullptr, 2);;

	int result = numA + numB; 

	string tmp = decTObin(result);
	string resultString = tmp.substr(0, 2);

	return resultString; 
}

string decTObin(float input){ //helper function decimal to binary
	int quotient = input * pow(2.0, 8.0); 
	string backwardsResult;  
	string str ;

	while(quotient > 0){
		int remainder = quotient % 2; 
		quotient = quotient/2; 
		str = bitset<1>(remainder).to_string(); 
		backwardsResult.append(str);
	} 

	string result; 
	string tmp; 
	for(int i = backwardsResult.size()-1; i >=0; i--){
		tmp = backwardsResult.at(i);
		result.append(tmp);
	}

	int shiftCounter = -1; 

	for(int i = result.size();i >= 0; i--){
		shiftCounter ++; 
		if(shiftCounter == 8){
			result.insert(i, ".");
		}
	}

	while(shiftCounter < 8){
		result.insert(0, "0");
		shiftCounter++; 
		if(shiftCounter == 8){
			result.insert(0, ".");
		}
	}


	return result; 
}
string generator(float tmp){
	string input = decTObin(tmp);
	//cout << input << endl;

	input = input.substr(2,4);

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
void scalingUnit(string a, string b, string& newSigma, string& piNew){
	int absPi = 0; 
    for(int i = 0; i < b.size(); i++){
        if(b.at(i) == 49){ // counts the 1's
            absPi++;
        }
    }
 
    int pi = b.size(); 
    float PI = float(absPi) /pi ; 
    int count = 0;

 	if(PI != 0){
 		while ( PI < 0.5){
        	PI = PI * 2;
    	    count++;
   		}
 	}else{
 		PI = (float)1/7; // (# of 1's / length of b )
 		while ( PI < 0.5){
        	PI = PI * 2;
    	    count++;
   		}

 	}

    float beta = pow (2.0, count);
  
    float numA = stoi(a, nullptr, 2);
    
    string sigmaNew = bitset<2>(count).to_string();
    int new_pi = absPi * beta;
    string piOutput ; 
    int counter = 0; 

    for(int i = 0; i <= b.size(); i++){
    	while(counter < new_pi){
    		piOutput.append("1");
    		counter ++;  
    	}
    	while(counter <= b.size()){
    		piOutput = "0" + piOutput; 
    		counter++; 
    	}
    }  

    

    piNew = piOutput; 
    newSigma = sigmaNew; 
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

	if(tmp > 0.5){
		return true;
	}
	
	return false; 
}

float numFormat(string a, string b){ // a is σ , b is π

	// finding absPi(# of 1s in b) and Pi(length of b)
	int counter = 0; 

	for(int i = 0; i < b.size(); i++){
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
int main(){
	ofstream outFS; 
	outFS.open("numbersFile.txt");

	if(!outFS.is_open()){
		cout << "Error." << endl;
		exit(1);
	}

	int counter = 0; 
	srand( (unsigned)time( NULL ) );
	while(counter < 100){
		outFS << fixed << setprecision(2) << (float) rand()/RAND_MAX << " " << (float) rand()/RAND_MAX << endl ; 
		counter++; 
	}
	cout << "numbers created " << endl;

	outFS.close(); 

	ifstream inFS; 
	inFS.open("numbersFile.txt");

	if(!inFS.is_open()){
		cout << "Could not open file "  << endl;
		exit(1);
	}

	float inputA;
	float inputB;  

	ofstream oFS; 
	oFS.open("results.csv");

	if(!oFS.is_open()){
		cout << "Error." << endl;
		exit(1);
	}

	oFS << "InputA	InputB 	A_in_Bin	B_in_Bin	AGenerator			BGenerator		DensityCheckA	DensityCheckB		Multiplication 		Actual 	Expected	%Error" << endl;
	//oFS << "InputA  InputB Actual    Expected      %Error" << endl;

	while(inFS >> inputA){
		inFS >> inputB; 
		oFS << fixed << setprecision(2) << inputA << ",	" << inputB << ",	" ;

		string A = decTObin(inputA);
		string B = decTObin(inputB);

		oFS << A << "	" << B << "	"; 

		string sigmaA = "01"; 
		string sigmaB = "01"; 
		string piA = generator(inputA); 
		string piB = generator(inputB) ; 

		oFS << "(" << sigmaA << ", " << piA << ")		" << "(" << sigmaB << ", " << piB << ")	 "; 


		string sigmaResultA; 
		string piResultA; 

		string sigmaResultB; 
		string piResultB; 

		

		if(densityCheck(sigmaA, piA)){
		 	oFS << " 	pass " << "		" ;
		}else{
			scalingUnit(sigmaA, piA, sigmaResultA, piResultA); 
			sigmaA = sigmaResultA; 
			piA = piResultA;
		  	oFS << "(" << sigmaA << ", " << piA << ")	";
		}

		if(densityCheck(sigmaB, piB)){
		 	oFS << " 	pass " << "			" ;
		}else{
			scalingUnit(sigmaB, piB, sigmaResultB, piResultB);
		 	oFS << "(" << piResultB  << ", " << sigmaResultB << ")		" ;
		 	sigmaB = sigmaResultB;
		 	piB = piResultB; 
		}

		string newSigma = multiplicationSigma(sigmaA, sigmaB); 
		string newPi = multiplicationPi(piA, piB); 

		float expected = (inputA*inputB);

		oFS << "(" <<  newSigma << ", " ; 
		oFS << newPi<< ")		"; 

		float actual = numFormat(newSigma, newPi);

		oFS << actual;
		oFS << ",		" << fixed << setprecision(2) << expected << ",";

		float error = abs( float(actual - expected) );

		oFS << "		 " << error << endl;

	}
	outFS.close(); 

	return 0; 
}
