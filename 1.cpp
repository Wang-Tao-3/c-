#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <conio.h> 

#define  N  5
struct  PCB
{
	char name[8];              //��������
	int  arrive_time;           //����ʱ��
	int  run_time;             //����ʱ��
	int  finish_time;           //���ʱ��
    int  zhouzhuan_time;        //��תʱ��
	float  daiquan_time;        //��Ȩ��תʱ��
    bool  finished;             //�Ƿ�������� 
	
}; 
//���̳�ʼ��
struct  PCB  pcb[N]=
	{{"AAA",0,4},{"BBB",1,3},{"CCC",2,5},{"DDD",3,2},{"EEE",4,4}};
//�����������
void  output()
{   
    printf("----------------------------------------------------------------------------------------------\n");
    printf("������   ����ʱ��  ����ʱ��  ���ʱ��  ��תʱ��  ��Ȩ��תʱ��\n");
	printf("----------------------------------------------------------------------------------------------\n");
    for(int  i=0;i<N;i++)
	{
	  	printf(" %s        %d         %d         %d         %d         %f\n",pcb[i].name,pcb[i].arrive_time,pcb[i].run_time,pcb[i].finish_time,pcb[i].zhouzhuan_time,pcb[i].daiquan_time);
	}
    printf("----------------------------------------------------------------------------------------------\n");
}

void  main()
{   
   
	int i,j,k,min_time,index;
    int  last_finishedPCB_index;    //��¼��һ���Ѿ����еĽ��̵������±�
    output(); 

// ���е�һ������Ľ���  �õ��������ʱ�䡢��תʱ���,������Ϊ�ѷ���
	 pcb[0].finish_time=pcb[0].arrive_time+pcb[0].run_time;
	 pcb[0].zhouzhuan_time=pcb[0].finish_time-pcb[0].arrive_time;
      pcb[0].finished=true;
     last_finishedPCB_index=0; 

//������ʣ�µĽ�����ѭ���ҳ�����ʱ����С�Ľ��̣�
//�����������ʱ�䡢��תʱ��ȣ�������Ϊ�ѷ��ʡ�

     for(i=0;i<N;i++)
	 {
		 //���ҳ�û�з��ʹ�������ʱ����С�Ľ��̵��±�
		   index=-1;
		   min_time=100;
		   for(j=0;j<N;j++)
		   {
			   if(min_time>pcb[j].run_time&&pcb[j].finished==false)
			   {
				   min_time=pcb[j].run_time;
				   index=j;
			   }
		   }

		   //�����ҵ�����̽���  �õ��������ʱ�䡢��תʱ���,������Ϊ�ѷ���
           pcb[index].finish_time=pcb[last_finishedPCB_index].finish_time+pcb[index].run_time;
		   pcb[index].zhouzhuan_time=pcb[index].finish_time-pcb[index].arrive_time;
		   pcb[index].finished =true;
           last_finishedPCB_index=index; 
 
	}    
    output();
}