#include <iostream>

//#define debug

struct nodes{
	int number;
	int before;
	int after;

	nodes( int number = 0 , int before = -1 , int after = -1)
		: number(number) , before(before) , after(after){}
};

int find_last( nodes* problem , int number){
	int run = 0;
	for(run = number ; problem[run].after!= -1 ; ){
		#ifdef debug
			std::cout << "run is " << run << "\n";
		#endif
		run = problem[run].after;
	}
	return run;
}

int main(){
	int amont = 0;
	std::cin >> amont;
	nodes answer[amont];
	int move, to , last;
	for(int count = 0 ; count < amont ; count++){
		answer[count].number = count+1;
	}
	#ifdef debug
		std::cout << "--------------- print all data -----------------\n";
		for(int run = 0 ; run < amont ; run++){
			std::cout << "run is " << run << "\tbefore is"
					<< answer[run].before
					<< "\tnumber is " << answer[run].number
					<< "\tafter is " << answer[run].after << "\n";
		}
		std::cout << "---------------- finish print -------------------\n";
	#endif
	for(int count = 0 ; count < amont-1 ; count++){
		std::cin >> move >> to;
		move--;
		to--;
		last = find_last( answer , move);
		#ifdef debug
			std::cout << "last is " << last << "\n";
		#endif
		answer[last].after = answer[to].after;
		if( answer[to].after != -1){
			#ifdef debug
				std::cout << "answer[to].after != -1\n";
			#endif
			answer[ answer[to].after ].before = last;
		}
		answer[to].after = move;
		if( answer[move].before != -1){
			#ifdef debug
				std::cout << "answer[move].before != -1\n";
			#endif
			answer[ answer[move].before ].after = -1;
		}
		answer[move].before = to;
		#ifdef debug
			std::cout << "--------------- print all data -----------------\n";
			for(int run = 0 ; run < amont ; run++){
				std::cout << "run is " << run << "\tbefore is "
						<< answer[run].before
						<< "\tnumber is " << answer[run].number
						<< "\tafter is " << answer[run].after << "\n";
			}
			std::cout << "---------------- finish print -------------------\n";
		#endif
	}
	int start;
	for(int run = 0 ; run < amont ; run++){
		#ifdef debug
			std::cout << "Now run is " << run 
					<< " before is " << answer[run].before << "\n";
		#endif
		if( answer[run].before == -1){
			start = run;
			break;
		}
	}
	#ifdef debug 
		std::cout << "final stage run is " << start << "\n"; 
	#endif
	for(int run = start ;; ){
		std::cout << answer[run].number << " ";
		run = answer[run].after;
		if( run == -1) break;
	}
	std::cout << "\n";
}
