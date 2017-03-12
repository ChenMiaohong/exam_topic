#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 struct student{
    char *studentID;
    char *name;
    float studentmoney;
    char *buf;//缓存区，用于float变量与字符串的转化
    int temp[3];//用于存放上述变量的
 };
struct student input()
{
    struct student stu;
    char *ystudentID=(char *)malloc(sizeof(char)*12);
    char *yname=(char *)malloc(sizeof(char)*12);
    float ystudentmoney;
    printf("please input your name(12)\n");
    gets(yname);
    while(strlen(yname)>12)
    {
        printf("your name is not legal\n");
        printf("please try again\n");
        free(yname);
        gets(yname);
    }
    stu.name=yname;
    printf("please input your ID(12)\n");
    gets(ystudentID);
    while(strlen(ystudentID)>12)
    {
        printf("your ID is not legal\n");
        printf("please try again\n");
        free(ystudentID);
        gets(ystudentID);
    }
    stu.studentID=ystudentID;
    printf("please input your money(0-500)\n");
    scanf("%f",&ystudentmoney);
    while((ystudentmoney<0)||(ystudentmoney>500))
    {
        printf("your input money is not legal\n");
        printf("please try again\n");
        scanf("%f",&ystudentmoney);
    }
    stu.studentmoney=ystudentmoney;
    return  stu;
}
struct student lsecret(struct student per,char *key,int len)
{   int sel =len;
    struct student cer;

    int i;
    char *bef=(char *)malloc(sizeof(char)*12);
    char *aft=(char *)malloc(sizeof(char)*12);
    bef = per.name ;
    for(i=0;*(bef+i)!='\0';i++)
	{
        int j=0;
		j=i%sel;
		*(aft+i)=*(bef+i)^*(key+j);
	}
	cer.name=aft;
	free(bef);free(aft);
	char *cef=(char *)malloc(sizeof(char)*12);
    char *dft=(char *)malloc(sizeof(char)*12);
	cef = per.studentID ;
    for(i=0;*(cef+i)!='\0';i++)
	{	int j;
		j=i%sel;
		*(dft+i)=*(cef+i)^*(key+j);

	}
	cer.studentID=dft;
	free(cef);free(dft);
	char *mon=(char *)malloc(sizeof(char)*12);
    char *luf=(char *)malloc(sizeof(char)*12);
    sprintf(mon,"%.2f",per.studentmoney);
    cer.temp[0]=strlen(mon);
	for(i=0;i<cer.temp[0];i++)
	{	int j;
		j=i%sel;
		*(luf+i)=*(mon+i)^*(key+j);
	}
	cer.buf=luf;
    return cer;
}
void asecret(struct student per,char *key,int len)
{
    int sel =len;
    struct student cer;

    int i;
    char *bef=(char *)malloc(sizeof(char)*12);
    char *aft=(char *)malloc(sizeof(char)*12);
    bef = per.name ;

	for(i=0;*(bef+i)!='\0';i++)
	{	int j;
		j=i%sel;
		*(aft+i)=*(bef+i)^*(key+j);
	}
	cer.name=aft;
	free(bef);free(aft);
	char *cef=(char *)malloc(sizeof(char)*12);
    char *dft=(char *)malloc(sizeof(char)*12);
	cef = per.studentID ;

	for(i=0;*(cef+i)!='\0';i++)
	{	int j;
		j=i%sel;
		*(dft+i)=*(cef+i)^*(key+j);
	}
	cer.studentID=dft;
	free(cef);free(dft);
    char *mon=(char *)malloc(sizeof(char)*12);
    char *luf=(char *)malloc(sizeof(char)*12);
    char *cdf;

    mon = per.buf;
    int lsd = per.temp[0];
	for(i=0;i<lsd;i++)
	{	int j;
		j=i%sel;
		*(luf+i)=*(mon+i)^*(key+j);

	}
	float f1 = strtof(luf,&cdf);
	cer.studentmoney=f1;
	printf("\nid is %s , name is   %s,money is   %.2f",cer.name,cer.studentID,cer.studentmoney);
    return cer;
}
int main()
{
    int m,j;
    char *mykey=(char *)malloc(sizeof(char)*6);
    char *a=(char *)malloc(sizeof(char)*1);
    struct student per[50];
    printf("how many student you will input?\n");
    scanf("%d",&m);
    gets(a);
    for(j=0;j<m;j++)
    {
         per[j]=input();
         gets(a);
    }
    printf("input your key\n");
    gets(mykey);
    int len = strlen(mykey);
     printf("start do secreting\n");
    for(j=0;j<m;j++)
    {
         lsecret(per[j],mykey,len);
    }
    printf("start decode secret\n");
    printf("-----------------------------------\n");
    printf("\n");
    for(j=0;j<m;j++)
    {
        asecret( lsecret(per[j],mykey,len),mykey,len);
    }
    printf("\n");
    printf("-----------------------------------\n");


}

