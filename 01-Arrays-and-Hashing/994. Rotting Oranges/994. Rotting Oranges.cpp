1class Solution {
2public:
3    int orangesRotting(vector<vector<int>>& grid) {
4        int n=grid.size();
5        int m=grid[0].size();
6        int vis[n][m];
7        queue<pair<pair<int,int>,int>>q;
8        int cf=0;
9        for(int i=0;i<n;i++){
10            for(int j=0;j<m;j++){
11                if(grid[i][j]==2){
12                q.push({{i,j},0});
13                vis[i][j]=2;
14                }
15                else{
16                    vis[i][j]=0;
17                }
18                if(grid[i][j]==1){
19                    cf++;
20                }
21            }
22        }
23        int tm=0;
24        int dr[]={-1,0,1,0};
25        int dc[]={0,1,0,-1};
26        int cnt=0;
27        while(!q.empty()){
28            int r=q.front().first.first;
29            int c=q.front().first.second;
30            int t=q.front().second;
31            q.pop();
32            tm=max(tm,t);
33
34            for(int i=0;i<4;i++){
35                int nr=r+dr[i];
36                int nc=c+dc[i];
37                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && vis[nr][nc]!=2){
38                    q.push({{nr,nc},t+1});
39                    vis[nr][nc]=2;
40                    cnt++;
41                }
42            }
43        }
44        if(cnt!=cf) return -1;
45        return tm;
46    }
47};