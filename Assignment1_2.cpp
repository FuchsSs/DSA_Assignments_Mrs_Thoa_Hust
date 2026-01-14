#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph
{
private:
    int V;                      // so luong dinh
    vector<vector<int>> matrix; // Ma tran luu canh ke

    void DFSUtil(int u, vector<bool> &visited)
    {
        visited[u] = true;
        cout << u << " -> ";
        for (int i = 0; i < V; i++)
        {
            if (matrix[u][i] == 1 && visited[i] != 1)
            {
                DFSUtil(i, visited);
            }
        }
    }

    // DFS Non recursion:
    void DFS_Stack(int vertex)
    {
        vector<bool> visited(V, false);
        stack<int> s;

        s.push(vertex);

        while (!s.empty())
        {
            int u = s.top();
            s.pop();
            if (!visited[u])
            {
                cout << u << " -> ";
            }
            visited[u] = true;

            for (int i = V - 1; i >= 0; i--) // Phai lay tu duoi cung len
            {
                if (matrix[u][i] == 1 && !visited[i])
                {
                    s.push(i);
                }
            }
        }
    }

public:
    Graph(int vertices)
    {
        V = vertices;

        matrix.resize(V, vector<int>(V, 0)); // V hang + moi cot se la 1 Vector co V gia tri, moi gia tri = 0
    }
    void addEdge(int u, int v)
    {
        if (u >= 0 && u < V && v >= 0 && v < V)
        {
            matrix[u][v] = 1;
        }
        else
        {
            cout << "Invalid" << endl;
        }
    }

    void printMatrix()
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void DFS(int vertex)
    {
        vector<bool> visited(V, false);
        cout << "DFS start from " << vertex << ": ";
        DFS_Stack(vertex);
        cout << "NULL" << endl;
    }

    void BFS(int vertex)
    {
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(vertex);
        visited[vertex] = true;
        cout << "BFS start from " << vertex << ": ";
        while (!q.empty())
        {
            int tmp = q.front();
            cout << tmp << " -> ";
            q.pop();
            for (int i = 0; i < V; i++)
            {
                if (matrix[tmp][i] == 1 && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    // Tạo đồ thị có
    int soDinh = 8;
    Graph g(soDinh);

    // Thêm các cạnh nối
    g.addEdge(1, 6);
    g.addEdge(6, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(3, 7);
    g.addEdge(3, 5);
    g.addEdge(4, 2);

    // Xuất ma trận
    g.DFS(1);
    g.BFS(1);

    return 0;
}