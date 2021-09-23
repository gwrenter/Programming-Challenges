//The 3n+1 Problem

#include <iostream>
using namespace std;

//Function to find the cycle size of 
//each number including endpoints
int CycleSize(int k){
    int cycle = 1;
    
    while(k != 1){
        if(k % 2 == 0){
            k = k/2;
        }
        else{
            k = k * 3 + 1;
        }
        ++cycle;
    }
    return cycle;
}

//Function that compares both inputs and then loops
//to find the maximum cycle size between endpoints
int MaxCycleLength(int i, int j){
    if(i > j){ //swap i to j in case i is greater than j
        int temp = i;
        i = j;
        j = temp;
    }
    
    int maxCycle = 0;
    
    for(; i <= j; i++){
        int cycleSize = CycleSize(i);
        
        if(cycleSize > maxCycle){
            maxCycle = cycleSize;
        }
    }
    
    return maxCycle;
}

//Function to print output formatted
void output(int i, int j, int result){
    cout << i << " " << j << " " << result << endl;
}


int main(){
    int i,j;
    while(cin >> i >> j){
        int result = MaxCycleLength(i,j);
        output(i,j,result);
    }

    return 0;
}