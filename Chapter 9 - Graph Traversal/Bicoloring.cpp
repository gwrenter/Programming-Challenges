#include <iostream>
#include <vector>
using namespace std;

const int ROWS = 1000;
const int COLS = 1000;
int graph[ROWS][COLS];

bool IsBicolorable(int graph[][COLS], int nVertex){
	string colorVertex[nVertex];
	colorVertex[0] = "red";
	
	for(int i = 1; i < nVertex; i++)
		colorVertex[i] = "uncolored";
	
	for(int i = 0; i < nVertex; i++){
		for(int j = 0; j < nVertex; j++){
			if(graph[i][j]){
				if(colorVertex[i] != "uncolored" &&
				   colorVertex[j] != "uncolored"){
					if(colorVertex[i] != colorVertex[j]){
						continue;
					}
					else{
						return false;
					}
				}
				else if(colorVertex[i] == "red")
					colorVertex[j] = "black";
				else if(colorVertex[i] == "black")
					colorVertex[j] = "red";
			}
		}
	}
	
	return true;
}


void Bicoloring(){
	int nVertex,nEdges; 
	int vtx1, vtx2;
	
	while(cin >> nVertex){
		if(nVertex == 0)
			break;
		else{
			cin >> nEdges;
			
			if(nEdges > 0){
				graph[nVertex][nVertex] = {0};
				
				while(nEdges--){
					cin >> vtx1 >> vtx2;
					graph[vtx1][vtx2] = 1;
					graph[vtx2][vtx1] = 1;
				}
				
				bool answer = IsBicolorable(graph,nVertex);
				
				if(answer)
					cout << "BICOLORABLE." << endl;
				else 
					cout << "NOT BICOLORABLE." << endl;
			}
			else
				cout << "BICOLORABLE." << endl;
		}
		
		//Clearing graph array
		for(int i = 0; i < nVertex; i++){
			for(int j = 0; j < nVertex; j++)
				graph[i][j] = 0;
		}
	}
}


int main() {
	Bicoloring();
	return 0;
}
