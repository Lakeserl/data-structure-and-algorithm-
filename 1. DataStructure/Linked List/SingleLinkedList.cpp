#include <iostream>
#include <malloc.h>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
};
Node *start = NULL, *temp, *node, *ptr;

int IsEmpty()
{
    if (start == NULL)
        return 1;
    else
        return 0;
}

int DemNodes()
{
    int n = 0;
    temp = start;
    while (temp != NULL)
    {
        n++;
        temp = temp->next;
    }
    return n;
}

int SearchNode(int n)
{
    int c = 1, flag = 0;
    temp = start;
    while (temp != NULL)
    {
        if (temp->val == n)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
        c++;
    }
    if (flag == 1)
        return c;
    else
        return flag;
}

void CreateList()
{
    temp = new Node();
    cout << "Nhập giá trị : ";
    cin >> temp->val;
    temp->next = NULL;
    if (start == NULL)
    {
        start = temp;
        node = temp;
    }
    else
    {
        node->next = temp;
        node = temp;
    }
}

void ChayList()
{
    if (IsEmpty())
        cout << "\n Trống!!" << endl;
    else
    {
        temp = start;
        while (temp != NULL)
        {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void InsertBeg()
{
    temp = new Node();
    cout << "Nhập giá trị: ";
    cin >> temp->val;
    temp->next = start;
    start = temp;
}

void InsertEnd()
{

    if (IsEmpty())
        CreateList();
    else
    {
        temp = new Node();
        cout << "Nhập giá trị : ";
        cin >> temp->val;
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->next = NULL;
    }
}

void InsertAfter()
{
    int n;
    temp = start;
    cout << "Nhập vị trí cần tìm : ";
    cin >> n;
    if (n == 1)
    {
        if (IsEmpty())
            CreateList();
        else
            InsertBeg();
    }
    else
    {
        if (n > 0 && n <= DemNodes())
        {
            int c = 1;
            while (c != n)
            {
                temp = temp->next;
                c++;
            }
            ptr = new Node();
            cout << "Nhập giá trị: ";
            cin >> ptr->val;
            ptr->next = temp->next;
            temp->next = ptr;
        }
        else
            cout << "\nVị trí không xác định!!" << endl;
    }
}

void InsertBefore()
{
    int n;
    cout << "Nhập giá trị trước khi chèn : ";
    cin >> n;
    if (SearchNode(n))
    {
        temp = start;
        while (temp->next->val != n)
        {
            temp = temp->next;
        }
        ptr = new Node();
        cout << "Nhập phần tử: ";
        cin >> ptr->val;
        ptr->next = temp->next;
        temp->next = ptr;
    }
    else
        cout << "Không tìm thấy!!" << endl;
}

void DeleteFirst()
{
    if (IsEmpty())
        cout << "\nGiá trị không tồn tại để xóa!!" << endl;
    else
    {
        temp = start;
        start = temp->next;
        delete temp;
    }
}

void DeleteLast()
{
    if (IsEmpty())
        cout << "\nGiá trị không tồn tại để xóa!!" << endl;
    else
    {
        temp = start;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete (temp->next);
        temp->next = NULL;
    }
}

void DeletePos()
{
    int n, c = 1;
    cout << "Nhập vị trí : ";
    cin >> n;
    if (n == 1)
    {
        if (IsEmpty())
            cout << "\nVị trí không tồn tại để xóa!!" << endl;
        else
            DeleteFirst();
    }
    else
    {
        if (n > 0 && n <= DemNodes())
        {
            temp = start;
            while (c != n - 1)
            {
                temp = temp->next;
                c++;
            }
            ptr = temp->next;
            temp->next = temp->next->next;
            delete (ptr);
        }
        else
            cout << "Vị trí không xác định!!" << endl;
    }
}

void DeleteVal()
{
    int n;
    cout << "Nhập giá trịto delete : ";
    cin >> n;
    if (IsEmpty())
        cout << "\nGiá trị không tồn tại để xóa!!" << endl;
    else
    {
        if (SearchNode(n))
        {
            int c = 0;
            temp = start;
            while (temp->next->val != n)
            {
                temp = temp->next;
            }
            delete (temp->next);
            temp->next = temp->next->next;
        }
        else
            cout << "Không tìm thấy!!" << endl;
    }
}

void UpdateNode()
{
    temp = start;
    int v, count = 1, newvalue;
    cout << "Nhập giá trị : ";
    cin >> v;
    if (SearchNode(v))
    {
        while (temp->val != v)
        {
            temp = temp->next;
            count++;
        }
        cout << "Giá trị mới : ";
        cin >> newvalue;
        temp->val = newvalue;
    }
    else
        cout << "Value không hợp lệ!!" << endl;
}

void ReverseList()
{
}

int main()
{
    int ch;
    do
    {
        cout << "\n\t-: M E N U :- \n================================" << endl;
        cout << "1.....Create List." << endl;
        cout << "2.....Chay List." << endl;
        cout << "3.....Insert at beginning." << endl;
        cout << "4.....Insert at the end." << endl;
        cout << "5.....Insert after specific position." << endl;
        cout << "6.....Insert before a given node." << endl;
        cout << "7.....Search an element." << endl;
        cout << "8.....Delete first element." << endl;
        cout << "9.....Delete last element." << endl;
        cout << "10.....Delete any position." << endl;
        cout << "11.....Delete any value." << endl;
        cout << "12.....Update a node." << endl;
        cout << "13.....Reverse the List." << endl;
        cout << "0.....EXIT." << endl;
        cout << "\nEnter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 0:
            cout << "\nEnd of Program" << endl;
            break;
        case 1:
            CreateList();
            break;
        case 2:
            ChayList();
            break;
        case 3:
            InsertBeg();
            break;
        case 4:
            InsertEnd();
            break;
        case 5:
            InsertAfter();
            break;
        case 6:
            InsertBefore();
            break;
        case 7:
            int n;
            cout << "Enter element to search : ";
            cin >> n;
            if (SearchNode(n))
                cout << "Element found at " << SearchNode(n) << " position!" << endl;
            else
                cout << "Element not found!" << endl;
            break;
        case 8:
            DeleteFirst();
            break;
        case 9:
            DeleteLast();
            break;
        case 10:
            DeletePos();
            break;
        case 11:
            DeleteVal();
            break;
        case 12:
            UpdateNode();
            break;
        case 13:
            ReverseList();
            break;
        default:
            cout << "\nInvalid Input!!" << endl;
            break;
        }
    } while (ch != 0);
    return 0;
}