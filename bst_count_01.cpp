#include <iostream>

struct int_node{
	int data;
	int_node* next;

	int_node(int data = 0 , int_node* next = 0)
		: data(data) , next(next){}
};

class int_list{
	private:
		int_node* header;
		int_node* tail;

	public:
		int_list();
		void append(int number);
		void print();
};

int_list::int_list(){
	header = new int_node();
	tail = header;
}

void int_list::append(int number){
	tail->next = new int_node(number);
	tail = tail->next;
}

void int_list::print(){
	int_node* target = header;
	while(target->next != 0){
		target = target->next;
		std::cout << target->data << std::endl;
	}
}

struct bst_node{
	int data;
	int more;
	bst_node* parent;
	bst_node* left;
	bst_node* right;

	bst_node( int data = 0, int more = 0 , bst_node* parent = 0 , bst_node* left = 0 , bst_node* right = 0)
		: data(data) , parent(parent) , left(left) , right(right), more(more){}	
};

int count_node(bst_node* problem);

class bst_list{
	private:
		bst_node* header;
		bst_node* target;
		bst_node* del;

	public:
		bst_list();
		void add_key(int key);
		int count_more(int key);
};

bst_list::bst_list(){
	header = 0;
}

void bst_list::add_key(int key){
	if(header == 0 ) header = new bst_node(key);
	else{
		target = header;
		while(true){
	//		std::cout << "add key" << std::endl;
//			std::cout << "target_data " << target->data << " have more " << target->more << std::endl; 
			if(key < target->data){ 
				if(target->left != 0) target = target->left;
				else{
					target->left = new bst_node(key);
					break;
				}
			}
			else if(key > target->data){ 
				if(target->right != 0){
					target->more += 1;
//					std::cout << "target_data " << target->data << " have more " << target->more << std::endl; 
					target = target->right;
				}
				else{
					target->more += 1;
//					std::cout << "target_data " << target->data << " have more " << target->more << std::endl; 
					target->right = new bst_node(key);
					break;
				}
			}
		}
	}
}

int count_node( bst_node* problem){
	int count = 1;
	if(problem->left != 0) count+= count_node(problem->left);
	if(problem->right != 0) count+= count_node(problem->right);
	return count;
}

int bst_list::count_more(int key){
	int sum = 0;
	target = header;
	while( target != 0){
		if(key < target->data){
//			return count_node( target);
			sum += target->more + 1;
			target = target->left;
		}
		else if( key == target->data){
//			if(target->right == 0 ) return 0;
//			return count_node(target->right);
			return target->more;
		}
		else target = target->right;
	}
	return sum;
}

int main(){
	int amont, type, key;
	bst_list problem;
	int_list answer;
	std::cin >> amont;
	for( int count = 0 ; count < amont ; count++){
//		std::cout << "count is " << count << std::endl;
		std::cin >> type >> key;
		if(type == 1) problem.add_key( key );
		else if(type == 2) answer.append( problem.count_more( key));
//		std::cout << "==========================" << std::endl; 
//		answer.print();
//		std::cout << "==========================" << std::endl; 
	}
	answer.print();
}
