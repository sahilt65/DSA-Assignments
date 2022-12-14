/*
Represent a graph of your college campus using adjacency list /adjacency matrix. Nodes should
represent the various departments/institutes and links should represent the distance between them.
Find minimum spanning tree
a) Using Kruskal’s algorithm.
b) Using Prim’s algorithm.
*/

/*
Here I have used Adjacency Matrix for Prims Algorithm and
Adjacency List for Kruskals Algorithm
*/

#include <bits/stdc++.h>
#include<vector>
using namespace std;
#define v 5
class Graph{
    public:

  //Taking Input fo rAdjacency Matrix
    int graph[v][v];
    int selected[v] = {0, 0, 0, 0, 0};
    void getAndCreateGraph(){
        cout<<"Enter edges and weights of the graph"<<endl;

        for(int i = 0; i<v; i++){
            for(int j = 0; j<v; j++){
                cin>>graph[i][j];
            }
        }

        //Print Adjacency Matrixw
        cout<<"Printing Adjacency Matrix"<<endl;
        for(int i = 0; i<v; i++){
            for(int j = 0; j<v; j++){
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
    }
  
  //Part 1 : Prims Algorithm
    void findMstByPrims(){
        cout<<"Printing edges and Minimum Weights of the tree"<<endl;
        int noOfEdges = 0;
        selected[0] = 1;

        while(noOfEdges<v-1){
            int min = INT_MAX;
            int x = 0;
            int y = 0;
            for(int i = 0; i<v; i++){
                if(selected[i]){
                    for(int j = 0; j<v; j++){
                        if(!selected[j] && graph[i][j]){
                            if(min > graph[i][j]){
                                min= graph[i][j];
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
            }

            selected[y] = 1;
            cout<<x<<" -> "<<y<<" : "<<graph[x][y]<<endl;
            noOfEdges++;
        }
    }



  
  //Part 2 : Kruskals Algorithm
    vector<vector<int> > krus;
    void getKruskalGraph(){
      //Taking input for Adjancency List (weight, edge1, edge2)
        cout<<"Enter edges"<<endl;
        for(int i = 0; i<7; i++){
            int w, u, e;
            cin>>w>>u>>e;
            krus.push_back({w, u, e});
        }

        sort(krus.begin(), krus.end());
        cout<<"Printing Sorted Edges"<<endl;
        for(int i = 0; i<krus.size(); i++){
            cout<<krus[i][1]<<" -> "<<krus[i][2]<<" : "<<krus[i][0]<<endl;  
        }

        vector<int> vec(v);
        for(int i = 0; i<v; i++){
            vec[i] = false;
        }

        int noOfEdhges = 0;
        cout<<"Printing Edges of Minimun Spanning tree"<<endl;
        while(noOfEdhges <= v-1){
            for(int i = 0 ; i<7; i++){
                int u = krus[i][1];
                int e = krus[i][2];
                int w = krus[i][0];

                if(vec[u] == false  || vec[e] == false){
                    cout<<u<<" "<<e<<" -> "<<w<<endl;
                    noOfEdhges++;
                }
                vec[e] = true;
                vec[u] = true;
            }
        }
    }
};



int main(){

    Graph g;
    cout<<"---------------Minimum Spannin Tree by Prims Algorithm--------------"<<endl;
    g.getAndCreateGraph();
    g.findMstByPrims();

    cout<<endl;
    cout<<"---------------Minimum Spannin Tree by Kruskal's Algorithm--------------"<<endl;
    g.getKruskalGraph();


    return 0;
}


//For Prims
// 0 1 0 3 0
// 1 0 5 4 0
// 0 5 0 6 7
// 3 4 6 0 8
// 0 0 7 8 0

//For Kruskals
// 1 0 1 
// 3 0 3 
// 4 1 3
// 5 1 2
// 6 3 2
// 8 3 4
// 7 2 4
