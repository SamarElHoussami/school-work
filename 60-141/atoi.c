#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char text[] = "37 hello 3.14";
	float val = atof(text);
	
	printf("%lf", val);
	
	return 0;
}