#include	<iostream>
#include	<vector>

#define max_amont 1000
#define debug
//#define test

std::vector<int> graph_vector[max_amont];
std::vector<int> graph_weight[max_amont];

int degree[max_amont];

bool visited[max_amont];

void print_vector(std::vector<int> problem[] , int size);
int find_min(std::vector<int> problem[] , int size , int order);
int weight_of_travel(std::vector<int> problem[] , int size);


void init(){
	for(int count = 0 ; count < max_amont ; count++) degree[count] = 0;
}

int main(){
	#ifdef test
		std::cout << "----------print data test-------------\n";
		graph_vector[0].push_back(100);
		std::vector<int>::iterator point_vector = graph_vector[0].begin();
		std::vector<int>::iterator point_weight = graph_vector[0].end();
		if(point_vector == point_weight) std::cout << "don't have data\n";
		std::cout << "graph_vector[0].begin is " << *point_vector << "\n";
		std::cout << "graph_weight[0].end is " << *point_weight << "\n";
	#endif

	int amont , command;
	std::cin >> amont >> command;
	int A , B , W;
	for(int count = 0 ; count < command ; count++){
		#ifdef debug
			std::cout << "Input data form A to B by weight is W : ";
		#endif	
		std::cin >> A >> B >> W;
		A--;
		B--;
		#ifdef debug
			std::cout << "Input is " << A << " : " << B << " : " << W << "\n";
		#endif
		graph_vector[A].push_back(B);
		graph_vector[B].push_back(A);
		graph_weight[A].push_back(W);
		graph_weight[B].push_back(W);
		degree[A]++;
		degree[B]++;
		#ifdef debug
			std::cout << "---------------print all data-----------------\n";
			std::cout << "first order : graph_vector\n";
			print_vector(graph_vector , amont);
			std::cout << "second oeder: graph_weight\n";
			print_vector(graph_weight , amont);
		#endif
	} 
}

int find_min(std::vector<int> problem  , int size , int order){
	#ifdef debug 
		std::cout << "Welcome to find min in order is " << oreder;
	#endif
	int min[order] , change = 0;
	for(int count = 0 ; count < order ; count++ , change = 0) min[count] = -1;
	for(std::vector<int>::iterator point_vector = problem.begin()
		; point_vector != problem.end() ; point_vector++){
		int value = *point_vector;
		for(int count = 0 ; count < order ; count++){
			if(min[count] == -1){
				
			}	
		}
	}
}

int find_mst(int start){
	int result = 0;
	
}

void print_vector(std::vector<int> problem[] , int size){
	std::vector<int>::iterator point_print;
	for(int count = 0 ; count < size ; count++){
		std::cout << "count " << count << " :";
		for( point_print = problem[count].begin() 
			; point_print != problem[count].end()
			; point_print++){
			std::cout << " " << *point_print;
		}
		std::cout << "\n";
	}
}
