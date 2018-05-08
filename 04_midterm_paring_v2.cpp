#include <iostream>
#include <algorithm>

//#define debug

int main(){
	long amont; 

	long begin = 0 , end = 0 , running;	

	long long min , max , number; 

	long long num_pair = 0;
	
	std::cin >> amont >> min >> max;

	#ifdef debug
		std::cout << "amont is " << amont << " min " << min << " max " << max << "\n";
	#endif

	long long *set = new long long[amont];

	long count = amont - 1;

	for( ; count > -1 ; begin = 0 , end = 0 , count--){
		std::cin >> number;
		for( running = count + 1 ; running < amont ; running ++){
			if( number + set[running] >= min){
				begin = running;
				break;
			}
		}
		for( running = amont - 1 ; running > count ; running --){
			if( number + set[running] <= max){
				end = running;
				break;
			}
		}
		if(end > begin) num_pair+= end - begin +1;
		else if(end != 0 && end == begin) num_pair++;
		set[0] = number;
		std::sort( set , set+amont);
	}
	std::cout << num_pair << "\n";
}

