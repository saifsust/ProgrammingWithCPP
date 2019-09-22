#include<bits/stdc++.h>

using namespace std;

const int MAX_LEN = 19;
const int MAX_SUM = 162;
const int MAX_SQR_SUM = 1458;

typedef long long ll;

ll is_prime[MAX_SQR_SUM+1];
ll save[MAX_LEN+1][MAX_SUM+1][MAX_SQR_SUM+1];
ll digits[MAX_LEN+1];


/** declaration of function **/
void seive();
ll get_total_lucky_nums_in_range(ll num);
ll luck_num_checker(int len, ll sum, ll sqr_sum, bool checker);

void seive(){
    
    is_prime[0] = 1;
    is_prime[1] = 1;
    for(int i=4;i<=MAX_SQR_SUM;i+=2) is_prime[i] = 1;

    for(int i=3; i<= (int) sqrt(MAX_SQR_SUM); i+=2){
        
        if(!is_prime[i]){
            for(int j= i*i; j<=MAX_SQR_SUM; j+=i*2) is_prime[j] = 1;
        }
    }
}


ll get_total_lucky_nums_in_range(ll num){
    if(num == 0) return 0;

    int len =0;
    while(num != 0){
        digits[len++]= num % 10;
        num /= 10;
    }

  return luck_num_checker(len -1 , 0,0 , true);
    
}

ll luck_num_checker(int len, ll sum, ll sqr_sum, bool checker){
    if( len == -1) return !is_prime[sum] && !is_prime[sqr_sum];

    if( !checker && save[len][sum][sqr_sum] != -1) return save[len][sum][sqr_sum];
     
    int end = checker ? digits[len] : 9;

    ll answer = 0;

    for(ll d = 0; d<= end; ++d){
       answer += luck_num_checker(len -1, sum + d, sqr_sum + d * d, checker & d == end);
    }
     if(!checker) save[len][sum][sqr_sum] = answer;

    return answer;
}


int main(){
   
   ios::sync_with_stdio(false);
   cin.tie(0);
   
   //freopen("in.txt","r", stdin);
   seive();

    ll testCase =0, a = 0, b = 0;
    memset(save, -1, sizeof(save));

    scanf("%lld", &testCase);
    for( ll test =1; test <= testCase; ++test ){
      scanf("%lld%lld",&a,&b);
      printf("%lld\n",get_total_lucky_nums_in_range(b)-get_total_lucky_nums_in_range(a-1));

    }

    return 0;
}