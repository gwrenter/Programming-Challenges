#include <iostream>
using namespace std;

int main() {
	long long numToReach;
	while(cin >> numToReach){
		bool notReached = false;
		long long numStan = 9;
		long long numOllie = 1;
		while(!notReached){
			numStan = numOllie * 9;
			numOllie = numStan * 2;
			
			if(numStan >= numToReach){
				notReached = true;
				cout << "Stan wins." << endl;
			}else if(numOllie >= numToReach){
				notReached = true;
				cout << "Ollie wins." << endl;
			}
		}
	}
	return 0;
}
