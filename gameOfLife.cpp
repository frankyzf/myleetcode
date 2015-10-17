#include "common.h"
//not checked yet


// -1 : die next cycle
// 2: live next cycle

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        const size_t rowsize = board.size();
        if(rowsize == 0)
            return;
        const size_t colsize = board[0].size();
        if(colsize ==0)
            return;

        enum Direction{N=0, NE, E, SE, S, SW, W, NW};
        auto getpoint= [rowsize, colsize](pair<int, int> point, Direction direction){
            switch(direction){
                case N:
                    point.first --;
                    break;
                case NE:
                    point.first --;
                    point.second++;
                    break;
                case E:
                    point.second ++;
                    break;
                case SE:
                    point.first ++;
                    point.second ++;
                    break;
                case S:
                    point.first ++;
                    break;
                case SW:
                    point.first ++;
                    point.second --;
                    break;
                case W:
                    point.second --;
                    break;
                case NW:
                    point.first --;
                    point.second --;
                    break;
                default:
                    break;
            }

            return point;
        };


        auto cntliveneighbor=[&board, &getpoint, colsize, rowsize](const pair<int, int>& point){
            int cnt = 0;
            set<pair<int, int>> neighbors;
            neighbors.insert(point);
            for (int i = 0; i < 8; ++i) {
                auto np = getpoint(point, (Direction)i);
                if( np.first <0|| np.first >= rowsize || np.second < 0 || np.second >= colsize
                         || board[np.first][np.second] == 0 || board[np.first][np.second] == 2){
                    //skip;
                }
                else{
                    ++cnt;
                }
                neighbors.insert(np);
            }
            return cnt;
        };

        for (int i = 0; i < rowsize; ++i) {
            for (int j = 0; j < colsize; ++j) {
                int cnt = cntliveneighbor(make_pair(i, j));
                if(board[i][j] == 0 && cnt == 3){
                    board[i][j] = 2;
                }
                else if (board[i][j] == 1){
                    if(cnt < 2 || cnt > 3)
                        board[i][j] = -1;
                }
            }
        }

        for_each(board.begin(), board.end(), [](vector<int>& row){
            for_each(row.begin(), row.end(), [](int& i){
                if(i == -1)
                    i = 0;
                else if (i == 2)
                    i = 1;
            });
        });
    }
};



int main() {
    vector<vector<int>> board{{0,1,0,0,1,1,0},{1,1,1,1,1,1,1},{1,1,0,0,0,0,1},{1,1,0,0,1,0,0}};
    Solution().gameOfLife(board);
    for (auto row : board) {
        for (auto item : row) {
            cout << item << ",";
        }
        cout << endl;
    }
    return 1;
}