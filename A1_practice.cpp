// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long

// vector<ll>edges[1001];
// vector<ll>vis(1001,0);
// void dfs(ll node){
//     if(vis[node]==1){
//         return;
//     }
//     vis[node]=1;
//     cout<<node<<" ";
//     for (auto i:edges[node]){
//         if(vis[i]!=1){
            
//             dfs(i);
//         }
//     }
// }
// void dfsIter(ll node){
//     stack<ll>s;
//     s.push(node);
//     vis[node]=1;
//     while(!s.empty()){
//         ll curr=s.top();
//         s.pop();
//         cout<<curr<<" ";
//         for(auto i:edges[curr]){
//             if(!vis[i])
//             {
//                 s.push(i);
//             vis[i]=1;
//             }
            
//         }
//     }
// }
// void bfs(ll node){
//     queue<ll>q;
//     q.push(node);
//     vis[node]=1;
//     while(!q.empty()){
//         ll curr=q.front();
//         q.pop();
       
//         cout<<curr<<" ";
//         for(auto i:edges[curr]){
//             if(vis[i]!=1){
//                 q.push(i);
//                 vis[i]=1;
//             }
//         }
//     }
// }

// int main(){
//     ll v,e;
//     cin>>v>>e;
//     for(ll i=0;i<e;i++){
//         ll u1,v1;
//         cin>>u1>>v1;
//         edges[u1].push_back(v1);
//         edges[v1].push_back(u1);
//     }
//     // dfs(1);
//     dfsIter(1);
// }

#include<bits/stdc++.h>
using namespace std;
#define ll long long
 

vector<ll>edges[1001];
vector<ll>vis(1001);

void dfs(ll node){
    if(vis[node]){
        return;
    }
    vis[node]=1;
    cout<<node<<endl;
    for(auto i:edges[node]){
        if(vis[i]!=1)
            dfs(i);
    }
}

int main(){
    ll vert,edg;
    cin>>vert>>edg;
    for(ll i=0;i<edg;i++){
        ll u,v;
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

}