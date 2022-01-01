#include <iostream>
#include <queue>
int rsize, csize;
int sr, sc, tr, tc;
std::vector<std::string> map;
void mapinput(){
	std::cin >> rsize >> csize;
	map.resize(rsize);
	for(int r = 0; r < rsize; r++){
		map[r].resize(csize);
		std::cin >> map[r];
		//Get start and end
		for(int c = 0; c < csize; c++)
			if(map[r][c] == 's'){
				sr = r;
				sc = c;
			}
			else if(map[r][c] == 't'){
				tr = r;
				tc = c;
			}
	}
}
int dirs[4][2] = {
	0, 1,
	0, -1,
	1, 0,
	-1, 0
};
inline bool onmap(int r, int c){
	return 0 <= r && r < rsize && 0 <= c && c < csize;
}
bool bfs(){
	int r = sr, c = sc;
	std::queue<std::pair<int, int>> que;
	que.push({r, c});
	map[r][c] = 'w';
	while(que.size()){
		int nr, nc;
		r = que.front().first;
		c = que.front().second;
		que.pop();
		for(int d = 0; d < 4; d++){
			nr = r + dirs[d][0];
			nc = c + dirs[d][1];
			if(onmap(nr, nc) == true){
				if(map[nr][nc] == '.'){
					map[nr][nc] = 'w';
					que.push({nr, nc});
				}
				else if(map[nr][nc] == 't'){
					return true;
				}
			}
		}
	}
	return false;
}
int main(){
	int T;
	std::cin >> T;
	while(T--){
		mapinput();
		puts(bfs() ? "YES":"NO");
	}
	return 0;
}
