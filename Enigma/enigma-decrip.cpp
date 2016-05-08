#include <iostream>
#include <cstring>
#define SIZE 100
#define length_alfabet 53
using namespace std;
 
void print(char *s)
{
 
    int i,n=strlen(s);
    for(i=0;i<n;i++)
        cout<<s[i];
    cout<<"\n";
}
 
void shuffle(char *alfabet)
{
    char c;
    int i;
    for(i=0;i<length_alfabet/2;i+=2)
    {
        c=alfabet[i];
        alfabet[i]=alfabet[i+length_alfabet/2];
        alfabet[i+length_alfabet/2]=c;
    }
 
    for(i=0;i<length_alfabet/2;i++)
    {
        c=alfabet[i];
        alfabet[i]=alfabet[i+length_alfabet/2];
        alfabet[i+length_alfabet/2]=c;
    }
 
    for(i=0;i<length_alfabet/4;i++)
    {
        c=alfabet[i];
        alfabet[i]=alfabet[i+length_alfabet/4];
        alfabet[i+length_alfabet/4]=c;
    }
 
}
 
void generate_alfabet(char *alfabet)
{
    int i;
 
    char c='a';
     
    for(i=0;i<26;i++)
    {  
        alfabet[i]=c;
        c++;
    }
    c='A';
    for(i=26;i<52;i++)
    {
        alfabet[i]=c;
        c++;
    }
 
    alfabet[52]=' ';
 
}
template <typename T>
void reset(T v,int length)
{
    int i;
    for(i=0;i<length;i++)
        v[i]=0;
}
 
int find(char *str,char s)
{
    char * pch;
    pch=strchr(str,s);
    return (pch-str);
}
 
void encode(char *msg,char *alfabet,char *new_alfabet)
{
    char n = strlen(msg);
    int i;
    for(i=0;i<n;i++)
        cout<<new_alfabet[find(alfabet,msg[i])];
    cout<<"\n";
}
 
void decode(char *msg,char *alfabet,char *new_alfabet)
{
    encode(msg,new_alfabet,alfabet);
}
 
void generate_new_alfabet(char* new_alfabet,char *alfabet,char *cuv)
{
    char last = ' ';
    int n = strlen(cuv);
    bool viz[SIZE];
    bool taken[2*SIZE];
   
    reset(viz,SIZE);
    reset(taken,2*SIZE);
   
    int i,j;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if( !viz[i] && cuv[i] == cuv[j])
                viz[j] = 1;
 
    int poz=0;
    for(i=0;i<n;i++)
        if(!viz[i])
        {
            new_alfabet[poz] = cuv[i];
            poz++;
            taken[ (int)cuv[i] ] = 1;
        }  
   
    if(!taken[ (int)last ])
    {
        new_alfabet[poz] = last;
        taken[ (int)cuv[i] ] = 1;
        poz++;
    }
 
     for(i=0;i<length_alfabet;i++)
     {
         if(!taken[alfabet[i]])
         {
             new_alfabet[poz] = alfabet[i];
             poz++;
         }
     }
 
     //shuffle(new_alfabet);
}
 
int main()
{
    char mesaj[SIZE*SIZE];
    cout<<"Intoduceti un mesaj:";
    cin.getline(mesaj,SIZE*SIZE);
 
    cout<<"Introduceti cuvantul cheie:";
    char cuv[SIZE+1];
    cin.getline(cuv,SIZE+1);
 
    char new_alfabet[SIZE],alfabet[SIZE];
   
    generate_alfabet(alfabet);
    generate_new_alfabet(new_alfabet,alfabet,cuv);
 
    print(alfabet);
    print(new_alfabet);
   
    encode(mesaj,alfabet,new_alfabet);
 
    cout<<"Introduceti textul pe care vreti sa-l decodati:";
    char mesaj2[SIZE*SIZE];
    cin.getline(mesaj2,SIZE*SIZE);
    for(int i = 0 ; i <= 52 ; i++ )
    {
        cuv[2] = alfabet[i];
        generate_new_alfabet(new_alfabet,alfabet,cuv);
        decode(mesaj2,alfabet,new_alfabet);
    }
   
    return 0;
}
