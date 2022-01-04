#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <unordered_set>
int count;
std::vector<int>tree[(int)1e6+1];
bool visited[(int)1e6 + 1];
int stepmax, end;
void dfs(int node, int step){
	step++;
	int size = tree[node].size();
	for(int i = 0; i < size; i++){
		int t = tree[node][i];
		if(visited[t] == false){
			visited[t] = true;
			if(step > stepmax){
				stepmax = step;
				end = t;
			}
			dfs(t, step);
		}
	}
}
int main(){
	int f, c;
	scanf("%d", &count);
	//构建树
	while(scanf("%d%d", &f, &c) == 2){
		tree[f].push_back(c);
		tree[c].push_back(f);
	}
	dfs(1, 0);
	stepmax = 0;
	memset(visited + 1, 0, count);
	dfs(end, 1);
	std::cout << stepmax << std::endl;
	return 0;
}
