#include <iostream>

//#define debug

struct milk{
	int number;
	int group;
	int member;
	
	milk ( int number = 0 , int group = 0 , int member = 0)
		: number(number) , group(group) , member(member){}
};

int find_group(milk array_problem[] , int problem);

int main(){
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int amont_milk , amont_command;
	std::cin >> amont_milk >> amont_command;
/*	#ifdef debug
		std::cout << "test code declare\n";
		milk array_milk[2];
		array_milk[0].number = 1;
		std::cout << array_milk[0].number << "\n";
	#endif*/
	milk array_milk[amont_milk];
	for(int count = 0 , number = 1 ; count < amont_milk ; count++ , number ++){
		array_milk[count].number = number-1;
		array_milk[count].group = number-1;
		array_milk[count].member = 1;
	}
		#ifdef debug
			std::cout << "-------------print all milk---------------\n";
			std::cout << "\tnumber\tgroup\tmember\tfinal_group\n";
			for(int count = 0 ; count < amont_milk ; count++)
				std::cout << "\t" << array_milk[count].number
						  << "\t" << array_milk[count].group
						  << "\t" << array_milk[count].member << "\n";
		#endif
	std::string type, answer = "";
	int input_01 , input_02 ,
		group_of_input_01 , group_of_input_02 ;
	for(int count = 0 ; count < amont_command ; count++){
		std::cin >> type >> input_01 >> input_02;
		input_01--;
		input_02--;
		#ifdef debug
			std::cout << type << " " << input_01 << " " << input_02 << "\n";
		#endif
		if(type == "c"){
			#ifdef debug
				std::cout << "merge between " << array_milk[input_01].number 
							<< " with " << array_milk[input_02].number << "\n";
			#endif
			if(array_milk[input_01].group == array_milk[input_02].group){
				#ifdef debug
					std::cout << "===============SAME GROUP================\n";
				#endif
				continue;
			}
			group_of_input_01 = find_group( array_milk , input_01);
			group_of_input_02 = find_group( array_milk , input_02);
			array_milk[group_of_input_01].group = array_milk[group_of_input_02].group;
		}
		else if(type == "q"){
			group_of_input_01 = find_group( array_milk , input_01);
			group_of_input_02 = find_group( array_milk , input_02);
			#ifdef debug
				std::cout << "group of input 01 : " << group_of_input_01 << "\n"
					<< "group of input 02 : " << group_of_input_02 << "\n";
			#endif
			if( group_of_input_01 == group_of_input_02 ) answer+="yes\n";
			else answer+="no\n";
		}
		#ifdef debug
			std::cout << "-------------print all milk---------------\n";
			std::cout << "\tnumber\tgroup\tmember\tfinal_group\n";
			for(int count = 0 ; count < amont_milk ; count++)
				std::cout << "\t" << array_milk[count].number
						  << "\t" << array_milk[count].group
						  << "\t" << array_milk[count].member
						  << "\t" << find_group(array_milk , count) << "\n";
			std::cout << "--------------print answer----------------\n";
			std::cout << answer;
			std::cout << "-------------finish print-----------------\n"; 
		#endif
	}
	std::cout << answer;
}

int find_group(milk array_problem[] , int problem){
	int run;
	for(run = array_problem[problem].group ; array_problem[run].group != run ; ){
		run = array_problem[run].group;
		#ifdef debug
			std::cout << "check array_problem[problem].group : " << array_problem[problem].group << "\n";
			std::cout << "check array_problem[run].group : " << array_problem[run].group << "\n";
			std::cout << "run :" << run << "\n";
		#endif
	}
	return run;
}
