#include <iostream>
#include <vector>
using namespace std;

bool IsHartalDay(int val,int party,vector<int> hartalVector){
	int i = 0;
	while(party != 0){
		if(val % hartalVector[i] == 0)
			return true;
		i++;
		party--;
	}
	return false;
}

int main(){
	int numTests,simNum,partyNum,hartalParam,counter;
	vector<int> simVector,partyVector;
	
	cin >> numTests;
	int tempTests = numTests;
	
	while(numTests != 0){
		cin >> simNum >> partyNum;
		int tempParty = partyNum;
		vector<int> hartalVector;
		
		while(partyNum != 0){
			cin >> hartalParam;
			hartalVector.push_back(hartalParam);
			partyNum--;
		}
		
		counter = 0;
		int i = 1;
		while(i <= simNum){
			if(i % 7 != 0 && i % 7 != 6 && IsHartalDay(i,tempParty,hartalVector)){
				counter++;
			}
			i++;
		}
		cout << counter << endl;
		numTests--;	
	}
}
