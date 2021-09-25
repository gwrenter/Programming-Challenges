#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string strNumA,strNumB;
	while(cin >> strNumA >> strNumB){
		if(strNumA == "0" && strNumB == "0")
			return 0;
		
		vector<int> numA,numB;
		
		//Parsing strings into integers and store them in vectors
		for(int i = 0; i < strNumA.size(); i++)
			numA.push_back(strNumA[i] - 48);
			
		for(int i = 0; i < strNumB.size(); i++)
			numB.push_back(strNumB[i] - 48);
			
		//Loop and checking if sum contains carry values
		int counter = 0;
		if(numA.size() == numB.size() || numA.size() > numB.size()){
			int carry = 0;
			int bSize = numB.size()-1;
			for(int i = numA.size()-1; i >= 0; i--){
				if(bSize >= 0){
					int sum = numA[i] + numB[bSize] + carry;
					if(to_string(sum).length() == 2){
						counter++;
						carry = 1;
					}
					else
						carry = 0;
					bSize--;
				}else if(bSize < 0){
					int sum = numA[i] + 0 + carry;
					if(to_string(sum).length() == 2){
						counter++;
						carry = 1;
					}
					else
						carry = 0;
				}		
			}		
		}else{
			int carry = 0;
			int aSize = numA.size()-1;
			for(int i = numB.size()-1; i >= 0; i--){
				if(aSize >= 0){
					int sum = numA[aSize] + numB[i] + carry;
					if(to_string(sum).length() == 2){
						counter++;
						carry = 1;
					}
					else
						carry = 0;
					aSize--;
				}else if(aSize < 0){
					int sum = 0 + numB[i] + carry;
					if(to_string(sum).length() == 2){
						counter++;
						carry = 1;
					}
					else
						carry = 0;
				}		
			}	
		}
		
		if(counter > 1)
			cout << counter << " carry operations." << endl;
		else if (counter == 1)
			cout << counter << " carry operation." << endl;
		else
			cout << "No carry operation." << endl;
	}
	return 0;
}
