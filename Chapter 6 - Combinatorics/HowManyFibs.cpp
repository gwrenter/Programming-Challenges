#include <iostream>
#include <vector>
using namespace std;

int CountFibonacci(string a, string b, vector<int> vecA, vector<int> vecB){
	int fib = 0;
	vector<int> addArr;
	
	for(int i = 0; i < a.size(); i++)
		vecA.push_back((int)a[i] - 48);
	
	for(int i = 0; i < b.size(); i++)
		vecB.push_back((int)b[i] - 48);
		
	if(a.size() < b.size()){
		addArr = vecA;
		addArr[addArr.size()-1] += 1;
		
		cout << addArr[1] << endl;
		
		for(int i = a.size()-1; i >= 0; i--)
			vecA[i] += addArr[i];
			
		//for(int i = 0; i < a.size(); i++)
		//	cout << vecA[i];
		//cout << endl;
		
	}else if(a.size() > b.size()){
		addArr = vecB;
	}else{
		
	}
}


int main() {
	string numA, numB;
	vector<int> vecA, vecB;
	
	while(cin >> numA >> numB){
		if(numA == "0" && numB == "0")
			return 0;
		else{
			int numFibonacci = CountFibonacci(numA,numB,vecA,vecB);
		}
	}
	return 0;
}
