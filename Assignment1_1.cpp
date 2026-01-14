#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

typedef struct Node
{
    int vertex;
    Node *next;
} Node;

Node *createNode(int value)
{
    Node *t = new Node();
    t->vertex = value;
    t->next = NULL;
    return t;
}

class Graph
{
private:
    int V;           // So luong dinh ke
    Node **adjLists; // Danh sach cac Node Vertex (like Matrix but element is a pointer that save Adj of this node)
    bool *visited;

    // DFS
    void DFS(int src)
    {
        visited[src] = true;
        cout << src << " -> ";
        Node *tmp = adjLists[src];
        while (tmp != NULL)
        {
            if (visited[tmp->vertex] != true)
            {
                DFS(tmp->vertex);
            }
            tmp = tmp->next;
        }
    }

    // BFS
    void BFS(int src)
    {
        resetVisted();

        queue<int> Q;
        Q.push(src);
        while (!Q.empty())
        {
            int index = Q.front();

            Q.pop();
            if (visited[index] != true)
            {

                cout << index << " -> ";
            }
            visited[index] = true;
            Node *t = adjLists[index];
            while (t != NULL)
            {
                if (visited[t->vertex] != true)
                {
                    Q.push(t->vertex);
                }
                t = t->next;
            }
        }
    }

public:
    // Construct
    Graph(int V)
    {
        this->V = V;
        adjLists = new Node *[V];
        visited = new bool[V];

        for (int i = 0; i < V; i++)
        {
            adjLists[i] = NULL;
            visited[i] = false;
        }
    }

    // Add edge from Src -> dest
    void addEdge(int src, int dest)
    {
        Node *newNode = createNode(dest);
        newNode->next = adjLists[src];
        adjLists[src] = newNode;
    }

    // RUN DFS
    void runDFS(int src)
    {
        resetVisted();
        cout << "DFS from Vertex " << src << ": ";
        DFS(src);
        cout << "NULL" << endl;
    }

    // RUN BFS
    void runBFS(int src)
    {
        resetVisted();
        cout << "BFS from Vertex " << src << ": ";
        BFS(src);
        cout << "NULL" << endl;
    }

    // Reset Visted
    void resetVisted()
    {
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }
    }

    // Destruct
    ~Graph()
    {
        for (int i = 0; i < V; i++)
        {
            Node *temp = adjLists[i];
            while (temp != NULL)
            {
                Node *next = temp->next;
                delete temp;
                temp = next;
            }
        }
        delete[] adjLists;
        delete[] visited;
    }
};

int main()
{

    int V = 10;
    Graph g(V);

    g.addEdge(1, 6);
    g.addEdge(6, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(3, 7);
    g.addEdge(3, 5);
    g.addEdge(4, 2);

    g.runDFS(1);
    g.runBFS(1);
    return 0;
}