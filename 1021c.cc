#include <iostream>
#include <cstdlib>
int input[1000];
struct Quary{
	int lenth;
	int mod;
	int end;
}quary[1000];
int intcmp(const void* a, const void* b){
	return *(int*)a - *(int*)b;
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int books, people;
	std::cin >> books >> people;
	for(int b = 0; b < books; b++)
		std::cin >> input[b];
	for(int p = 0; p < people; p++){
		int mod = 1;
		int lenth, end;
		std::cin >> lenth >> end;
		for(int i = 0; i < lenth; i++)
			mod *= 10;
		quary[p].mod = mod;
		quary[p].lenth = lenth;
		quary[p].end = end;
	}
	qsort(input, books, sizeof(int), intcmp);
	for(int p = 0; p < people; p++){
		int b;
		for(b = 0; b < books; b++){
			if(input[b] % quary[p].mod == quary[p].end){
				std::cout << input[b] << '\n';
				break;
			}
		}
		if(b == books)
			std::cout << "-1" << '\n';
	}
	return 0;
}
