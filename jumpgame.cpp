#include	<iostream>

//#define debug

bool can_walk( int current , int add , int target){
	if( current + add >= target) return true;
	else return false;
}

int main(){
	int size , add_power , max_power;
	std::cin >> size >> add_power;
	int current_table[ size ] , new_table[ size ];
// can_table 1 can go 0 can't go
	int can_table[ size ] , next_table[ size ];
	int count;
	std::string answer = "don't know";
	if ( size  == 1) std::cout << "yes\n";
	else{
		for( count = 0 ; count < size ; count++ ){
			#ifdef debug
				std::cout << "----- please input data -------\n";
			#endif
			if ( count == 0 ){
				for( int running = 0 ; running < size ; running++){
					std::cin >> current_table[running];
				}
				#ifdef debug
					std::cout << "----- test input ----- of count " << count << "\n";
					for( int running = 0 ; running < size ; running++){
						std::cout << current_table[running] << " ";
					}
					std::cout << "\n ----- finish print first line ------ \n";
				#endif
				for( int running =0 ; running < size ; running++){
					if( running == 0) can_table[ running ] = 1;
					else{
						if( can_table[ running-1 ] == 1 && can_walk( current_table[ running-1] , add_power, current_table[ running ] )){
							can_table[ running ] = 1;
						}
						else{
							can_table[ running ] = -0;
						}
					}
				}
				#ifdef debug
					std::cout << "----- print first can table ------\n";
					for( int running = 0 ; running < size ; running++){
						std::cout << can_table[ running ] << " ";
					}
					std::cout << "\n";
				#endif
			}
			else{
				for( int running = 0 ; running < size ; running++){
					std::cin >> new_table[ running ];
				}
				#ifdef debug
					std::cout << "---------- print input table for count " << count << " ------------------\n";
					for( int running = 0 ; running < size ; running++){
						std::cout << new_table[running] << " ";
					}
					std::cout << "\n";
				#endif
				#ifdef debug
					std::cout << "\nnow will find next table from upper and left\n";
				#endif
				for( int running = 0 ; running < size ; running++){
					next_table[ running ] = 0;
					if( can_table[ running ] == 1 && can_walk( current_table[ running ] , add_power , new_table[ running ])){
						next_table[ running ] = 1;
						continue;
					}
					if( running != 0){
						if( next_table[ running - 1 ] == 1 && can_walk( new_table[ running - 1 ] , add_power , new_table[ running ])){
							next_table[ running ] = 1;
							continue;
						}
					}
				}
				#ifdef debug
					std::cout << "-------------------- result 01 ---------------------\n";
					std::cout << "------ current table\n";
					for( int running  = 0 ; running < size ; running++ ) std::cout << current_table[ running ] << " ";
					std::cout << "\n";
					for( int running  = 0 ; running < size ; running++ ) std::cout << can_table[ running ] << " ";
					std::cout << "\n------ new table\n";
					for( int running  = 0 ; running < size ; running++ ) std::cout << new_table[ running ] << " ";
					std::cout << "\n";
					for( int running  = 0 ; running < size ; running++ ) std::cout << next_table[ running ] << " ";
				#endif
				#ifdef debug
					std::cout << "\nnow will find next table from right\n";
				#endif
				for( int running = size - 2 ; running > -1 ; running--){
					if( next_table[ running + 1] == 1 && can_walk( new_table[ running+1] , add_power , new_table[ running ])) next_table[ running ] = 1;
				}
				#ifdef debug
					std::cout << "-------------------- result 02 ---------------------\n";
					std::cout << "------ current table\n";
					for( int running  = 0 ; running < size ; running++ ) std::cout << current_table[ running ] << " ";
					std::cout << "\n";
					for( int running  = 0 ; running < size ; running++ ) std::cout << can_table[ running ] << " ";
					std::cout << "\n------ new table\n";
					for( int running  = 0 ; running < size ; running++ ) std::cout << new_table[ running ] << " ";
					std::cout << "\n";
					for( int running  = 0 ; running < size ; running++ ) std::cout << next_table[ running ] << " ";
				#endif
				for(int running = 0 ; running < size ; running++){
					if( next_table[ running ] == 1){
						break;
					}
					else if( running == size - 1){
						answer = "no";
					}
				}
				#ifdef debug
					std::cout << "\ncount is " << count << " and answer is " << answer << "\n";
				#endif
				if( answer == "no") break;
				else{
					for(int running = 0 ; running < size ; running++){
					current_table[ running ] = new_table[ running ];
					can_table[ running ] = next_table[ running ];
					}
				}	
			}
		}
		#ifdef debug
			std::cout << "Out of loop count is " << count << "\n";
		#endif
		if( count == size && can_table[size - 1] == 1) std::cout << "yes\n";
		else std::cout << "no\n"; 
	}
}
