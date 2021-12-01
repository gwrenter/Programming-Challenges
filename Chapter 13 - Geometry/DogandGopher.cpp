#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

void DogGopher(){
	float numHoles,dhDist,ghDist,xG,yG,xD,yD;
	vector<float> xH, yH;
	while(cin >> numHoles){
		cin >> xG >> yG >> xD >> yD;
		for(int i = 0; i < numHoles; i++){
			float xCoord, yCoord;
			cin >> xCoord >> yCoord;
			xH.push_back(xCoord);
			yH.push_back(yCoord);
		}
		int i;
		for(i = 0; i < numHoles; i++){
			dhDist = sqrt((pow(xD-xH[i],2)) + (pow(yD-yH[i],2)));
			ghDist = sqrt((pow(xG-xH[i],2)) + (pow(yG-yH[i],2)));
			if(dhDist >= 2*ghDist)
				break;	
		}
		
		if(dhDist >= 2*ghDist)
			cout << fixed << setprecision(3) << "The gopher can escape through the hole at ("
			 	 << xH[i] << "," << yH[i] << ")." << endl;
		else
			cout << "The gopher cannot escape." << endl;
			
		xH.clear();
		yH.clear();	
	}
}

int main() {
	DogGopher();
	return 0;
}

