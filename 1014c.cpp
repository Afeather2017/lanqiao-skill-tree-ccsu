#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin >> T;
	while(T--){
		int n;
		std::cin >> n;
		std::vector<int> piles(n, 0);
		for(int i = 0; i < n; i++)
			std::cin >> piles[i];
		std::sort(piles.begin(), piles.end());
		int step = 0;
		for(int i = 1; i < n; i++){
			if(piles[i - 1] == piles[i])
				continue;
			else
				step++;
		}
		std::cout << step + 1<< std::endl;
	}
}
