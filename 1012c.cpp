#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
#ifdef DEBUG
#include <gdbout_api.h>
#endif
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
#ifdef DEBUG
	clientAutoInit();
#endif
	int T, command, k;
	while(std::cin >> T){
		std::stack<std::string> recordings;
		std::string str, input;
		recordings.push(" ");
		while(T--){
inputcommand:
			std::cin >> command;
			switch(command){
				case 1:
					std::cin >> input;
#ifdef DEBUG
					std::cout << command << ':' << input << std::endl;
#endif
					recordings.push(recordings.top() + input);
					break;
				case 2:
					std::cin >> k;
					input = recordings.top().substr(0, recordings.top().length() - k);
#ifdef DEBUG
					std::cout << command << ':' << input << std::endl;
#endif
					recordings.push(input);
					break;
				case 3:
					std::cin >> k;
					std::cout << recordings.top()[k] << std::endl;
					break;
				case 4:
					str = recordings.top();
					recordings.pop();
					input = recordings.top();
					recordings.push(str);
					recordings.push(input);
#ifdef DEBUG
					std::cout << command << ':' << recordings.top() << std::endl;
#endif
			}
		}
	}
	return 0;
}
