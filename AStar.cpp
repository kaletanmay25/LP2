//a star algorithm
#include<bits/stdc++.h>

using namespace std;
//the dimensions of the matrix will be 3x3
map<vector<vector<int>>, bool> visit;
vector<vector<int>> initialstate(4); //it will store the initial state of the matrix

vector<vector<int>> goalstate(4); //it will store the goal state of the matrix

//this function will check if the current state and the goal state is equal or not
bool isEqualToGoalState(vector<vector<int>> mat)
{
    for (int i = 0; i < 3;i++)
    {
        for (int j = 0; j < 3;j++)
        {
            if(mat[i][j]==goalstate[i][j])
            {
                continue;
            }
            return false;
        }
    }

    return true;
}

vector<vector<vector<int>>> NeighbouringChilds(vector<vector<int>> mat)
{
    int indi;
    int indj;

    for (int i = 0; i < 3;i++)
    {
        for (int j = 0; j < 3;j++)
        {
            if(mat[i][j]==0)
            {
                indi = i;
                indj = j;
            }
        }
    }

    vector<vector<vector<int>>> ans;

    if((indi-1)>=0)
    {
        swap(mat[indi][indj], mat[indi - 1][indj]);
        ans.push_back(mat);
        swap(mat[indi][indj], mat[indi - 1][indj]);
    }

    if ((indi + 1) < 3)
    {
        swap(mat[indi][indj], mat[indi + 1][indj]);
        ans.push_back(mat);
        swap(mat[indi][indj], mat[indi + 1][indj]);
    }

    if((indj-1)>=0)
    {
        swap(mat[indi][indj - 1], mat[indi][indj]);
        ans.push_back(mat);
        swap(mat[indi][indj - 1], mat[indi][indj]);
    }

    if((indj+1)<3)
    {
        swap(mat[indi][indj], mat[indi][indj + 1]);
        ans.push_back(mat);
        swap(mat[indi][indj], mat[indi][indj + 1]);
    }

    return ans;
}

int MissMatch(vector<vector<int>> mat)
{
    int ans = 0;

    for (int i = 0; i < 3;i++)
    {
        for (int j = 0; j < 3;j++)
        {
            if(mat[i][j]==0)
            {
                continue;
            }

            if(mat[i][j]!=goalstate[i][j])
            {
                ans++;
            }
        }
    }

    return ans;
}

int main()
{
    initialstate.resize(3);
    for (int i = 0; i < 3;i++)
    {
        initialstate[i].clear();
    }

    // taking the input for the initial state of the matrix
    cout << "Enter the initial state: " << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int ele;
            cin >> ele;

            initialstate[i].push_back(ele);
        }
    }
    cout << endl;

    //initializing the goal state manually
    goalstate.resize(3);
    for (int i = 0; i < 3;i++)
    {
        goalstate[i].clear();
    }

    // goalstate[0].push_back(0);
    // goalstate[0].push_back(1);
    // goalstate[0].push_back(2);
    // goalstate[1].push_back(3);
    // goalstate[1].push_back(4);
    // goalstate[1].push_back(5);
    // goalstate[2].push_back(6);
    // goalstate[2].push_back(7);
    // goalstate[2].push_back(8);

    cout << "Enter the goal state: " << endl;
    for (int i = 0; i < 3;i++)
    {
        for (int j = 0; j < 3;j++)
        {
            int ele;
            cin >> ele;

            goalstate[i].push_back(ele);
        }
    }
    cout << endl;

    visit[initialstate] = true;

    
    priority_queue<pair<int,pair<int, vector<vector<int>>>>, vector<pair<int,pair<int, vector<vector<int>>>>>, greater<pair<int,pair<int, vector<vector<int>>>>>> pq; //we are storing different state with respect to the mismatch of the positions in the matrix
    //f(x),level,state

    pq.push({0, {0, initialstate}});

    cout << "Calculating..." << endl;

    long long int cnt = 0;

    while (pq.size())
    {
        cnt++;
        pair<int, pair<int, vector<vector<int>>>> p = pq.top();
        pq.pop();

        for (int i = 0; i < 3;i++)
        {
            for (int j = 0; j < 3;j++)
            {
                cout << p.second.second[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        if (isEqualToGoalState(p.second.second))
        {
            cout << "We Got the Goal State" << endl;
            break;
        }

        vector<vector<vector<int>>> allchilds = NeighbouringChilds(p.second.second);

        for (int i = 0; i < allchilds.size();i++)
        {
            if(!visit[allchilds[i]])
            {
                visit[allchilds[i]] = true;
                int mismatch = MissMatch(allchilds[i]);

                pq.push({p.second.first + 1 + mismatch,{p.second.first+1, allchilds[i]}});
            }
        }

    }

    cout << "NO OF STATES: " << cnt << endl;

    cout << "OVER" << endl;
}