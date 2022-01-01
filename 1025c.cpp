#include <iostream>
#include <cstdio>
#include <unordered_set>
int main(){
	std::unordered_set<int> set;
	set.reserve(1000);
	int n, x, t;
	scanf("%d%d", &n, &x);
	for(int i = 0; i < n; i++){
		scanf("%d", &t);
		set.emplace(t);
	}
	for(auto a = set.begin(); a != set.end(); a++){
		for(auto b = set.begin(); b != set.end(); b++){
			t = *a * x * x + *b * x;
			if(set.find(-t) != set.end()){
				puts("YES");
				return 0;
			}
			t = *b * x * x + *a * x;
			if(set.find(-t) != set.end()){
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}
