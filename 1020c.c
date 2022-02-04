#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int strcomparer(A, B) const void* A, *B;{
	char a[22], b[22];
 	sprintf(a, "%s%s", *(char**)A, *(char**)B);
 	sprintf(b, "%s%s", *(char**)B, *(char**)A);
	return -strcmp(a, b);
}
int main(){
	int count;
	scanf("%d", &count);
	char** strs = malloc(sizeof(char*) * count);
	for(int i = 0; i < count; i++){
		strs[i] = malloc(sizeof(char) * 11);
		scanf("%s", strs[i]);
	}
	qsort(strs, count, sizeof(char*), strcomparer);
	for(int i = count - 1; i >= 0; i--)
		printf("%s", strs[i]);
	return 0;
}

