#include<stdio.h>
int n;
struct srf
{

int p_no; 

int arrival_t,burst_t,ct,wait_t,taround_time,p;

int flag;
 }p_process[100];
 

void Sorting()
 {
struct srf p;

int i, j;

for(i=0;i<n-1;i++)
{
  for(j=i+1;j<n;j++)
    {
      if(p_process[i].arrival_t > p_process[j].arrival_t)
        {
          p = p_process[i];

          p_process[i] = p_process[j];

          p_process[j] = p;
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
Sorting();
for(int i=0;i<n;i++)
{
a[i]=p_process[i].burst_t;
}
p_process[9].burst_t = 9999;
for(t = p_process[0].arrival_t; t <= b_t+1;)
{
peak = 9;
for(i=0;i<n;i++)
{
if(p_process[i].arrival_t <= t && p_process[i].burst_t < p_process[peak].burst_t && p_process[i].flag != 1)
{
peak = i;
}
if(p_process[peak].burst_t==0 && p_process[i].flag != 1)
{
p_process[i].flag = 1;
p_process[peak].ct=t;
p_process[peak].burst_t=9999;
printf("P%d completes in %d\n",p_process[i].p_no,p_process[peak].ct);
}
}
t++;
(p_process[peak].burst_t)--;
}
for(i=0;i<n;i++)
{
p_process[i].taround_time=(p_process[i].ct)-(p_process[i].arrival_t);
avg_taround_time=avg_taround_time+p_process[i].taround_time;
p_process[i].wait_t=((p_process[i].taround_time)-a[i]);
avg_w_t=avg_w_t+p_process[i].wait_t;
}
printf("PNO\tAT\tCT\tTA\tWTt\n");
for(i=0;i<n;i++)
{
printf("P%d\t%d\t%d\t%d\t%d\n",p_process[i].p_no,p_process[i].arrival_t,p_process[i].ct,p_process[i].taround_time
,p_process[i].wait_t);
 }
printf("Average Turn around Time: %f\t\n\n",avg_taround_time);
printf("Average Waiting Time :\t %f\t\n",avg_w_t);
}
