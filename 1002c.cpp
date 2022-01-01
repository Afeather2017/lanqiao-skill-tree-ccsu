//什么鬼题目，扫雷不需要用搜索算法的吗？
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cctype>
#include <algorithm>
int rsize, csize;
std::vector<std::string> map;
std::vector<std::string> copy;
void mapinput(int rsize, int csize){
	map.resize(rsize);
	copy.resize(rsize);
	for(int r = 0; r < rsize; r++){
		map[r].resize(csize);
		copy[r].resize(csize);
		fill_n(copy[r].begin(), copy[r].length(), '.');
		std::cin >> map[r];
	}
}
void mapoutput(int rsize, int csize){
	for(int r = 0; r < rsize; r++){
		std::cout << map[r] << '\n';
	}
}
struct POS{
	int r, c;
};
inline bool onmap(POS p){
	return 0 <= p.r && p.r < rsize && 0 <= p.c && p.c < csize;
}
char dr[] = {0, 0, 1, -1, 1, -1, -1, 1};
char dc[] = {1, -1, 0, 0, 1, -1, 1, -1};
void bfsAt(POS pos){
	std::queue<POS> next;
	next.push(pos);
	copy[pos.r][pos.c] = '0';
	map[pos.r][pos.c] = '0';
	while(next.size()){
		POS n;
		for(int i = 0; i < sizeof(dr) / sizeof(char); i++){
			n.r = next.front().r + dr[i];
			n.c = next.front().c + dc[i];
			if(onmap(n)){
				if(map[n.r][n.c] == '.'){
					map[n.r][n.c] = '0';
					copy[n.r][n.c] = '0';
					next.push(n);
				}
				else if(isdigit(map[n.r][n.c])){
					copy[n.r][n.c] = map[n.r][n.c];
				}
			}
		}
		next.pop();
	}
}
int main1(){
	int opr, T, step;
	std::cin >> T;
	for(T; T > 0; T--){
		//std::cin >> rsize >> csize >> opr;
		std::cin >> rsize >> csize >> opr;
		map.resize(0);
		mapinput(rsize, csize);
		for(step = 1; step <= opr; step++){
			POS pos;
			std::cin >> pos.r >> pos.c;
			pos.r--;
			pos.c--;
			char elm = map[pos.r][pos.c];
			if(elm == '*'){
				std::cout << "Game over in step " << step << '\n';
				break;
			}
			else if(elm == '.'){
				bfsAt(pos);
				map[pos.r][pos.c] = 0;
			}
			else{
				//copy[pos.r][pos.c] = elm;
			}
#ifdef DEBUG
			std::cout << '\n';
			mapoutput(rsize, csize);
#endif
		}
		if(step > opr)
			mapoutput(rsize, csize);
	}
	return 0;
}
int main2(){
	int opr, T, step;
	std::cin >> T;
	for(T; T > 0; T--){
		int rsize, csize;
		std::cin >> rsize >> csize >> opr;
		char map[510][510];
		bool mapprint = true;
		for(int r = 1; r <= rsize; r++)
			std::cin >> map[r] + 1;
		for(step = 1; step <= opr; step++){
			int r, c;
			std::cin >> r >> c;
			if(mapprint == false)
				continue;
			if(map[r][c] == '.')
				map[r][c] = '0';
			if(map[r][c] == '*'){
				std::cout << "Game over in step " << step << std::endl;
				mapprint = false;
			}
		}
		if(mapprint == true)
			for(int r = 1; r <= rsize; r++)
				std::cout << map[r] + 1 << std::endl;
	}
	return 0;
}
int main(){
	int opr, T, step;
	std::cin >> T;
	for(T; T > 0; T--){
		int rsize, csize;
		std::cin >> rsize >> csize >> opr;
		char map[510][510];
		for(int r = 1; r <= rsize; r++)
			std::cin >> map[r] + 1;
		for(step = 1; step <= opr; step++){
			int r, c;
			std::cin >> r >> c;
			if(map[r][c] == '.')
				map[r][c] = '0';
			if(map[r][c] == '*'){
				std::cout << "Game over in step " << step << std::endl;
				break;
			}
		}
		if(step > opr)
			for(int r = 1; r <= rsize; r++)
				std::cout << map[r] + 1 << std::endl;
		else{
			for(step++; step <= opr; step++){
				int r, c;
				std::cin >> r >> c;
			}

		}
	}
	return 0;
}
