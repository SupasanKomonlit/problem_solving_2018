#include <iostream>

int main(){
	int amont;
	int problem;
	std::cin >> amont;
	int* answer = new int[amont];
	for(int count = 0 ; count < amont ; count++){
		std::cin >> problem;
		if(problem == 1) answer[count] = 1;
		else if(problem == 2) answer[count] = 3;
		else if(problem == 3) answer[count] = 13;
		else if(problem == 4) answer[count] = 73;
	}
	for(int count = 0 ; count < amont; count++){
		std::cout << answer[count] << "\n";
	}
}
