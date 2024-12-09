#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
vector<int> data;
vector< vector<int> > mis;
vector<bool> checkcase;
void track(int i, int j){
    int k = data[j];
    if (i < j){
        if ((k >= j && k < i) || (mis[i][j] == mis[i][j - 1])){
            track(i, j - 1);
        }
        else if (k >= i && k < j){
            checkcase[k] = 1;
            track(i, k - 1);     
            track(k + 1, j - 1);
        }
        else if (k == i){
            checkcase[k] = 1;
            track(i + 1, j - 1);
        }
    }
}
int main(int argc, const char *argv[]){
    fstream fin(argv[1]);
    fstream fout;

    fout.open(argv[2], ios::out);
    int num;
    fin >> num;
    int chords, k;
    int N = num/2;
    data.assign(num,0);
   
    checkcase.assign(num, 0);
    mis.assign(num, data);
    while (fin >> chords >> k){
        data[chords] = k;
        data[k] = chords;
    }


    for(int  j = 0 ; j < 2*N ; j++){
        int k = data[j];
        for(int i = 0 ; i < j; i++){
            if( i < k && k < j && mis[i][k-1] + 1 + mis[k+1][j-1] > mis[i][j-1]){
                mis[i][j] = mis[i][k-1] + 1 + mis[k+1][j-1];
            }
            else if( k == i ){
                mis[i][j] =  mis[i+1][j-1] + 1;
            }
            else{
                mis[i][j] = mis[i][j-1];
            }
        }
    }
/*
    for(int d = 1; d < 2*N ; d++){
        for(int i = 0; i < 2*N-d; i++){
            int j = i + d;
            int k = data[i];
            if ( k < i || k > j)
                mis[i][j] = mis[i][j-1];
            else if( i < k || k < j){
                if(mis[i][k-1]+1+mis[k+1][j-1]>mis[i][j-1])
                    mis[i][j] =mis[i][k-1]+1+mis[k+1][j-1];
                else
                    mis[i][j] = mis[i][j-1];
            }
            else if( k == i )
                 mis[i][j] =  mis[i+1][j-1] + 1;
        }
    }

*/
    fout << mis[0][2*N-1] << endl;
    int ans;
    track(0, 2*N-1);
    for (int i = 0; i < 2*N-1; i++){
        //cout << checkcase[i];
        if (checkcase[i] == 1){
            fout << i << " " << data[i] << endl;
        }
    }
    fin.close();
    fout.close();
   	return 0;
}