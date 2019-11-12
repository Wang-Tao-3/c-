//先来先服务调度算法模拟程序
#include <stdio.h>
#include<math.h>
int a[9]={55,58,39,18,90,160,150,38,184};
int current=100;
struct result
{
	int next;
	int number;
}fcfs[9];
int total_length=0;
float average_length=0;
void fcfs_cipandiaodu()
{
    int i;
	fcfs[0].next=a[0];
	fcfs[0].number=abs(a[0]-current);

	for(i=1;i<9;i++)
	{
	   fcfs[i].next=a[i];
	   fcfs[i].number=abs(a[i]-a[i-1]);
	}
	for(i=0;i<9;i++)
	{
		total_length+=fcfs[i].number;
	}
	average_length=(float)total_length/9;
}

void output()
{
	printf("      磁盘调度算法   \n");
	printf("-------------------------------------------\n");
	printf("   (a)FCFS                             \n");
	printf("---------------------------------------------\n");
	printf("下一个被   移动的      \n");
    printf("访问磁道   磁道数      \n");
    printf("---------------------------------------------\n");
	for(int i=0;i<9;i++)
		printf("  %d         %d         \n",fcfs[i].next,fcfs[i].number );
	 printf("---------------------------------------------\n");
	printf("平均寻道长度：%2f       \n",average_length );

}
void main()
{
   fcfs_cipandiaodu();
   output();
}



//扫描算法（SCAN）磁盘调度模拟程序
/*#include <stdio.h>
#include<math.h>
int a[9]={55,58,39,18,90,160,150,38,184};
int total_length[4];
float average[4];
int current=100;
struct result
{
	int next;
	int number;
}fcfs[9],sstf[9],scan[9],cscan[9];

void fcfs_func()
{
    int i;
	fcfs[0].next=a[0];
	fcfs[0].number=abs(a[0]-current);

	for(i=1;i<9;i++)
	{
	   fcfs[i].next=a[i];
	   fcfs[i].number=abs(a[i]-a[i-1]);
	}
	for(i=0;i<9;i++)
	{
		total_length[0]+=fcfs[i].number;
	}
	average[0]=(float)total_length[0]/9;
}
void scan_func()
{
	int scan_current=current;
	int scan_arr[9];
	int i,j;
	for(i=0;i<9;i++)
	{
		scan_arr[i]=a[i];
	}
	
	for(i=0;i<8;i++)
	{
		for(j=i+1;j<9;j++)
		{
			if(scan_arr[i]>scan_arr[j])
			{
				int temp;
				temp=scan_arr[i];
				scan_arr[i]=scan_arr[j];
				scan_arr[j]=temp;
			}
		}
	}
	j=0;
	int temp=scan_current;
	for(i=0;i<9;i++)
	{
		if(scan_arr[i]>=current)
		{
			scan[j].next=scan_arr[i];
			scan[j].number=abs(scan_arr[i]-scan_current);
			scan_current=scan_arr[i];
			j++;
		}
	}
	
	for(i=8;i>=0;i--)
	{
		if(scan_arr[i]<current)
		{	
		
			scan[j].next=scan_arr[i];
			scan[j].number=abs(scan_arr[i]-scan_current);
		    scan_current=scan_arr[i];
			j++;
		}
	}
    	for(i=0;i<9;i++)
		{
	    	total_length[2]+=scan[i].number;
		}
    	average[2]=(float)total_length[2]/9;
	
}
void output()
{
	printf("      磁盘调度算法   \n");
	printf("-------------------------------------------\n");
	printf("   (a)FCFS              (b)SCAN                    \n");
	printf("---------------------------------------------\n");
	printf("下一个被   移动的     下一个被   移动的\n");
    printf("访问磁道   磁道数     访问磁道   磁道数\n");
    printf("---------------------------------------------\n");
	for(int i=0;i<9;i++)
		printf("  %d         %d          %d         %d\n",fcfs[i].next,fcfs[i].number,scan[i].next,scan[i].number);
	printf("平均寻道长度：%2f       %2f\n",average[0],average[2]);

}

void main()
{
    fcfs_func();
    scan_func();
	output();
}*/