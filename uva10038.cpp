#include<bits/stdc++.h>
#define sf scanf
#define pf printf
int main(int argc,char** argv) {
    using namespace std;
    int n;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while(sf("%d",&n)!=EOF) {
        if(n<1) continue;
        long long arr[n+1];

        for(int i=0; i<n; i++)
            cin>>arr[i];
        if(n==1) {
            pf("Jolly\n");
            continue;
        }
        long long store[n+1];
        for(int i=0; i<n-1; i++) {
            store[i]=abs(arr[i+1]-arr[i]);
        }

        sort(store+0,store+n-1);
        bool test=true;
        for(int i=0; i<n-1; i++) {
            if(store[i]!=i+1) {
                test=false;
                break;
            }
        }
        if(test) {
            pf("Jolly\n");
        } else {
            pf("Not jolly\n");
        }

    }

}
