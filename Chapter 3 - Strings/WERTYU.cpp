#include <iostream>
#include <cstring>
using namespace std;

int main(){
	char input;
	const char *quote = "'";
	char bslash = '\\';
	char fslash = '//';
	char letterReplaced[49] = {'1','2','3','4','5','6',
							   '7','8','9','0','-','Q',
							   'W','E','R','T','Y','U',
							   'I','O','P','[',']','A',
							   'S','D','F','G','H','J',
							   'K','L',';','Z','X','C',
							   'V','B','N','M',',','.',
							   '=',bslash,fslash,*quote,
							   ' ','\n',':'};

	while(cin.get(input)){
		for(int i = 0; i < sizeof(letterReplaced)/sizeof(letterReplaced[0]); i++){
			if(input == letterReplaced[i]){
				if(input == '1'){
					cout << '`';
					continue;
				}else if(input == '='){
					cout << '-';
					continue;
				}else if(input == bslash){
					cout << ']';
					continue;
				}else if(input == *quote){
					cout << ';';
					continue;
				}else if(input == fslash){
					cout << '.';
					continue;
				}else if(input == ' '){
					cout << ' ';
					continue;
				}else if(input == '\n'){
					cout << '\n';
					continue;
				}else if(input == ':'){
					cout << ':';
					continue;
				}
				cout << letterReplaced[i-1];
			}
		}
	}
	return 0;
}
