/**
* DFS로 각 인접노드로 갔을 때 반환되는 노드 개수 비교하여 가장 큰 값 반환
* 시작점 마다 DFS 를 실행하여 가장 큰 값이 답
*/
#include<iostream>
#include<vector>
using namespace std;

int N,M;
vector<vector<int> > adj;

int dfs(int cur, int visited) {
    int max=0;
    for (int next:adj[cur]) {
        if ((visited&(1<<next))==0) {
            visited|=1<<cur;
            int num=dfs(next,visited);
            if (max<num) max=num;
        }
    }

    return max+1;
}

int get_max(){
    int max=0;

    for(int i=0;i<N;i++){ //시작지점
        int visited=(1<<i);
        int num=dfs(i,visited);
        if (max<num) max=num;
    }

    return max;
}

int main(){
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        cin>>N>>M;

        adj.resize(N);
        adj.clear();
        for(int i=0;i<M;i++){
            int x,y;
            cin>>x>>y;
            adj[x-1].push_back(y-1);
            adj[y-1].push_back(x-1);
        }

        cout<<'#'<<t<<' '<< get_max() <<endl;
    }
}