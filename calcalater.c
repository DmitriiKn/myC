#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define PI 3.1415926535
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

//char * func[] = {"a+b","a-b","a*b", "a/b"}
float a, b, x, x1;
int y, e;

void algebraic(int n);
void trigonometric(int n);
void others(int n);
void twoArg(void);
float oneArg(void);

void twoArg(void)
{
	printf("%s", "a = ");
	scanf("%f", &a);
	printf("%s", "b = ");
	scanf("%f", &b);
}
float oneArg(void)
{
	printf("%s", "x = ");
	scanf("%f", &x);
	x1 = (x * PI) / 180;
		return x1;
}
//алгебраические
void sum(void)
{
	float c = a + b;
	printf("%.3f\n", c);
}
void minus(void)
{
	float c = a - b;
	printf("%.3f\n", c);
}
void multy(void)
{
	float c = a * b;
	printf("%.3f\n", c);
}
void dived(void)
{
	float c = a / b;
	printf("%.3f\n", c);
}
void ctg(float x1)
{
	float c = 1/tan(x1);
	printf("%.3f\n", c);
}
void cosM(float x1)
{
	float c = cos(x1);
	printf("%.3f\n", c);
}
void sinM(float x1)
{
	float c = sin(x1);
	printf("%.3f\n", c);
}
void tanM(float x1)
{
	float c = tan(x1);
	printf("%.3f\n", c);
}
void xn(float x)
{
	printf("%s", "n=");
	float s;
	scanf("%f", &s);
	float c = pow(x, s);
	printf("%.3f\n", c);
}
void Square(float x)
{
	float c = sqrt(x);
	printf("%.3f\n", c);
}
void Ln(float x1)
{
	float c = log(x1);
	printf("%.3f\n", c);
}
void Lg(float x)
{
	float c = log10(x);
	printf("%.3f\n", c);
}
void en(float x)
{	printf("%s", "n=");
	float s;
	scanf("%f", &s);
	float c = exp(s);
	printf("%.3f\n", c);
}
void(*commandStore1[])(int n) = {algebraic, trigonometric, others};
void(*commandStore2[])(void) = {sum, minus, multy, dived};
void(*commandStore3[])(float x1) = {cosM, sinM, tanM, ctg};
void(*commandStore4[])(float x) = {xn, Square, Ln, Lg, en};

void RepeatO1(int k);
void RepeatO2(int k);
void RepeatO3(int k);
void RepeatC(int n);

int category(void)
{
	char * func[] = {"algebraic operations", "trigonometric functions", "others"};
	printf("%s\n", "Select a category from the list");
	printf("\n");
	for(int i = 0; i<3; i++) printf("%d: %s\n", i+1, func[i]);
		printf("\n%s\n", "Enter a number of category");
		printf("%s", "n=");
	int n;
	scanf("%d", &n);
	commandStore1[n-1](n);
	//printf("%d\n", n);
}

void algebraic(int n)
{
	char * func[] = {"a+b","a-b","a*b", "a/b"};
	printf("%s\n", "Select a operation from the list");
	printf("\n");
	for(int i = 0; i<4; i++) printf("%d: %s\n", i+1, func[i]);
		printf("\n%s\n", "Enter a number of operation");
		printf("%s", "k=");
	int k;
	scanf("%d", &k);
	twoArg();
	commandStore2[k-1]();
	RepeatO1(k);
	RepeatC(n);
}

void trigonometric(int n)
{
	char * func[] = {"cos(x)","sin(x)","tg(x)", "ctg(x)"};
	
	printf("%s\n", "Select a functions from the list");
	printf("\n");
	for(int i = 0; i<4; i++) printf("%d: %s\n", i+1, func[i]);
		printf("\n%s\n", "Enter a number of functions");
		printf("%s", "k=");
	int k;
	scanf("%d", &k);
	oneArg();
	commandStore3[k-1](x1);
	RepeatO2(k);
	RepeatC(n);
}
void others(int n)
{
	char * func[] = {"x^n","Square root of x","Ln(x)", "Log10(x)", "e^n"};
	printf("%s\n", "Select a operation from the list");
	printf("\n");
	for(int i = 0; i<4; i++) printf("%d: %s\n", i+1, func[i]);
		printf("\n%s\n", "Enter a number of operation");
		printf("%s", "k=");
	int k;
	scanf("%d", &k);
	oneArg();
	commandStore4[k-1](x);
	RepeatO3(k);
	RepeatC(n);
}

//повторение операции
void RepeatO1(int k)
{
printf("%s\n%s", "Repeat operation?", "Yes[1]/no[0]");
	scanf("%d", &y);
while(y==1) {twoArg();commandStore2[k-1](); RepeatO1(k);}
}
void RepeatO2(int k)
{
printf("%s\n%s", "Repeat operation?", "Yes[1]/no[0]");
	scanf("%d", &y);
while(y==1) {oneArg();commandStore3[k-1](x1); RepeatO2(k);}
}
void RepeatO3(int k)
{
printf("%s\n%s", "Repeat operation?", "Yes[1]/no[0]");
	scanf("%d", &y);
while(y==1) {oneArg();commandStore3[k-1](x); RepeatO3(k);}
}

//повторение выбора категории
void RepeatC(int n)
{
printf("%s\n%s", "Repeat operation checking?", "Yes[1]/no[0]");
	scanf("%d", &y);
	while(y==1) {commandStore1[n-1](n);}
}


int main(int argc, char const *argv[])
{
	category();
	while(e!=1)
		{
			printf("\n%s\n%s ", "Exit the calculater?", "Yes[1]/no[0]");
			scanf("%d", &e);
		if (e==1) exit(EXIT_FAILURE);
			category();
		}

}
