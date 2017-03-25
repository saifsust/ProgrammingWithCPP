#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
int BearAndBigBrother(int  Limak,int Bob) {


    int countYears=0;
    while(Limak<=Bob) {
        Limak=Limak*3;
        Bob=Bob*2;
        countYears++;
    }
    return countYears;

}
int main(int argc,char** argv) {

    int a,b;
    sf("%d%d",&a,&b);
    pf("%d\n",BearAndBigBrother(a,b));
    return 0;
}
