#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
const int inf = 1e8;
int TheMonster(int a,int b,int c,int d) {
    while(b!=d && b<inf) {
        if(b<d) {
            b+=a;
        } else
            d+=c;
    }
    return b<inf ? b: -1 ;
}
int main(int aargc,char** argv) {

    int a,b,c,d;
    sf("%d%d%d%d",&a,&b,&c,&d);
    cout<<TheMonster(a,b,c,d)<<endl;
    return 0;
}
