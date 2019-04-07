#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<conio.h>
void Sort();
int n;
struct pro
{
    int p_no;
    int arr_t,bur_t,ct,wait_t,tar_time,p;
	int flag;
}p_list[100];
void Sort()
{
    struct pro p;
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(p_list[i].arr_t>p_list[j].arr_t)
            {
                p=p_list[i];
                p_list[i]=p_list[j];
                p_list[j]=p;
            }
        }
    }
}
int main()
{
    int i,t=0,b_t=0,peak;
    int a[10];
    float wait_time=0,tar_time=0,avg_w_t=0,avg_tar_time=0;
    printf("Enter the number of total processes\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        p_list[i].p_no=i+1;
        printf("Enter details For process %d\n",p_list[i].p_no);
        printf("Enter arrival time");
        scanf("%d",&p_list[i].arr_t);
        printf("Enter burst time");
        scanf("%d",&p_list[i].bur_t);
        p_list[i].flag = 0;
        b_t=b_t+p_list[i].bur_t;
    }
    Sort();
    for(i=0;i<n;i++)
    {
        a[i]=p_list[i].bur_t;
    }
    p_list[9].bur_t=1111;
    for(t=p_list[0].arr_t;t<=b_t+1;)
    {
        peak=9;
        for(i=0;i<n;i++)
        {
            if(p_list[i].arr_t<=t && p_list[i].bur_t<p_list[peak].bur_t && p_list[i].flag !=1)
            {
                peak=i;
            }
            if(p_list[peak].bur_t == 0 && p_list[i].flag !=1)
            {
                p_list[i].flag=1;
                p_list[peak].ct=t;
                p_list[peak].bur_t=1111;
                printf("P%d completes in %d\n",p_list[i].p_no, p_list[peak].ct);
            }
        }
        t++;
        (p_list[peak].bur_t)--;
    }
    for(i=0;i<n;i++)
    {
        p_list[i].tar_time=(p_list[i].ct)-(p_list[i].arr_t);
        avg_tar_time=avg_tar_time+p_list[i].tar_time;
        p_list[i].wait_t=((p_list[i].tar_time)-a[i]);
        avg_w_t=avg_w_t+p_list[i].wait_t;
    }
    printf("PNO \tAT \tCT \tTA \tWT t\n");
    for(i=0;i<n;i++)
    {
        printf("P%d \t %d \t %d \t %d \t %d\n",p_list[i].p_no,p_list[i].arr_t,p_list[i].ct,p_list[i].tar_time,p_list[i].wait_t);
    }
    printf("Average turn-around time%f\t\n\n",avg_tar_time);
    printf("Average waiting time\t %f\t\n",avg_w_t);
	getch();
}
