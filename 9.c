#include<stdio.h>
#include<conio.h>
int main()
 {
   int x,n,p[10],pp[10],bt[10],w[10],t[10],awt,atat,i,at[10],tq;
 
   //n is number of process
   //p is process
   //pp is process priority
   //bt is process burst time
   //w is wait time
   // t is turnaround time
   //awt is average waiting time
   //atat is average turnaround time
   //at is arrival time
   //tq is time qunatum
 
 
   printf("Enter the number of process : ");
   scanf("%d",&n);
   printf("Enter time quantum");
   scanf("%d",&tq);
   printf("\n\t Enter burst time : time priorities : Arrival time  \n");
 
   for(i=0;i<n;i++)
    {
      //cout<<"\nProcess["<<i+1<<"]:";
      printf("\n Process %d ",i+1);
      //cin>>bt[i]>>pp[i]>>at[i];
      scanf("%d %d %d",&bt[i],&pp[i],&at[i]);
	  p[i]=i+1;
    }
 
//sorting on the basis of priority
int j;
  for(i=0;i<n-1;i++)
   {
     for(j=i+1;j<n;j++)
       {
     x=pp[i];
     pp[i]=pp[j];
     {
       if(pp[i]<pp[j])
     pp[j]=x;
     x=bt[i];
     bt[i]=bt[j];
     bt[j]=x;
     x=p[i];
     p[i]=p[j];
     p[j]=x;
      }
   }
}
w[0]=0;
awt=0;
t[0]=bt[0];
atat=t[0];
for(i=1;i<n;i++)
 {
 	if(tq<n || tq>n) {
	 
   w[i]=t[i-1];
   awt+=w[i];
   t[i]=w[i]+bt[i];
   atat+=t[i];
	 }
 }
 
 //Gantt chrat
 printf("\n");
 printf("Gantt chart\n");
 for(i=0;i<n;i++)
 {
 	printf("P %d ",p[i]);
 }
//Displaying the process
 
printf("\n\nProcess \t Burst Time \t Wait Time \t Turn Around Time   Priority \tArrival time \n");
for(i=0;i<n;i++){
printf("\n  %d",p[i]); printf("\t\t %d",bt[i]); printf("\t\t %d",w[i]); printf("\t\t %d",t[i]); printf("\t\t %d",pp[i]); printf("\t\t %d",at[i]);

}
awt/=n;
atat/=n;
printf("\n Average Wait Time : %d ",awt);
printf("\n Average Turn Around Time : %d",atat);
getch();
}
