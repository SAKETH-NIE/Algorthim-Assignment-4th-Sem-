#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

bool isSafe(int row, int col, vector<int>& solution) {
    for (int prevRow = 0; prevRow < row; ++prevRow) {
        if (solution[prevRow] == col || abs(solution[prevRow] - col) == abs(prevRow - row)) {
            return false;
        }
    }
    return true;
}

void solveNQueens(int n, int row, vector<int>& solution, vector<vector<int>>& solutions) {
    if (row == n) {
        solutions.push_back(solution);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(row, col, solution)) {
            solution[row] = col;
            solveNQueens(n, row + 1, solution, solutions);
        }
    }
}

void printSolution(const vector<vector<int>>& solutions) {
    for (const vector<int>& solution : solutions) {
        for (int col : solution) {
            for (int i = 0; i < solution.size(); ++i) {
                if (i == col) {
                    cout << "Q ";
                } else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the value of N (number of queens): ";
    cin >> n;

    vector<vector<int>> solutions;
    vector<int> solution(n, -1);

    solveNQueens(n, 0, solution, solutions);

    if (solutions.empty()) {
        cout << "No solutions found." << endl;
    } else {
        cout << "Found " << solutions.size() << " solutions:" << endl;
        printSolution(solutions);
    }

    return 0;
}