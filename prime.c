#include <stdio.h>
#include <stdlib.h>

void EmptyQuery();
void Prime();

int main (){
	int num;
	char* query = getenv("QUERY_STRING");
	if (query == NULL){
		printf("Enter a number to see if it's prime: ");
		scanf("%d", &num);
		Prime(num);		
	}else{
		printf("Content-Type: text/html;charset=us-ascii\n\n");
		printf("<!DOCTYPE html>\n<html>\n");
		if (query[0] == '\0')
			EmptyQuery();
		else 
			printf("%s\n", query);
		printf("\n</html>\n");
	}
}

void EmptyQuery (){
	printf("<form action=\"http://www.csun.edu/~ak505188/cgi-bin/prime.cgi\")>\n");
	printf("<div><label>Is it prime? <input name=\"num\" size=\"10\"></label></div>\n");
	printf("<div><input type =\"submit\" value=\"Find out!\"></div>\n");
}//VoidQuery

void Prime(int num){
	FILE *primes = fopen("primes1.txt", "r");
	int div, prime = 1;
	fscanf(primes, "%d", &div);
	for (;div < num && prime == 1; fscanf(primes, "%d", &div)){
	//	printf("%d\n", div);
		if (num % div == 0)
			prime = 0;
	}
	if (prime == 0)
		printf("Not prime!\n");
	else printf("Prime!\n");
}//Prime
