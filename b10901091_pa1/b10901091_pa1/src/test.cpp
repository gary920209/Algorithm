#include<iostream>
#include"sort_tool.h"
using namespace std;

int main(){
    vector<int> num {4,22,55,67,90,2,47,8};
    SortTool st;
    st.HeapSort(num);
    for (const int& i : num) {
    cout << i << "  ";
    }
}
