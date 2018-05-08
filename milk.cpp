#include <iostream>

//#define debug

struct milk{
	int number;
	int group;
	int member;
	
	milk ( int number = 0 , int group = 0 , int member = 0)
		: number(number) , group(group) , member(member){}
};

int find_group(milk problem);

int main(){
	int amont_milk , amont_command;
	std::cin >> amont_milk >> amont_command;
	#ifdef debug
		std::cout << "test code declare\n";
		milk array_milk[2];
		array_milk[0].number = 1;
		std::cout << array_milk[0].number << "\n";
	#endif
	milk array_milk[amont_milk];
	for(int count = 0 , number = 1 ; count < amont_milk ; count++ , number ++){
		array_milk[count].number = number;
		array_milk[count].group = number;
		array_milk[count].member = 1;
	}
	std::string type, answer = "";
	int input_01 , input_02 , min_group , more_group,
		limit_01 , limit_02 , amont_min , amont_more;
	for(int count = 0 ; count < amont_command ; count++){
		std::cin >> type >> input_01 >> input_02;
		input_01--;
		input_02--;
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
			else if(array_milk[input_01].member < array_milk[input_02].member){
				min_group = array_milk[input_01].group;
				limit_01 = array_milk[input_01].member;
				more_group = array_milk[input_02].group;
				limit_02 = array_milk[input_02].member;
				amont_min = array_milk[input_01].member;
				amont_more = array_milk[input_02].member;
			}
			else{
				min_group = array_milk[input_02].group;
				limit_01 = array_milk[input_02].member;
				more_group = array_milk[input_01].group;
				limit_02 = array_milk[input_01].member;
				amont_min = array_milk[input_02].member;
				amont_more = array_milk[input_01].member;
			}
			
			for(	int count_01 = 0 , count_02 = 0 , run = 0,
					plus_member = array_milk[input_02].member + array_milk[input_01].member;
					run < amont_milk ; run++){
				if(min_group == array_milk[run].group){
					array_milk[run].group = more_group;
					array_milk[run].member = plus_member;
					count_01++;
					#ifdef debug
						std::cout << "min_group number " << array_milk[run].number 
								  << " to group is " << array_milk[run].group 
								  << " count is " << count_01 << "\n";
					#endif
				}
				else if(more_group == array_milk[run].group){
					array_milk[run].member = plus_member;
					count_02++;
					#ifdef debug
						std::cout << "max_group number " << array_milk[run].number 
								  << " to group is " << array_milk[run].group 
								  << " count is " << count_02 << "\n";
					#endif
				}
				if(count_01 == amont_min && count_02 == amont_more){
					#ifdef debug
						std::cout << "break out \n";
					#endif
					break;
				}
			}
		}
		else if(type == "q"){
			#ifdef debug
				std::cout << "question input_01 : " << input_01 
							<< "and input_02 : " << input_02 << "\n";
			#endif
			if(array_milk[input_01].group == array_milk[input_02].group)
				answer += "yes\n";
			else answer += "no\n";
		}
		#ifdef debug
			std::cout << "-------------print all milk---------------\n";
			std::cout << "\tnumber\tgroup\tmember\n";
			for(int count = 0 ; count < amont_milk ; count++)
				std::cout << "\t" << array_milk[count].number
						  << "\t" << array_milk[count].group
						  << "\t" << array_milk[count].member << "\n";
			std::cout << "--------------print answer----------------\n";
			std::cout << answer;
			std::cout << "-------------finish print-----------------\n"; 
		#endif
	}
	std::cout << answer;
}

int find_group(milk problem){
	#ifdef debug
		std::cout << "Welcome to find group" << "\n";
		std::cout << "size of problem is " << sizeof(problem) << "\n";
	#endif
	
}
