// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long

// int is_valid(ll curr,ll col,vector<vector<ll>>&board,ll n){
//     for(ll i=0;i<col;i++){
//         if(board[curr][i]){
//             return 0;
//         }
//     }
//     for(ll i=curr, j=col;i>=0 && j>=0;i--,j--){
//         if(board[i][j]){
//             return 0;
//         }
//     }
//     for(ll i=curr,j=col;i<n && j>=0;i++,j--){
//         if(board[i][j]){
//             return 0;
//         }
//     }
//     return 1;
// }
// int solve(vector<vector<ll>>&board,ll n,ll col){
//     if(col>=n){
//         return 1;
//     }
//     for(ll i=0;i<n;i++){
//         if(is_valid(i,col,board,n)){
//             board[i][col]=1;
//             if(solve(board,n,col+1)){
//                 return 1;
//             }
//             board[i][col]=0;
//         }
//     }
//     return 0;
// }

// int main(){
//     ll n;
//     cin>>n;
//     vector<vector<ll>>board;
//     for(ll i=0;i<n;i++){
//         vector<ll>v;
//         for(ll j=0;j<n;j++){
//             v.push_back(0);
//         }
//         board.push_back(v);
//     }
//     if(solve(board,n,0)){
//         for(ll i=0;i<n;i++){
//             for(ll j=0;j<n;j++){
//                 cout<<board[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//     }
//     else{
//         cout<<"Not Possible"<<endl;
//     }
// }

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int is_valid(vector<vector<ll>>&v,ll n,ll col,ll row){
    for(ll i=0;i<col;i++){
        if(v[row][i]){
            return 0;
        }
    }
    for(ll i=row,j=col;i>=0 && j>=0;i--,j--){
        if(v[i][j]){
            return 0;
        }
    }
    for(ll i=row,j=col;j>=0 && i<n;i++,j--){
        if(v[i][j]){
            return 0;
        }
    }
    return 1;
}

int solve(vector<vector<ll>>&v,ll n,ll col){
    if(col>=n){
        return 1;
    }
    for(ll i=0;i<n;i++){
        if(is_valid(v,n,col,i)){
            v[i][col]=1;
            if(solve(v,n,col+1)){
                return 1;
            }
            v[i][col]=0;
        }
    }
    return 0;
}

int main(){
    ll n;
    cin>>n;
    vector<vector<ll>>v;
    for(ll i=0;i<n;i++){
        vector<ll>vec;
        for (ll j=0;j<n;j++){
            vec.push_back(0);
        }
        v.push_back(vec);
    }

    if(solve(v,n,0)){
        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"NOT POSSIBLE"<<endl;
    }
}