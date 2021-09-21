//Minesweeper

#include <iostream>
#include <string>   
using namespace std;

//Function to find the number of adjacent mines
string findingMines(string *field, int row, int col){
    string answer;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(field[i][j] == '*'){
                answer += '*';
            }
            else if(field[i][j] == '.'){
                bool mineFound = true,adjSqr1 = true,adjSqr2 = true,
                     adjSqr3 = true,adjSqr4 = true,adjSqr5 = true,
                     adjSqr6 = true,adjSqr7 = true,adjSqr8 = true;
                int numMines = 0;
                
                
                while(mineFound){
                    if(i != 0 && j != 0 && field[i-1][j-1] == '*' && adjSqr1){
                        numMines++;
                        adjSqr1 = false;
                    }
                    else if(i != 0 && field[i-1][j] == '*' && adjSqr2){
                        numMines++;
                        adjSqr2 = false;
                    }
                    else if(i != 0 && j != col-1 && field[i-1][j+1] == '*' && adjSqr3){
                        numMines++;
                        adjSqr3 = false;
                    }
                    else if(j != 0 && field[i][j-1] == '*' && adjSqr4){
                        numMines++;
                        adjSqr4 = false;
                    }
                    else if(j != col-1 && field[i][j+1] == '*' && adjSqr5){
                        numMines++;
                        adjSqr5 = false;
                    }
                    else if(i != row-1 && j != 0 && field[i+1][j-1] == '*' && adjSqr6){
                        numMines++;
                        adjSqr6 = false;
                    }
                    else if(i != row-1 && field[i+1][j] == '*' && adjSqr7){
                        numMines++;
                        adjSqr7 = false;
                    }
                    else if(i != row-1 && j != col-1 && field[i+1][j+1] == '*' && adjSqr8){
                        numMines++;
                        adjSqr8 = false;
                    }
                    else{
                        mineFound = false;
                    }
                }
                string s = to_string(numMines);  //cast integer into string
                answer += s;
            }
        }
        answer += '\n';
    }
    return answer;
}
    
    
int main(){
    const int MAX_FIELD = 100;
    int row, col, index, fieldCounter = 0;
    
    while(cin >> row >> col){
        if(row != 0 && col != 0){
            fieldCounter++;
            if(fieldCounter != 1){
                cout << endl;
            }
            string field[MAX_FIELD];
            index = 0;
        
            do{
                cin >> field[index];
                row--;
                index++;
            }while(row != 0 && field[index-1].size() == col);
        
            row = index;
            string answer;
            answer = findingMines(field,row,col);
    
            cout << "Field #" << fieldCounter << ":" << endl;
            cout << answer;
        }
        else{
            break;
        }
    }
    return 0;
}