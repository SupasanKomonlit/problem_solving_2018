#include <iostream>

struct int_node{
	int_node* next_node;
	int data;

	int_node ( int_node* next_node = 0 , int data = 0 , )
			:	next_node(next_node) , data(data){}
};

struct linked_node{
	linked_node* previous_node;
	int number_node;
	int_node header;
	linked_node* next_node;

	linked_node( linked_node* previous_node = 0, int number_node = 0, 
					int_node* header = new int_node(0 , 0) , linked_node* next_node = 0)
				: previous_node(previous_node),
					number_node(number_node),
					next_node(next_node){}
};

namespace int_node_handle{
	int_node* target_node = new int_node() ;

	void append_node( int_node* problem_node , int number_train){
		target_node = problem_node;
		int_node* new_node = new int_node( 0 , number_train);
		while(true){
			if(target_node->next_node == 0){
				target_node->next_node = new_node;
				break;
			}
			else
				target_node = target_node->next_node;
		}
		print_node( problem_node ); 
	}

	void print_node( int_node* problem_node){
		target_node = problem_node;
		std::cout << "Welcome to print node" << std::endl;
		while( target_node->next_node != 0){
			target_node = target_node->next_node;
			std::cout << target_node->data << std::endl;
		}
		std::cout << "finish print node" << std::endl;
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
		void free_list();
		void new_train( int number_node , int number_train);
		int find_number_node(int number_node); // 0 is not_found , 1 is found
		void create_node(int number_node);
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
	std::cout << "Don't get message " << std::endl;
}

linked_list::linked_list( std::string message ){
	std::cout << "Get message is " << message << std::endl;
}

int main(){
	int amont_line;
	std::cin >> amont_line;
	linked_list answer_node;
	linked_list test_node("test create");
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
			answer_node.new_train( num_01 , num_02);	
		}
		else if(type == "M"){

		}
	}
}

void int_list::free_list(){
	while( header_node-> next_node!=0){
		delete_node = header_node;
		header_node = header_node->next_node;
		delete delete_node;
	}
}

void linked_list::free_list(){
	while( header_node->next_node !=0){
		delete_node = header_node;
		header_node = header_node->next_node;
		delete delete_node;
	}
}

void linked_list::new_train( int number_node , int number_train){
	std::cout << "Welcome to add " << number_train << " into " << number_node << std::endl;
//	int have_node = 0;
	int have_node = find_number_node( number_node );
	std::cout << "Result of have_node is " << have_node << std::endl;
	if(have_node == 0){
		create_node(number_node);
		int_node_handle::add_train( list_train , number_train);
	}
	else if(have_node == 1){
		int_node_handle::add_train( list_train , number_train);
	}
}

int linked_list::find_number_node( int number_node ){
	std::cout << "Welcome to find_number_node." << std::endl << "Target is " << number_node << std::endl;
	this->target_node = this->header_node;
	while(target_node->next_node != 0){
		target_node = target_node->next_node;
		std::cout << "number_node of target is " << target_node->number_node << std::endl;
		if(target_node->number_node == number_node)
			return 1;
		else if(target_node->next_node == 0)
			return 0;
	}
}
