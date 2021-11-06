#include <iostream>
#include <vector>
using namespace std;

const int WIDTH = 1000;
const int HEIGHT = 1000;
int slashMaze[WIDTH][HEIGHT];
bool visited[WIDTH][HEIGHT];

bool IsACycle(int maze[][WIDTH], bool visited[][WIDTH], int length, int height, int width, int row, int col){
	
	if(length >= 4){
	   if(maze[row-1][col] == 3 && visited[row-1][col] == true) //check up
        	return true;
        else if(maze[row+1][col] == 3 && visited[row+1][col] == true) //check down
        	return true;
        else if(maze[row][col-1] == 3 && visited[row][col-1] == true) //check left
        	return true;
        else if(maze[row][col+1] == 3 && visited[row][col+1] == true) //check right
        	return true;
        else if(maze[row-1][col+1] == 3 && maze[row][col+1] != 1 && visited[row-1][col+1] == true) //upper right
        	return true;
        else if(maze[row-1][col-1] == 3 && maze[row][col-1] != 2 && visited[row-1][col-1] == true) //upper left
        	return true;
        else if(maze[row+1][col+1] == 3 && maze[row][col+1] != 2 && visited[row+1][col+1] == true) //bottom right
        	return true;
        else if(maze[row+1][col-1] == 3 && maze[row][col-1] != 1 && visited[row+1][col-1] == true)  //bottom left
        	return true; 
	}
	return false;
}


void FindPath(int maze[][WIDTH], int height, int width, bool &pathNotFound, int &row, int &col){
    
    pathNotFound = true;
    
	for(row = 1; row < height*2; row++){
		for(col = 1; col < width*2; col++){
			if(maze[row][col] == 0){
				pathNotFound = false;
				break;
			}
		}
		if(!pathNotFound)
			break;
	}
}

void MazeCycle(int maze[][WIDTH], int height, int width, int row, int col, int numMaze){

	int counter = 0, length = 1;
	bool completed = false;
	vector<int> cycleLength;
	cycleLength.push_back(0);

    //Clearing visited array after every test case
    for(int i = 0; i < height*2; i++){
        for(int j = 0; j < width*2; j++){
            visited[i][j] = 0;
        }
    }


    if(maze[1][1] == 0)
        visited[1][1] = true;
        
    
	while(!completed){
		if(maze[row][col] == 0){
			if(maze[row-1][col] == 0){ //check up
				maze[row][col] = 3; //set as visited
				row = row-1;
				length++;
			} 
			else if(maze[row+1][col] == 0){ //check down
				maze[row][col] = 3; //set as visited
				row = row+1;
				length++;
			} 	
			else if(maze[row][col-1] == 0){ //check left
				maze[row][col] = 3; //set as visited
				col = col-1;
				length++;
			} 
			else if(maze[row][col+1] == 0){ //check right
				maze[row][col] = 3; //set as visited
				col = col+1;
				length++;
			} 
			else if(maze[row-1][col+1] == 0 && maze[row][col+1] != 1){  //upper right
				maze[row][col] = 3; //set as visited
				row = row-1;
				col = col+1;
				length++;
			}
			else if(maze[row-1][col-1] == 0 && maze[row][col-1] != 2){ //upper left
				maze[row][col] = 3; //set as visited
				row = row-1;
				col = col-1;
				length++;
			} 
			else if(maze[row+1][col+1] == 0 && maze[row][col+1] != 2){ //bottom right
				maze[row][col] = 3; //set as visited
				row = row+1;
				col = col+1;
				length++;
			} 
			else if(maze[row+1][col-1] == 0 && maze[row][col-1] != 1){  //bottom left
				maze[row][col] = 3; //set as visited
				row = row+1;
				col = col-1;
				length++;
			}
			else{
				maze[row][col] = 3;
				if(IsACycle(maze,visited,length,height,width,row,col)){
					counter++;
					cycleLength.push_back(length);
				}
			}
		}
		else if(maze[row][col] != 0){
			length = 0;
			FindPath(maze,height,width,completed,row,col);
			length++; //start counting length of possible cycle
			visited[row][col] = true;
		}
	}
	
	int maxLength = cycleLength[0];
	for(int i = 0; i < cycleLength.size(); i++){
	    if(maxLength < cycleLength[i])
	        maxLength = cycleLength[i];
	}
	
	cout << "Maze #" << numMaze << ":" << endl;
	
	if(counter > 0)
	    cout << counter << " Cycles;" << " the longest has length " << maxLength << "." << endl << endl;
	else
	    cout << "There are no cycles." << endl << endl;
	
    cycleLength.clear();
	
}

void SlashMaze(){
	int wMaze, hMaze, numMaze = 0; //width and height of the maze
	
	while(cin >> wMaze >> hMaze){
		if(wMaze == 0 && hMaze == 0)
			break;
			
		int i = hMaze;
		char slash;
		slashMaze[hMaze][wMaze];
		int a = 0, b = 0;
		
		while(i--){
			int j = wMaze;
			b = 0;
			while(j--){
				cin >> slash;
				if(slash == '\\'){
					slashMaze[a][b] = 1;
					slashMaze[a][b+1] = 0;
					slashMaze[a+1][b] = 0;
					slashMaze[a+1][b+1] = 1;
				}
				else if(slash == '/'){
					slashMaze[a][b] = 0;
					slashMaze[a][b+1] = 2;
					slashMaze[a+1][b] = 2;
					slashMaze[a+1][b+1] = 0;
				}
				b = b + 2;
			}
			a = a + 2;
		}
		
		//Changing boundary 0s to 3s since they
		//do not form cycles in the matrix
		for(int i = 0; i < hMaze*2; i++){
			if(slashMaze[i][0] == 0)
				slashMaze[i][0] = 3;
			if(slashMaze[i][(wMaze*2)-1] == 0)
				slashMaze[i][(wMaze*2)-1] = 3;
		}
		for(int j = 0; j < wMaze*2; j++){
			if(slashMaze[0][j] == 0)
				slashMaze[0][j] = 3;
			if(slashMaze[(hMaze*2)-1][j] == 0)
				slashMaze[(hMaze*2)-1][j] = 3;
		}
		
		numMaze++;
		MazeCycle(slashMaze,hMaze,wMaze,1,1,numMaze);
	}
}


int main() {
	SlashMaze();
	return 0;
}
