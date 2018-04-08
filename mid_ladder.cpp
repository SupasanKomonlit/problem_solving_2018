#include	<iostream>

//#define DEBUG

int main(){
	int amont_move , amont;
	std::cin >> amont >> amont_move;

	#ifdef DEBUG
	std::cout << "amont is " << amont << " and amont_move is " << amont_move << "\n";
	#endif

	int table[amont];
	for(int count = 0 ; count < amont ; count++) std::cin >> table[count];

	#ifdef DEBUG
	std::cout << "----- print table -----\n";
	for(int count = 0 ; count < amont ; count++){
		if(count%4 == 0  && count != 0) std::cout << "\n";
		std::cout << table[count] << " ";
	}
	#endif	

	int current_position = 0 , input;

	for(int count = 0 ; count < amont_move ; count++){
		std::cin >> input;
		current_position+=input;
		#ifdef DEBUG
			std::cout 	<< "input is " << input << " current_position is " 
						<< current_position << "\n";
		#endif
		current_position+=table[current_position-1];
		#ifdef DEBUG
			std::cout 	<< "current_position again is " << current_position <<"\n";
		#endif
		if(current_position < 0) current_position = 0;
		else if (current_position > amont) current_position = amont;
		#ifdef DEBUG
			std::cout 	<< "after bound position is " << current_position <<"\n";
		#endif			
	}
	std::cout << current_position << "\n";
}
