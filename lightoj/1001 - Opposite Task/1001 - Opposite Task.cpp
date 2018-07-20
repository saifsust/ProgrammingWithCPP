#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;

int main(int argc,char *argv[])
{

    int testCase,num;
    scanf("%d",&testCase);
    for(int test = 1;test<=testCase;++test){

        scanf("%d",&num);
        int a=0;
        if(num<10)printf("0 %d\n",num);
        else printf("%d 10\n",(num-10));
    }
    return 0;
}
