#include	<iostream>

#define debug 

int factorial(int number , int last){
	int answer = 1;
	for(int count = last ; count < number ; count++) answer*=number;
	return answer;
}

int main(){
	int problem;
	std::cin >> problem;
	
	#ifdef debug
		std::cout << "print problem " << problem << "\n";
	#endif

	int* answer = new int[problem];
	int solve;
	int amont_sign , amont_swap;
	for( int count = 0 ; count < problem ; count++){
		std::cin >> solve;
		#ifdef debug
			std::cout << "print solve : " << solve << "\n";
		#endif
	}
	for( int count = 0 ; count < problem ; count++){
		std::cout << answer[count] << "\n";
	}
}
