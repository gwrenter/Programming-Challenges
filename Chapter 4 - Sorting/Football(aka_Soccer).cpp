#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

void SortingVectors(int i, int j, vector<string> &teamVector, vector<int> &numPts, vector<int> &gamesPlayed, vector<int> &numWins,
                    vector<int> &numTies, vector<int> &numLoses, vector<int> &gDiff, vector<int> &numGScored, vector<int> &numGAgainst){
    string tempTeam = teamVector[j];
	int tempPts = numPts[j], tempGames = gamesPlayed[j], tempWins = numWins[j],
		tempTies = numTies[j], tempLoses = numLoses[j], tempDiff = gDiff[j], 
		tempScored = numGScored[j], tempAgainst = numGAgainst[j];
	
	    teamVector[j] = teamVector[i];
		teamVector[i] = tempTeam;
				
		numPts[j] = numPts[i];
		numPts[i] = tempPts;
				
		gamesPlayed[j] = gamesPlayed[i];
		gamesPlayed[i] = tempGames;
				
		numWins[j] = numWins[i];
		numWins[i] = tempWins;
				
		numTies[j] = numTies[i];
		numTies[i] = tempTies;
				
		numLoses[j] = numLoses[i];
		numLoses[i] = tempLoses;
				
		gDiff[j] = gDiff[i];
		gDiff[i] = tempDiff;
				
		numGScored[j] = numGScored[i];
		numGScored[i] = tempScored;
				
		numGAgainst[j] = numGAgainst[i];
		numGAgainst[i] = tempAgainst;
}


void GroupTables(vector<string> teamVector, vector<string> lTeam, vector<string> vTeam, vector<int> lGoals, vector<int> vGoals){
	vector<int> gamesPlayed,numPts,numWins,numLoses,numTies,numGScored,numGAgainst,gDiff;
	
	for(int i = 0; i < teamVector.size(); i++){
		int numGames = 0, pts = 0, wins = 0, loses = 0, ties = 0, gScored = 0, gAgainst = 0;
		for(int j = 0; j < lTeam.size(); j++){
			if(teamVector[i] == lTeam[j]){
				numGames++;
				if(lGoals[j] > vGoals[j]){
					pts += 3;
					wins++;
					gScored += lGoals[j];
					gAgainst += vGoals[j];
				}else if(lGoals[j] < vGoals[j]){
					pts += 0;
					loses++;
					gScored += lGoals[j];
					gAgainst += vGoals[j];
				}else{
					pts += 1;
					ties++;
					gScored += lGoals[j];
					gAgainst += vGoals[j];
				}
			}
			else if(teamVector[i] == vTeam[j]){
				numGames++;
				if(lGoals[j] < vGoals[j]){
					pts += 3;
					wins++;
					gScored += vGoals[j];
					gAgainst += lGoals[j];
				}else if(lGoals[j] > vGoals[j]){
					pts += 0;
					loses++;
					gScored += vGoals[j];
					gAgainst += lGoals[j];
				}else{
					pts += 1;
					ties++;
					gScored += vGoals[j];
					gAgainst += lGoals[j];
				}	
			}	
		}
		int gDifference = gScored - gAgainst;
		gamesPlayed.push_back(numGames);
		numPts.push_back(pts);
		numWins.push_back(wins);
		numLoses.push_back(loses);
		numTies.push_back(ties);
		numGScored.push_back(gScored);
		numGAgainst.push_back(gAgainst);
		gDiff.push_back(gDifference);
	}
	
	for(int i = 0; i < numPts.size(); i++){
		for(int j = i+1; j < numPts.size(); j++){
			//sort by most pts
			if(numPts[i] < numPts[j])
		        SortingVectors(i,j,teamVector,numPts,gamesPlayed,numWins,numTies,numLoses,gDiff,numGScored,numGAgainst);
			else if(numPts[i] > numPts[j])
				continue;
			else{
				//sort by most wins
				if(numWins[i] < numWins[j])
					SortingVectors(i,j,teamVector,numPts,gamesPlayed,numWins,numTies,numLoses,gDiff,numGScored,numGAgainst);
				else if(numWins[i] > numWins[j])
					continue;
				else{
					//sort by most goal difference
					if(gDiff[i] < gDiff[j])
						SortingVectors(i,j,teamVector,numPts,gamesPlayed,numWins,numTies,numLoses,gDiff,numGScored,numGAgainst);
					else if(gDiff[i] > gDiff[j])
						continue;
					else{
						//sort by most goals scored
						if(numGScored[i] < numGScored[j])
							SortingVectors(i,j,teamVector,numPts,gamesPlayed,numWins,numTies,numLoses,gDiff,numGScored,numGAgainst);
						else if(numGScored[i] > numGScored[j])
							continue;
						else{
							//sort by fewest games played
							if(gamesPlayed[i] > gamesPlayed[j])
								SortingVectors(i,j,teamVector,numPts,gamesPlayed,numWins,numTies,numLoses,gDiff,numGScored,numGAgainst);
							else if(gamesPlayed[i] < gamesPlayed[j])
								continue;
							else{
								//sort by case-insensitive lex order
								vector<string> temp = teamVector;
								
								for(int i = 0; i < temp.size(); i++){
									string str = temp[i];
									int j = 0;
									while(str[j]){
										str[j] = tolower(str[j]);
										j++;
									}
									temp[i] = str;
								}
								
								
								if(temp[i] > temp[j]){
									SortingVectors(i,j,teamVector,numPts,gamesPlayed,numWins,numTies,numLoses,gDiff,numGScored,numGAgainst);
								}
								else
							        continue;
							}
						}
					}
				}
			}		
		}	
	} 
	
	//Print final output
	int pos = 1;
	for(int i = 0; i < teamVector.size(); i++){
		cout << pos << ") " << teamVector[i] << " "
		     << numPts[i] << "p, " << gamesPlayed[i] << "g ("
			 << numWins[i] << "-" << numTies[i] << "-"
			 << numLoses[i] << "), " << gDiff[i] << "gd ("
			 << numGScored[i] << "-" << numGAgainst[i] << ")"
			 << endl;
		pos++;
	}
}





int main() {
	//Getting number of tests
	int numTests;
	cin >> numTests;
	cin.ignore();
	while(numTests--){
		vector<string> teamVector,localTeam,visitorTeam;
		vector<int> localGoals,visitorGoals;
		
		//Getting tournament name
		string tournament;
		getline(cin,tournament);
		
		//Getting number of teams
		int numTeams;
		cin >> numTeams;
		cin.ignore();
		
		int temp = numTeams;
		while(numTeams--){
			//Getting team name
			string teamName;
			getline(cin,teamName);
			teamVector.push_back(teamName);
		}
	
		//Getting number of results
		int numResults;
		cin >> numResults;
		cin.ignore();
		
		while(numResults--){
			string local,visitor,locGoal,visGoal;
			int lGoal,vGoal;
			
			getline(cin,local,'#');
			localTeam.push_back(local);
			
			getline(cin,locGoal,'@');
			stringstream strLGoal(locGoal);
			strLGoal >> lGoal;
			localGoals.push_back(lGoal);
			
			getline(cin,visGoal,'#');
			stringstream strVGoal(visGoal);
			strVGoal >> vGoal;
			visitorGoals.push_back(vGoal);
			
			getline(cin,visitor);
			visitorTeam.push_back(visitor);
		}
		
		//Printing tournament name
		cout << tournament << endl;
		
		//Printing group table sorted
		GroupTables(teamVector,localTeam,visitorTeam,localGoals,visitorGoals);
		
		if(numTests != 0)
			cout << endl;
	}
	return 0;
}
