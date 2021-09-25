#include <iostream>
#include <string>
using namespace std;

int ReverseNum(long long num){
	string numStr = to_string(num), revNumStr;
	
	for(int i = numStr.size()-1; i >= 0; i--){
		revNumStr += numStr[i]; 
	}
	long long revNum = stoi(revNumStr);
	
	return revNum;
}

bool isThereAPalindrome(long num){
	string strDig = to_string(num);
	
	if(num < 10)
		return true;
	else{
		int j = 0;
		for(int i = strDig.size()-1; i >= 0; i--){
			if(strDig[i] == strDig[j])
				j++;
			else
				return false;
		}
	}
	
	return true;
}

int main() {
	int tests;
	cin >> tests;
	
	while(tests--){
		int numIter = 0;
		long long num, resSum = 0, revNum = 0;
		bool isPalindrome = false;
		cin >> num;
		
		while(!isPalindrome){
			numIter++;
			if(numIter > 1000 || resSum > 4294967295)
				break;
				
			revNum = ReverseNum(num);
			resSum = num + revNum;
			num = resSum;
			isPalindrome = isThereAPalindrome(resSum);
		}
		
		cout << numIter << " " << resSum << endl;
		
	}
	return 0;
}
