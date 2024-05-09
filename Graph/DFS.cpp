#include<iostream>
#include<stack>
using namespace std;
int num_vertices = 5;
int adj_matrix[5][5];
void addedge(int i,int j){
    adj_matrix[i][j] = 1;
    adj_matrix[j][i] = 1;
}
void dfs(int start){
    bool visited[num_vertices] = {false};
    stack<int> dfs_stack;
    visited[start] = true;
    dfs_stack.push(start);
    while(!dfs_stack.empty()){
        int current_vertex = dfs_stack.top();
        cout<<current_vertex<<" ";
        dfs_stack.pop();
        for (int i = 0; i < num_vertices; i++){
            if (adj_matrix[current_vertex][i]==1 && visited[i]==false){
                visited[i] = true;
                dfs_stack.push(i);
            }
        }
    }
}
int main(){
    addedge(0,1);
    addedge(1,3);
    addedge(0,2);
    addedge(2,1);
    addedge(3,4);
    addedge(2,4);
    dfs(0);
}