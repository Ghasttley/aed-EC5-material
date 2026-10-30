#include <bits/stdc++.h>

// implementación del curso de programación III teoría 2026-1
// taken from el ppt de semana 14 teoría 

template<typename T>
struct Graph{
    std::unordered_map<T, std::unordered_set<T>> unordered;
    std::unordered_map<T, std::set<T>> ordered; 
    // unordered_set for storing every visited node
    // unordered_map for storing the conections between nodes

    void unordered_new_edge(T a, T b){
        unordered[a].insert(b); unordered[b].insert(a);
        // works for undirected graph
    }

    void ordered_new_edge(T a, T b){
        ordered[a].insert(b); ordered[b].insert(a);
        // works for undirected graph
    }

    void unordered_BFS(T s){ // s: origin
        std::queue<T> q;
        q.push(s);

        std::unordered_set<T> visited_nodes;

        while(not q.empty()){
            T current_node = q.front(); q.pop();
            if(visited_nodes.find(current_node) == visited_nodes.end()){
                visited_nodes.insert(current_node);
                std::cout << current_node << ' ';
                    for(const T& i: unordered[current_node]){
                        if(visited_nodes.find(i) == visited_nodes.end()) q.push(i);
                    }
            }
        }
    }

    void ordered_BFS(T s){ // s: origin
        std::queue<T> q;
        q.push(s);

        std::unordered_set<T> visited_nodes;

        while(not q.empty()){
            T current_node = q.front(); q.pop();
            if(visited_nodes.find(current_node) == visited_nodes.end()){
                visited_nodes.insert(current_node);
                std::cout << current_node << ' ';
                    for(const T& i: ordered[current_node]){
                        if(visited_nodes.find(i) == visited_nodes.end()) q.push(i);
                    }
            }
        }
    }
};

// unordered_map doesnt alphabet sort it 
// and when i do the diagram i output the ordered solution

int main(){
    Graph<char> g;

    // unordered
    g.unordered_new_edge('A', 'B');
        g.unordered_new_edge('A', 'C');
            
    g.unordered_new_edge('B', 'C');
        g.unordered_new_edge('B', 'D');
    
    g.unordered_new_edge('C', 'E');

    g.unordered_BFS('A'); // Output: ACBED

    std::cout << std::endl;
    //ordered
    g.ordered_new_edge('A', 'B');
        g.ordered_new_edge('A', 'C');
            
    g.ordered_new_edge('B', 'C');
        g.ordered_new_edge('B', 'D');
    
    g.ordered_new_edge('C', 'E');

    g.ordered_BFS('A'); // Output: ABCDE

    return 0;
}