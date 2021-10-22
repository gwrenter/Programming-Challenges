#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;


bool IsDivisible(vector<unsigned int> nPri, vector<unsigned int> mPri,
				 vector<unsigned int> nPow, vector<unsigned int> mFreq){

	vector<bool> testDiv; 	
	
	for(int i = 0; i < mPri.size(); i++){
		if(nPow[i] >= mFreq[i])
			testDiv.push_back(true);
		else
			testDiv.push_back(false);
	}
	
	for(int i = 0; i < testDiv.size(); i++){
		if(testDiv[i] == false)
			return false;
	}
	
	return true;
}

unsigned int get_powers(unsigned int n, unsigned int p){
    unsigned int res = 0;
    for (unsigned int power = p ; power <= n ; power *= p)
        res += n/power;
        
    return res;
}

void fix_prime_vector(vector<unsigned int> vec, vector<unsigned int> &vecTemp){
	int temp = vec[0];
	vecTemp.push_back(temp);
	
	for(int i = 1; i < vec.size(); i++){
 		if(vec[i] != temp){
			temp = vec[i];
			vecTemp.push_back(temp);
		}			
	}
}

void prime_factorization(unsigned int x, vector<unsigned int> &val)
{
	unsigned int i; /* counter */
	unsigned int c; /* remaining product to factor */
	
	c = x;
	while ((c % 2) == 0) {
		//cout << 2 << endl;
		c = c / 2;
		val.push_back(2);
	}

	
	i = 3;	
	while (i <= (sqrt(c)+1)) {
		if ((c % i) == 0) {
			//cout << i << endl;
			c = c / i;
			val.push_back(i);
		}
		else
			i = i + 2;
	}

	if (c > 1){
		//cout << c << endl;
		val.push_back(c);
	}

}

int main(){
    unsigned int n,m;
	
	while(cin >> n >> m){
		if(n < m){
			vector<unsigned int> mVal,mValTemp,mFreq;
			vector<unsigned int> nVal,nValTemp,nPow;
			//Testing 0! and 1! cases
			if((n == 0 && m == 1) || (n == 1 && m == 1)){
				cout << m << " divides " << n << "!" << endl;
				continue;
			}else if((n == 0 && m != 1) || (n == 1 && m != 1)){
				cout << m << " does not divide " << n << "!" << endl;
				continue;
			}
			
			//Looking prime values of n and m
			prime_factorization(n,nVal);
			prime_factorization(m,mVal);
			
			//Getting n and m primes values without repetition
			fix_prime_vector(nVal, nValTemp);
			fix_prime_vector(mVal, mValTemp);
		
		    for(int i = 0; i < mValTemp.size(); i++)
				nPow.push_back(get_powers(n,mValTemp[i]));
            
			//Getting prime frequency of m	
			//Counting m prime values frequency
			int counter = 1;
			int tempM = mVal[0];
			for(int i = 1; i <= mVal.size(); i++){
			    if(i == mVal.size())
			        mVal[mVal.size()] = 0;
		 		if(mVal[i] != tempM){
					mFreq.push_back(counter);	
					tempM = mVal[i];
					counter = 1;
				}else if(mVal[i] == tempM)
					counter++;
				if(i == mVal.size() && mFreq.size() == 0)
				    mFreq.push_back(counter-1);
			}
			
			bool answer = IsDivisible(nValTemp,mValTemp,nPow,mFreq);
		
			if(answer)
				cout << m << " divides " << n << "!" << endl;
			else
				cout << m << " does not divide " << n << "!" << endl;	
			
			//Clear vector values
			mVal.clear();
			mValTemp.clear();
			mFreq.clear();
			nVal.clear();
			nValTemp.clear();
			nPow.clear(); 	
		}
		else if(n >= m)
			cout << m << " divides " << n << "!" << endl;
	}
	
	return 0;
}
