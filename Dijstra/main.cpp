#include<cstdio>
#include<iostream>
#include<vector>
//#include<pair>
#include<queue>

using namespace std;
const int N = 1000;
queue< pair<int,int> >q;

vector< pair<int,int> > graph[N];

int dists[N];

void fresh(){
	for(int i=0;i<N;++i) dists[i]=100000;
}

int dijstra(int start,int dest){
   
   q.push(make_pair(start,0));
   fresh();
   dists[start]=0;
   while(!q.empty()){
   	pair<int,int> head = q.front();
   	q.pop();
   	for(int i =0;i<graph[head.first].size();++i){
   		pair<int,int> next = graph[head.first][i];
   		int dist = dists[head.first]+next.second;
   		if(dist<dists[next.first]){
   			dists[next.first]=dist;
   			q.push(make_pair(next.first,dist));
   		}
   	}
   }
   return dists[dest];
  }


int main(int argc,char* argv[]){
   
   freopen("in.txt","r",stdin);

  int node ,edge,u,v,w;

   scanf("%d%d",&node,&edge);

   for(int i=0;i<edge;++i){
      scanf("%d%d%d",&u,&v,&w);
      graph[u].push_back(make_pair(v,w));
      graph[v].push_back(make_pair(u,w));
   }

   int start,dest;
   scanf("%d%d",&start,&dest);

   int dist = dijstra(start,dest);

   printf("Distance %d To %d = %d\n\n",start,dest,dist);


}












