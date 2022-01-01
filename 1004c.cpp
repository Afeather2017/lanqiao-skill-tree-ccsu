#include <iostream>
#include <queue>
#include <vector>
#include <climits>
struct POS{
	int r, c;
	int step;
};
int rsize, csize;
std::vector<std::string> map;
POS start, end, key, door;
void mapinput(){
	std::cin >> rsize >> csize;
	map.resize(rsize);
	for(int r = 0; r < rsize; r++){
		map[r].resize(csize);
		std::cin >> map[r];
		for(int c = 0; c < csize; c++){
			char elm = map[r][c];
			if(elm == 'S')
				start = {r, c, 0};
			else if(elm == 'D')
				door = {r, c, 0};
			else if(elm == 'E')
				end = {r, c, 0};
			else if(elm == 'K')
				key = {r, c, 0};
		}
	}
}
int dirs[4][2] = {
	1, 0,
	-1, 0,
	0, 1,
	0, -1
};
inline bool onmap(POS p){
	return 0 <= p.r && p.r < rsize && 0 <= p.c && p.c < csize;
}
inline bool canwalk(char elm, const char* road){
	for(int i = 0; road[i] != '\0'; i++)
		if(road[i] == elm)
			return true;
	return false;
}
int step = 0;
void printmap(std::vector<std::string> &map){
#ifdef DEBUG
	std::cout << std::endl << "step: " << step << std::endl;
	for(int r = 0; r < rsize; r++)
		std::cout << map[r] << std::endl;
#endif
}
int search(std::vector<std::string> map, POS start, char target, const char* road){
	std::queue<POS> que;
	que.push(start);
	map[start.r][start.c] = 'G';
	step = 0;
	printmap(map);
	while(que.size()){
		POS n, p = que.front();
		que.pop();
		for(int d = 0; d < 4; d++){
			n.r = p.r + dirs[d][0];
			n.c = p.c + dirs[d][1];
			n.step = p.step + 1;
			step = n.step;
			if(onmap(n) == true){
				char elm = map[n.r][n.c];
				if(canwalk(elm, road) == true){
					map[n.r][n.c] = 'G';
					printmap(map);
					que.push(n);
				}
				else if(elm == target)
					return step;
			}

		}
	}
	return INT_MAX;
}
#ifdef DEBUG
#include <gdbout_api.h>
#endif
int main(){
#ifdef DEBUG
	clientAutoInit();
#endif
	//.SEKDW
	mapinput();
	int s2e;
	int t, t1, s2k2d2e;
	s2e = search(map, start, 'E', ".K");
	if((t = search(map, start, 'K', ".")) != INT_MAX){
		if((t1 = search(map, key, 'E', ".DS")) != INT_MAX){
			s2k2d2e = t1 + t2;
		}
	}
	int d = std::min(s2e, s2k2d2e);
	if(d == INT_MAX)
		puts("-1");
	else
		printf("%d", d);
	return 0;
}
