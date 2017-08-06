#include<stdio.h>
main()
{
int t;
scanf("%d",&t);
while(t--)
{
    unsigned long long int N,M,i,j,numstudentselected=0,sum=0,numofcompselectedstudents=0;
    scanf("%llu %llu",&N,&M);
    int minSalary[N];
    for(i=0;i<N;i++)
    {
        scanf("%llu",&minSalary[i]);
    }
    unsigned long long int companyrelatedinfo[M][3];
    for(i=0;i<M;i++)
    {
        scanf("%llu %llu",&companyrelatedinfo[i][0],&companyrelatedinfo[i][1]);
        companyrelatedinfo[i][2]=0;
    }
    char qual[N][M];

    for(i=0;i<N;i++)
    {
        getchar();
        for(j=0;j<M;j++)
        {
            scanf("%c",&qual[i][j]);
        }
    }


    for(i=0;i<N;i++)
    {
        int max=0,maxindex=-1;
        for(j=0;j<M;j++)
        {
            if(qual[i][j]=='1')
            {
                if(companyrelatedinfo[j][0]>=minSalary[i] && companyrelatedinfo[j][0]>max && companyrelatedinfo[j][1]>0)
                {
                    max=companyrelatedinfo[j][0];
                    maxindex=j;
                }
            }
        }
        if(maxindex!=-1)
        {
            companyrelatedinfo[maxindex][1]=companyrelatedinfo[maxindex][1]-1;
            sum=sum+max;
            numstudentselected=numstudentselected+1;
            companyrelatedinfo[maxindex][2]=1;
        }
    }


    for(j=0;j<M;j++)
    {
        if(companyrelatedinfo[j][2]==1)
        {
            numofcompselectedstudents=numofcompselectedstudents+1;
        }
    }


    printf("%llu %llu %llu\n",numstudentselected,sum,M-numofcompselectedstudents);
}
}
