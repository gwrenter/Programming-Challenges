#include <iostream>
using namespace std;

//Define size for part of
//the values in the array
#define SIZE_ARR 673368
	
//Long long array holding first values of the sequence 
long long numSeq[SIZE_ARR] = {1,1,2,2};

//Some variables to control iteration of array in loop
long long k,currVal,bound,arrSize = 4;
	
//Long long variable to get input from the user
long long numInput;


int main(){
	//Nested loop to populate array starting at position 4
	//and finishing in value set in variable SIZE_ARR
	for(long long i = 3; arrSize < SIZE_ARR; ++i){
		for(long long j = 0; j < numSeq[i] && arrSize < SIZE_ARR; ++j){
			numSeq[arrSize++] = i;
		}		
	}
	
	
	//After part of the array is populated, get input from user
	while(cin >> numInput){
		if(numInput == 0)
			break;
		else if(numInput < SIZE_ARR){
			cout << numSeq[numInput] << endl;
			continue;
		}else{
			k = 3;
			currVal = 4;
			bound = 6;
			
			while(bound + k * numSeq[k] < numInput){
				bound += k * numSeq[k];
				currVal += numSeq[k];
				++k;
			}
		}
		
		cout << (currVal + (numInput - bound) / k) << endl;
	}	
}