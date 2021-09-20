#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int counter = 0;
int N;

class Queen{
    public:
        int x;
        int y;

        Queen(int, int);
        void setp(int, int);
        bool ok(Queen);

};


Queen:: Queen(int _x, int _y):
 x(_x), y(_y){}



void Queen:: setp(int _x, int _y){
    x = _x;
    y = _y; 
   
}



bool Queen:: ok(Queen q2){
    if( (y ==q2.y) ){
        return false;
    }
    if( (x+y == q2.x+q2.y) || (x-y == q2.x - q2.y) ){
        return false;
    }

    return true;
}

void backtracking(vector<Queen>& q, int depth){
    bool skip = true;

    if(depth == N-1){
        for(int i = 0 ; i < N ; i++){
            q[depth].setp(depth, i);
            skip = true;
            for(int j = 0 ; j <depth ; j++){
                if(!q[depth].ok(q[j])){
                    skip = false;
                    break;
                }
            }
            if(skip){
                counter++;
            }
        }
    }
    else if(depth < N-1){
        for(int i = 0 ; i < N ; i++){  
            skip = true; 
            q[depth].setp(depth, i);
            for(int j = 0 ; j <depth ; j++){
                if(!q[depth].ok(q[j])){
                    skip = false;
                    break;
                }
            }
            if(skip){
                backtracking(q, depth+1);
            }
        }
    }
    

    
}



int main() {
    cin >> N;

    vector<Queen> q(N,Queen(0,0));

    
    
    backtracking(q, 0 );
    
    cout << counter;



}