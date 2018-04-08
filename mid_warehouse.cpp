#include 	<iostream>

#define 	debug

int find_min(int a , int b){
	if (a < b) return a;
	else return b;
}

int find_max(int a , int b){
	if(a < b) return b;
	else return a;
}

int main(){
	int amont_station , amont_question , amont_line;
	std::cin >> amont_station >> amont_line >> amont_question;
	#ifdef debug
		std::cout 	<< "number of station is " << amont_station
					<< "\nnumber of line is " << amont_line
					<< "\nnumber of question is " << amont_question << "\n";
	#endif
	int connect_table[amont_station][amont_station];
	int original_check[amont_station];
	for(int row = 0 ; row < amont_station ; row++){
		for(int column = 0 ; column < amont_station ; column++)
			if (column == row) connect_table[row][column] = 1;
			else connect_table[row][column] = 0;
		original_check[amont_station] = -1;
	}
	int input_01 , input_02 , max , min;
	for(int count = 0 ; count < amont_line ; count++){
		std::cin >> input_01 >> input_02;
		max = find_max(input_01 , input_02);
		min = find_min(input_01 , input_02);
		#ifdef debug
			std::cout	<< "max value is " << max << "and min value is " << min << "\n";
		#endif
		connect_table[min-1][max-1] = 1;
		original_check[min-1] = 0;
		#ifdef debug
			std::cout 	<< "print after add\n";
			std::cout 	<< "  ";
			for(int print_row = 1 ; print_row <= amont_station ; print_row++)
				std::cout << print_row << " ";
			std::cout 	<< "\n"; 
			for(int print_row = 0 ; print_row < amont_station ; print_row++){
				std::cout << print_row+1 << " ";
				for(int print_column = 0 ; print_column < amont_station ; print_column++){
					std::cout << connect_table[print_row][print_column] << " ";
				}
				std::cout << "\n--------------------------\n";
			}
		#endif
	}
	#ifdef debug
		std::cout 	<< "----------question----------------\n";
	#endif
	int answer[amont_question];
	for(int count = 0 ; count < amont_question ; count++){
		int current_check[amont_station] = original_check;
		std::cin >> input_01 >> input_02;
		max = find_max(input_01 , input_02);
		min = find_min(input_01 , input_02);
		for(int row = 0 ; row < min ; row++){
			if( connect_table[row][min-1] == 0 || 
				current_check[row] == -1 || 
				current_check[row] == 1){
				#ifdef debug 
					std::cout << row << "not connect to " << min-1 << "\n";
				#endif
				continue;
			}
			else{
				#ifdef debug
					std::cout << row << "connect to " << min-1 << "\n";
				#endif
				for(int column = row+1 ; column < amont_station ; column++){
					
				}
			}
		}
	}
}
