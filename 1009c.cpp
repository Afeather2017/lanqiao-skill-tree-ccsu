#include <iostream>
#include <queue>
#include <cstring>
#include <list>
char map[100][100];
short status[100][100];
int rsize, csize;
int sfr, sfc, spr, spc, er, ec;
void mapinput(){
	std::cin >> rsize >> csize;
	for(int r = 1; r <= rsize; r++){
		std::cin >> map[r] + 1;
		for(int c = 1; c <= csize; c++){
			char tmp = map[r][c];
			if(tmp == '*'){
				sfr = r;
				sfc = c;
			}
			else if(tmp == 'S'){
				spr = r;
				spc = c;
			}
			else if(tmp == 'E'){
				er = r;
				ec = c;
			}
		}
	}
}
void mapprint(){
	putchar('\n');
	for(int r = 1; r <= rsize; r++){
		for(int c = 1; c <= csize; c++){
			std::cout << map[r][c] << ' ';
		}
		putchar('\n');
	}
	for(int r = 1; r <= rsize; r++){
		for(int c = 1; c <= csize; c++){
			std::cout << status[r][c] << ' ';
		}
		putchar('\n');
	}
}
inline bool onmap(int r, int c){
	return 1 <= r && r <= rsize && 1 <= c && c <= csize;
}
bool couldwalk(int r, int c){
	//return map[r][c] != '\0' && (map[r][c] == '.' || map[r][c] == 'E');
	return map[r][c] == '.' || map[r][c] == 'E';
}
bool couldfire(int r, int c){
	return map[r][c] != '\0' && map[r][c] != '*';
	//return onmap(r, c) == true && map[r][c] != '*' && (map[r][c] == '#' ||  map[r][c] == '.' || map[r][c] == 'V');
	//return onmap(r, c) == true && map[r][c] != '*';
}
struct POS{
	int r, c, step;
};
char dr[] = {0, 0, 1, -1, 1, -1, -1, 1};
char dc[] = {-1, 1, 0, 0, 1, -1, 1, -1};
bool visited[100][100];
int bfs(int spr, int spc, int sfr, int sfc){
	std::queue<POS> fire;
	memset(status, 0xffffffff, sizeof(status));
	status[sfr][sfc] = 0;
	fire.push({sfr, sfc, 0});
fire:
	while(fire.size()){
		auto tmp = fire.front();
		fire.pop();
		for(int d = 0; d < 8; d++){
			int nr = dr[d] + tmp.r;
			int nc = dc[d] + tmp.c;
			int step = tmp.step + 1;
			if(map[nr][nc] != '\0' && status[nr][nc] < 0){
				status[nr][nc] = step;
				fire.push({nr, nc, step});
			}
		}
	}
people:
	std::queue<POS> people;
	people.push({spr, spc, 0});
	map[spr][spc] = 'V';
	while(people.size()){
		auto tmp = people.front();
		people.pop();
		for(int d = 0; d < 4; d++){
			int nr = dr[d] + tmp.r;
			int nc = dc[d] + tmp.c;
			int step = tmp.step + 1;
			if(map[nr][nc] != '\0' && map[nr][nc] != '#' && map[nr][nc] != 'V'){
				map[nr][nc] = 'V';
				if(nr == er && nc == ec){
					if(step <= status[nr][nc])
						return step;
					else
						return -1;
				}
				else{
					if(step < status[nr][nc])
						people.push({nr, nc, step});
				}
			}
		}
	}
	return -1;
}
int main(){
	int T;
	std::cin >> T;
	for(T; T > 0; T--){
		memset(map, 0, sizeof(map));
		sfr = sfc = spr = spc = 0;
		mapinput();
inputted:
		if(spr == er && spc == ec)
			std::cout << 0 << std::endl;
		else{
			int second = bfs(spr, spc, sfr, sfc);
			if(second == -1)
				std::cout << "T_T" << std::endl;
			else
				std::cout << second << std::endl;
		}
	}
	return 0;
}
