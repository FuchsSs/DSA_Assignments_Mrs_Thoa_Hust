#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct Student
{
    int id;
    string name;
    float CPA;
    bool visited;
} Student;

Student *createStudent(int id, string name, float CPA)
{
    Student *t = new Student();
    t->id = id;
    t->name = name;
    t->CPA = CPA;
    t->visited = false;
    return t;
}

class StudentGraph
{
private:
    int V;
    int **adjMatrix;
    Student **masterList;

    void DFS(Student *a)
    {
        a->visited = true;
        cout << a->id << " (" << a->name << ")" << endl;
        for (int i = 1; i < V; i++)
        {
            if (adjMatrix[a->id][i] == 1 && masterList[i] != NULL)
            {
                if (masterList[i]->visited == false)
                {
                    DFS(masterList[i]);
                }
            }
        }
    }

    void resetVisited()
    {
        for (int i = 1; i < V; i++)
        {
            if (masterList[i] != NULL)
                masterList[i]->visited = false;
        }
    }

    double BFS(Student *a)
    {
        double sum = 0;
        int count = 0;
        queue<Student *> Q;

        a->visited = true;
        Q.push(a);

        while (!Q.empty())
        {
            Student *tmp = Q.front();
            Q.pop();

            sum += tmp->CPA;
            count++;

            for (int i = 1; i < V; i++)
            {
                if (adjMatrix[tmp->id][i] == 1 && masterList[i] != NULL)
                {
                    if (masterList[i]->visited == false)
                    {
                        masterList[i]->visited = true;
                        Q.push(masterList[i]);
                    }
                }
            }
        }
        return (count == 0) ? 0 : sum / count;
    }

public:
    StudentGraph(int V)
    {
        this->V = V;
        adjMatrix = new int *[V];
        masterList = new Student *[V];

        for (int i = 0; i < V; i++)
        {
            masterList[i] = NULL;
            adjMatrix[i] = new int[V];
            for (int j = 0; j < V; j++)
            {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addStudent(Student *s)
    {
        if (s->id < V)
        {
            masterList[s->id] = s;
        }
    }

    void addEdge(Student *u, Student *v)
    {
        addStudent(u);
        addStudent(v);
        adjMatrix[u->id][v->id] = 1;
    }

    void runBFS(Student *a)
    {
        resetVisited();
        cout << "--------------------------" << endl;
        cout << "CPA Average (Visited reachable): " << BFS(a) << endl;
        cout << "--------------------------" << endl;
    }

    void runDFS(Student *a)
    {
        resetVisited();
        cout << "--------------------------" << endl;
        cout << "List of Student: " << endl;
        DFS(a);
        cout << "--------------------------" << endl;
    }

    ~StudentGraph()
    {
        for (int i = 0; i < V; i++)
        {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
        delete[] masterList;
    }
};

int main()
{
    int V = 8;
    StudentGraph g(V);

    Student *s1 = createStudent(1, "Node 1", 1.5);
    Student *s2 = createStudent(2, "Node 2", 2.0);
    Student *s3 = createStudent(3, "Node 3", 3.2);
    Student *s4 = createStudent(4, "Node 4", 3.3);
    Student *s5 = createStudent(5, "Node 5", 2.5);
    Student *s6 = createStudent(6, "Node 6", 2.6);
    Student *s7 = createStudent(7, "Node 7", 3.7);

    g.addEdge(s1, s2);
    g.addEdge(s1, s3);
    g.addEdge(s1, s4);
    g.addEdge(s2, s5);
    g.addEdge(s3, s5);
    g.addEdge(s4, s5);
    g.addEdge(s4, s6);
    g.addEdge(s5, s6);
    g.addEdge(s5, s7);
    g.addEdge(s7, s2);
    g.addEdge(s7, s6);

    cout << "--- KET QUA ---" << endl;
    g.runDFS(s1);
    g.runBFS(s1);

    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
    delete s6;
    delete s7;

    return 0;
}