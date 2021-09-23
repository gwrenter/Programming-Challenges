#include <iostream>
#include <string>
using namespace std;

string DigitSize(int size, int row, string numStr){
	string LCDNum;
	if(size == 1){
		for(int i = 0; i < row; i++){
			if(i == 0){
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '1' && numStr[j] != '4'){ LCDNum += " -  ";}
					else if(numStr[j] == '1' || numStr[j] == '4'){ LCDNum += "    ";}
				}
				LCDNum.pop_back();		
			}else if(i == 1){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] == '0' || numStr[j] == '4' || numStr[j] == '8' || numStr[j] == '9'){ LCDNum += "| | ";}
					else if(numStr[j] == '1' || numStr[j] == '2' || numStr[j] == '3' || numStr[j] == '7'){ LCDNum += "  | ";}
					else if(numStr[j] == '5' || numStr[j] == '6'){ LCDNum += "|   ";}
  				}
  				LCDNum.pop_back();
			}else if(i == 2){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '0' && numStr[j] != '1' && numStr[j] != '7'){ LCDNum += " -  ";}
					else if(numStr[j] == '0' || numStr[j] == '1' || numStr[j] == '7'){ LCDNum += "    ";}
  				}
  				LCDNum.pop_back();
			}else if(i == 3){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] == '0' || numStr[j] == '6' || numStr[j] == '8'){ LCDNum += "| | ";}
					else if(numStr[j] == '1' || numStr[j] == '3' || numStr[j] == '4' || numStr[j] == '5' || numStr[j] == '7' || numStr[j] == '9'){ LCDNum += "  | ";}
					else if(numStr[j] == '2'){ LCDNum += "|   ";}
 				}
 				LCDNum.pop_back();
			}else if(i == 4){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '1' && numStr[j] != '4' && numStr[j] != '7'){ LCDNum += " -  ";}
					else if(numStr[j] == '1' || numStr[j] == '4' || numStr[j] == '7'){ LCDNum += "    ";}
  				}
  				LCDNum.pop_back();
			}				
		}
		return LCDNum;
	}else if(size == 2){
		for(int i = 0; i < row; i++){
			if(i == 0){
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '1' && numStr[j] != '4'){ LCDNum += " --  ";}
					else if(numStr[j] == '1' || numStr[j] == '4'){ LCDNum += "     ";}
				}
				LCDNum.pop_back();		
			}else if(i == 1 || i == 2){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] == '0' || numStr[j] == '4' || numStr[j] == '8' || numStr[j] == '9'){ LCDNum += "|  | ";}
					else if(numStr[j] == '1' || numStr[j] == '2' || numStr[j] == '3' || numStr[j] == '7'){ LCDNum += "   | ";}
					else if(numStr[j] == '5' || numStr[j] == '6'){ LCDNum += "|    ";}
  				}
  				LCDNum.pop_back();
			}else if(i == 3){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '0' && numStr[j] != '1' && numStr[j] != '7'){ LCDNum += " --  ";}
					else if(numStr[j] == '0' || numStr[j] == '1' || numStr[j] == '7'){ LCDNum += "     ";}
  				}
  				LCDNum.pop_back();
			}else if(i == 4 || i == 5){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] == '0' || numStr[j] == '6' || numStr[j] == '8'){ LCDNum += "|  | ";}
					else if(numStr[j] == '1' || numStr[j] == '3' || numStr[j] == '4' || numStr[j] == '5' || numStr[j] == '7' || numStr[j] == '9'){ LCDNum += "   | ";}
					else if(numStr[j] == '2'){ LCDNum += "|    ";}
 				}
 				LCDNum.pop_back();
			}else if(i == 6){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '1' && numStr[j] != '4' && numStr[j] != '7'){ LCDNum += " --  ";}
					else if(numStr[j] == '1' || numStr[j] == '4' || numStr[j] == '7'){ LCDNum += "     ";}
  				}
  				LCDNum.pop_back();
			}				
		}	
		return LCDNum;	
	}else if(size == 3){
		for(int i = 0; i < row; i++){
			if(i == 0){
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '1' && numStr[j] != '4'){ LCDNum += " ---  ";}
					else if(numStr[j] == '1' || numStr[j] == '4'){ LCDNum += "      ";}
				}
				LCDNum.pop_back();		
			}else if(i == 1 || i == 2 || i == 3){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] == '0' || numStr[j] == '4' || numStr[j] == '8' || numStr[j] == '9'){ LCDNum += "|   | ";}
					else if(numStr[j] == '1' || numStr[j] == '2' || numStr[j] == '3' || numStr[j] == '7'){ LCDNum += "    | ";}
					else if(numStr[j] == '5' || numStr[j] == '6'){ LCDNum += "|     ";}
  				}
  				LCDNum.pop_back();
			}else if(i == 4){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '0' && numStr[j] != '1' && numStr[j] != '7'){ LCDNum += " ---  ";}
					else if(numStr[j] == '0' || numStr[j] == '1' || numStr[j] == '7'){ LCDNum += "      ";}
  				}
  				LCDNum.pop_back();
			}else if(i == 5 || i == 6 || i == 7){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] == '0' || numStr[j] == '6' || numStr[j] == '8'){ LCDNum += "|   | ";}
					else if(numStr[j] == '1' || numStr[j] == '3' || numStr[j] == '4' || numStr[j] == '5' || numStr[j] == '7' || numStr[j] == '9'){ LCDNum += "    | ";}
					else if(numStr[j] == '2'){ LCDNum += "|     ";}
 				}
 				LCDNum.pop_back();
			}else if(i == 8){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '1' && numStr[j] != '4' && numStr[j] != '7'){ LCDNum += " ---  ";}
					else if(numStr[j] == '1' || numStr[j] == '4' || numStr[j] == '7'){ LCDNum += "      ";}
  				}
  				LCDNum.pop_back();
			}
		}
		return LCDNum;
	}else if(size == 4){
		for(int i = 0; i < row; i++){
			if(i == 0){
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '1' && numStr[j] != '4'){ LCDNum += " ----  ";}
					else if(numStr[j] == '1' || numStr[j] == '4'){ LCDNum += "       ";}
				}
				LCDNum.pop_back();		
			}else if(i == 1 || i == 2 || i == 3 || i == 4){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] == '0' || numStr[j] == '4' || numStr[j] == '8' || numStr[j] == '9'){ LCDNum += "|    | ";}
					else if(numStr[j] == '1' || numStr[j] == '2' || numStr[j] == '3' || numStr[j] == '7'){ LCDNum += "     | ";}
					else if(numStr[j] == '5' || numStr[j] == '6'){ LCDNum += "|      ";}
  				}
  				LCDNum.pop_back();
			}else if(i == 5){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '0' && numStr[j] != '1' && numStr[j] != '7'){ LCDNum += " ----  ";}
					else if(numStr[j] == '0' || numStr[j] == '1' || numStr[j] == '7'){ LCDNum += "       ";}
  				}
  				LCDNum.pop_back();
			}else if(i == 6 || i == 7 || i == 8 || i == 9){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] == '0' || numStr[j] == '6' || numStr[j] == '8'){ LCDNum += "|    | ";}
					else if(numStr[j] == '1' || numStr[j] == '3' || numStr[j] == '4' || numStr[j] == '5' || numStr[j] == '7' || numStr[j] == '9'){ LCDNum += "     | ";}
					else if(numStr[j] == '2'){ LCDNum += "|      ";}
 				}
 				LCDNum.pop_back();
			}else if(i == 10){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '1' && numStr[j] != '4' && numStr[j] != '7'){ LCDNum += " ----  ";}
					else if(numStr[j] == '1' || numStr[j] == '4' || numStr[j] == '7'){ LCDNum += "       ";}
  				}
  				LCDNum.pop_back();
			}
		}
		return LCDNum;
	}else if(size == 5){
		for(int i = 0; i < row; i++){
			if(i == 0){
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '1' && numStr[j] != '4'){ LCDNum += " -----  ";}
					else if(numStr[j] == '1' || numStr[j] == '4'){ LCDNum += "        ";}
				}
				LCDNum.pop_back();		
			}else if(i == 1 || i == 2 || i == 3 || i == 4 || i == 5){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] == '0' || numStr[j] == '4' || numStr[j] == '8' || numStr[j] == '9'){ LCDNum += "|     | ";}
					else if(numStr[j] == '1' || numStr[j] == '2' || numStr[j] == '3' || numStr[j] == '7'){ LCDNum += "      | ";}
					else if(numStr[j] == '5' || numStr[j] == '6'){ LCDNum += "|       ";}
  				}
  				LCDNum.pop_back();
			}else if(i == 6){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '0' && numStr[j] != '1' && numStr[j] != '7'){ LCDNum += " -----  ";}
					else if(numStr[j] == '0' || numStr[j] == '1' || numStr[j] == '7'){ LCDNum += "        ";}
  				}
  				LCDNum.pop_back();
			}else if(i == 7 || i == 8 || i == 9 || i == 10 || i == 11){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] == '0' || numStr[j] == '6' || numStr[j] == '8'){ LCDNum += "|     | ";}
					else if(numStr[j] == '1' || numStr[j] == '3' || numStr[j] == '4' || numStr[j] == '5' || numStr[j] == '7' || numStr[j] == '9'){ LCDNum += "      | ";}
					else if(numStr[j] == '2'){ LCDNum += "|       ";}
 				}
 				LCDNum.pop_back();
			}else if(i == 12){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '1' && numStr[j] != '4' && numStr[j] != '7'){ LCDNum += " -----  ";}
					else if(numStr[j] == '1' || numStr[j] == '4' || numStr[j] == '7'){ LCDNum += "        ";}
  				}
  				LCDNum.pop_back();
			}
		}
		return LCDNum;
	}else if(size == 6){
		for(int i = 0; i < row; i++){
			if(i == 0){
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '1' && numStr[j] != '4'){ LCDNum += " ------  ";}
					else if(numStr[j] == '1' || numStr[j] == '4'){ LCDNum += "         ";}
				}
				LCDNum.pop_back();		
			}else if(i == 1 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] == '0' || numStr[j] == '4' || numStr[j] == '8' || numStr[j] == '9'){ LCDNum += "|      | ";}
					else if(numStr[j] == '1' || numStr[j] == '2' || numStr[j] == '3' || numStr[j] == '7'){ LCDNum += "       | ";}
					else if(numStr[j] == '5' || numStr[j] == '6'){ LCDNum += "|        ";}
  				}
  				LCDNum.pop_back();
			}else if(i == 7){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '0' && numStr[j] != '1' && numStr[j] != '7'){ LCDNum += " ------  ";}
					else if(numStr[j] == '0' || numStr[j] == '1' || numStr[j] == '7'){ LCDNum += "         ";}
  				}
  				LCDNum.pop_back();
			}else if(i == 8 || i == 9 || i == 10 || i == 11 || i == 12 || i == 13){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] == '0' || numStr[j] == '6' || numStr[j] == '8'){ LCDNum += "|      | ";}
					else if(numStr[j] == '1' || numStr[j] == '3' || numStr[j] == '4' || numStr[j] == '5' || numStr[j] == '7' || numStr[j] == '9'){ LCDNum += "       | ";}
					else if(numStr[j] == '2'){ LCDNum += "|        ";}
 				}
 				LCDNum.pop_back();
			}else if(i == 14){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '1' && numStr[j] != '4' && numStr[j] != '7'){ LCDNum += " ------  ";}
					else if(numStr[j] == '1' || numStr[j] == '4' || numStr[j] == '7'){ LCDNum += "         ";}
  				}
  				LCDNum.pop_back();
			}
		}
		return LCDNum;
	}else if(size == 7){
		for(int i = 0; i < row; i++){
			if(i == 0){
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '1' && numStr[j] != '4'){ LCDNum += " -------  ";}
					else if(numStr[j] == '1' || numStr[j] == '4'){ LCDNum += "          ";}
				}
				LCDNum.pop_back();		
			}else if(i == 1 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] == '0' || numStr[j] == '4' || numStr[j] == '8' || numStr[j] == '9'){ LCDNum += "|       | ";}
					else if(numStr[j] == '1' || numStr[j] == '2' || numStr[j] == '3' || numStr[j] == '7'){ LCDNum += "        | ";}
					else if(numStr[j] == '5' || numStr[j] == '6'){ LCDNum += "|         ";}
  				}
  				LCDNum.pop_back();
			}else if(i == 8){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '0' && numStr[j] != '1' && numStr[j] != '7'){ LCDNum += " -------  ";}
					else if(numStr[j] == '0' || numStr[j] == '1' || numStr[j] == '7'){ LCDNum += "          ";}
  				}
  				LCDNum.pop_back();
			}else if(i == 9 || i == 10 || i == 11 || i == 12 || i == 13 || i == 14 || i == 15){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] == '0' || numStr[j] == '6' || numStr[j] == '8'){ LCDNum += "|       | ";}
					else if(numStr[j] == '1' || numStr[j] == '3' || numStr[j] == '4' || numStr[j] == '5' || numStr[j] == '7' || numStr[j] == '9'){ LCDNum += "        | ";}
					else if(numStr[j] == '2'){ LCDNum += "|         ";}
 				}
 				LCDNum.pop_back();
			}else if(i == 16){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '1' && numStr[j] != '4' && numStr[j] != '7'){ LCDNum += " -------  ";}
					else if(numStr[j] == '1' || numStr[j] == '4' || numStr[j] == '7'){ LCDNum += "          ";}
  				}
  				LCDNum.pop_back();
			}
		}
		return LCDNum;
	}else if(size == 8){
		for(int i = 0; i < row; i++){
			if(i == 0){
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '1' && numStr[j] != '4'){ LCDNum += " --------  ";}
					else if(numStr[j] == '1' || numStr[j] == '4'){ LCDNum += "           ";}
				}
				LCDNum.pop_back();		
			}else if(i == 1 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] == '0' || numStr[j] == '4' || numStr[j] == '8' || numStr[j] == '9'){ LCDNum += "|        | ";}
					else if(numStr[j] == '1' || numStr[j] == '2' || numStr[j] == '3' || numStr[j] == '7'){ LCDNum += "         | ";}
					else if(numStr[j] == '5' || numStr[j] == '6'){ LCDNum += "|          ";}
  				}
  				LCDNum.pop_back();
			}else if(i == 9){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '0' && numStr[j] != '1' && numStr[j] != '7'){ LCDNum += " --------  ";}
					else if(numStr[j] == '0' || numStr[j] == '1' || numStr[j] == '7'){ LCDNum += "           ";}
  				}
  				LCDNum.pop_back();
			}else if(i == 10 || i == 11 || i == 12 || i == 13 || i == 14 || i == 15 || i == 16 || i == 17){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] == '0' || numStr[j] == '6' || numStr[j] == '8'){ LCDNum += "|        | ";}
					else if(numStr[j] == '1' || numStr[j] == '3' || numStr[j] == '4' || numStr[j] == '5' || numStr[j] == '7' || numStr[j] == '9'){ LCDNum += "         | ";}
					else if(numStr[j] == '2'){ LCDNum += "|          ";}
 				}
 				LCDNum.pop_back();
			}else if(i == 18){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '1' && numStr[j] != '4' && numStr[j] != '7'){ LCDNum += " --------  ";}
					else if(numStr[j] == '1' || numStr[j] == '4' || numStr[j] == '7'){ LCDNum += "           ";}
  				}
  				LCDNum.pop_back();
			}
		}
		return LCDNum;
	}else if(size == 9){
		for(int i = 0; i < row; i++){
			if(i == 0){
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '1' && numStr[j] != '4'){ LCDNum += " ---------  ";}
					else if(numStr[j] == '1' || numStr[j] == '4'){ LCDNum += "            ";}
				}
				LCDNum.pop_back();		
			}else if(i == 1 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] == '0' || numStr[j] == '4' || numStr[j] == '8' || numStr[j] == '9'){ LCDNum += "|         | ";}
					else if(numStr[j] == '1' || numStr[j] == '2' || numStr[j] == '3' || numStr[j] == '7'){ LCDNum += "          | ";}
					else if(numStr[j] == '5' || numStr[j] == '6'){ LCDNum += "|           ";}
  				}
  				LCDNum.pop_back();
			}else if(i == 10){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '0' && numStr[j] != '1' && numStr[j] != '7'){ LCDNum += " ---------  ";}
					else if(numStr[j] == '0' || numStr[j] == '1' || numStr[j] == '7'){ LCDNum += "            ";}
  				}
  				LCDNum.pop_back();
			}else if(i == 11 || i == 12 || i == 13 || i == 14 || i == 15 || i == 16 || i == 17 || i == 18 || i == 19){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] == '0' || numStr[j] == '6' || numStr[j] == '8'){ LCDNum += "|         | ";}
					else if(numStr[j] == '1' || numStr[j] == '3' || numStr[j] == '4' || numStr[j] == '5' || numStr[j] == '7' || numStr[j] == '9'){ LCDNum += "          | ";}
					else if(numStr[j] == '2'){ LCDNum += "|           ";}
 				}
 				LCDNum.pop_back();
			}else if(i == 20){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '1' && numStr[j] != '4' && numStr[j] != '7'){ LCDNum += " ---------  ";}
					else if(numStr[j] == '1' || numStr[j] == '4' || numStr[j] == '7'){ LCDNum += "            ";}
  				}
  				LCDNum.pop_back();
			}
		}
		return LCDNum;
	}else if(size == 10){
		for(int i = 0; i < row; i++){
			if(i == 0){
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '1' && numStr[j] != '4'){ LCDNum += " ----------  ";}
					else if(numStr[j] == '1' || numStr[j] == '4'){ LCDNum += "             ";}
				}
				LCDNum.pop_back();		
			}else if(i == 1 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9 || i == 10){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] == '0' || numStr[j] == '4' || numStr[j] == '8' || numStr[j] == '9'){ LCDNum += "|          | ";}
					else if(numStr[j] == '1' || numStr[j] == '2' || numStr[j] == '3' || numStr[j] == '7'){ LCDNum += "           | ";}
					else if(numStr[j] == '5' || numStr[j] == '6'){ LCDNum += "|            ";}
  				}
				LCDNum.pop_back(); 
			}else if(i == 11){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '0' && numStr[j] != '1' && numStr[j] != '7'){ LCDNum += " ----------  ";}
					else if(numStr[j] == '0' || numStr[j] == '1' || numStr[j] == '7'){ LCDNum += "             ";}
  				}
  				LCDNum.pop_back();
			}else if(i == 12 || i == 13 || i == 14 || i == 15 || i == 16 || i == 17 || i == 18 || i == 19 || i == 20 || i == 21){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] == '0' || numStr[j] == '6' || numStr[j] == '8'){ LCDNum += "|          | ";}
					else if(numStr[j] == '1' || numStr[j] == '3' || numStr[j] == '4' || numStr[j] == '5' || numStr[j] == '7' || numStr[j] == '9'){ LCDNum += "           | ";}
					else if(numStr[j] == '2'){ LCDNum += "|            ";}
 				}
 				LCDNum.pop_back();
			}else if(i == 22){
				LCDNum += "\n";
				for(int j = 0; j < numStr.length(); j++){
					if(numStr[j] != '1' && numStr[j] != '4' && numStr[j] != '7'){ LCDNum += " ----------  ";}
					else if(numStr[j] == '1' || numStr[j] == '4' || numStr[j] == '7'){ LCDNum += "             ";}
  				}
  				LCDNum.pop_back();
			}
			
		}
		return LCDNum;
	}
}


int main() {
	int size;
	string numStr;
	while(cin >> size >> numStr){
		if(size == 0 && numStr == "0")
			return 0;
			
		int row = 2 * size + 3;					
		string output = DigitSize(size,row,numStr);
		cout << output << endl << endl;	
	}						
}