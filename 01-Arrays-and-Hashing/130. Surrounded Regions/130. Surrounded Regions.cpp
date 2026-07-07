1class Solution {
2    private :
3    void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<char>>&board){
4        int n=board.size();
5        int m=board[0].size();
6        vis[r][c]=1;
7        int dr[]={-1,0,1,0};
8        int dc[]={0,1,0,-1};
9        for(int i=0;i<4;i++){
10            int nr=r+dr[i];
11            int nc=c+dc[i];
12            if(nr>=0 && nr<n && nc>=0 && nc<m &&  vis[nr][nc]==0 && board[nr][nc]=='O' ){
13                dfs(nr,nc,vis,board);
14            }
15        }
16      
17
18    }
19public:
20    void solve(vector<vector<char>>& board) {
21        int n=board.size();
22        int m=board[0].size();
23        vector<vector<int>>vis(n,vector<int>(m,0));
24        for(int j=0;j<m;j++){
25            if(board[0][j]=='O' && !vis[0][j]){
26               dfs(0,j,vis,board);
27            }
28            if(board[n-1][j]=='O' && !vis[n-1][j]){
29              dfs(n-1,j,vis,board);
30            }
31        }
32        for(int i=0;i<n;i++){
33            if(board[i][0]=='O' && !vis[i][0]){
34                dfs(i,0,vis,board);
35            }
36            if(board[i][m-1]=='O' && !vis[i][m-1]){
37               dfs(i,m-1,vis,board);
38            }
39        }
40          for(int i=0;i<n;i++){
41            for(int j=0;j<m;j++){
42                if(board[i][j]=='O' && !vis[i][j]){
43                    board[i][j]='X';
44                }
45            }
46        }
47    }
48};