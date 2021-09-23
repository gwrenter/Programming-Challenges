#include <iostream>
#include <cstdlib>
using namespace std;

bool IsItJolly(int seqArr[], int size){
	int i;
	int diff;
	int diffSeq[size];

	for(i = 1; i < size; i++)
		diffSeq[i] = 0;
	
	for(i = 0; i < size-1; i++){
		diff = abs(seqArr[i] - seqArr[i+1]);
		if(diff < 1 || diff > size-1 || diffSeq[diff] == 1)
			return false;
		
		diffSeq[diff] = 1;
	}
	
	if(i == size-1)
		return true;
}

int main(){
	int size;
	
	while(!(cin >> size).eof()){
		//Getting the sequence
		int seqArr[size];
		for(int i = 0; i < size; i++){
			cin >> seqArr[i];
		}
		
		//Checking if sequence is jolly or not
		bool answer = IsItJolly(seqArr,size);
		if(answer)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;
	}

	return 0;
}
