1class Solution {
2public:
3    int numEnclaves(vector<vector<int>>& grid) {
4        queue<pair<int,int>>q;
5        int n=grid.size();
6        int m=grid[0].size();
7        vector<vector<int>> vis(n, vector<int>(m, 0));
8       for(int i=0;i<n;i++){
9        for(int j=0;j<m;j++){
10             if(i==0 || j==0 || i==n-1 || j==m-1){
11                if(grid[i][j]==1){
12                    q.push({i,j});
13                    vis[i][j]=1;
14                }
15             }
16        }
17       }
18       int dr[]={-1,0,1,0};
19        int dc[]={0,1,0,-1};
20       while(!q.empty()){
21        int r=q.front().first;
22        int c=q.front().second;
23        q.pop();
24        for(int i=0;i<4;i++){
25            int nr=r+dr[i];
26            int nc=c+dc[i];
27            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && vis[nr][nc]==0){
28                q.push({nr,nc});
29                vis[nr][nc]=1;
30
31            }
32        }
33       }
34       int cnt=0;
35       for(int i=0;i<n;i++){
36        for(int j=0;j<m;j++){
37            if(grid[i][j]==1 && !vis[i][j]){
38                 cnt++;
39            }
40        }
41       }
42       return cnt;
43    }
44};