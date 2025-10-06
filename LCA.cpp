#include<bits/stdc++.h>
using namespace std;
const int N=100000;
vector<int>graph[N],parent(N);
void dfs(int vertex,int par=-1)
{
    parent[vertex]=par;
    for(auto child:graph[vertex]){
        if(child==par)continue;
        dfs(child,vertex);
    }
}

vector<int> path(int vertex){
    vector<int>p;
    while(vertex!=-1){
        p.push_back(vertex);
        vertex=parent[vertex];
    }
    reverse(p.begin(),p.end());
    return p;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        v1--;
        v2--;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(0);
    int x,y;cin>>x>>y;
    vector<int> path_x=path(x);
    vector<int> path_y=path(y);
    int ln=min(path_x.size(),path_y.size());
    int lca=-1;
    for(int i=0;i<ln;i++){
        if(path_x[i]==path_y[i]){
            lca=i;
        }else{
            break;
        }
    }
    cout<<"LCA : "<<lca<<endl;
}