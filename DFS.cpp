#include<bits/stdc++.h>
using namespace std;
const int N=10000;
vector<int>graph[N];
bool vis[N];
void dfs(int vertex)
{
    vis[vertex]=true;
    cout<<"vertex : "<<vertex<<"\n";
    for(int child:graph[vertex])
    {
        cout<<"Vertex :"<<vertex<<" "<<"child : "<<child<<"\n";
        if(vis[child])continue;
        dfs(child);
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
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(graph[1][0]);
}
