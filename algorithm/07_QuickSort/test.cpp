#include <iostream>
#include <cstdio>

using namespace std;

struct Node   
{  
    int key;  
    Node* next;  
    // Node(int nKey, Node* pNext)  
    //     : key(nKey)  
    //     , next(pNext)  
    // {}  
};  

void PrintList(Node* head)
{
    while (head != nullptr)
    {
        cout << head->key << " ";
        head = head->next;
    }
    cout << endl;
}
  
  
Node* GetPartion(Node* pBegin, Node* pEnd)  
{  
    int key = pBegin->key;  
    Node* p = pBegin;  
    Node* q = p->next;  
  
    while(q != pEnd)  
    {  
        if(q->key < key)  
        {  
            p = p->next;  
            swap(p->key,q->key);  
        }  
  
        q = q->next;  
    }  
    swap(p->key,pBegin->key);  
    return p;  
}  
  
void QuickSort(Node* pBeign, Node* pEnd)  
{  
    if(pBeign != pEnd)  
    {  
        Node* partion = GetPartion(pBeign,pEnd);  
        QuickSort(pBeign,partion);  
        QuickSort(partion->next,pEnd);  
    }  
}  


int main()
{
    freopen("05.txt", "r", stdin);
    int len;
    cin >> len;
    Node* arr = new Node[len];
    for (int i = 0; i < len - 1; ++i)
    {
        cin >> arr[i].key;
        arr[i].next = &arr[i + 1];
    }
    cin >> arr[len - 1].key;
    arr[len - 1].next = nullptr;

    PrintList(arr);

    QuickSort(&arr[0], &arr[len - 1]);

    PrintList(arr);

    delete[] arr;
    fclose(stdin);
    return 0;
}