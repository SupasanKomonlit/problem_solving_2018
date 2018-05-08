#include <iostream>

//#define debug

int main(){
	int amont, question;
	std::cin >> amont >> question;

	#ifdef debug
		std::cout << "amont family " << amont << " amont question is" << question << "\n";
	#endif

	int* parent = new int[amont];
	int* answer = new int[question];

	for(int count  = 1 ; count < amont ; count++){
		std::cin >> parent[count];
	}

	#ifdef debug
		for(int count = 0; count < amont ; count++){
			std::cout << "----------------show parent-------------------------";
			std::cout << "parent of number " << count + 1 << " is " << parent[count] << "\n";
		}
	#endif
	
	int target_01 , target_02;

	for(int count = 0 ; count < question ; count++){		
		std::cin >> target_01 >> target_02;
		#ifdef debug
			std::cout << "target_01 is " << target_01 << " target_02 is " << target_02 << "\n"; 
		#endif
		for(int running = target_01 ; parent[running - 1] != 0 ; running = parent[running - 1]){
			#ifdef debug
				std::cout << "running is " << running << " and parent is " << parent[running-1] << "\n";
			#endif
			if( parent[running-1] == target_02){
				#ifdef debug
					std::cout << "found target is " << target_02 << "\n";
				#endif
				answer[count] = target_02;
				break;
			}
		}
		if( answer[count] != 0){
			#ifdef debug
				std::cout << "found \n ---------------------- next question ---------------------------- \n";
			#endif
			continue;
		}
		#ifdef debug
			std::cout << "--------------- try again ---------------\n";
		#endif	
		for(int running = target_02 ; parent[running - 1] != 0 ; running = parent[running - 1]){
			#ifdef debug
				std::cout << "running is " << running << " and parent is " << parent[running-1] << "\n";
			#endif
			if( parent[running-1] == target_01){
				#ifdef debug
					std::cout << "found target is " << target_01 << "\n";
				#endif
				answer[count] = target_01;
				break;
			}
		}
		if( answer[count] == 0){
			#ifdef debug
				std::cout << "don't found\n ------------------------ next question ------------------------------\n";
			#endif
			answer[count] = -1;
		}
	}
	for(int count = 0 ; count < question ; count++){
		std::cout << answer[count] << "\n";
	}
}
