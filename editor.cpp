#include <iostream>
#include <vector>

void print_vector(std::vector<std::string> data_collect){
	std::cout << "Welcome to print vector" << std::endl ;
	if(data_collect.size() != 0)
		for ( std::vector<std::string>::iterator data_point = data_collect.begin();
				data_point != data_collect.end() ; 
				data_point++){
			std::cout << "data is " << *data_point << std::endl;
		} 
}

int main(){
	std::vector<std::string> data_collect;
	std::vector<std::string>::iterator data_point = data_collect.begin(); 
	print_vector(data_collect);
	std::string type;
	std::string input;
	int amont;
	std::cin >> amont;
	for (	int count = 0 ;
			count < amont ;
			count++ ){
		std::cin >> type;
		if(	type == "i"){
			std::cin >> input;
			data_point = data_collect.insert( data_point , input );
			std::cout << "after insert " << std::endl;
			print_vector(data_collect);
		}	
	}
}
