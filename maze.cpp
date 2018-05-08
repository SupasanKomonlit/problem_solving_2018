#include	<iostream>

//#define debug

std::string direction[4] = { "right" , "left" , "up" , "down"};

std::string travel(int current_x , int current_y , int target_x , int target_y 
			, int key , std::string a_direction , int map[1000][1000] , std::string* origin_map , int size){
	std::string answer = "no";
		#ifdef debug
			std::cout << "Now I'm at ["<< current_x << "," << current_y << "] and move " 
						<< a_direction << " and size is " << size <<"\n";
		#endif
		if( a_direction == "right"){
			if(current_x < size-1) current_x++;
			else return answer;
		}
		else if( a_direction == "left"){
			if(current_x > 0) current_x--;
			else return answer;
		}
		else if( a_direction == "up"){
			if(current_y > 0) current_y--;
			else return answer;
		}
		else{
			if(current_y < size-1) current_y++;
			else return answer;
		}
		key = key + map[current_x][current_y];
		#ifdef debug
			std::cout << key << "\n";
		#endif
		if(key < 0 ){
			#ifdef debug
				std::cout << "out of key\n" ;
			#endif
			return "no";
		}else{
			for( int run = 0 ; run < 4 ; run++){
					if( current_x == target_x && current_y == target_y) answer = "yes";
					else{
						int past = map[current_x][current_y];
						map[current_x][current_y] = -4;
						answer = travel( current_x , current_y , target_x , target_y
									, key , direction[run] , map , origin_map , size);
						map[current_x][current_y] = past;
					}
				if( answer == "yes"){
					break;
				}
			}
		}
		#ifdef debug
			std::cout << "End function answer is " << answer << "\n";
		#endif
		return answer;
}

int main(){
	#ifdef debug
		std::cout << "---------- Welcome to maze ----------\n";
	#endif
	int size , number_question;
	std::cin >> size >> number_question;
	int origin_map[1000][1000];
	std::string list_answer[number_question];
	std::string input[size];
	for(int count = 0 ; count < size ; count++){
		std::cin >> input[count];
	}
	#ifdef debug
		for(int count = 0 ; count < size ; count++){
			std::cout << input[count] << "\n";
		}
	#endif

	for(int run_01 = 0 ; run_01 < size ; run_01++){
		for(int run_02 = 0 ; run_02 < size ; run_02++)
			if( input[run_01][run_02] == '0'){
				origin_map[run_01][run_02] = -1;
			}
			else if( input[run_01][run_02] == '#'){
				origin_map[run_01][run_02] = -99;
			}
			else{
				origin_map[run_01][run_02] = 0;
			}
	}
	#ifdef debug
		for(int run_01 = 0 ; run_01 < size ; run_01++){
			for(int run_02 = 0 ; run_02 < size ; run_02++)
				std::cout << origin_map[run_01][run_02] << " ";
			std::cout << "\n";
		}
	#endif
	int key = 1;
	int start_x , start_y , target_x , target_y;
	std::string answer;
	for(int count = 0 ; count < number_question ; count++){
		std::cin >> start_x >> start_y >> target_x >> target_y;
		start_x-- ;
		start_y--;
		target_x--;
		target_y--;
		#ifdef debug
			std::cout << "At start [" << start_x << "," << start_y << "]  ";
			std::cout << "At Target [" << target_x << "," << target_y << "]  \n";
		#endif
		for( int run = 0 ; run < 4 ; run++){
			#ifdef debug
				std::cout << "\n\n\nI will move " << direction[run] << " and send to function\n";
			#endif
				if( start_x == target_x && start_y == target_y) answer = "yes";
				else{
					#ifdef debug
						std::cout << "before send to function " << "\n";
					#endif
					answer = travel( start_x , start_y , target_x , target_y
								, key , direction[run] , origin_map , input , size);
					
				}
			if( answer == "yes"){
				break;
			}
		}
		list_answer[count] = answer;
		#ifdef debug
			std::cout << "answer is " << list_answer[count] << "\n";
		#endif		
	}
	for(int count = 0 ; count < number_question ; count++){
		std::cout << list_answer[count] << "\n";
	}
}
