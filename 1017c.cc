#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <vector>
class Square{
public:
	int** ret;
	int rsize, csize;
	int size;
	Square(char** strs, int** buffer, int count, int length, int size){
		//Using Robin-Karp algorithm
		ret = buffer;
		rsize = count - size + 1;
		csize = length - size + 1;
		this->size = size;

		int t = 0, r, c, k;
		for(r = count - size; r < count; r++)
			for(c = length - size; c < length; c++)
				t = strs[r][c] + t;
		ret[count - size][length - size] = t;

base:
		//Write the last line.
		for(c = length - size - 1; c >= 0; c--){
			for(r = count - size; r < count; r++)
				t = t - strs[r][c + size] + strs[r][c];
			ret[count - size][c] = t;
		}
other:
		for(r = count - size - 1; r >= 0; r--){
			for(c = length - size; c >= 0; c--){
				//Fill ret[r][c]
				t = ret[r + 1][c];
				for(k = c + size - 1; k >= c; k--)
					t = t - strs[r + size][k] + strs[r][k];
				ret[r][c] = t;
			}
		}
	}
	~Square(){
	}
	int* operator[](int another){
		return ret[another];
	}
	friend std::ostream& operator<<(std::ostream& ost, Square& from){
		ost << from.size << '\n';
		for(int r = 0; r < from.rsize; r++){
			for(int c = 0; c < from.csize; c++){
				ost << std::setw(4) << from.ret[r][c] << ' ';
			}
			ost << '\n';
		}
		return ost;
	}
};
bool squarecmp(char** strs, int count, int length, std::pair<int, int> a, std::pair<int, int> b, int size){
	for(int r = 0; r < size; r++){
		for(int c = 0; c < size; c++){
			if(strs[a.first + r][a.second + c] != strs[b.first + r][b.second + c])
				return false;
		}
	}
	return true;
}
bool findSameValue(std::unordered_map<int, std::vector<std::pair<int, int>>>& map, Square& square, char** strs, int count, int length){
	for(auto k = map.begin(); k != map.end(); k++)
		for(int i = 0; i < k->second.size(); i++)
			for(int j = 0; j < i; j++)
				if(squarecmp(strs, count, length, k->second[i],
						k->second[j], square.size)){
					return true;
				}
	return false;
}
int main(){
	int count, length;
	std::cin >> count >> length;
	char** strs = (char**)malloc(sizeof(char*) * count);
	for(int i = 0; i < count; i++){
		strs[i] = (char*)malloc(sizeof(char) * length + 1);
		std::cin >> strs[i];
	}
	int max = 0;
	int** buf = (int**)malloc(sizeof(int*) * count);
	for(int i = 0; i < count; i++)
		buf[i] = (int*)malloc(sizeof(int) * length);
	int l, r;
	for(l = 1, r = std::min(length, count); l < r;){
		//9 * 2500 * 100 == 20000 * 100 = 2e6
		int size = (l + r + 1) / 2;
		Square square(strs, buf, count, length, size);
square:
		std::unordered_map<int, std::vector<std::pair<int, int>>> map;
map:
		for(int r = 0; r < square.rsize; r++){
			for(int c = 0; c < square.csize; c++){
				if(map.find(square[r][c]) != map.end()){
					map[square[r][c]].push_back({r, c});
				}
				else{
					map[square[r][c]] = {{r, c}};
				}
			}
		}
		if(findSameValue(map, square, strs, count, length) == true){
			l = size;
		}
		else{
			r = size - 1;
		}
	}
	std::cout << r;
	return 0;
}
#include <bits/stdc++.h>
namespace UnknowSolution{
#define ull unsigned long long

using namespace std;

const int N = 510, base1 = 131, base2 = 13331;

int n, m;
char s[N];
ull sum[N][N], a[N][N], p1[N], p2[N];

bool check(int len)
{
    unordered_map<ull, int> Hash;
    for (int i = len; i <= n; i ++ )
        for (int j = len; j <= m; j ++ ) {
            ull k = sum[i][j] - sum[i - len][j] * p1[len] - sum[i][j - len] * p2[len] + sum[i - len][j - len] * p1[len] * p2[len];
            Hash[k] ++;
            if (Hash[k] == 2)    return true;
        }
    return false;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++ i ) {
		scanf("%s", s+1);
		for (int j = 1; j <= m; ++ j ) 
			sum[i][j] = s[j] - 'a';
	}
	
	p1[0] = p2[0] = 1;
	for (int i = 1; i <= n; ++ i )	p1[i] = p1[i - 1] * base1;
	for (int i = 1; i <= m; ++ i )	p2[i] = p2[i - 1] * base2;
	
	for (int i = 1; i <= n; ++ i )
		for (int j = 1; j <= m; ++ j )
			sum[i][j] += sum[i - 1][j] * base1;
	for (int i = 1; i <= n; ++ i )
		for (int j = 1; j <= m; ++ j )
			sum[i][j] += sum[i][j - 1] * base2;
	
    int l = 1, r = min(n, m);
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid))    l = mid;
        else r = mid - 1;
    }
    printf("%d\n", l);
	return 0;
}
}
namespace RobinKarpInMatrix{
class Square{
public:
	int** ret;
	int rsize, csize;
	int size;
	Square(char** strs, int** buffer, int count, int length, int size){
		//Using Robin-Karp algorithm
		ret = new int*[count - size + 1];
		rsize = count - size + 1;
		csize = length - size + 1;
		this->size = size;
		for(int r = count - size; r >= 0; r--)
			ret[r] = new int[length - size + 1];

		int t = 0, r, c, k;
		for(r = count - size; r < count; r++)
			for(c = length - size; c < length; c++)
				t = strs[r][c] + t;
		ret[count - size][length - size] = t;

base:
		//Write the last line.
		for(c = length - size - 1; c >= 0; c--){
			for(r = count - size; r < count; r++)
				t = t - strs[r][c + size] + strs[r][c];
			ret[count - size][c] = t;
		}
other:
		for(r = count - size - 1; r >= 0; r--){
			for(c = length - size; c >= 0; c--){
				//Fill ret[r][c]
				t = ret[r + 1][c];
				for(k = c + size - 1; k >= c; k--)
					t = t - strs[r + size][k] + strs[r][k];
				ret[r][c] = t;
			}
		}
	}
	int* operator[](int another){
		return ret[another];
	}
	friend std::ostream& operator<<(std::ostream& ost, Square& from){
		ost << from.size << '\n';
		for(int r = 0; r < from.rsize; r++){
			for(int c = 0; c < from.csize; c++){
				ost << std::setw(4) << from.ret[r][c] << ' ';
			}
			ost << '\n';
		}
		return ost;
	}
	~Square(){
		for(int i = 0; i < rsize; i++)
			delete ret[i];
		delete ret;
	}
};
}
