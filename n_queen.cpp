#include <bits/stdc++.h>
using namespace std;
void solve(int row, int n, vector<string> &board, vector<vector<string>>&ans,vector<int> &leftDiagonal, vector<int> &upperCol, vector<int>&rightDiagonal);
int main() {
 int n;
 cout << "Enter the number of queens: "; cin >> n;
 vector<string> board(n, string(n, '*'));
 vector<vector<string>> ans;
 vector<int> leftDiagonal(2 * n - 1, 0), upperCol(n, 0),rightDiagonal(2 * n - 1, 0);
 solve(0, n, board, ans, leftDiagonal, upperCol, rightDiagonal);
 for(auto Board: ans) {
 for(int i = 0; i < n; ++i) {
 for(int j = 0; j < n; ++j)
 cout << Board[i][j] << " ";
 cout << endl;
 }
 cout << endl;
 }
 return 0;
}

void solve(int row, int n, vector<string> &board, vector<vector<string> >&ans,vector<int> &leftDiagonal, vector<int> &upperCol, vector<int>&rightDiagonal) {
 if(row == n) {
 ans.push_back(board);
 return;
 }

 for(int col = 0; col < n; ++col) {
 if(!leftDiagonal[n - 1 + col - row] && !upperCol[col] &&!rightDiagonal[row + col]) {
 board[row][col] = 'Q';
 leftDiagonal[n - 1 + col - row] = 1;
 upperCol[col] = 1;
 rightDiagonal[row + col] = 1;
 solve(row + 1, n, board, ans, leftDiagonal, upperCol,rightDiagonal);
 board[row][col] = '*';
 leftDiagonal[n - 1 + col - row] = 0;
 upperCol[col] = 0;
 rightDiagonal[row + col] = 0;
 }
 }
}