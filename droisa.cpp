#include 	<iostream>

//#define debug

struct robot{
	int number;
	int position;
	int status;
	robot* before;
	robot* next;
// status 1 is free 0 is busy
	robot ( int number = -1 , int position = -1 , int status = 1, 
			robot* before = 0 , robot* next = 0):
		number( number ), position( position ), status( status ) , 
		before( before ) , next( next ){}
	
};

int absolute( int num_01 , int num_02){
	int answer = num_01 - num_02;
	if( answer < 0) return answer*(-1);
	else return answer;
}

class list_robot{
	public:
		list_robot();
		robot* header;
		robot* tail;
		robot* create;
		robot* middle;
		robot* target;
		void insert(int number , int position);
		void print(std::string text);
};

list_robot::list_robot(){
	#ifdef debug
		std::cout << "Welcome to list_robot\n";
	#endif
	header = new robot();
	tail = header; 
}

void list_robot::print( std::string text){
	std::cout << "----- " << text << " -----\n";
	std::cout << "number\tposition\tstatus\n";
	target = header;
	while( target->next != 0){
		target = target->next;
		std::cout << target->number << "\t" << target->position << "\t" 
				<< target->status << "\n";
	}
	std::cout << "-------- finish print ----------\n";
}

void list_robot::insert( int number , int position ){
	target = header;
	create = new robot( number , position);
	while(true){
		if( target->next == 0){
			#ifdef debug 
				std::cout << "Case 01\n";
			#endif
			target->next = create;
			create->before = target;
			tail = target->next;
			break;
		}
		else if( target->next->position > position){
			#ifdef debug 
				std::cout << "Case 02\n";
			#endif
			create->next = target->next;
			create->before = target;
			target->next->before = create;
			target->next = create;
			break;
		}
		else{
			#ifdef debug 
				std::cout << "Case 03\n";
			#endif
			target = target->next;	
		}
	}
}

void print_array_robot( robot* problem , int size , std::string text){
	std::cout << "------- " << text << " --------\n";
	std::cout << "number\tposition\tstatus\n";
	for( int count  = 0 ; count < size ; count++)
		std::cout << problem[count].number << "\t"
				<< problem[count].position << "\t\t"
				<< problem[count].status << "\n";
	std::cout << "-------------- after print test ------------------\n";
}

int find_distance( robot* problem , int size , int left , int right , int target){
	#ifdef debug
		std::cout << "left is " << left << " and right is " << right 
					<< " target is " << target << "\n"; 
	#endif
	int middle = ( right + left	) / 2;
	#ifdef debug 
		std::cout << "middle is " << middle << "\n"
				<< "different is " << right - left << "\n"
				<< "problem[left] " << problem[left].position
				<< " and problem[left + 1] " << problem[left + 1].position << "\n"
				<< "problem[right-1] " << problem[right-1].position
				<< " and problem[right] " << problem[right].position << "\n";
	#endif
	if( problem[ left ].position <= target && target <= problem[ left + 1].position ) 
		return left;
	else if( problem[right].position >= target && target >= problem[ right-1 ].position ) 
		return right - 1;
	else if( target < problem[ middle ].position ) 
		return find_distance( problem , size , left , middle , target);
	else return find_distance( problem , size , middle , right , target);
}

int main(){
	int amont_robot , amont_problem , input , answer = 0;
	list_robot list;
	std::cin >> amont_robot >> amont_problem;
	for( int run = 0 ; run < amont_robot ; run++){
		std::cin >> input;
		list.insert( run+1 , input);
		#ifdef debug
			std::cout << "Input is " << input << "\n";
			list.print( "Insert Value");
		#endif
	}
	robot robot_list[ amont_robot ];
	list.target = list.header;
	for(int count  = 0 ; count < amont_robot ; count++ ){
		list.target = list.target->next;
		robot_list[ count ] = *list.target;	
	}
	#ifdef debug
		print_array_robot( robot_list , amont_robot , "after copy form class");
	#endif
	int distance_right , distance_left , past_use , use = -1 , position_left , right , left;
	for(int count  = 0 ; count < amont_problem ; count++){
		past_use = use;
		std::cin >> input;
		if( robot_list[ 0 ].position >= input ){
			if( robot_list[ 0 ].status == 1) use = 0;
			else use = 1;
			answer += absolute( input , robot_list[use].position);
			robot_list[ use ].status = 0;
		}
		else if( robot_list[ amont_robot - 1].position <= input){
			if( robot_list[ amont_robot - 1 ].status == 1) use = amont_robot - 1;
			else use = amont_robot - 2;
			answer += absolute( input , robot_list[use].position);
			robot_list[ use ].status = 0;
		}
		else{
			#ifdef debug
				std::cout << "------------- use function ---------------\n";
			#endif
			position_left = find_distance( robot_list , amont_robot , 
											0 , amont_robot-1 , input);
			#ifdef debug
				std::cout << "-------------- detail for decision -----------------\n"
						<< "left - 1 :\t" << robot_list[position_left - 1 ].number
						<< "\t" << robot_list[position_left - 1].position
						<< "\t" << robot_list[position_left - 1].status << "\n"
						<< "left :\t" << robot_list[position_left ].number
						<< "\t" << robot_list[position_left ].position
						<< "\t" << robot_list[position_left ].status << "\n"
						<< "left + 1 :\t" << robot_list[position_left + 1 ].number
						<< "\t" << robot_list[position_left + 1].position
						<< "\t" << robot_list[position_left + 1].status << "\n"
						<< "left + 2 :\t" << robot_list[position_left + 2].number
						<< "\t" << robot_list[position_left + 2].position
						<< "\t" << robot_list[position_left + 2].status << "\n";
			#endif
			if(robot_list[position_left].status==1) left = position_left;
			else left = position_left - 1;
			if(robot_list[position_left+1].status==1) right = position_left+1;
			else right = position_left + 2;
			distance_left = absolute( input , robot_list[left].position);
			distance_right = absolute( input , robot_list[right].position);
			if( distance_right < distance_left ){
				answer += distance_right;
			 	use = right;
				robot_list[ use ].status = 0;
			}
			else{
				answer += distance_left;
			 	use = left;
				robot_list[ use ].status = 0;
			}
		}
		if( past_use != -1) robot_list[ past_use ].status = 1;
		#ifdef debug
			print_array_robot( robot_list , amont_robot , "after input\n");
			std::cout << "answer is " << answer;
			std::cout << "\n--------------------- finish -------------------------\n";
		#endif
	}
	std::cout << answer << "\n";
}
