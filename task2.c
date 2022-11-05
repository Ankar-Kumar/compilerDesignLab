#include<stdio.h>

char str[1000];
int is_digit(char ch)
{
    if(ch>='0' && ch<='9') return 1;
    return 0;
}
int is_char(char ch)
{
    if(ch>='a' && ch<='z') return 1;
    if(ch>='A' && ch<='Z') return 1;
    return 0;
}

int is_vowel(char ch)
{
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U') return 1;
    return 0;
}
int mrk[1000];
void count()
{
    int v_cnt=0,cnt=0,i,j,k,v=0,c=0,in1=0,in2=0;
    char vowel[400],cont[400];
    char vw[400],cns[400];
    for(i=0; str[i]; i++)
    {
        char x=str[i];

        //printf("%c",x);
        if(is_vowel(x))
        {
            v_cnt++;
            if(!mrk[(int)x])
            {
                vowel[v++]=x;
                vowel[v++]=' ';
            }

        }
        else if(is_char(x))
        {
            cnt++;
            if(!mrk[(int)x])
            {
                cont[c++]=x;
                cont[c++]=' ';
            }

        }
        mrk[(int)x]=1;
        int t=(int)x+32;
        int tt=(int)x-32;

        mrk[t]=1;
        mrk[tt]=1;

    }

    vowel[v] = '\0';
    cont[c] = '\0';
    printf("Numbers of vowels : %d\n",v_cnt);
    printf("Numbers of constants : %d\n",cnt);

    //find unique character
    printf("\nvowels are :%s\n",vowel);
    printf("constants are :%s\n",cont);
}

void separate(){
    int i,j,k,v=0,c=0,in1=0,in2=0;

    char vw[100],cns[100];
    for(i=0; str[i]; i++)
    {
        char x=str[i];

        //printf("%c",x);
        if(is_vowel(x))
        {

            while(str[i]!=' '&&str[i]!='\0')
            {
                vw[in1++] = str[i++];
            }
            i--;
            vw[in1++]  = ' ';
        }
        else if(is_char(x))
        {

            while(str[i]!=' '&&str[i]!='\0')
            {
                cns[in2++] = str[i++];
            }
            i--;
            cns[in2++]  = ' ';

        }


    }
    vw[in1] = '\0';
    cns[in2] = '\0';
    printf("\n\nWords started with vowel : %s\n",vw);
    printf("Words started with consonant : %s\n",cns);

}
int main(){

    freopen("in.txt","r",stdin);
   //freopen("task2.txt","w",stdout);
    gets(str);
    count();
    separate();
}
