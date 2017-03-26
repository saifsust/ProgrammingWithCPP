#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define pf printf
long long lcs(string mother,string child) {

    long long motherSize=mother.size();
    long long childSize = child.size();
    int ans=0;
    for(int i=0; i<motherSize; i++) {

        for(int j=0; j<childSize; j++) {
            if(mother[i]==child[j]) {
                int count=0;
                for(int k=i,l=j; l<childSize; k++,l++) {
                    if(mother[k]==child[l]) {
                        count++;
                    } else break;
                }
                ans=max(count,ans);
            }
        }

    }
    return ans;
}
int main(int argc,char** argv) {
    string mother,child;
    while(getline(cin,mother)) {
        getline(cin,child);
        pf("%lld\n",lcs(mother,child));
    }
    return 0;
}
