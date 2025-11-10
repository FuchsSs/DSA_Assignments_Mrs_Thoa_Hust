#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Subject
{
    char *ID;
    char *name;
    float mid_score;
    float final_score;
    float total_score;
    struct Subject *next;
} Subject;

typedef struct Student
{
    char *ID;
    char *name;
    Subject *subject;
    float GPA;
    struct Student *next;
} Student;

// A. Quản lý môn học của 1 sinh viên
// Khởi tạo môn học
Subject *SubjectInit(char *ID, char *name)
{
    Subject *p = (Subject *)malloc(sizeof(Subject));
    p->ID = strdup(ID);
    p->name = strdup(name); // Lỗi khiến cho hàm nhận sai
    p->next = NULL;
    p->mid_score = 0.00;
    p->final_score = 0.00;
    p->total_score = 0.00;
    return p;
}
// Tìm kiếm môn học
Subject *GetSubject(Student *x, char *ID)
{
    Subject *p = x->subject;
    if (x->subject == NULL)
    {
        printf("List of Subject is empty\n");
    }
    else
    {
        while (p != NULL && strcmp(p->ID, ID))
            p = p->next;
    }
    return p;
}
// 1. Thêm môn học
void AddSubject(Student *x, char *ID, char *name)
{
    if (x->subject == NULL)
    {
        x->subject = SubjectInit(ID, name);
    }
    else
    {
        if (GetSubject(x, ID) != NULL)
        {
            printf("Subject ID: %s has had in the list of Subjects of Student: %s\n", ID, x->name);
        }
        else
        {
            Subject *p = SubjectInit(ID, name);
            p->next = x->subject;
            x->subject = p;
        }
    }
}
// 2. Hiển thị danh sách môn học
void DisplaySubjectOfStudent(Student *x)
{
    Subject *q = x->subject;
    if (q == NULL)
    {
        printf("Student don't have any subject\n");
    }
    else
    {
        while (q != NULL)
        {
            printf("----------------------------\n");
            printf("Subject ID: %s, Name: %s\n", q->ID, q->name);
            printf("Mid Score: %.2f, Final Score: %.2f, Total Score: %.2f\n", q->mid_score, q->final_score, q->total_score);
            printf("----------------------------\n");
            q = q->next;
        }
    }
}
// 3. Xóa một môn học theo mã môn
void DeleteSubjectByID(Student *x, char *ID)
{

    if (x->subject == NULL)
    {
        printf("Student haven't studied any Subject\n");
    }
    else
    {
        Subject *prev = NULL;
        Subject *curr = x->subject;
        while (curr != NULL && strcmp(curr->ID, ID))
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL)
        {
            printf("Student ID: %s Name: %s haven't studied Subject ID: %s", x->ID, x->name, ID);
        }
        else
        {
            if (prev == NULL)
            {
                x->subject = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
            printf("Remove Subject ID: %s of Student ID: %s\n", ID, x->ID);
            free(curr->ID);
            free(curr->name);
            free(curr);
        }
    }
}
// 4. Update điểm môn học của sinh viên
void UpdateScore(Student *x, char *ID, float mid, float final)
{
    if ((mid < 0 || mid > 10) || (final < 0 || final > 10))
    {
        printf("Invalid score\n");
    }
    else
    {
        if (x->subject == NULL)
        {
            printf("Student ID: %s hasn't study Subject ID: %s\n", x->ID, ID);
        }
        else
        {
            if (GetSubject(x, ID) == NULL)
            {
                printf("Student ID: %s Name: %s hasn't study Subject ID: %s\n", x->ID, x->name, ID);
            }
            else
            {
                Subject *p = GetSubject(x, ID);
                p->mid_score = mid;
                p->final_score = final;
                p->total_score = mid * 0.4 + final * 0.6;
            }
        }
    }
}

// 5. Tính GPA của sinh viên
void CaculateGPA(Student *x)
{
    Subject *tmp = x->subject;
    int count = 0;
    float sum = 0;
    if (tmp == NULL)
    {
        printf("Student hasn't studied any Subject\n");
        x->GPA = 0;
    }
    else
    {
        while (tmp != NULL)
        {
            count++;
            sum += tmp->total_score;
            tmp = tmp->next;
        }
        x->GPA = sum / count;
    }
    printf("GPA of Student: %.2f\n", x->GPA);
}

