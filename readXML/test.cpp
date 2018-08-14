#include <iostream>
#include<cstdlib>
#include <stdio.h>
using namespace std;
typedef struct node 
{
int data;
struct node *link;
}NODE;
NODE *NewNode(void);       //宣告建立新節點 
NODE *Invert(NODE*);
NODE *Remove(NODE*);
void PrintLists(NODE*);    //宣告列印兩個或兩個以上串列的內容 
int main(void)
{
 int i,a;
 NODE *head,*temp;      //宣告head,temp為指向結構NODE的指標 
    head = NewNode( );     //分配新節點空間 
    temp = head;           //兩個指標指向同一個節點 
    cout << "請輸入第1個資料:";
 cin >> head->data;
 for(i=0;i<4;i++)
 {
  cout << "請輸入第" << i+2 << "個資料:";
  temp->link = NewNode( );                      //呼叫建立新節點 
  cin >> temp->link->data;
  temp = temp->link; 
 }
 temp->link = NULL;
 PrintLists(head);
 while(1)
 {
  cout << "1.反轉" << endl;
  cout << "2.刪除" << endl;
  cout << "3.結束" << endl;
  cout << "請選擇以下步驟:";
  cin >> a;
  switch(a)
  {
   case 1: head=Invert(head);
           PrintLists(head);
           break;
           
   case 2:head=Remove(head);
          break;
       
   case 3: cout << "Goodbye~";
           exit(1);             
  }   
 }
 system("pause");
 return 0;
}

NODE *NewNode(void)  //建立新節點之副程式 
{
  NODE *pt;
  pt = (NODE*)malloc(sizeof(NODE));
  if(pt== NULL ) 
  {
    cout << "記憶體空間不足!" << endl; 
    exit(1);
  }
  return pt;
}

void PrintLists(NODE* head)  //列印兩個或兩個以上串列的內容之副程式 
{
  NODE *temp=head;
  cout << "鏈結串列為：";       //印出串列的資料欄之內容
  while(temp != NULL)
  {
    cout << temp->data;
    temp = temp->link;
  }
  cout << endl;
}

NODE *Invert(NODE* head)
{
 NODE *previous,*current,*pt;
    current = NULL;
    pt = head;
    while(pt != NULL)
    {
     previous = current;
     current = pt;
     pt = pt->link;
     current->link =previous;     
 }
    head = current;
 return head;  
}

 NODE *Remove(NODE* head)
{
 int find;
 NODE *temp;
 cout << "請輸入要刪除的值:";
 cin >> find;                            //要被刪除的值 
 NODE *follow;
 if (head == NULL)                       //head為空連結
 {
  cout << "找不到此數字" << endl; 
 }
 if(head->data == find)                  //第一個節點是要刪除的目標值
 { 
        head = head->link;
        delete temp; 
     temp=head;
     PrintLists(head);
     temp = head; //把temp指回 head
        while(true)
  {
            printf("%d ", temp->data); //印目前的節點
            temp = temp->link; //印完後要印下一個節點的內容
            if (temp == NULL) //temp為NULL的時候停下來
   {
    break;
            } 
        }    
 } 
 else
 {
  while((temp != NULL) && (temp->data != find))
  {                                                   //尋找要刪除的目標
            follow = temp;
            temp = temp->link;
        }
        if(temp == NULL)
  {
            cout << "找不到此數字" << endl;
        }
        else
        {
         follow->link = temp->link;
            free(temp);
  }
  PrintLists(head);
  temp = head; //把temp指回 head
        while(true)
  {
            printf("%d ", temp->data); //印目前的節點
            temp = temp->link; //印完後要印下一個節點的內容
            if (temp == NULL) //temp為NULL的時候停下來
   { 
                break;
            }
        }
 }
 cout << endl;  
}
