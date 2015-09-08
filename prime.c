#include <stdio.h>
#include <stdlib.h>

void EmptyQuery();

int main (){

	int number1, number2;
	char* query = getenv("QUERY_STRING");
	if (query != NULL){
		printf("Content-Type: text/html;charset=us-ascii\n\n");
		printf("<!DOCTYPE html>\n<html>\n");
	}
	if (query[0] == '\0')
		EmptyQuery();
//	scanf("%d%d", &number1, &number2);
//	printf("%d\n", number1*number2);

	if (query != NULL)
		printf("\n</html>\n");
}

void EmptyQuery (){
//	printf("<form action="http://www.csun.edu/~ak505188/cgi-bin/prime.cgi")>\n");
	printf("Hello World!\n");
}//VoidQuery






