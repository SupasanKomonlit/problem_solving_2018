#include 	<stdio.h>

int find_sum(int problem[] , int last_unit){
	int answer  = 0 ; 
	for(int count = 0 ;
			count < last_unit ;
			count++ ){
		answer += problem[count];
	}
	std::cout << "Last Unit is " << last_unit << "  and answer is " << answer << std::endl;
	return answer;
}

int binary_search(int problem[] , int number, int start , int end ){
	int plus_or_minus = (end-start)/2-0.1 , answer = 0;
	int current_position = 0; // find start position to compare I want to bound value
	std::cout 	<< "Welcome to search is " << current_position 
				<< "plus_or_minus " << plus_or_minus // what is plus to next position 
				<< std::endl;
	for(;;){
		std::cout 	<< "Want find " 
					<< number 
					<< "number in current_position is " 
					<< problem[current_position]
					<< std::endl;
		if( problem[current_position] == number ){
			std::cout 	<< "Correct Number " 
						<< problem[current_position]
						<< std::endl;
			answer = current_position;
			break;
		}
		else if( problem[current_position] > number ){
			if( plus_or_minus == 1 ){
				if(	problem[current_position - 1] <= number 
					|| current_position < 0)	
					answer = current_position - 1;
				else answer = current_position - 2;
				std::cout 	<< "This problem[current_position] " 
							<< problem[current_position]
							<< "more than " 
							<< number
							<< " and plus_or_minus = 1 so answer is "
							<< answer << std::endl;
			}
			else{
				current_position -= plus_or_minus;
				plus_or_minus = 
			}
		}
	}
}

int main(){
	int amont_book, amont_round;
	std::cin >> amont_book >> amont_round;
	int sum_prize[amont_book], prize;
	int answer[amont_round];
	for(int count = 0 ;
			count < amont_book;
			count++){
		std::cin >> prize;
		answer[amont_round] = find_sum(answer , count ) + prize;
	}
	std::cout << "print sum_prize" << std::endl << answer << std::endl;
	
}
