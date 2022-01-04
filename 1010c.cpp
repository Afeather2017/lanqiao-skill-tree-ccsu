#include <iostream>
#include <string>
#include <cstring>
char* findConstant(char* str){
	char* tmp1 = strstr(str, "OO");
	char* tmp2 = strstr(str, "oo");
	if(tmp1 != NULL)
		if(tmp2 != NULL)
			return std::min(tmp1, tmp2);
		else
			return tmp1;
	else
		if(tmp2 != NULL)
			return tmp2;
		else
			return NULL;
}
int main(){
	std::string bubble;
	std::string O;
	while(std::cin >> bubble){
		O = "";
		while(true){
			char* p = findConstant((char*)bubble.c_str());
			if(p == NULL)
				break;
			else{
				char* b = (char*)"";
				if(p[0] == 'o' && p[1] == 'o')
					b = (char*)"O";
				O = bubble.substr(0, p - bubble.c_str()) + b + bubble.substr(p - bubble.c_str() + 2);
#ifdef DEBUG
				std::cout << ">>" << O << std::endl;
#endif
				bubble = O;
				O = "";
			}
		}
		std::cout << bubble << std::endl;
	}
	return 0;
}
