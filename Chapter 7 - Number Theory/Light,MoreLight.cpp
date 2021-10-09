#include <iostream>
#include <math.h>
using namespace std;

int main() {
    //Variable with max size 2^32-1
	unsigned int numBulb;
	
	//Loop that gets input from user
	//and perform problem solution
	while(cin >> numBulb){
	    //Compares if user input is zero
	    //and exits the problem is it is true
		if(numBulb == 0)
			break;
		
		//Comparing if input gets a perfect square root or not
		//print 'yes' if true; otherwise print 'no'
		if(ceil((double)sqrt(numBulb)) == floor((double)sqrt(numBulb)))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}
