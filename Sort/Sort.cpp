#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int ary = 1,maxAry=0,countAry=0;
	int i;
	char str[100];
	char* p, ** pSpace;
	scanf("%[^\n]s", str);
	p = str; 
	printf("str : %s\n", str);
	while (*p != '\0') {
		if (*p == ' ') { ary++; } //add number of space(ary) 
		p++;
	}
	pSpace = (char**)malloc(ary * sizeof(int)); // reserve area
	p = str; // reset p to str[0]

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
	printf("\nmax : %d\n",maxAry);
	p = str;
	for(i=0;i<ary;i++){
	pSpace[i] = (char*)malloc(maxAry * sizeof(int));
	}
	for (int j = 0;j < ary;j++) {
		for (int i = 0;i < maxAry;i++) {
			/*if (*p == ' ') {
				p++;  
			}
			else if (*p != ' '||*p >= 'a' && *p<='z' && *p>= 'A' && *p<='Z') {
				pSpace[j][i] = *p;	//add c to pSpace[j][i]
				p++;
			}*/
			if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) {
				pSpace[j][i] = *p;	//add c to pSpace[j][i]
				p++;
			}
			else if (*p == ' ' && j>0){
				for(int k = 0;k<(maxAry-i+1);k++){
					pSpace[j][i] = ' ';	//add c to pSpace[j][i]
					i++;
				}
				p++;
			}
			else {
				pSpace[j][i] = ' ';
			}
		}
	}
	printf("\npSpace\n");
	for (int j = 0;j < ary;j++) {
		for (int i = 0;i < maxAry;i++) {
			printf("[%d] [%d] : %c  ",j,i,pSpace[j][i]);
			//printf(" %c ",pSpace[j][i]);
		}
		printf("\n");
	}
	//printf("\nspace : %d\n pScape : %s", ary, pSpace[1]);
	return 0;
}