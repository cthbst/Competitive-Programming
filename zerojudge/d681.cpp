#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string.h>
#include<string>
using namespace std ;

int main(){
    char in[10000] ;
    while (cin.getline(in,10000)){
		if (strlen(in)==0){
			puts("") ;
			continue ;
		}
        stringstream ss ;
        ss << in ;
        char ans[100] ;
        char ele[100] ;
        ss>>ans ;
        printf("%s",ans) ;
        while (ss>>ele){
			if (strcmp(ele,"or")==0){
				printf("||") ;
				ss>>ele ;
				printf("%s",ele) ;
				for (int i=0 ;ele[i];i++){
					if (ans[i]=='0'&&ele[i]=='0')ans[i]='0' ;
					else ans[i]='1' ;
				}
			}
			else if (strcmp(ele,"and")==0){
				printf("&&") ;
				ss>>ele ;
				printf("%s",ele) ;
				for (int i=0 ;ele[i];i++){
					if (ans[i]=='1'&&ele[i]=='1')ans[i]='1' ;
					else ans[i]='0' ;
				}
			}
        }
        printf(" = %s\n",ans) ;
    }
}
