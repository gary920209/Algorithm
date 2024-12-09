#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
//void buildedge;
struct input{
    int i;
    int j;
    int w;
};
bool op(input a, input b) { return a.w > b.w; }  // 排列
/*
class disjointset{
    public:
        disjointset(int n): num(n);
        int num;
        int rank;
        int parent; 
        void makeset(){
            for(int i=0 ; i<num ; i++ ){
                par[i] = i 
            }
        }
        int find(int &i) const{
            if (sub[i].parent == i)
                return i;
            return find(sub[i].parent);
        }
        int Union(int &i,int &j){
            if (sub[find(i)].rank < sub[find(j)].rank)
                sub[find(i)].parent = find(j);
            else  if (_subs[find(i)].rank > sub[find(j)].rank)
                sub[find(j)].parent = find(i);
            else{
                sub[find(j)].parent = find(i);
                sub[find(i)].rank++;
            }
        }
}
*/

int Find (int a,int* par) {
    if (par[a] == a)
        return a;
    else{
        return  Find (par[a],par);
    }
}

void Union(int a, int b, int* rank,int* par) {
    int ra = Find(a,par);
    int rb = Find(b,par);
    if (ra != rb) {
        if (rank[ra] > rank[rb]) {
            par[rb] = ra;
        }
        else if (rank[ra] < rank[rb]) {
            par[ra] = rb;
        } else {
            par[rb] = ra;
            rank[rb]++;
        }
    }
}
bool DFSvisit(int v,vector<vector<int>>& adj,vector<char>& color)
{
    bool result = true;
    color[v] = 'g'; 
    for (auto x:adj[v]){
        if ( color[x] =='w'){
            result = DFSvisit(x,adj,color);
            if(result==false)
                break;
        }
        else if(color[x] =='g'){
            result=false;
            break;
        }
    }
    color[v] = 'b'; 
    return result;
}
bool DFS(vector<vector<int>>& adj){
            bool result = true; 
            vector<char> color;
            color.assign(adj.size(),'w');
            for (int x = 0; x < adj.size();x++){
                if ( color[x] =='w'){
                    result = DFSvisit(x,adj,color);
                    if(result==false)
                        break;
                        
                }
            }
            return result;
}

//bool cycle(int v,vector<vector<int>>& adj,vector<char>& color)

    
//    color[v] = 'g'; 
  //  for (auto x:adj[v]){
    //    if ( color[x] =='w')
      //      DFS(adj[v][x],adj,color);
   // }
    //color[v] = 'b'; 

int main(int argc, const char *argv[]){
    ifstream fin;
    ofstream fout;
    fin.open(argv[1]);
    fout.open(argv[2], ios::out);
    char type;
    int v , e;
    fin >> type;
    fin >> v;
    fin >> e;
//    cout<<type<<' '<<v<<' '<<e<<'\n';
    int par[v];
    int rank[v];
//makeset(v)
    for(int i=0 ; i<v ; i++ ){
        par[i] = i;
        rank[i] = 0;
    }
    vector<input> data;
    data.reserve(v);
    vector<input> answer;
    answer.reserve(v);

    for (int k = 0; k < e; k++){
        // cout<<k<<'\n';
        int w, i, j;
        fin >> i >> j >> w;
        data.push_back({i,j,w});
    }
   // for (int k = 0; k < e; k++){
        // cout<<data[k].i<<' '<<data[k].j<<' '<<data[k].w;
    //}
    //sort e
    sort(data.begin(), data.end(), op);
/*    for (int k = 0; k < e; k++){
        cout<<data[k].i<<' '<<data[k].j<<' '<<data[k].w<<'\n';
    }
*/

if(type != 'd'){
    int sum = 0;
    for(auto x:data){
        // fout << x.w << endl;
        if (Find(x.i,par)!=Find(x.j,par)){
            //A=A聯集ij
            Union(x.i,x.j,rank,par);
        }
        else{
            answer.push_back({x.i,x.j,x.w});
            sum += x.w;
        }
    }
        fout << sum << endl;
    for (int k = 0; k < answer.size(); k++){
        fout<<answer[k].i<<' '<<answer[k].j<<' '<<answer[k].w<<'\n';
    }
}
else{
    vector<vector<int>> adj;
    vector<int> a;
    adj.assign(v,a);
//  int adj[e];
    int sum = 0;
    for(auto x:data){
            adj[x.i].push_back(x.j);

            if(DFS(adj)!=1){
                adj[x.i].pop_back();
                answer.push_back({x.i,x.j,x.w});
                sum += x.w;
            }
            
         //   
          //  
        }
    
        fout << sum << endl;
    for (int k = 0; k < answer.size(); k++){
        fout<<answer[k].i<<' '<<answer[k].j<<' '<<answer[k].w<<'\n';
    }
}
    //output
    fin.close();
    fout.close();
   	return 0;
}