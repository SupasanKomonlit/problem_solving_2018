#include <iostream>

typedef int type_data;

struct linked_node{
	linked_node* previous;
	type_data data;
	linked_node* next;

	linked_node(linked_node* previous=0,type_data data=0, linked_node* next=0)
		: previous(previous), data(data), next(next){}	
};

class linked_list{
	private:
 		linked_node* header;
		linked_node* tail;
		linked_node* target_node;
		linked_node* delete_node;
		void free_list();

	public:
//		linked_list();
		linked_list(std::string message);
		linked_list(int message);
		~linked_list(); //do it before end and close program
		void print_list();
		void insert_front(type_data data); 
		void remove_data(int order);
		void append_data(type_data data);
		void turn_left();
		void turn_right();
		int amont;
};
/*
linked_list::linked_list(){
	this->header = new linked_node(0, 0);
	tail = header;
	amont = 0;
	std::cout << "don't get message" << std::endl;
}
*/
linked_list::linked_list( std::string message){
	std::cout << "get message is " << message << std::endl;
}

linked_list::linked_list( int message){
	std::cout << "get integer is " << message << std::endl;
}

linked_list::~linked_list(){
	free_list();
}

void linked_list::turn_left(){
	target_node = header->next;
	tail->next = target_node;
	header->next = target_node->next;
	target_node->next = 0;
	target_node->previous = tail;
	tail = target_node;
}

void linked_list::turn_right(){
	target_node = tail;
	tail = tail->previous;
	target_node->next = header->next;
	target_node->previous = header;
	header->next->previous = target_node;
	header->next = target_node;
	tail->next = 0;
}

void linked_list::print_list(){
	target_node = header;
	while(true){
		if(target_node->next == 0)
			break;
		target_node = target_node->next;
		std::cout << target_node->data << std::endl;
	}
}

void linked_list::insert_front(type_data data){
	linked_node* new_node = new linked_node(header , data ,header->next);
	if(header->next != 0) header->next->previous = new_node;
	header->next = new_node;
	if(header == tail) tail = new_node;
	amont++;
}

void linked_list::append_data(type_data data){
	linked_node* new_node = new linked_node(tail , data , 0);
	tail->next = new_node;
	tail = new_node;
	amont++;
}

void linked_list::remove_data(int order){
}

void linked_list::free_list(){
	while(header->next!=0){
		delete_node = header;
		header = header->next;
		delete delete_node;
	}
}

int main(){
	int amont , count=0, data;
	std::cin >> amont;
	linked_list answer;
//	linked_list test("test yeah");
	linked_list test_02(2);
	std::string type;
	for( ; count < amont ; count++){
		std::cin >> type;
		if(type == "li"){
			std::cin >> data;
			answer.insert_front(data);
		}
		else if(type == "ri" ){
			std::cin >> data;
			answer.append_data(data);
		}
		else if(type == "lr" && answer.amont > 1) answer.turn_left();
		else if(type == "rr" && answer.amont > 1) answer.turn_right();
		//std::cout << "-----Check data-----" << std::endl;
		//answer.print_list(); 
		//std::cout << "--------------------" << std::endl;
	}
	answer.print_list();
}
