#include 	<iostream>

//#define DEBUG

int main(){
	int problem , result;
	std::cin >> problem;
	result = ( problem- 2558 )%2;
	#ifdef DEBUG
		std::cout << "problem : " << problem << "original is 0 (K) 1 (C) : " << result << "\n"; 
	#endif
	int input;
	while(true){
		std::cin >> input;
		if(input == 0) break;
		else result = (result+1)%2;
	}
	if(result == 0 ) std::cout << "K\n";
	else std::cout << "C\n";
}
