```c++
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solveNQueens(int n);
void backtrack(vector<string> &board, int row);
bool isValid(vector<string> &board, int row, int col);

vector<vector<string>> res;
int n = 0;

int main()
{

    solveNQueens(8);
    for(int i = 0 ; i < res.size() ; i++){
        //vector<string> =res[i]
        for(int  n=0 ; n < res[i].size() ; n++){
            for( int j = 0 ; j < res[i][n].size() ; j++)
            {
                cout << res[i][n][j] << " "  ;
            }
            cout << '\n';
        }
        cout << '\n' << '\n' << '\n' ;   
    }
    cout << "总共用:" << n <<"种" << endl;
    return 0;
}

void solveNQueens(int n)
{
    vector<string> board(n, string(n, '.'));

    backtrack(board,0);
}

void backtrack(vector<string> &board, int row)
{
    if (row == board.size())
    {
        res.push_back(board);
        n++;
        return;
    }
    int n = board.size(); //棋盘长度
    for (int col = 0; col < n; col++)
    {
        if (!isValid(board, row, col))
            continue;
        board[row][col] = 'Q';     //选择
        backtrack(board, row + 1); //进入下一层
        board[row][col] = '.';     //撤销-----回溯
    }
}

bool isValid(vector<string> &board, int row, int col)
{
    int n = board.size();
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 'Q')
            return false;
    }

    for (int i = row - 1,  j = col + 1; i >= 0 && j >= 0; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    for (int i = row - 1,  j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}
```

