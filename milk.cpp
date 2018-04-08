#include <iostream>

struct string_node{
	std::string message;
	string_node* next;

	string_node(std::string message = "", string_node* next = 0)
		: message(message) , next(next){}
};

void add_message(string_node* problem,std::string message){
	string_node* target = problem;
	while(true){
		if(target->next != 0){
			target = target->next;
		}
		else{
			target->next = new string_node(message);
			break;
		}
	}
}

void print_message( string_node* problem){
	std::cout << "message : " ;
	string_node* target = problem;
	while(target->next != 0){
		target = target->next;
		std::cout << target->message << " ";
	}
	std::cout << std::endl;
}

struct component{
	int number;
	component* next;

	component(int number = 0 , component* next = 0)
		: number(number) , next(next){}
};

int add_component( component* problem , int key){
	component* target = problem;
	while(true){
		if(target->next != 0){
			target = target->next;
			if(target->number == key) return 0;
		}
		else{
			target->next = new component(key);
			return 1;
		}
	}
}

void print_component( component* problem){
	std::cout << "component : " ;
	component* target = problem;
	while(target->next != 0){
		target = target->next;
		std::cout << target->number << " ";
	}
	std::cout << std::endl;
}

void print_milk( component problem[] , int size){
	for(int count = 0 ; count < size ; count ++) print_component(&problem[count]);
}

std::string check_milk( component* problem, int key, int size){
	component* target = problem;
	while(target->next != 0){
		target = target->next;
		if(target->number == key) return "yes";
	}
	return "no";
}

void mix_milk( component problem[] , int size){
	int again = 0;
	do{
		again = 0;
		std::cout << "********** mix_milk **********" << std::endl;
		for(int count = 1 ; count <= size ; count++){
			component* target_data = problem[count-1];
			component* location_data = problem[count-1];
			while(target_data->next != 0){
				target = target->next;
				while(  )
			}
		}
		print_milk( problem , size);
		std::cout << "********* finish ************ and again is " << again << std::endl;
	}while(again == 1);
}


int main(){
	int num_01, num_02, amont, all_milk; 
	std::string type;
	std::cin  >> all_milk >> amont;
	component x[all_milk];
	string_node* answer = new string_node;
	for(int count = 0 ; count < amont ; count++){
		std::cout << "Input data : ";
		std::cin >> type >> num_01 >> num_02;
		if(type == "c"){
			add_component( &x[num_01-1] , num_02);
			mix_milk( x , all_milk);
		}
		else if(type == "q"){
			add_message( answer , check_milk(&x[num_01-1] , num_02));
		}
		std::cout << "==================" << std::endl;
		print_milk( x , all_milk);
		print_message( answer );
		std::cout << "==================" << std::endl;
	}
}
