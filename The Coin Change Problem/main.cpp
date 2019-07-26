#include<bits/stdc++.h>

using namespace std;

int main(){
   
   int  m,n;
   scanf("%d%d",&n,&m);

        long coins[m],changes[m+2][n+2];

       for(int i=0;i<m;++i){
           scanf("%ld",&coins[i]);
       }
   

       for(int i=0;i<=m;++i)changes[i][0]=0;
       for(int i=0;i<=n;++i) changes[0][i]=0;
      
       for(int i=1;i<=m;++i){
           for(int j=1;j<=n;++j){
               if(coins[i-1]==j)changes[i][j]=changes[i-1][j]+1;
               else if(coins[i-1]>j) changes[i][j] = changes[i-1][j];
               else changes[i][j] = changes[i-1][j]+changes[i][j-coins[i-1]];
           }
       }
       printf("%ld\n",changes[m][n]);
    return 0;
}