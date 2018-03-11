
#include <stdio.h> 

int main(){
	int ids[3] = {100,200,300};
	int *salary, salary1, salary2, *salary3;
		
	salary1 = ids[0] * ids[1];		//100 * 200
	salary = &ids[1] ;				//*salary = 200
	salary2 = *(ids+1)* *(ids+2);	//200 * 300
	salary3 = ids+2;				//2000 + 2
	printf("*salary = %d\nsalary1 = %d\n", *salary, salary1); 
	printf("salary2 = %d\nsalary3 = %p\n", salary2, salary3);
	
	
	//output:
	
	//*salary = 200
	//salary1 = 20,000
	//salary2 = 60,000
	//salary3 = 2002
	
	return 0;
}