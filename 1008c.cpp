#include <iostream>
#include <cstdio>
#include <cmath>
char number[100];
long long luck[(int)1e6];
int cur = 1;
void combine(int len, int size){
	if(len == size){
		long long n;
		sscanf(number, "%lld", &n);
#ifdef DEBUG
		//std::cout << ">>" << n << std::endl;
#endif
		luck[cur] = n;
		cur++;
	}
	else{
		number[len] = '4';
		combine(len + 1, size);
		number[len] = '7';
		combine(len + 1, size);
		number[len] = '\0';
	}
}
int main(){
	int L, R;
	std::cin >> L >> R;
	cur = 0;
	for(int i = 1; i < 11; i++)
		combine(0, i);

	int l, r;
	for(l = 0; luck[l] < L; l++);
	for(r = cur - 1; luck[r] > R; r--);

	//luck[l] >= L, luck[l - 1] < L, l > 0
	//luck[r] <= R, luck[r + 1] > R;
inputted:
	long long sum;
	if(l <= r){
		sum = (luck[l] - L + 1) * luck[l] + (R - luck[r]) * luck[r + 1];
		for(l; l < r; l++)
			sum += (luck[l + 1] - luck[l]) * luck[l + 1];
	}
	else{
		// l > r
		sum = (R - L + 1) * luck[l];
	}
	std::cout << sum << std::endl;
	return 0;
}
