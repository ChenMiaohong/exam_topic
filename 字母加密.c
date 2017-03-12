#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUF_MAX 100
static int square[27][27];
void input(char *studentID,float studentmoney )
{
    printf("please input your ID(12)\n");
    gets(studentID);
    while(strlen(studentID)>12)
    {
        printf("your ID is not legal\n");
        printf("please try again\n");
        free(studentID);
        gets(studentID);
    }
    printf("please input your money(0-500)\n");
    scanf("%f",&studentmoney);
    while((studentmoney<0)||(studentmoney>500))
    {
        printf("your input money is not legal\n");
        printf("please try again\n");
        scanf("%f",&studentmoney);
    }
    puts("you ID is ");
    puts(studentID);
    //puts("\n");
    printf("you money is %.2f\n",studentmoney);

}
char * UpperKey(char key[])
{
    int i;
    int key_length = strlen(key);
    for( i = 0; i < key_length; i++)
    {
        if (key[i] >= 'a' && key[i] <= 'z')
        {
            key[i] -= 32;
        }
    }
    return key;
}
char * VigenereEncrypt(char word[], char key[])
{
	char text[BUF_MAX];
	int key_length = strlen(key);
	int word_length = strlen(word);
	int i, j, k;
	for(i = 0; i < word_length; i++)
	{
		j = i % key_length;
		if (word[i] >= 'a' && word[i] <= 'z')
		{
			k = word[i] - 'a';
			k = (k + key[j] - 'A') % 26;
			text[i] = k + 'a';
		}
        else if (word[i] >= 'A' && word[i] <= 'Z')
        {
            k = word[i] - 'A';
            k = (k + key[j] - 'A') % 26;
            text[i] = k + 'A';
        }
        else
        {
            text[i] = word[i];
        }
    }
    text[i] = '\0';
    printf("Encrypt string:");
    puts(text);
    return text;
}
void VigenereDecript(char en_word[], char key[])
{
    char word[BUF_MAX];  int key_length = strlen(key);
    int word_length = strlen(en_word);
    int i, j, k;
    for(i = 0; i < word_length; i++)
    {
        j = i % key_length;
        if (en_word[i] >= 'a' && en_word[i] <= 'z')
        {
            k = en_word[i] - 'a';
            k = (k - (key[j] - 'A') + 26) % 26;
            word[i] = k + 'a';
        }
        else if (en_word[i] >= 'A' && en_word[i] <= 'Z')
        {
            k = en_word[i] - 'A';
            k = (k - (key[j] - 'A') + 26) % 26;
            word[i] = k + 'A';
        }


    }

    word[i]='\0';
    printf("Decrypt string:");
    puts(word);
}
int main()
{
    char *studentID=(char *)malloc(sizeof(char)*12);
    float studentmoney;
    char *mykey =(char *)malloc(sizeof(char)*6);
    char *enword=(char *)malloc(sizeof(char)*12);
    char *a=(char *)malloc(sizeof(char)*1);;
    input(studentID,studentmoney);
    gets(a);
    gets(mykey);
    puts(UpperKey(mykey));
    enword=VigenereEncrypt(studentID,UpperKey(mykey));

    VigenereDecript(enword,UpperKey(mykey));

}

