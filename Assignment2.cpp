#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

typedef struct Student
{
    int id;
    string name;
    float CPA;
    bool visited;
} Student;

typedef struct StudentListAdj
{
    Student *data;
    StudentListAdj *next;
} StudentAdj;

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
    int V;                    // So luong sinh vien
    StudentAdj **StudentAdjL; // Mảng các danh sách liên kết (Giống AdjMatrix)
    Student **masterList;     // Mảng lưu trữ các Student gốc

    // DFS
    void DFS(Student *a)
    {
        a->visited = true;
        cout << a->id << " (" << a->name << ")" << endl;
        StudentAdj *tmp = StudentAdjL[a->id];
        while (tmp != NULL)
        {
            Student *neighbor = tmp->data;
            if (neighbor->visited != true)
            {
                DFS(neighbor);
            }
            tmp = tmp->next;
        }
    }

    // Reset trạng thái Visited trước mỗi lần chạy
    void resetVisited()
    {
        for (int i = 1; i <= 7; i++) // Bat dau tu 1 va ket thuc tai 7
        {
            if (masterList[i] != NULL)
                masterList[i]->visited = false;
        }
    }

    // BFS
    double BFS(Student *a)
    {
        double sum = 0;
        queue<Student *> Q;
        Q.push(a);
        while (!Q.empty())
        {
            Student *tmp = Q.front(); // Check truyen tham so & hay la *

            Q.pop();
            if (tmp->visited != true)
            {
                sum += tmp->CPA;
                tmp->visited = true;
            }

            StudentAdj *t = StudentAdjL[tmp->id];
            while (t != NULL)
            {
                Student *neighbor = t->data;
                if (neighbor->visited == false)
                {
                    Q.push(neighbor);
                }
                t = t->next;
            }
        }
        return sum / V;
    }

public:
    // Construct
    StudentGraph(int V)
    {
        this->V = V;
        StudentAdjL = new StudentAdj *[V];
        masterList = new Student *[V];

        for (int i = 1; i <= V; i++) // Bat dau tu 1 va ket thuc tai 7
        {
            StudentAdjL[i] = NULL;
        }
    }

    // Add student to the master list
    void addStudent(Student *s)
    {
        if (s->id < V)
        {
            masterList[s->id] = s;
        }
    }

    // Add edge from Src -> dest
    void addEdge(Student *u, Student *v)
    {
        addStudent(u);
        addStudent(v);

        // Tao 1 node Adj de lam trung gian noi vao StduentAdjL cua u (Khong noi truc tiep u->next = v boi vi co the bi ghi de du lieu phai tao 1 ma tran de luu su lien ket cua u sau do cho v vao )
        StudentAdj *newNode = new StudentAdj();
        newNode->data = v;
        newNode->next = StudentAdjL[u->id];
        StudentAdjL[u->id] = newNode;
    }

    // RUN BFS
    void runBFS(Student *a)
    {
        resetVisited();
        cout << "--------------------------" << endl;
        cout << "CPA Avarage: " << BFS(a) << endl;
        cout << "--------------------------" << endl;
    }

    // RUN DFS
    void runDFS(Student *a)
    {
        resetVisited();
        cout << "--------------------------" << endl;
        cout << "List of Student: " << endl;
        DFS(a);
        cout << "--------------------------" << endl;
    }

    // Destruct
    ~StudentGraph()
    {
        delete[] StudentAdjL;
        delete[] masterList;
    }
};

int main()
{
    // Node có ID lớn nhất là 7, nên ta tạo V = 8 để chứa được index 7
    int V = 8;
    StudentGraph g(V);

    // Tạo các Node (Student)
    Student *s1 = createStudent(1, "Node 1", 1.5);
    Student *s2 = createStudent(2, "Node 2", 2.0);
    Student *s3 = createStudent(3, "Node 3", 3.2);
    Student *s4 = createStudent(4, "Node 4", 3.3);
    Student *s5 = createStudent(5, "Node 5", 2.5);
    Student *s6 = createStudent(6, "Node 6", 2.6);
    Student *s7 = createStudent(7, "Node 7", 3.7);

    //  Thêm cạnh

    // Từ Node 1 đi ra
    g.addEdge(s1, s2);
    g.addEdge(s1, s3);
    g.addEdge(s1, s4);

    // Từ Node 2 đi ra
    g.addEdge(s2, s5);

    // Từ Node 3 đi ra
    g.addEdge(s3, s5);

    // Từ Node 4 đi ra
    g.addEdge(s4, s5);
    g.addEdge(s4, s6);

    // Từ Node 5 đi ra
    g.addEdge(s5, s6);
    g.addEdge(s5, s7);

    // Từ Node 7 đi ra
    g.addEdge(s7, s2); // Mũi tên cong quay lại 2
    g.addEdge(s7, s6);

    cout << "--- KET QUA ---" << endl;
    g.runDFS(s1);
    g.runBFS(s1);

    // Cleanup bộ nhớ
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
    delete s6;
    delete s7;

    return 0;
}