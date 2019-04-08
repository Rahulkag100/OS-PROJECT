#include<stdio.h>
int n;
struct process
{

int p_no;

int arrival_t,burst_t,ct,wait_t,taround_time,p;

int flag;
 }p_list[100];
 

void Sorting()
 {
struct process p;

int i, j;

for(i=0;i<n-1;i++)
{
  for(j=i+1;j<n;j++)
    {
      if(p_list[i].arrival_t > p_list[j].arrival_t)
        {
          p = p_list[i];

          p_list[i] = p_list[j];

          p_list[j] = p;
        }
     }
  }
}
int main()
{

int i,t=0,b_t=0,peak;

int a[10];

float wait_time = 0, taround_time = 0, avg_w_t=0, avg_taround_time=0;

printf("enter the no. of processes: ");

scanf("%d",&n);
 for(i = 0; i < n; i++)

{

p_process[i].p_no = i+1;

printf("\nEnter Details For P%d process:-\n", p_process[i].p_no);
printf("Enter Arrival Time: ");
scanf("%d", &p_process[i].arrival_t );
printf("Enter Burst Time: ");
scanf("%d", &p_process[i].burst_t);
p_process[i].flag = 0;
b_t = b_t + p_process[i].burst_t;
}
}
