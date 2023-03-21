#include <bits/stdc++.h>
using namespace std;
bool issafe(vector<vector<int>> m, vector<vector<int>> visited, int x, int y, int n)
{
    /*
    Conditions for visit an index
    1. indexes should be inside the matrix m
    2. indexes should not be visited
    3. value at m[x][y] should be one
    */
    if ((x <= n - 1 && x >= 0) && (y >= 0 && y <= n - 1) && visited[x][y] == 0 && m[x][y] == 1)
        return true;
    return false;
}
void solve(vector<string> &ans, vector<vector<int>> &visited, vector<vector<int>> &m, string &temp, int &sx, int &sy, int dx, int dy, int n)
{
    if (sx == dx && sy == dy)
    {
        // rat is reached at destination so storing the Path;
        ans.push_back(temp);
        return;
    }
    // Making visited 1
    visited[sx][sy] = 1;
    // Calls --> D,R,L,U
    // Call for D --> x+1,y
    int newx = sx + 1;
    int newy = sy;
    if (issafe(m, visited, newx, newy, n))
    {
        temp.push_back('D');
        solve(ans, visited, m, temp, newx, newy, dx, dy, n);
        temp.pop_back();
    }
    // Call for R --> x,y+1
    newx = sx;
    newy = sy + 1;
    if (issafe(m, visited, newx, newy, n))
    {
        temp.push_back('R');
        solve(ans, visited, m, temp, newx, newy, dx, dy, n);
        temp.pop_back();
    }
    // Call of L --> x,y-1
    newx = sx;
    newy = sy - 1;
    if (issafe(m, visited, newx, newy, n))
    {
        temp.push_back('L');
        solve(ans, visited, m, temp, newx, newy, dx, dy, n);
        temp.pop_back();
    }
    // Call of U --> x-1,y
    newx = sx - 1;
    newy = sy;
    if (issafe(m, visited, newx, newy, n))
    {
        temp.push_back('U');
        solve(ans, visited, m, temp, newx, newy, dx, dy, n);
        temp.pop_back();
    }
    // Call is returning from here so making 0 the visited
    visited[sx][sy] = 0;
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    if (m[0][0] == 0)
        return ans;
    string temp = "";
    int sx = 0, sy = 0, dx = n - 1, dy = n - 1;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    solve(ans, visited, m, temp, sx, sy, dx, dy, n);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    // Enter only 0 and 1 only in matrix;
    vector<vector<int>> m(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> m[i][j];
    vector<string> ans = findPath(m, n);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
/*
input :
4
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1
output :
DDRDRR DRDDRR
*/
