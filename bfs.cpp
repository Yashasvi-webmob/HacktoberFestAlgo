#include<iostream>
#include<list>

using namespace std;


class Graph 
{ 
    int Vertices;   
  
     
    list<int> *adj;    
public: 
    Graph(int Vertices);   
  
    
    void addEdge(int v, int u);  
  
    
    void BFS(int s);   
}; 
  
Graph::Graph(int Vertices) 
{ 
    this->Vertices = Vertices; 
    adj = new list<int>[Vertices]; 
} 
  
void Graph::addEdge(int v, int u) 
{ 
    adj[v].push_back(u); 
} 
  
void Graph::BFS(int s) 
{ 
    
    bool *visited = new bool[Vertices]; 
    for(int i = 0; i < Vertices; i++) 
        visited[i] = false; 
  
    
    list<int> queue; 
  
   
    visited[s] = true; 
    queue.push_back(s); 
  
    
    list<int>::iterator i; 
  
    while(!queue.empty()) 
    { 
        
        s = queue.front(); 
        cout << s << " "; 
        queue.pop_front(); 
  
      
        for (i = adj[s].begin(); i != adj[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    } 
} 
  

int main() 
{ 
    int i,edge,v,b,c,d;
	cout<<"enter the no. of nodes";
    cin>> v;
    Graph a(v);
	cout<<"enter the no. of edges";
	cin>>edge;
	for(i=0;i<edge;i++)
	{
		cout<<"enter the edges";
		cin >> b >> c;
		a.addEdge(b, c);
		cout<<"\n";
	 } 
    
  	cout<<"enter the starting node\n";
  	cin>>d;
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex "<<d<<") \n"; 
    a.BFS(d); 
  
    return 0; 
} 
