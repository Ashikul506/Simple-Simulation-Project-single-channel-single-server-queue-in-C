#include<stdio.h>
int main(void)
{
    int i,p;
    int rd_arr[10],intr_arr[10],rd_ser[10],ser[10],arr_t[10],ser_beg[10],ser_end[10],wt[10],ts[10],it[10];
    printf("How many processes?\n");
    scanf("%d",&p);
    printf("Enter random digits for the arrival of the processes:\n");
    printf("RD for process 1:0\n");
    intr_arr[0]=0;
    for(i=1;i<p;i++)
    {
        printf("RD for process %d:",i+1);
        scanf("%d",&rd_arr[i]);
        if(rd_arr[i]>0 && rd_arr[i]<=125)
        {
            intr_arr[i]=1;
        }
        else if (rd_arr[i]>125 && rd_arr[i]<=250)
        {
            intr_arr[i]=2;
        }
        else if (rd_arr[i]>250 && rd_arr[i]<=375)
        {
            intr_arr[i]=3;
        }
        else if (rd_arr[i]>375 && rd_arr[i]<=500)
        {
            intr_arr[i]=4;
        }
        else if (rd_arr[i]>500 && rd_arr[i]<=625)
        {
            intr_arr[i]=5;
        }
        else if (rd_arr[i]>625 && rd_arr[i]<=750)
        {
            intr_arr[i]=6;
        }
        else if (rd_arr[i]>750 && rd_arr[i]<=875)
        {
            intr_arr[i]=7;
        }
        else if (rd_arr[i]>875 && rd_arr[i]<=1000)
        {
            intr_arr[i]=8;
        }
        else
            printf("Wrong input.\n");
    }
    printf("Enter random digits for the time of services\n");
    for(i=0;i<p;i++)
    {
        printf("RD for service %d:",i+1);
        scanf("%d",&rd_ser[i]);
        if(rd_ser[i]>0 && rd_ser[i]<=10)
        {
            ser[i]=1;
        }
        else if(rd_ser[i]>10 && rd_ser[i]<=30)
        {
            ser[i]=2;
        }
        else if(rd_ser[i]>30 && rd_ser[i]<=60)
        {
            ser[i]=3;
        }
        else if(rd_ser[i]>60 && rd_ser[i]<=85)
        {
            ser[i]=4;
        }
        else if(rd_ser[i]>85 && rd_ser[i]<=95)
        {
            ser[i]=5;
        }
        else if(rd_ser[i]>95 && rd_ser[i]<=100)
        {
            ser[i]=6;
        }
        else
            printf("Wrong input.\n");
    }
    arr_t[0]=0;
    for(i=1;i<p;i++)
    {
        arr_t[i]=arr_t[i-1]+intr_arr[i];
    }
    ser_beg[0]=0;
    ser_end[0]=ser_beg[0]+ser[0];
    for(i=1;i<p;i++)
    {
        if(arr_t[i]>=ser_end[i-1])
        {
            ser_beg[i]=arr_t[i];
        }
        else
        {
            ser_beg[i]=ser_end[i-1];
        }
        ser_end[i]=ser_beg[i]+ser[i];
    }
    for(i=0;i<p;i++)
    {
        wt[i]=ser_beg[i]-arr_t[i];
        ts[i]=ser[i]+wt[i];
    }
    it[0]=0;
    for(i=1;i<p;i++)
    {
        it[i]=ser_beg[i]-ser_end[i-1];
    }
    printf("Customer  |Intra     |Arrival   |Service   |Service   |Wait      |Service   |Time      |Idle      \n");
    printf("Number    |Arrival   |Time      |Time      |Begin     |Time      |End       |Spend     |Time      \n");
    for(i=0;i<p;i++)
    {
        printf("  %d         %d          %d          %d         %d          %d          %d           %d           %d\n",i+1,intr_arr[i],arr_t[i],ser[i],ser_beg[i],wt[i],ser_end[i],ts[i],it[i]);
    }
    return 0;
}
