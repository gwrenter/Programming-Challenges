#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int numTests;
	cin >> numTests;
	
	while(numTests--){
		int numRelatives, numStreet;
		vector<int> stVector;
		cin >> numRelatives;
		
		while(numRelatives--){
			cin >> numStreet;
			stVector.push_back(numStreet);
		}
		
		//Sorting streets from vector
		sort(stVector.begin(), stVector.end());
		
		//Check if the vector size is even or odd
		int distance = 0;
		if(stVector.size() % 2 == 0){
			int optimalSt = stVector.size()/2;
			for(int i = 0; i < stVector.size(); i++){
				if(i != optimalSt-1)
					distance += abs(stVector[optimalSt-1] - stVector[i]);
			}
		}else{
			int optimalSt = floor((float)stVector.size()/2);
			for(int i = 0; i < stVector.size(); i++){
				if(i != optimalSt){
					distance += abs(stVector[optimalSt] - stVector[i]);
				}
			}
		}
		
		cout << distance << endl;
	}
	return 0;
}
