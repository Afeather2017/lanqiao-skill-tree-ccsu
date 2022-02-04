#include <iostream>
#include <unordered_set>
#define SIZE 100000007
class hash{
public:
	std::size_t operator()(const int& key)const{
		return std::hash<int>()(key % SIZE);
	}
};

std::unordered_set<int, hash> has;
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	has.reserve(SIZE);
	std::cin >> T;
	while(T--){
		int size;
		int t;
		std::cin >> size;
		for(int i = 0; i < size; i++){
			std::cin >> t;
			if(has.find(t) == has.end()){
				has.insert(t);
				std::cout << t << ' ';
			}
		}
		std::cout << '\n';
		has.clear();
	}
	return 0;
}
