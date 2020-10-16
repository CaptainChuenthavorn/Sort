#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int ary = 1,maxAry=0,countAry=0;
	char str[100];
	char* p, ** pSpace;
	scanf("%[^\n]s", str);
	p = str; 
	printf("%s", str);
	while (*p != '\0') {
		if (*p == ' ') { ary++; } //add number of space(ary) 
		p++;
	}

	p = str; // reset p to str[0]

	while (*p != '\0') {
		if (*p != ' ') { 

			countAry++; 
			if()
			if (*p == ' ') {
				countAry = 0;
			}
		} //find number word largest ary 
		p++;
	}

	pSpace = (char**)malloc(ary * sizeof(int));
	for (int j = 0;j < ary;j++) {
		for (int i = 0;i < 3;i++) {
			if (*p == ' ') {
				p++;  
			}
			while (*p != ' ') {
				pSpace[j][i] = *p;
				p++;
			}
		}
	}
	for (int j = 0;j < ary;j++) {
		for (int i = 0;i < ary;i++) {
			printf("%c",pSpace[j][i]);
		}
	}
	//printf("\nspace : %d\n pScape : %s", ary, pSpace[1]);
	return 0;
}