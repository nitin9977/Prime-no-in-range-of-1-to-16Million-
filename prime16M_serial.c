#include"header.h"
#include<math.h>

main()
{
long int i,j,n,c=0;
clock_t start, end;
double cpu_time_used;
     
start = clock();

for(n=3;n<=16000000;n+=2)
{
j=sqrt(n);
	for(i=2;i<=j+1;i++)
		if(n%i==0)
			break;
	if(i>=j)
	{
		c++;
		printf("%ld\n",n);
	}
}

end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("total prime=%ld\n",c);
printf("total time=%lfsec\n",cpu_time_used);
}

