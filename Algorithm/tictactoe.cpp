#include<bits/stdc++.h>

#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

using namespace std;

const int INF = (int) 1e9;
const int MODULO = (int) 1e10 + 7;
const int maxn = (int) 1e5;
bool check(int m[3][3], int i);

	bool validTicTacToe(vector<string>& board) {
    	int xs = 0;
        int os = 0;
        int m[3][3];
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == 'X'){
                    m[i][j] = 1;
                    xs++;
                }else if(board[i][j] == 'O'){
                    m[i][j] = 2;
                    os++;
                }else{
                    m[i][j] = 0;
                }
            }
        }
        
        cout << xs << " " << os <<endl;
        if(xs - os != 0 && xs - os != 1){
            return false;
        }
        
        bool win1 = check(m,1);
        bool win2 = check(m,2);

        //cout << win1 << " " << win2 << endl;
        
        if(!win1 && !win2) return true;
        if(win1 && !win2){
            return os < xs;           
        }

        if(win2 && !win1){
            return xs <= os;
        }
        
        return false;
    }
    
    bool check(int m[3][3], int whichone){
        int target = whichone == 1? 1 : 2;
        int num = 0;
        
        int ch = 0;
        int cv = 0;
        int ch1 = 0;
        int cv1 = 0;
        for(int i = 0; i < 3; i++){
            ch += m[0][i] == target;
            cv += m[i][0] == target;
            ch1 += m[2][i] == target;
            cv1 += m[i][2] == target;            
        }
        
        num += ch == 3;
        num += cv == 3;
        num += ch1 == 3;
        num += cv1 == 3;
    
        cout << num << endl;
        if(num > 1) return false;
        
        if(m[1][1] == target){
            num += m[0][0] == target && m[2][2] == target;
            num += m[2][0] == target && m[0][2] == target;            
        }
        
        return num == 1;
    }

int main(){

    vector<string> input({"XXX", "XOO", "OO "});

    cout << validTicTacToe(input) << endl;

    return 0;
}