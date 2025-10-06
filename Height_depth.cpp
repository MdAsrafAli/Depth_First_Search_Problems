#include<bits/stdc++.h>
using namespace std;
const int N=100000;
vector<int>graph[N],depth(N),height(N);
void dfs(int vertex,int par=0)
{
    for(auto child:graph[vertex]){
        if(child==par)continue;
        depth[child]=depth[vertex]+1;
        dfs(child,vertex);
        height[vertex]=max(height[vertex],height[child]+1);
    }
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
    for(int i=0;i<n;i++){
        cout<<i<<" : "<<height[i]<<" "<<depth[i]<<endl;
    }
}