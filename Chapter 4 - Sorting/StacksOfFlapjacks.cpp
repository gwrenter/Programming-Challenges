#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

void ParseStr(string str, vector<int>& vec){
	int x;
	stringstream ss(str);
    while (ss >> x)
        vec.push_back(x);
}

bool IsStackSorted(vector<int> vec){
	int num = vec[0];
	for(int i = 1; i < vec.size(); i++){
		if(num < vec[i])
			num = vec[i];
		else
			return false;
	}
	return true;
}

int BiggestVal(vector<int> vec){
	int val = 0,num = vec[0];
	for(int i = 1; i < vec.size(); i++){
		if(num < vec[i]){
			num = vec[i];
			val = i;
		} 		
	}
	return val;
}

int main(){
	string inputs;
	while(getline(cin,inputs)){
		vector<int> vec;
		ParseStr(inputs,vec);
		
		int flipFinish = 0;
	    bool isThereZeros = false;
	    
	    //Check if vector contains zeros
		for(int i = 0; i < vec.size(); i++){
		    if(vec[i] == 0){
		        isThereZeros = true;
		        break;
		    }
		}
		
		if(isThereZeros)
		    cout << flipFinish << '\n' << flipFinish << endl;
		else{  
		    //echoing the input
		    for(int i = 0; i < vec.size(); i++){
			    if(i == vec.size()-1)
				    cout << vec[i] << endl;
			    else
				    cout << vec[i] << " ";
    		}
		}
		
		//Check if stack is sorted
		if(IsStackSorted(vec) && !isThereZeros)
			cout << flipFinish << endl;
		else if(!isThereZeros){
			stack<int> stack;
			int i = 0;
			while(!vec.empty()){
				int bigVal = BiggestVal(vec);
				//check if big value is in last pos of vector
				if(bigVal != vec.size()-1 && bigVal != 0){
					int flip = bigVal - vec.size();
					cout << abs(flip) + stack.size() << " ";
					//flip big val from found pos to first vector pos
					int front = 0;
					int back = bigVal; 
					while(front <= back){
						int temp = vec[front];
						vec[front] = vec[back];
						vec[back] = temp;
						front++;
						back--;
					}
					//flip big val from first pos to last vector pos
					flip = vec.size() - vec.size()-1;
					cout << abs(flip) + stack.size() << " ";
					front = 0;
					back = vec.size()-1;
					while(front <= back){
						int temp = vec[front];
						vec[front] = vec[back];
						vec[back] = temp;
						front++;
						back--;
					}
					stack.push(vec[vec.size()-1]);
					vec.pop_back();
				}else if(bigVal == vec.size()-1){
					//pop big val from vector and store it in stack
					stack.push(vec[vec.size()-1]);
					vec.pop_back();
				}else if(bigVal == 0){
					//flip big val from first pos to last vector pos
					int flip = vec.size() - vec.size()-1;
					cout << abs(flip) + stack.size() << " ";
					int front = 0;
					int back = vec.size()-1;
					while(front <= back){
						int temp = vec[front];
						vec[front] = vec[back];
						vec[back] = temp;
						front++;
						back--;
					}
					stack.push(vec[vec.size()-1]);
					vec.pop_back();
				}
			}
			cout << flipFinish << endl;
		}
	}

	return 0;
}
