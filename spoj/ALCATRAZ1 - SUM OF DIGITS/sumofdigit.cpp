#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main(int argc,char *argv[])
{
    int testCase;
    scanf("%d",&testCase);
    string num;
    for(int test = 1;test<=testCase;test++){
        cin>>num;

        int sum = 0;
        for(int i=0;i<num.size();i++){
            sum+=num[i]-'0';
        }
        printf("%d\n",sum);

    }
    return 0;
}
