#include <iostream>
using namespace std;
struct dqueue{
 int size,front,rear;
 int*b;
};
typedef struct dqueue dqueue;
void create(dqueue*dp)
{
 cout<<"enter size of dqueue\n";
 cin>>dp->size;
 dp->b=new int[dp->size];
 dp->front=-1;
 dp->rear=-1;
}

bool isfull(dqueue*dp)
{
 if((dp->rear+1)%dp->size==dp->front)
 return 1;
 else
 return 0;
}
void addrear(dqueue*dp,int x)
{
 if(isfull(dp))
  {
 cout<<"overflow condition\n";
 }
 else if(dp->rear==-1 && dp->front==-1)
 {
 dp->front=0;
 dp->rear=0;
 dp->b[dp->front]=x;
 }
 else
 {
 if(dp->front!=0)
 {dp->front=(dp->front-1);}
 else
 dp->front=dp->size-1;
 dp->b[dp->front]=x;
 }
}
bool isempty(dqueue*dp)
{
 if(dp->front==-1 && dp->rear==-1)
 return 1;
 else
 return 0;
}
void deletfront(dqueue*dp)
{
 if(isempty(dp))
 cout<<"underflow condition\n";
 else if(dp->front==dp->rear)
 {
 int x=dp->b[dp->front];
 cout<<x<<" is delete from queue\n";
 dp->front=-1;
 dp->rear=-1;
 }
 else
 {
 cout<<dp->b[dp->front]<<" deleted from queue\n";
 dp->front=(dp->front+1)%dp->size;
 }
}
void deleterear(dqueue*dp)
{
 if(isempty(dp))
 cout<<"underflow condition\n";
 else if(dp->front==dp->rear)
 {
 cout<<dp->b[dp->front]<<" is delete from queue\n";
 dp->front=-1;
 dp->rear=-1;
 }
 else{
 if(dp->rear!=0)
 {
 cout<<dp->b[dp->rear]<<" deleted from queue\n";
 dp->rear--;
 }
 else
 {
 cout<<dp->b[dp->rear]<<" deleted from queue\n";
 dp->rear=dp->size-1;
 }
 }
}
void display(dqueue*dp)
{
 if(isempty(dp))
 cout<<"underflow condition\n";
 else
 {
 int i=dp->front;
 cout<<"queue is \n";
 while(dp->front!=dp->rear)
 {
 cout<<dp->b[i]<<" ";
 i=(i+1)%dp->size;
 }
 cout<<dp->b[i]<<" ";
 cout<<endl;
 }
}
void addfront(dqueue*dp,int x)
{
 if(isfull(dp))
 {
 cout<<"overflow condition\n";
 }
 else if(dp->rear==-1 && dp->front==-1)
 {
 dp->front=0;
 dp->rear=0;
 dp->b[dp->front]=x;
 }
 else
 {
 if(dp->front!=0)
 {dp->front=(dp->front-1);}
 else
 dp->front=dp->size-1;
 dp->b[dp->front]=x;
 }
}
int main()
{
 dqueue de;
 create(&de);
 int a;
 cout<<"1 for enqueue from rear\n2 for dequeue front \n3 for checking queue is full or empty or partially filled\n4 display queue\nenter 0 for exit\n";
 cout<<"5 for enqueue from front\n6 for dequeue rear\n";

 cin>>a;
 while(a)
 {
 
 switch(a)
 {
 case 0:
 break;
 case 1:
 {
 int x;
 cout<<"enter the value for insert\n";
 cin>>x;
 addrear(&de,x);
 break;
 }
 case 2:
 {
 deletfront(&de);
 break;
 }
 case 3:
 {
 if(isfull(&de))
 cout<<"queue is full\n";
 else if(isempty(&de))
 cout<<"queue is empty\n";
 else
 cout<<"queue is partially full\n";
 break;
 }
 case 4:
 {
 display(&de);
 break;
 }
 case 5:
 {
 int x;
 cout<<"enter the value for insert\n";
 cin>>x;
 addfront(&de,x);
 break;
 }
 case 6:
 {
 deleterear(&de);
 break;
 }
 default:
 {
 cout<<"wrong input\n";
 break;
 }
 }
  cout<<"1 for enqueue from rear\n2 for dequeue front \n3 for checking queue is full or empty or partially filled\n4 display queue\nenter 0 for exit\n";
 cout<<"5 for enqueue from front\n6 for dequeue rear\n";

 cin>>a;
 }
 return 0;
}