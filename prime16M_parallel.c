//////////////////////////////////////////////////////////////////////
/*********************************************************************			
			author: Nitin Swami
			time: 3.30am, 5/1/2016
*********************************************************************/
//////////////////////////////////////////////////////////////////////
#include"header.h"

long int c1,c2,c3,c4;
pthread_mutex_t m1,m2,m3,m4;

void * th1(void * p)
{
long int i,j,n;
pthread_mutex_lock(&m1);
for(n=3;n<=4000000;n+=2)
{
j=sqrt(n);
	for(i=2;i<=j+1;i++)
		if(n%i==0)
			break;
	if(i>=j)
	{
		c1++;
		printf("%ld\n",n);
	}
}
pthread_mutex_unlock(&m1);
pthread_exit(0);
}

void * th2(void * p)
{
long int i,j,n;
pthread_mutex_lock(&m2);
for(n=4000001;n<=8000000;n+=2)
{
j=sqrt(n);
	for(i=2;i<=j+1;i++)
	if(n%i==0)
		break;
	if(i>=j)
	{
		c2++;
		printf("\t%ld\n",n);
	}
}
pthread_mutex_unlock(&m2);
pthread_exit(0);
}

void * th3(void * p)
{
long int i,n,j;
pthread_mutex_lock(&m3);
for(n=8000001;n<=12000000;n+=2)
{
j=sqrt(n);
	for(i=2;i<=j+1;i++)
	if(n%i==0)
		break;
	if(i>=j)
	{
		c3++;
		printf("\t\t%ld\n",n);
	}
}
pthread_mutex_unlock(&m3);
pthread_exit(0);
}

void * th4(void * p)
{
long int i,j,n;
pthread_mutex_lock(&m4);
for(n=12000001;n<=16000000;n+=2)
{
j=sqrt(n);
	for(i=2;i<=j+1;i++)
	if(n%i==0)
		break;
	if(i>=j)
	{
		c4++;
		printf("\t\t\t%ld\n",n);
	}
}
pthread_mutex_unlock(&m4);
pthread_exit(0);
}

void * th5(void *p)
{
clock_t start, end;
double cpu_time_used;

start = clock();

pthread_mutex_lock(&m1);
pthread_mutex_lock(&m2);
pthread_mutex_lock(&m3);
pthread_mutex_lock(&m4);

end = clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("total time=%lfsec\n",cpu_time_used);

pthread_mutex_unlock(&m1);
pthread_mutex_unlock(&m2);
pthread_mutex_unlock(&m3);
pthread_mutex_unlock(&m4);
pthread_exit(0);
}

void thread_init(void)
{
        pthread_mutex_init(&m1,NULL);
        pthread_mutex_init(&m2,NULL);
        pthread_mutex_init(&m3,NULL);
        pthread_mutex_init(&m4,NULL);
//        printf("mutex initialized\n");
}

void thread_dest(void)
{
        pthread_mutex_destroy(&m1);
        pthread_mutex_destroy(&m2);
        pthread_mutex_destroy(&m3);
        pthread_mutex_destroy(&m4);
//        printf("mutex destroyed\n");
}


main()
{
pthread_t t1,t2,t3,t4,t5;
thread_init();
	pthread_create(&t1,NULL,th1,NULL);
	pthread_create(&t2,NULL,th2,NULL);
	pthread_create(&t3,NULL,th3,NULL);
	pthread_create(&t4,NULL,th4,NULL);
	pthread_create(&t5,NULL,th5,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	pthread_join(t4,NULL);
	pthread_join(t5,NULL);
thread_dest();
printf("total no to primes=%ld\n",c1+c2+c3+c4);
}
