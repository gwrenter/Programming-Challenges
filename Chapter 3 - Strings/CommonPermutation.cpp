#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void SplitString(string str, vector<string> &vect){
	string tokenA;
	int indx = 0;
	for(int i = 0; i < str.size(); i++){
		if(str[i] == str[i+1]){
			tokenA += str[i];
		}
		else{
			tokenA += str[i];
			vect.push_back(tokenA);
			tokenA.clear();
		}
	}
}

int main(){
	string a,b;
	while(getline(cin,a) && getline(cin,b)){
		//Sorting inputs
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		
		//Creating array of sorted strings
		vector<string> strA,strB;
		SplitString(a,strA);
		SplitString(b,strB);
		
		//Comparing characters of vector strings
		string output;
		
		if(strA.size() > strB.size()){
			for(int i = 0; i < strA.size(); i++){
				for(int j = 0; j < strB.size(); j++){
					if(strA[i][0] == strB[j][0]){
						if(strA[i].size() > strB[j].size()){
							output += strB[j];
							continue;
						}else{
							output += strA[i];
							continue;
						}
					}
				}
			}
		}else{
			for(int i = 0; i < strB.size(); i++){
				for(int j = 0; j < strA.size(); j++){
					if(strB[i][0] == strA[j][0]){
						if(strB[i].size() > strA[j].size()){
							output += strA[j];
							continue;
						}else{
							output += strB[i];
							continue;
						}
					}
				}
			}
		}
		
		//Sort the output
		sort(output.begin(),output.end());
		cout << output << endl;
	}
	return 0;
}
