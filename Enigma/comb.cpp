#include <fstream>

using namespace std;
ofstream out("output");

int main()
{
    char v[60];
    char i,j,k;
    int ct=0;
    for(i='a';i<='z';i++)
        v[++ct] = i;
    for(i='A';i<='Z';i++)
        v[++ct] = i;

    v[++ct] = ' ';

    for(i=1;i<=ct;i++)
        for(j=1;j<=ct;j++)
            for(k=1;k<=ct;k++)
                out<<v[i]<<v[j]<<v[k]<<"\n";
    return 0;
}
