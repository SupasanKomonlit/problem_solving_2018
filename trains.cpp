#include <iostream>

struct int_node{
	int_node* next_node;
	int data;
	int_node* tail_node;

	int_node ( int_node* next_node = 0 , int data = 0 , int_node* tail_node = 0)
			:	next_node(next_node) , data(data) , tail_node(tail_node){}
};

struct linked_node{
	linked_node* previous_node;
	int number_node;
	int_node* header_data;
	linked_node* next_node;

	linked_node( linked_node* previous_node = 0, int number_node = 0, 
					int_node* header_data = new int_node(0 , 0) , linked_node* next_node = 0)
				: previous_node(previous_node),
					number_node(number_node),
					header_data(header_data),
					next_node(next_node){}
};

namespace int_node_handle{
	int_node* target_node = new int_node() ;

	void print_node( int_node* problem_node){
		target_node = problem_node;
		std::cout << "Welcome to print node" << std::endl;
		while( target_node->next_node != 0){
			target_node = target_node->next_node;
			std::cout << target_node->data << std::endl;
		}
//		std::cout << "finish print node" << std::endl;
	}

	void append_node( int_node* problem_node , int number_train){
		target_node = problem_node;
		int_node* new_node = new int_node( 0 , number_train);
/*		if(problem_node->tail_node == 0){
			problem_node->next_node == new_node;
			problem_node->tail_node == new_node;
		}
		else{
			problem_node->tail_node->next_node = new_node;
			problem_node->tail_node = problem_node->tail_node->next_node;
		}*/
		while(true){
			if(target_node->next_node == 0){
				target_node->next_node = new_node;
				break;
			}
			else
				target_node = target_node->next_node;
		}
//		print_node( problem_node ); 
	}

	void move_node( int_node* first_node , int_node* second_node){
//		std::cout << "Welcomde to move node" << std::endl;
		target_node = second_node;
//		second_node->tail_node->next_node = first_node->next_node;
//		second_node->tail_node = first_node->tail_node;
		while(target_node->next_node != 0){
			target_node = target_node->next_node;
		}
		target_node->next_node = first_node->next_node;
		first_node->next_node = 0;
//		std::cout << "finish move train" << std::endl;
	}
}

class linked_list{
	private:
		linked_node* header_node;
		linked_node* tail_node;
		linked_node* target_node;
		linked_node* delete_node;

	public:
		linked_list();
		linked_list(std::string message);
		void create_node(int number_node);
		void free_list();
		void find_target( int number_node );
		void new_train( int number_node , int number_train);
		void move_train( int first_node , int second_node); // move first to two
		void print_all();
		int find_number_node(int number_node); // 0 is not_found , 1 is found
//		void add_train(int number_train);
};
/*
int_list::int_list(){
	this->header_node = new int_node();
}
*/
linked_list::linked_list(){
	this->header_node = new linked_node();
	this->tail_node = this->header_node;
//	std::cout << "Don't get message " << std::endl;
}

linked_list::linked_list( std::string message ){
//	std::cout << "Get message is " << message << std::endl;
}

int main(){
	int amont_line;
	std::cin >> amont_line;
	linked_list answer_node;
	int num_01 , num_02;
	std::string type;
	for( int count  = 0 ;
			count < amont_line ;
			count++ ){
		std::cin >> type >> num_01 >> num_02;
		std::cout	<< "print input data " << std::endl
					<< "type = " << type << "\t" 
					<< "num_01 = " << num_01 << "\t" 
					<< "num_02 = " << num_02 << std::endl;
		if(type == "N"){
			answer_node.new_train( num_02 , num_01);	
		}
		else if(type == "M"){
			answer_node.move_train( num_01 , num_02);
		}
		std::cout << "==================answer_node========================" << std::endl;
		answer_node.print_all();
		std::cout << "=====================================================" << std::endl;
	}
	answer_node.print_all();
}
/*
void int_list::free_list(){
	while( header_node-> next_node!=0){
		delete_node = header_node;
		header_node = header_node->next_node;
		delete delete_node;
	}
}
*/
void linked_list::free_list(){
	while( header_node->next_node !=0){
		delete_node = header_node;
		header_node = header_node->next_node;
		delete delete_node;
	}
}

void linked_list::find_target(int number_node ){
//	std::cout << "Now I will find target " << number_node << std::endl;
	target_node = header_node->next_node;
	while(target_node->number_node != number_node){
//		std::cout << "My number node is " << target_node->number_node << std::endl;
		target_node = target_node->next_node;
	}
//	std::cout << "I found that my number is " << target_node->number_node << std::endl;
}

void linked_list::new_train( int number_node , int number_train){
	std::cout << "Welcome to add " << number_train << " into " << number_node << std::endl;
//	int have_node = 0;
	int have_node = find_number_node( number_node );
	std::cout << "Result of have_node is " << have_node << std::endl;
	if(have_node == 0){
		create_node(number_node);
		std::cout << "before into append_node : " << target_node->number_node << std::endl; 
		int_node_handle::append_node( target_node->header_data , number_train);
	}
	else if(have_node == 1){
		find_target( number_node );
//		std::cout << "before into append_node : " << target_node->number_node << std::endl; 
		int_node_handle::append_node( target_node->header_data , number_train);
	}
}

void linked_list::move_train( int first_node , int second_node){
/*	std::cout 	<< "Welcome to move train from " << first_node  
				<<" to " << second_node << std::endl;*/
	int have_first_node = find_number_node( first_node );
	int have_second_node = find_number_node( second_node );
/*	std::cout 	<< "Result of have_node are " << have_first_node << " " << have_second_node 
				<< std::endl;*/
	if(have_first_node == 1){
		find_target( first_node );
		delete_node = target_node;
		if(have_second_node == 0) create_node( second_node );
		else find_target( second_node );
		delete_node->previous_node->next_node = delete_node->next_node;
		if(delete_node->next_node != 0) 
			delete_node->next_node->previous_node = delete_node->previous_node;  
/*		else{
			tail_node = delete_node->previous_node;
		}*/
		int_node_handle::move_node(delete_node->header_data , target_node->header_data);
	}
	
}

int linked_list::find_number_node( int number_node ){
/*	std::cout 	<< "Welcome to find_number_node." << std::endl 
				<< "Target is " << number_node << std::endl;*/
	this->target_node = this->header_node;
	while(target_node->next_node != 0){
		target_node = target_node->next_node;
//		std::cout << "number_node of target is " << target_node->number_node << std::endl;
		if(target_node->number_node == number_node)
			return 1;
		else if(target_node->next_node == 0)
			return 0;
	}
	return 0;
}

void linked_list::create_node( int number_node){
//	std::cout << "Welcome to create node " << number_node << std::endl;
	this->target_node = this->header_node;
	while(target_node->next_node != 0){
		if(target_node->next_node->number_node > number_node && 
			target_node->number_node < number_node) break;
		target_node = target_node->next_node;
	}	
	target_node->next_node = new linked_node( target_node ,
											  number_node,
											  new int_node(0 , 0) ,
											  target_node->next_node);
	target_node = target_node->next_node;
}

void linked_list::print_all(){
	target_node = header_node;
	while(target_node->next_node != 0){
		target_node = target_node->next_node;
/*		std::cout 	<< "target_node->number_node is "  << target_node->number_node 
					<< std::endl;*/
		int_node_handle::print_node( target_node->header_data);
	}
}
