#include <iostream>

struct bst{
	int data;
	bst* right;
	bst* left;

	bst( int data = 0 , bst* right = 0 , bst* left = 0)
		:	data(data) , right(right) , left(left){}
};

class linked_bst{
	private:
		bst* target;

	public: 
		bst* header;
		linked_bst();
		void add_key(int key);
};

linked_bst::linked_bst(){
	this->header = 0;
}

void linked_bst::add_key(int key){
	if(header == 0) header = new bst(key);
	else { target = header;
	while(true){
		if(key < target->data ) 
			if(target->left == 0){
				target->left = new bst(key);
				break;
			}
			else target = target->left;
		else if(key > target->data ) 
			if(target->right == 0) {
				target->right = new bst(key);
				break;
			}
			else target = target->right;
		}
	}
}

void print_bst(bst* problem , int round){
	if(problem != 0){
		if(problem->right != 0) print_bst(problem->right , round+1);
		for(int count = 0 ; count < round ; count ++) std::cout << "...";
		std::cout << "* " << problem->data << std::endl;
		if(problem->left != 0 ) print_bst(problem->left , round+1);
	}
}

int main(){
	int amont, key;
	std::cin >> amont;
	linked_bst answer;
	for( int count = 0 ; count < amont ; count++){
		std::cin >> key;
		answer.add_key( key );
//		std::cout << "================" << std::endl;
		print_bst(answer.header , 0);
//		std::cout << "================" << std::endl;
	}
}
