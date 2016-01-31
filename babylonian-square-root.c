# Zoho-assignments.c
#include <stdio.h>
#include <stdlib.h>
int main(void) {
	double input,approximation,limiter,accuracyfinder;
	int accuracy;
	printf("Enter the number for which square root is to be found :\n");
	scanf("%lf",&input);
	printf("Enter the accuracy to which square root have to be calculated(interms of decimal points) \n");
	printf("from 1 to 8: \n");
	scanf("%d",&accuracy);
	switch(accuracy)
	{
		case 1:
			approximation=input;
			limiter=1;
			accuracyfinder=0.1;
			while((approximation-limiter)>accuracyfinder)
			{
				approximation=(approximation+limiter)/2;
				limiter=input/approximation;
			}
			printf("The square root is %.1lf\n",approximation);
			break;
		case 2:
			approximation=input;
			limiter=1;
			accuracyfinder=0.01;
			while((approximation-limiter)>accuracyfinder)
			{
				approximation=(approximation+limiter)/2;
				limiter=input/approximation;
			}
			printf("The square root is %.2lf\n",approximation);
			break;
		case 3:
			approximation=input;
			limiter=1;
			accuracyfinder=0.001;
			while((approximation-limiter)>accuracyfinder)
			{
				approximation=(approximation+limiter)/2;
				limiter=input/approximation;
			}
			printf("The square root is %.3lf\n",approximation);
			break;
		case 4:
			approximation=input;
			limiter=1;
			accuracyfinder=0.0001;
			while((approximation-limiter)>accuracyfinder)
			{
				approximation=(approximation+limiter)/2;
				limiter=input/approximation;
			}
			printf("The square root is %.4lf\n",approximation);
			break;
		case 5:
			approximation=input;
			limiter=1;
			accuracyfinder=0.00001;
			while((approximation-limiter)>accuracyfinder)
			{
				approximation=(approximation+limiter)/2;
				limiter=input/approximation;
			}
			printf("The square root is %.5lf\n",approximation);
			break;
		case 6:
			approximation=input;
			limiter=1;
			accuracyfinder=0.000001;
			while((approximation-limiter)>accuracyfinder)
			{
				approximation=(approximation+limiter)/2;
				limiter=input/approximation;
			}
			printf("The square root is %.6lf\n",approximation);
			break;
		case 7:
			approximation=input;
			limiter=1;
			accuracyfinder=0.0000001;
			while((approximation-limiter)>accuracyfinder)
			{
				approximation=(approximation+limiter)/2;
				limiter=input/approximation;
			}
			printf("The square root is %.7lf\n",approximation);
			break;
		case 8:
			approximation=input;
			limiter=1;
			accuracyfinder=0.00000001;
			while((approximation-limiter)>accuracyfinder)
			{
				approximation=(approximation+limiter)/2;
				limiter=input/approximation;
			}
			printf("The square root is %.8lf\n",approximation);
			break;
		default:
			approximation=input;
			limiter=1;
			accuracyfinder=0.00000001;
			while((approximation-limiter)>accuracyfinder)
			{
				approximation=(approximation+limiter)/2;
				limiter=input/approximation;
			}
			printf("The square root is %.8lf\n",approximation);
			break;
	}
	// your code goes here
	return 0;
}
