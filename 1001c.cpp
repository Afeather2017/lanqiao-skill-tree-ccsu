#include <iostream>
#include <cstdio>
#include <queue>
int rsize, csize;
std::vector<std::string> map;
short dirs[4][2] = {
	0, 1,
	0, -1,
	1, 0,
	-1, 0
};
inline bool onmap(int r, int c){
	return 0 <= r && r < rsize && 0 <= c && c < csize;
}
#ifdef DEBUG
void printmap(){
	for(int r = 0; r < rsize; r++){
		std::cout << map[r];
		putchar('\n');
	}
	putchar('\n');
}
#endif
void initbfs(int r, int c){
	std::queue<std::pair<int, int>> que;
	map[r][c] = '*';
	que.push({r, c});
#ifdef DEBUG
	printmap();
#endif
	int nr, nc;
	while(que.size()){
		r = que.front().first;
		c = que.front().second;
		que.pop();
		for(int i = 0; i < 4; i++){
			nr = r + dirs[i][0];
			nc = c + dirs[i][1];
			if(onmap(nr, nc) == true && map[nr][nc] == '.'){
				map[nr][nc] = '*';
#ifdef DEBUG
				printmap();
#endif
				que.push({nr, nc});
			}
		}
	}
}
int count = 0;
void bfs(int r, int c){
	std::queue<std::pair<int, int>> que;
	que.push({r, c});
	map[r][c] = '@';
#ifdef DEBUG
	printmap();
#endif
	count++;
	int nr, nc;
	while(que.size()){
		r = que.front().first;
		c = que.front().second;
		que.pop();
		for(int i = 0; i < 4; i++){
			nr = r + dirs[i][0];
			nc = c + dirs[i][1];
			if(onmap(nr, nc) == true && (map[nr][nc] == '#' || map[nr][nc]  == '.')){
				count++;
				map[nr][nc] = '@';
#ifdef DEBUG
				printmap();
#endif
				que.push({nr, nc});
			}
		}
	}
}
#ifdef DEBUG
#include <gdbout_api.h>
#endif
int mainbfs(){
#ifdef DEBUG
	clientAutoInit();
#endif
	scanf("%d%d", &csize, &rsize);
	std::swap(csize, rsize);
	map.resize(rsize);
	for(int r = 0; r < rsize; r++){
		map[r].resize(csize + 2);
		std::cin >> map[r];
	}
#ifdef DEBUG
	printmap();
#endif
	for(int r = 0; r < rsize; r++){
		if(map[r][0] == '.')
			initbfs(r, 0);
		if(map[r][csize - 1] == '.')
			initbfs(r, csize - 1);
	}
	for(int c = csize - 2; c >= 1; c--){
		if(map[0][c] == '.')
			initbfs(0, c);
		if(map[rsize - 1][c] == '.')
			initbfs(rsize - 1, c);
	}
	for(int r = 0; r < rsize; r++){
		for(int c = 0; c < csize; c++){
			if(map[r][c] == '#' || map[r][c]  == '.'){
				bfs(r, c);
			}
		}
	}
	printf("%d\n", count);
	return 0;
}
void initdfs(int r, int c){
	if(onmap(r, c) == true && map[r][c] == '.'){
		map[r][c] = '*';
		int nr, nc;
		for(int i = 0; i < 4; i++){
			nr = r + dirs[i][0];
			nc = c + dirs[i][1];
#ifdef DEBUG
			printmap();
#endif
			initdfs(nr, nc);
		}
	}
}
void dfs(int r, int c){
	if(onmap(r, c) == true && (map[r][c] == '#' || map[r][c]  == '.')){
		map[r][c] = '@';
		count++;
		int nr, nc;
		for(int i = 0; i < 4; i++){
			nr = r + dirs[i][0];
			nc = c + dirs[i][1];
#ifdef DEBUG
			printmap();
#endif
			dfs(nr, nc);
		}
	}
}
int maindfs(){
#ifdef DEBUG
	clientAutoInit();
#endif
	scanf("%d%d", &csize, &rsize);
	std::swap(csize, rsize);
	map.resize(rsize);
	for(int r = 0; r < rsize; r++){
		map[r].resize(csize);
		std::cin >> map[r];
	}
#ifdef DEBUG
	printmap();
#endif
	for(int r = 0; r < rsize; r++){
		if(map[r][0] == '.')
			initdfs(r, 0);
		if(map[r][csize - 1] == '.')
			initdfs(r, csize - 1);
	}
	for(int c = csize - 2; c > 1; c--){
		if(map[0][c] == '.')
			initdfs(0, c);
		if(map[rsize - 1][c] == '.')
			initdfs(rsize - 1, c);
	}
	for(int r = 0; r < rsize; r++){
		for(int c = 0; c < csize; c++){
			if(map[r][c] == '#' || map[r][c]  == '.'){
				dfs(r, c);
			}
		}
	}
	printf("%d\n", count);
	return 0;
}
int main(){
	return mainbfs();
}
