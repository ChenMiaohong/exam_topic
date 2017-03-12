#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* struct student{
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
}*/
int main()
{
    int m,j;
    char *studentid=(char *)malloc(sizeof(char)*12);
    char *sstudentid=(char *)malloc(sizeof(char)*12);
    char *jstudentid=(char *)malloc(sizeof(char)*12);
    char *key=(char *)malloc(sizeof(char)*6);
    char *ssmoney=(char *)malloc(sizeof(char)*10);
    char *jmoney=(char *)malloc(sizeof(char)*10);
    char *moneybuf=(char *)malloc(sizeof(char)*10);;
    char *buf;
    float studentmoney;
    int i;
    printf("input  you  studentid\n");
    gets(studentid);

    printf("please input your money(0-500)\n");
    scanf("%f",&studentmoney);
     printf("input your six characters key\n");
     getchar();
    gets(key);

    printf("start do secreting\n");
    int sel;
    sel=strlen(key);
    printf("%s\n",studentid);
     printf("%s\n",key);
     printf("%f\n",studentmoney);
   for(i=0;*(studentid+i)!='\0';i++)
	{
        int j=0;
		j=i%sel;
		*(sstudentid+i)=*(studentid+i)^*(key+j);
	}
	sprintf(moneybuf,"%.2f",studentmoney);
	for(i=0;*(moneybuf+i)!='\0';i++)
	{	int j;
		j=i%sel;
		*(ssmoney+i)=*(moneybuf+i)^*(key+j);
	}
    printf("start decode secret\n");
    printf("-----------------------------------\n");
	for(i=0;*(studentid+i)!='\0';i++)
	{
        int j=0;
		j=i%sel;
		*(jstudentid+i)=*(sstudentid+i)^*(key+j);
	}
    free(moneybuf);
	for(i=0;*(moneybuf+i)!='\0';i++)
	{	int j;
		j=i%sel;
		*(jmoney+i)=*(ssmoney+i)^*(key+j);
	}
	float f1 = strtof(jmoney,&buf);
	free(studentid); free(sstudentid);free(jstudentid);
	free(key);free(ssmoney);free(jmoney);
	printf("%s\n",jstudentid);
	printf("%.2f",f1);

}

/*#include<stdio.h>
#include<string.h>

int main()
{
	char bfs[1024]={0};
	char afs[1024]={0};
	char sls[1024]={0};
	char secret[1024]={0};
	int sel=0;
	int sl=0;
	int i=0;
	printf(" plsase data\n");
	gets(bfs);
	//printf("%[^'\n']",bfs);
	printf("please secret \n");
	gets(secret);
	sel=strlen(secret);
	for(i=0;*(bfs+i)!='\0';i++)
	{	int j;
		j=i%sel;
		*(afs+i)=*(bfs+i)^*(secret+j);

	}
	sl=i;
	for(i=0;i<sl;i++)
	{	int j;
		j=i%sel;
		*(sls+i)=*(afs+i)^*(secret+j);
	}
	printf("%s\n",sls);


}*/
