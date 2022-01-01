#include <iostream>
bool has4(int n){
	int r;
	while(n != 0){
		r = n % 10;
		if(r == 4)
			return true;
		n /= 10;
	}
	return false;
}
bool has38(int n){
	int r;
	while(n != 0){
		r = n % 100;
		if(r == 38)
			return true;
		n /= 10;
	}
	return false;
}
int main(){
	int l, r, count = 0;
	while(scanf("%d%d", &l, &r)){
		if(l == 0 && r == 0)
			break;
		count = 0;
		for(int i = l; i <= r; i++){
			count += has4(i) == true || has38(i) == true;
		}
		std::cout << count << std::endl;
	}
	return 0;
}
