#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
//умножает два числа n-ой разрядности используя ввод с терминала без буферизации
//аргументом функции максимальная является разрядность чисел
void main(int argc, char const *argv[])
{
	
	int n = atoi(argv[1]);
if(argc < 2) n = 2;
	//int k = atoi(argv[2]);
	//int* r[1] = {n, k};
	char string[n];
	char * vars[] = {"x = ", "y = ", "xy = "};
	int values[2];
	for (int j = 0; j < 2; j++){
		printf("\n%s", vars[j]);
		for (int i = 0; i < n/*r(j)*/; i++)
		
	{//printf("Cooked, press any key\n");
      	                while(!kbhit());
      	                string[i] = getch();
      	                putch(string[i]);
      	                //if(strcmp(string[i], '!')
      	            }
      	            values[j] = atof(string);
      	        }
      	        values[2] = values[0] * values[1];
      	        printf("\n%s%d\n", vars[2], values[2]);
        //printf("Input string: %s\n", string);
      }
