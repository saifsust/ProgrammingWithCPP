#include<bits/stdc++.h>
#define sf scanf
#define pf printf
using namespace std;
int main(int argc,char** argv) {

    int n;
    freopen("inOut/in.txt","r",stdin);
    freopen("inOut/uvaOut.txt","w",stdout);
    while(sf("%d",&n),n) {
        double arr[n+2];
        double in;
        double totalTripCost=0.0;
        for(int i=0; i<n; i++) {
            cin>>arr[i];
            totalTripCost+=arr[i];
        }
        double averageCost=totalTripCost/(n*1.0);
        sort(arr+0,arr+n);
        double returnBalance=0.0,gainBalance=0.0;
        for(int i=0; i<n; i++) {
            if(averageCost>arr[i]) {
                returnBalance+=floor((averageCost-arr[i])*100.0)/100.0;
            } else {

                gainBalance+=floor((arr[i]-averageCost)*100.0)/100.0;
            }

        }
        pf("$%.2f\n",returnBalance>gainBalance? returnBalance:gainBalance);

    }
    return 0;
}
