#include <iostream>
#include <algorithm>

//#define debug

int main(){
	long amont; 

	long long min , max; 

	long long num_pair = 0;
	
	std::cin >> amont >> min >> max;

	#ifdef debug
		std::cout << "amont is " << amont << " min " << min << " max " << max << "\n";
	#endif

	long long set[amont];

	for(long count = 0 ; count < amont ; count++) std::cin >> set[count];

	#ifdef debug
		std::cout << amont / 2 << "\n";
		std::cout << "-----------------------before sort-----------------------\n";
		for(long count = 0 ; count < amont ; count++) std::cout << set[count] << "\n";
	#endif

	std::sort( set , set + amont);

	#ifdef debug
		std::cout << "-----------------------after sort-----------------------\n";
		for(long count = 0 ; count < amont ; count++) std::cout << set[count] << "\n";
	#endif

	long result;

	for(long count = 0, begin = 0 , end = 0 ; count < amont ; count++ , begin = 0 , end = 0){
// run begin to find least min
		for(long run = count+1 ; run < amont ; run++){
			if( set[count] + set[run] >= min ){
				begin = run;
				break;
			}
			#ifdef debug
				std::cout << "result is " << set[count] + set[run] << "\n";
			#endif
		}
		#ifdef debug
			std::cout << "begin is " << begin << "\n";
		#endif	
		for(long run = amont - 1 ; run > count ; run --){
			if( set[count] + set[run] <= max){
				end = run;
				break;
			}
			#ifdef debug
				std::cout << "result is " << set[count] + set[run] << "\n";
			#endif
		}
		#ifdef debug
			std::cout << "end is " << end << "\n";
		#endif
		if(end > begin){
			num_pair += end-begin+1;
		}
		else if(end != 0 && end == begin){
			num_pair++;
		}
		#ifdef debug
			std::cout << "num_pair is " << num_pair << "\n";
		#endif	
	}
	std::cout << num_pair << "\n";
}
