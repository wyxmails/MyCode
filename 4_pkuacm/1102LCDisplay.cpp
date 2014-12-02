#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc,char*argv[]){
	char n1[11] = {"- -- -----"};
	char n2[11] = {"|   ||| ||"};
	char n3[11] = {"|||||  |||"};
	char n4[11] = {"  ----- --"};
	char n5[11] = {"| |   | | "};
	char n6[11] = {"|| |||||||"};
	char n7[11] = {"- -- -- --"};
	int s;
	char n[20];
	while(scanf("%d%s",&s,n)==2&&s){
		for(int i=0;n[i]!='\0';++i){
			printf(" ");
			for(int j=0;j<s;++j){
				printf("%c",n1[n[i]-'0']);
			}
			printf("  ");
		}
		printf("\n");
		for(int k=0;k<s;++k){
			for(int i=0;n[i]!='\0';++i){
				printf("%c",n2[n[i]-'0']);
				for(int j=0;j<s;++j){
					printf(" ");
				}
				printf("%c ",n3[n[i]-'0']);
			}
		printf("\n");
		}
		for(int i=0;n[i]!='\0';++i){
			printf(" ");
			for(int j=0;j<s;++j){
				printf("%c",n4[n[i]-'0']);
			}
			printf("  ");
		}
		printf("\n");
		for(int k=0;k<s;++k){
			for(int i=0;n[i]!='\0';++i){
				printf("%c",n5[n[i]-'0']);
				for(int j=0;j<s;++j){
					printf(" ");
				}
				printf("%c ",n6[n[i]-'0']);
			}
		printf("\n");
		}
		for(int i=0;n[i]!='\0';++i){
			printf(" ");
			for(int j=0;j<s;++j){
				printf("%c",n7[n[i]-'0']);
			}
			printf("  ");
		}
		printf("\n\n");
	}
	return 0;
}
