#include <iostream>
#include <vector>
#include <list>
std::vector<std::list<int>> map;
bool visited[(int)1e6 + 1];
int count = 0;
int deepfirstsearch(int cur){
	int second = 0;
	auto end = map[cur].end();
	int tmp;
dfs:
	for(auto node = map[cur].begin(); node != end; node++){
		tmp = *node;
		if(visited[tmp] == false){
			visited[tmp] = true;
			second += deepfirstsearch(tmp);
		}
	}
	return second + 1;
}
int maindfs(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::cin >> count;
	map.resize(count + 1);
	int f, c;
	while(std::cin >> f >> c){
		map[f].push_back(c);
		map[c].push_back(f);
	}
dfsstart:
	int second = 0;
	auto end = map[1].end();
	int tmp;
	visited[1] = true;
	for(auto node = map[1].begin(); node != end; node++){
		tmp = *node;
		if(visited[tmp] == false){
			visited[tmp] = true;
			second = std::max(second, deepfirstsearch(tmp) - 1);
		}
	}
	std::cout << second + 1 << std::endl;
	return 0;
}
