#include <iostream>
short figers[10000];
bool nextpermutation(short* nums, int size){
	int i, j;
	for(i = size - 2; i >= 0; i--)
		if(nums[i] < nums[i + 1])
			break;
	if(i < 0)
		return false;
	int min = i + 1;
	for(j = i + 1; j < size; j++)
		if(nums[j] > nums[i])
			if(nums[min] > nums[j])
				min = j;
	std::swap(nums[min], nums[i]);
	for(i++, j = size - 1; i < j; i++, j--)
		std::swap(nums[i], nums[j]);
	return true;
}
int main(){
	int count, add;
	std::cin >> count >> add;
	for(int i = 0; i < count; i++)
		std::cin >> figers[i];
inputted:
	while(add--)
		nextpermutation(figers, count);
	for(int i = 0; i < count; i++)
		std::cout << figers[i] << ' ';
}
