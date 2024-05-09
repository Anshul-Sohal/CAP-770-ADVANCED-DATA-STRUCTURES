#include<iostream>
#include<queue>
using namespace std;
int num_vertices = 5;
int adj_matrix[5][5];
void addedge(int i,int j){
    adj_matrix[i][j] = 1;
    adj_matrix[j][i] = 1;
}
void bfs(int start){
    bool visited[num_vertices] = {false};
    queue<int> bfs_queue;
    visited[start] = true;
    bfs_queue.push(start);
    while (!bfs_queue.empty()){
        int current_vertex = bfs_queue.front();
        cout<<current_vertex<<" ";
        bfs_queue.pop();
        for (int i = 0; i < num_vertices; i++){
            if (adj_matrix[current_vertex][i]==1 && visited[i]==false){
                visited[i] = true;
                bfs_queue.push(i);
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
    bfs(0);
}