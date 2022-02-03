#include <iostream>
#include <stack>
#include <vector>
int main(){
	int count;
	std::cin >> count;
	std::vector<int> input;
	input.resize(count);
	for(int i = 0; i < count; i++)
		std::cin >> input[i];
	std::vector<int> maxBehind;
	maxBehind.resize(count);
	maxBehind[count - 1] = input[count - 1];
	for(int i = count - 2; i >= 0; i--)
		maxBehind[i] = std::max(input[i], maxBehind[i + 1]);
	std::stack<int> stack;
	std::vector<int> output;
	output.reserve(count);
	for(int i = 0; i < count; i++){
		while(stack.size() && stack.top() >= maxBehind[i]){
			/*
			 * 算法正确性证明：
			 *   过程描述：
			 *     从栈顶和i后最大的数字中选最大的那个输出。
			 * 1.对于位数相同的数字，我们可以从左往右比较每位的数字来判断两个数字的大小关系
			 * 2.证明：
			 *   1.如果栈里有>=input[i..]的最大的数字x
			 *     1.如果x是栈顶，那么x可以直接输出
			 *     2.如果x不是栈顶，那么尝试输出x后，输出序列不是答案。
			 *       证明：
			 *         1.输出这个x，假定栈是[.., x, .., d], 那么这么做后，输出序列一定是d, .., x...
			 *           这不是输出序列的原因是，input[i..]后有一个大于x的数字，暂时叫这个数字为c吧，
			 *           而此时能够做到先输出c，这样的序列更大。
			 *   2.如果栈里所有数字都小于input[i..]中的最大的数字，那么继续入栈，直到遇到这个数字。
			 *     遇到这个数字后，有两种情况
			 *     1.之后还有等于它的数字
			 *       输出它。
			 *     2.之后的数字都小于它
			 *       输出它。
			 *     注意，之后的数字不可能大于它。
			 */
			output.push_back(stack.top());
			stack.pop();
		}
		stack.push(input[i]);
	}
	while(stack.size()){
		output.push_back(stack.top());
		stack.pop();
	}
	for(int i = 0; i < count; i++)
		std::cout << output[i] << ' ';
	std::cout << std::endl;
	return 0;
}
