#include <iostream>
#include<cstdlib>
#include <stdio.h>
using namespace std;
typedef struct node 
{
int data;
struct node *link;
}NODE;
NODE *NewNode(void);       //�ŧi�إ߷s�`�I 
NODE *Invert(NODE*);
NODE *Remove(NODE*);
void PrintLists(NODE*);    //�ŧi�C�L��өΨ�ӥH�W��C�����e 
int main(void)
{
 int i,a;
 NODE *head,*temp;      //�ŧihead,temp�����V���cNODE������ 
    head = NewNode( );     //���t�s�`�I�Ŷ� 
    temp = head;           //��ӫ��Ы��V�P�@�Ӹ`�I 
    cout << "�п�J��1�Ӹ��:";
 cin >> head->data;
 for(i=0;i<4;i++)
 {
  cout << "�п�J��" << i+2 << "�Ӹ��:";
  temp->link = NewNode( );                      //�I�s�إ߷s�`�I 
  cin >> temp->link->data;
  temp = temp->link; 
 }
 temp->link = NULL;
 PrintLists(head);
 while(1)
 {
  cout << "1.����" << endl;
  cout << "2.�R��" << endl;
  cout << "3.����" << endl;
  cout << "�п�ܥH�U�B�J:";
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

NODE *NewNode(void)  //�إ߷s�`�I���Ƶ{�� 
{
  NODE *pt;
  pt = (NODE*)malloc(sizeof(NODE));
  if(pt== NULL ) 
  {
    cout << "�O����Ŷ�����!" << endl; 
    exit(1);
  }
  return pt;
}

void PrintLists(NODE* head)  //�C�L��өΨ�ӥH�W��C�����e���Ƶ{�� 
{
  NODE *temp=head;
  cout << "�쵲��C���G";       //�L�X��C������椧���e
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
 cout << "�п�J�n�R������:";
 cin >> find;                            //�n�Q�R������ 
 NODE *follow;
 if (head == NULL)                       //head���ųs��
 {
  cout << "�䤣�즹�Ʀr" << endl; 
 }
 if(head->data == find)                  //�Ĥ@�Ӹ`�I�O�n�R�����ؼЭ�
 { 
        head = head->link;
        delete temp; 
     temp=head;
     PrintLists(head);
     temp = head; //��temp���^ head
        while(true)
  {
            printf("%d ", temp->data); //�L�ثe���`�I
            temp = temp->link; //�L����n�L�U�@�Ӹ`�I�����e
            if (temp == NULL) //temp��NULL���ɭ԰��U��
   {
    break;
            } 
        }    
 } 
 else
 {
  while((temp != NULL) && (temp->data != find))
  {                                                   //�M��n�R�����ؼ�
            follow = temp;
            temp = temp->link;
        }
        if(temp == NULL)
  {
            cout << "�䤣�즹�Ʀr" << endl;
        }
        else
        {
         follow->link = temp->link;
            free(temp);
  }
  PrintLists(head);
  temp = head; //��temp���^ head
        while(true)
  {
            printf("%d ", temp->data); //�L�ثe���`�I
            temp = temp->link; //�L����n�L�U�@�Ӹ`�I�����e
            if (temp == NULL) //temp��NULL���ɭ԰��U��
   { 
                break;
            }
        }
 }
 cout << endl;  
}
