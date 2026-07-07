1class Solution {
2public:
3    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
4        int n=mat.size();
5        int m=mat[0].size();
6        vector<vector<int>>dist(n,vector<int>(m,0));
7        vector<vector<int>>vis(n,vector<int>(m,0));
8        queue<pair<pair<int,int>,int>>q;
9        for(int i=0;i<n;i++){
10            for(int j=0;j<m;j++){
11                if(mat[i][j]==0){
12                    q.push({{i,j},0});
13                    vis[i][j]=1;
14                }
15                else{
16                    vis[i][j]=0;
17                }
18            }
19        }
20        while(!q.empty()){
21            int r=q.front().first.first;
22            int c=q.front().first.second;
23            int steps=q.front().second;
24            q.pop();
25            dist[r][c]=steps;
26            int dr[]={-1,0,1,0};
27            int dc[]={0,1,0,-1};
28            for(int i=0;i<4;i++){
29                int nr=r+dr[i];
30                int nc=c+dc[i];
31                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0){
32                    vis[nr][nc]=1;
33                    q.push({{nr,nc},steps+1});
34                }
35            }
36        }
37        return dist;
38    
39    }
40};