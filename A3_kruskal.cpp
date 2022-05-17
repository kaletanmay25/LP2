// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long

// vector<ll>parent(1001);
// vector<ll>rank1(1001,0);
// ll get(ll node){
//     if(parent[node]==node){
//         return node;
//     }
//     return parent[node]=get(parent[node]);
// }

// void union_sets(ll a,ll b){
//         a=get(a);
//         b=get(b);
//     if(a!=b){
//         if(rank1[a]<rank1[b]){
//             swap(a,b);
//         }
//         parent[b]=a;
//         if(rank1[a]==rank1[b]){
//             rank1[a]++;
//         }
//     }
// }

// vector<vector<ll>>edgelist;
// void kruskal(){
//     ll ans=0;
 
//     sort(edgelist.begin(),edgelist.end());
//     for(auto i:edgelist){
//         ll w=i[0];
//         ll u=i[1];
//         ll v=i[2];
//         if(get(u)!=get(v)){
//             ans+=w;
//             union_sets(u,v);
//             cout<<u<<" "<<v<<endl;
//         }
//     }
//     cout<<ans<<endl;
// }
// int main(){
//     for(ll i=0;i<1001;i++){
//         parent[i]=i;
//     }
//     ll v,edge;
//     cin>>v>>edge;
//     for(ll i=0;i<edge;i++){
//         ll u1,v1,w1;
//         cin>>u1>>v1>>w1;
//         edgelist.push_back({w1,u1,v1});
//     }
//     kruskal();

// }

#include<bits/stdc++.h>
using namespace std;

void selection_sort(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    for(int i=0;i<n-1;i++){
        int mini=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[mini]){
                mini=j;
            }
        }
        swap(a[i],a[mini]);
        
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
vector<int>parent(1001);
vector<int>rank1(1001,0);

int get(int node){
    if(parent[node]==node){
        return node;
    }
    return parent[node]=get(parent[node]);
}

void union_sets(int a, int b){
    a=get(a);
    b=get(b);
    if(a!=b){
        if(rank1[a]<rank1[b]){
            swap(a,b);
        }   
        parent[b]=a;
        if(rank1[a]==rank1[b]){
            rank1[a]++;
        }
    }
}
vector<vector<int>>edgelist;
void kruskals(){
    
    int vert,edge;
    cin>>vert>>edge;
    for(int i=1;i<=vert;i++){
        parent[i]=i;
    }
    for(int i=0;i<edge;i++){
        int u1,v1,w1;
        cin>>u1>>v1>>w1;
        edgelist.push_back({w1,u1,v1});
    }
    sort(edgelist.begin(),edgelist.end());
    int ans=0;
    for(auto i:edgelist){
        int w=i[0];
        int u=i[1];
        int v=i[2];

        if(get(u)!=get(v)){
            union_sets(u,v);
            cout<<u<<" "<<v<<endl;
            ans+=w;
        }
    }
    cout<<ans<<endl;
}
int main(){
    // selection_sort();
    kruskals();
}