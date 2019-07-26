#include<stdio.h>
int main(int argc, char *argv[])
{
printf("The number of arguments is%d\n",argc-1);
printf("Program name is %s\n",argv[0]);
for(int i=0;i<argc;i++)
printf("The %d argument is %s\n",i,argv[i]);
}