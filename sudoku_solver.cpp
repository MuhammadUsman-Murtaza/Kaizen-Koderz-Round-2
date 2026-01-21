// Bismillah
#include <bits/stdc++.h>
using namespace std;


#define intt int32_t
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define nl cout<<endl;
#define vi vector<int>
#define vii vector<vector<int>>
#define f(i,s,e) for(int i=s;i<e;i++)
#define sa(vec) sort(vec.begin(), vec.end())
#define sd(vec) sort(vec.begin(), vec.end(), [](int a, int b){return a>b;})
#define printv(vec) for(auto &value: vec) cout<<value<<endl;
#define inputv(vec) for(auto &value: vec)   cin>>value;
#define all(s) s.begin(), s.end()

const intt MOD = 1e9 + 7;
const intt INF = 1e9;
const int LINF = 1e18;
const double EPS = 1e-9;

#define NEDUET ios::sync_with_stdio(0);cin.tie(0);cout.tie(NULL);int t = 1;
//=========================================
void print_board(vii& board){
    f(i,0,9){
        if(i%3==0 && i!=0){
            cout << "--------------------\n";
        }

        f(j,0,9){
            if(j%3==0 && j!=0){
                cout << "| ";
            }
            if(board[i][j]==0){
                cout << ".";
            }else{
                cout << board[i][j] <<"  ";
            }

        }
        cout << endl;
    }
}

pair<int,int> find_empty(vii& board){
    f(i,0,9){
        f(j,0,9){
           if(board[i][j]==0){
            return {i,j};
           }
        }
    }
    return {-1,-1};
}
//+==================================================
bool is_board_valid(vii& board){
    int num ;
    f(i,0,9){
        f(j,0,9){
            if(board[i][j]!=0){
                num = board[i][j];

                f(col,0,9){
                    if(col!=j && board[i][col]==num){return false;}
                }

                f(row,0,9){
                    if(row!=i && board[row][j]==num){return false;}
                }

                int box_row = i/3;
                 int box_col = j/3;

                 f(r,box_row*3,box_row*3+3){
                    f(c,box_col*3,box_col*3+3){
                               if((r!=i || c!=j)&&board[r][c]==num) return false;
                    }
                 }
            }
        }
    }
    return true;
}

bool is_valid(vii& board, int num,pair<int,int> position){
    int row = position.first;
    int col = position.second;
f(j,0,9){//
    if(board[row][j]==num && (j != col)) return false;
}

f(i,0,9){//
    if(board[i][col]==num && (i != row)) return false;
}


int box_row = row/3;
int box_col = col/3;
f(i,box_row*3,box_row*3+2+1){
   f(j,box_col*3,box_col*3+2+1){
      if((board[i][j] == num) && (i!=position.first && j!=position.second)) return false;
   }
}
return true;
}
//main
bool solve_sudoku(vii& board){

if(!is_board_valid(board)){
    return false;
}

pair<int,int> cell=find_empty(board);

if(cell.first==-1 && cell.second==-1){
    return true;
}

int row = cell.first;
int col = cell.second;


f(num,1,10){
    if(is_valid(board, num, {row,col})){
    board[row][col]=num;
       if(solve_sudoku(board)){
        return true;
        }
    board[row][col] = 0;
  }
}
return false;
}

void solve(){
    vii Unsolved(9,vi(9));
// vii Unsolved =
// {
// {0, 0, 0, 0, 4, 0, 0, 2, 6},
// {3, 0, 9, 7, 2, 0, 0, 0, 0},
// {0, 5, 0, 0, 0, 0, 4, 0, 0},
// {0, 0, 7, 9, 1, 3, 0, 0, 0},
// {6, 0, 3, 0, 0, 0, 0, 0, 0},
// {0, 0, 0, 0, 0, 0, 0, 0, 2},
// {1, 0, 0, 0, 0, 0, 0, 8, 0},
// {0, 0, 0, 0, 0, 8, 0, 0, 9},
// {0, 9, 0, 0, 0, 0, 7, 0, 4}
// };


for(auto& arr : Unsolved){
    for(auto& ar : arr){
        cin >> ar ;
    }
}
cout << "Unsolved Sudoku:\n";
print_board(Unsolved);
if(solve_sudoku(Unsolved)){
    cout << "\nSolved Sudoku\n";
    print_board(Unsolved);
}else{
    cout << "\nNO Solution exists (puzzle may be invalid or unsolvable).\n";
}

}
signed main() {
NEDUET;
//  cin >> t;
while (t--) {
solve();
}
return 0;
}