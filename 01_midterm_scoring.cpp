#include <iostream>

//#define debug

int main(){
	int amont_problem, round;
	std::cin >> amont_problem >> round;

	#ifdef debug
		std::cout << "amont_problem : " << amont_problem << "and round " << round <<"\n"; 
	#endif

	int* send_time = new int[amont_problem];
	int* max_point = new int[amont_problem];

	#ifdef debug
		std::cout << "check send_time \n";
		for(int count = 0 ; count < amont_problem ; count++){
			std::cout << "count is " << count << " and value is " << send_time[amont_problem] << "\n";
		}
		for(int count = 0 ; count < amont_problem ; count++){
			std::cout << "count is " << count << " and value is " << max_point[amont_problem] << "\n";
		}
	#endif
	
	int sum_point = 0;
	int point = 0;
	int problem = 0;

	for(int count = 0 ; count < round ; count++){
		std::cin >> problem >> point;
		problem--;
		#ifdef debug
			std::cout << "input problem is " << problem << " and point is " << point << "\n";
		#endif

		if( send_time[problem] < 5 ){
			send_time[problem]++;
			if(max_point[problem] < point){
				max_point[problem] = point;
			}
		}
		else{
			max_point[problem] = 0;
		}
		#ifdef debug
			std::cout << "after calculate \n";
			for(int count = 0 ; count < amont_problem ; count++){
				std::cout << "count is " << count << " and value is " << send_time[amont_problem] << "\n";
			}
			for(int count = 0 ; count < amont_problem ; count++){
				std::cout << "count is " << count << " and value is " << max_point[amont_problem] << "\n";
			}
		#endif
	}
	for(int count = 0 ; count < amont_problem ; count++){
		sum_point += max_point[count];
		#ifdef debug
			std::cout << "sum_point = " << sum_point << " beacause max_point is " << max_point[count] << "\n"; 
		#endif
	}
	std::cout << sum_point << "\n";
}
