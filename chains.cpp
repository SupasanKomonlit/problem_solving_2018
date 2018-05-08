#include	<iostream>

//#define debug

struct node{
	node* before;
	int number;	
	node* next;
	
	node ( int number = 0 , node* before = 0 , node* next = 0)
		: number(number) , before(before) , next(next){}
};

class link_node{
	public:
		node* header;
		node* tail;
		node* target;
		node* point;
		link_node();
		void set_link(int begin , int last);
		void print();
};

link_node::link_node(){
	header = new node();
	tail = header;
}

void link_node::set_link(int begin , int last){
	target = header;
	#ifdef debug
		std::cout << "start assign value so begin " << begin << " and last " << last << "\n";
	#endif
	for(int count = begin ; count < last ; count++){
		#ifdef debug
			std::cout << "You are set link so count is " << count << "\n"; 
		#endif
		target->next = new node( count , target);
		target = target->next; 
	}
	tail = target;
}

void link_node::print(){
	target = header;
	#ifdef debug
		std::cout << "---------- Now you will print node ----------\n"; 
	#endif
	while(target->next!=0){
		target = target->next;
		std::cout << target->number << "\n";
	}
	#ifdef debug
		std::cout << "----------------- finish print --------------------\n";
	#endif
}

int main(){
	int amont_start , amont_event , number = 1 , input;

	std::cin >> amont_start >> amont_event;

	link_node* set_node = new link_node[amont_start];	

	for(int count = 0 ; count < amont_start ; count++){
		std::cin >> input;
		set_node[count].set_link( number , number+input );
		#ifdef debug
			std::cout << "number is " << number << " and input is " << input;
		#endif
		number = number + input;
		#ifdef debug
			std::cout << " final next number is " << number << "\n";
		#endif
	}
	#ifdef debug
		std::cout << "Print all set node";
		for(int count = 0 ; count < amont_start ; count++){
			set_node[count].print();
		}
		std::cout << "finish set node \n";
	#endif

	int forward = 1 , can_use = 0;
	std::string type;
	link_node answer = set_node[0];
	answer.point = answer.header->next;
	for(int count = 0 ; count < amont_event ; count++){
		#ifdef debug
			std::cout << "now point at number is " << answer.point->number << "\n";
		#endif

		std::cin >> type;
		
		#ifdef debug
			std::cout << "print type is " << type << "\n";
		#endif

		if(type == "F"){
			#ifdef debug 
				std::cout << "in if of type F now " << answer.point->number << "\n";
			#endif
			if( answer.point->next != 0){
				answer.point = answer.point->next;
			}
			#ifdef debug
				std::cout << "before out point " << answer.point->number << "\n";
			#endif
		}
		else if(type == "B"){
			#ifdef debug 
				std::cout << "in if of type B now " << answer.point->number << "\n";
			#endif
			if( answer.point->before != answer.header){
				answer.point = answer.point->before;
			}
			#ifdef debug
				std::cout << "before out point " << answer.point->number << "\n";
			#endif
		}
		else if(type == "C"){
			std::cin >> input;
			#ifdef debug
				std::cout << "number of input type C is " << input << "\n";
				std::cout << "Now we are collect node\n";
			#endif
			answer.target = answer.point;
			set_node[ can_use ].header = new node();
			set_node[ can_use ].tail = set_node[ can_use ].header;
			set_node[ can_use ].target = set_node[ can_use ].header;
			while( answer.target->next != 0){
				answer.target = answer.target->next;
				set_node[ can_use ].target->next 
					= new node( answer.target->number , set_node[ can_use ].target);
				set_node[ can_use ].target = set_node[ can_use ].target->next;
			}
			set_node[ can_use ].tail = set_node[ can_use].target; 
			#ifdef debug
				std::cout << "print collect node number " << can_use << "\n";
				set_node[ can_use ].print();
			#endif
			for(int running_number = 0 ; running_number < amont_start ; running_number++){
				#ifdef debug
					std::cout << "----------- find can use ---------------\n"
							<< "running number is " << running_number << "\n";
					if( set_node[ running_number ].header->next != 0  ){
						 std::cout << "start at " 
									<< set_node[ running_number ].header->next->number << "\n";
					}
					else{
						std::cout << "don't have begin\n";
					}
					if( set_node[ running_number ].tail != set_node[ running_number ].header ){
						std::cout << "end at "
								<< set_node[ running_number ].tail->number << "\n";
					}
					else{
						std::cout << "don't have end\n";
					}
				#endif
				if( set_node[ running_number ].header->next != 0 )
					if( set_node[ running_number ].header->next->number == input ){
						can_use = running_number;
						forward = 1;
						break;
					}
				if( set_node[ running_number ].tail->number != 0 )
					if( set_node[ running_number ].tail->number == input ){
						can_use = running_number;
						forward = 0;
						break;
					}
			}
			#ifdef debug
				std::cout << "finish find can_use : " << can_use 
							<< " forward " << forward << "\n";
			#endif
			#ifdef debug
				std::cout << "-------------------- before connect ----------------------\n";
				answer.print();
			#endif
			if( forward == 1){
				set_node[ can_use ].target = set_node[ can_use ].header;
				answer.target = answer.point;
				while( set_node[ can_use ].target->next != 0){
					set_node[ can_use ].target = set_node[ can_use].target->next;
					answer.target->next = 
						new node( set_node[ can_use ].target->number , answer.target);
					answer.target = answer.target->next;
				}
				answer.tail = answer.target;
			}
			else{
				set_node[ can_use ].target = set_node[ can_use ].tail;
				answer.target = answer.point;
				while( set_node[ can_use ].target != set_node[ can_use].header ){
					answer.target->next 
						= new node( set_node[ can_use ].target->number , answer.target);
					set_node[ can_use ].target = set_node[ can_use ].target->before;
					answer.target = answer.target->next;
				}
			}
			answer.point = answer.point->next;
			#ifdef debug
				std::cout << "-------------------- after connect ----------------------\n";
				answer.print();
			#endif
		} 
		#ifdef debug
			std::cout << "---------------- finish action ------------------------\n";
		#endif
	}
	answer.target = answer.header->next;
	while( true ){
		std::cout << answer.target->number << "\n";
		if( answer.target == answer.point) break;
		answer.target = answer.target->next;
	}

}