// Lựa chọn hành động cho Subject of Student
void SelectSubjectAction(Student *x)
{
    int A;
    while (1)
    {
        printf("----------------------------\n");
        printf("1. Add Subject \n2. Display list of Subject \n3. Delete Subject \n4. Update Score \n5. Caculate GPA \n0. Back \n");
        printf("Action: ");
        scanf("%d", &A);
        getchar();
        switch (A)
        {
        case 1:
        {
            char ID1[200];
            char name[100];
            printf("Subject ID: ");
            fgets(ID1, sizeof(ID1), stdin);
            ID1[strcspn(ID1, "\n")] = '\0';
            printf("Subject Name: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            printf("\n");
            AddSubject(x, ID1, name);
            break;
        }
        case 2:
        {
            DisplaySubjectOfStudent(x);
            break;
        }
        case 3:
        {
            char ID3[200];
            printf("Subject ID: ");
            scanf("%s", ID3);
            getchar();
            DeleteSubjectByID(x, ID3);
            break;
        }
        case 4:
        {
            char ID4[200];
            float mid, final;
            printf("Subject ID: ");
            scanf("%s", ID4);
            getchar();
            printf("Mid Score: ");
            scanf("%f", &mid);
            printf("Final Score: ");
            scanf("%f", &final);
            UpdateScore(x, ID4, mid, final);
            break;
        }
        case 5:
        {
            CaculateGPA(x);
            break;
        }
        case 0:
        {
            printf("----------------------------\n");
            return;
        }
        default:
        {
            printf("Invalid Action type again\n");
            break;
        }
        }
        printf("----------------------------\n");
    }
}

// B. Quản lí sinh viên

// Khởi tạo sinh viên
Student *StudentInit(char *ID, char *name)
{
    Student *p = (Student *)malloc(sizeof(Student));
    if (p == NULL)
    {
        printf("Out of memory\n");
        return NULL;
    }
    p->ID = strdup(ID);
    p->name = strdup(name);
    p->GPA = 0.0;
    p->next = NULL;
    p->subject = NULL;
    return p;
}

// Tìm kiếm vị trí sinh viên = ID
Student *GetStudent(Student *head, char *ID)
{
    Student *p = head;
    if (head == NULL)
    {
        printf("List of student is empty\n");
    }
    else
    {
        while (p != NULL && strcmp(p->ID, ID))
            p = p->next;
    }
    return p;
}
// Hiển thị thông tin một sinh viên
void DisplayStudent(Student *x)
{
    printf("Student ID: %s\n", x->ID);
    printf("Student Name: %s\n", x->name);
    CaculateGPA(x);
}

// 1. Thêm sinh viên vào cuối danh sách
void AddStudent(Student **head, char *ID, char *name)
// Lỗi vì không để **head mà để *head thì sẽ không add vào và con trỏ head sẽ không di chuyển được
{

    if (*head == NULL)
    {
        *head = StudentInit(ID, name);
    }
    else
    {
        if (GetStudent(*head, ID) != NULL)
        {
            printf("ID: %s of Student: %s has had in the list\n", ID, name);
        }
        else
        {
            Student *p = StudentInit(ID, name);
            p->next = *head;
            *head = p;
        }
    }
}

// 2. Hiển thị danh sách sinh viên
void DisplayStudents(Student *head)
{
    Student *p = head;
    while (p != NULL)
    {
        printf("----------------------------\n");
        DisplayStudent(p);
        p = p->next;
        printf("----------------------------\n");
    }
}
// 3. Tìm sinh viên theo mã
void FindStudentByID(Student *head, char *ID)
{
    Student *p = GetStudent(head, ID);
    printf("----------------------------\n");
    if (p == NULL)
    {
        printf("Student ID: %s is not in the list\n", ID);
    }
    else
    {
        DisplayStudent(p);
    }
    printf("----------------------------\n");
}

// 4. Xóa sinh viên theo mã
void DeleteStudentByID(Student **head, char *ID)
{

    if (*head == NULL)
    {
        printf("List of Student is empty\n");
    }
    else
    {
        Student *prev = NULL;
        Student *curr = *head;
        while (curr != NULL && strcmp(curr->ID, ID))
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL)
        {
            printf("Student ID: %s is not in the list\n", ID);
        }
        else
        {
            if (prev == NULL)
            {
                *head = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }

            printf("Student with ID: %s has been remove from the list\n", ID);
            free(curr->ID);
            free(curr->name);
            free(curr);
            return;
        }
    }
}
// 5. Quản lí môn học của sinh viên
void ManageSubjectOfStudentID(Student *head, char *ID)
{
    if (head == NULL)
    {
        printf("List of Student is empty\n");
        return;

        // Trường hợp này vẫn đang bị lỗi nếu head rỗng nhưng vẫn thực hiện SelectSubjectAction
    }
    else
    {
        Student *p = head;
        while (p != NULL && strcmp(p->ID, ID))
        {
            p = p->next;
        }
        if (p == NULL)
            printf("Student ID: %s is not in the list\n", ID);

        // Vẫn chưa kiểm tra được điều kiện naỳ nếu nhập ID chưa có trong list

        else
        {
            SelectSubjectAction(p);
        }
    }
}

// Lựa chọn hành động cho Student
void SelectStudentAction(Student *head)
{
    int A;
    while (1)
    {
        printf("----------------------------\n");
        printf("1. Add Student \n2. Display list of Student \n3. Find Student \n4. Delete Student \n5. Manage Student Subject \n0. Exit \n");
        printf("Action: ");
        scanf("%d", &A);
        getchar();
        switch (A)
        {
        case 1:
        {
            char ID1[200];
            char name[50];
            printf("Student ID: ");
            fgets(ID1, sizeof(ID1), stdin);
            ID1[strcspn(ID1, "\n")] = '\0';
            printf("Student Name: ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';
            printf("\n");
            AddStudent(&head, ID1, name);
            break;
        }
        case 2:
        {
            DisplayStudents(head);
            break;
        }
        case 3:
        {
            char ID3[200];
            printf("ID of Student: ");
            scanf("%s", ID3);
            getchar();
            FindStudentByID(head, ID3);
            break;
        }
        case 4:
        {
            char ID4[200];
            printf("ID of Student: ");
            scanf("%s", ID4);
            getchar();
            DeleteStudentByID(&head, ID4);
            break;
        }
        case 5:
        {
            char ID5[200];
            printf("Student ID: ");
            scanf("%s", ID5);
            ManageSubjectOfStudentID(head, ID5);
            break;
        }
        case 0:
            return;

        default:
        {
            printf("Invalid Action type again\n");
            break;
        }
        }
        printf("----------------------------\n");
    }
}

int main()
{
    Student *head = NULL;
    SelectStudentAction(head);
}