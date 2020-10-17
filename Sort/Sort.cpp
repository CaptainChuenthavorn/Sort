#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int Max(int , int, char* );
int main()
{
	int ary = 1,maxAry=0,countAry=0;
	int i, space = 0;;
	char str[100];
	char* p, ** pSpace;
	scanf("%[^\n]s", str); //input sentence
	p = str; 
	printf("Message : %s\n", str);
	while (*p != '\0') {
		if (*p == ' ') { ary++; } //add number of space(ary) 
		p++;
	}
	pSpace = (char**)malloc(ary * sizeof(int)); // reserve area[]
	p = str; // reset p to str[0]
	maxAry= Max(maxAry, countAry, p);
	printf("max character : %d\n", maxAry);
	p = str;
		for(i=0;i<ary;i++){
			pSpace[i] = (char*)malloc(maxAry * sizeof(int));//reserve area[][]
		}
	for (int j = 0;j < ary;j++) {	//method : put *p in [][]
		for (int i = 0;i < maxAry;i++) {
			jumper:
			if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) {
				pSpace[j][i] = *p;	//add char to pSpace[j][i]
				p++;
			}
			else if (*p == ' ') {	
				if (i == (maxAry)|| i == 0) {
					p++;
					goto jumper;
				}
				else {
					while (i < maxAry)
					{ 
					pSpace[j][i] = ' ';	
					i++;
					}
					p++;
				}
			}
			else {	//at last word < maxAry
				pSpace[j][i] = ' ';
			}
		}
	}
	printf("\nSeparate to word by word\n");
	
	for (int j = 0;j < ary;j++) {	//print result
		printf("word %d : ",j+1);
		for (int i = 0;i < maxAry;i++) {
			//printf("[%d][%d] : %c  ",j,i,pSpace[j][i]);
			printf("%c", pSpace[j][i]);
		}
		printf("\n");
	}
	return 0;
}
int Max(int maxAry,int countAry, char *p) {
	while (*p != '\0') {	//find number word largest ary 
		if (*p != ' ') {

			countAry++;
			if (countAry > maxAry) {
				maxAry = countAry;
			}
		}
		else if (*p == ' ') {
			countAry = 0;
		}
		p++;
	}
	return maxAry;
}