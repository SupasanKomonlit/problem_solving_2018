#include <iostream>

struct node{
	int data;
	node* next;

	node(int data = 0 , node* next = 0)
		: data(data), next(next){}
};

struct bst{
	int data;
	bst* right;
	bst* left;
	bst(int data = 0 , bst* right = 0 , bst* left = 0)
		: data(data) , right(right) , left(left){}
};

class linked_node{
	private:
		node* tail;
		node* header;
		node* target;
	public:
		void append(int data);
		void print();
		linked_node();
};

class linked_bst{
	private:
		bst* previous;
		bst* target;
		bst* del;
	public:
		bst* header;
		linked_bst();
		void add_key(int key);
		int find_key(int key);
		void delete_key(int key);
};

linked_node::linked_node(){
	header = new node(0,0);
	tail = header;
}

linked_bst::linked_bst(){
	header = 0;
}

void linked_node::append(int data){
	tail->next = new node(data);
	tail = tail->next;
}

void linked_node::print(){
	target = header;
	while(target->next != 0){
		target = target->next;
		std::cout << target->data << std::endl;
	}
}

void linked_bst::add_key(int key){
	if(header == 0 ) header = new bst(key);
	else{
		target = header;
		while(true){
			if(key < target->data){
				if(target->left == 0){
					target->left = new bst(key);
					break;
				}
				else target = target->left;
			}
			else if(key > target->data){
				if(target->right == 0){
					target->right = new bst(key);
					break;
				}
				else target = target->right;
			}
		}
	}
}

int linked_bst::find_key(int key){
	target = header;
	while(true){
		if(target == 0) return 0;
		else if( key < target->data) target = target->left;
		else if( key > target->data) target = target->right;
		else{
/*			std::cout << "In delete number is " << target->data 
						<< " want find " << key
						<< " but now status is " << target->status << std::endl;*/
			return 1;
		}
	}
}

void linked_bst::delete_key(int key){
	del = header;
	if(key == del->data){
		if(del->right == 0) header = header->left;
		else{
			target = del->right;
			previous = target;
			while(target->left != 0){
				previous = target;
				target = target->left;
			}
			del->data = target->data;
			if(previous == target)  del->right = target->right;
			else{
				previous->left = 0;
			}
		}
	}
	else{
		while(del != 0){
			if(key < del->data) del = del->left;
			else if(key > del->data) del = del->right;
			else{
				if(del->right != 0){
					target = del->right;
					previous =target;
					while(target->left != 0){
						previous = target;
						target = target->left;
					}
					del->data = target->data;
					if(previous == target) del->right = target->right;
					else{
						previous->left = 0;
					}
				}
				else if(del->left != 0){
					target = del->left;
					previous = target;
					while(target->right != 0){
						previous = target;
						target = target->right;
					}
					del->data = target->data;
					if(previous == target) del->left = target->left;
					else{ previous->right = 0;}
				}
				else del = 0;
			}
		}
	}
}

int main(){
	int amont, type , key;
	linked_node answer;
	linked_bst problem;
	std::cin >> amont;
	for( int count  = 0 ; count < amont ; count++){
//		std::cout << count << "  :  "  << amont << std::endl;
		std::cin >> type >> key;
		if(type == 1) problem.add_key(key);
		else if(type == 2) answer.append( problem.find_key(key) );
		else if(type == 3) problem.delete_key(key);
//		std::cout << "==================" << std::endl;
//		answer.print();
//		std::cout << "==================" << std::endl;
	}
	answer.print();
}
