
/************************************************************************
Program to create hash table and to handle the collision using chianing
with replacement.In this program hash function is (number %10)
*************************************************************************/
#include<iostream>

#include<stdlib.h>
#define MAX 10
using namespace std;
class W_chain
{
  private:
   int a[MAX][2];
  public:
   W_chain();
   int create(int);
   void chain(int,int),display();
   int match(int,int);
   ~W_chain();
};
/*
--------------------------------------------------------------------------
The constructor defined
--------------------------------------------------------------------------
*/
W_chain::W_chain()
{
 int i;
 for(i=0;i<MAX;i++)
 {
  a[i][0]=-1;
  a[i][1]=-1;
 }
}
/*
--------------------------------------------------------------------------
The destructor defined
--------------------------------------------------------------------------
*/
W_chain::~W_chain()
{
 int i;
 for(i=0;i<MAX;i++)
 {
  a[i][0]=-1;
  a[i][1]=-1;
 }
}
/*
--------------------------------------------------------------------------
The create function
--------------------------------------------------------------------------
*/
int W_chain::create(int num)
{
 int key;
 key=num%10;
 return key;
}
/*
--------------------------------------------------------------------------
The match function
--------------------------------------------------------------------------
*/
int W_chain::match(int prev,int num)
{
  if(create(num)==create(prev))
 return 1;
 return 0;
}
/*
--------------------------------------------------------------------------
The chain function
--------------------------------------------------------------------------
*/
void W_chain::chain(int key,int num)
{
 int flag,i,count=0,ch,temp,j,prev_ch;
 flag=0;

//checking full condition
  i=0;
  while(i<MAX)
  {
 if(a[i][0]!=-1)
  count++;
 i++;
  }
 if(count==MAX)
 {
 cout<<"\nHash Table Is Full";
 display();
 //getch();
 exit(1);
 }
//placing number otherwise
 if(a[key][0]==-1)//no collision case
  a[key][0]=num;
 else
 {
  ch=a[key][1];
  if(match(a[key][0],num))
  {
 if(ch==-1)//no chain
 {
  for(i=key+1;i<MAX;i++)
  if(a[i][0]==-1)
  {
  a[i][0]=num;
  a[key][1]=i;
  flag=1;
  break;
  }
 }
 else
 {
  while((a[ch][0]!=-1)&&(a[ch][1]!=-1))
  ch=a[ch][1];
 for(i=ch+1;i<MAX;i++)
 {
  if(a[i][0]==-1)
  {
  a[i][0]=num;
  a[ch][1]=i;
  flag=1;
  break;
  }
 }
 }
 }
 else                    //unmatched
 {
 if(ch==-1)
 {
  temp =a[key][0];
  for(i=key+1;i<MAX;i++)
  if(a[i][0]==-1)
  {
  a[key][0]=num;//replacement is done
  a[i][0]=temp;
  for(j=0;j<MAX;j++)
   if(key==a[j][1])
   a[j][1]=i;
   flag=1;
  break;
  }
 }
 else //chain exists
 {
  for(j=0;j<MAX;j++)
  if(key==a[j][1])
  prev_ch=j;
  temp=a[key][0];
  ch=key;
  while(a[ch][1]!=-1)     //traversal for continuos chain
  ch=a[ch][1];
  for(i=ch+1;i<MAX;i++)
  if(a[i][0]==-1)//actual replacement
   {
   a[i][0]=temp;
   a[ch][1]=i;
   a[key][0]=num;
   a[prev_ch][1]=a[key][1];
   a[key][1]=-1;
   flag=1;
   break;
   }
  }
 }
  if(flag!=1)
  {
 if(match(a[key][0],num))
 {
 if(ch==-1)//no chain
 {
  for(i=0;i<key;i++)
  if(a[i][0]==-1)
  {
  a[i][0]=num;
  a[key][1]=i;
  flag=1;
  break;
  }
 }
 else
 {
  while((a[ch][0]!=-1)&&(a[ch][1]!=-1))
  ch=a[ch][1];
 for(i=0;i<key;i++)
 {
  if(a[i][0]==-1)
  {
  a[i][0]=num;
  a[ch][1]=i;
  flag=1;
  break;
  }
 }
 }
 }
 else                   //unmatched
 {
 if(ch==-1)
 {
  temp =a[key][0];
  for(i=0;i<key;i++)
  if(a[i][0]==-1)
  {
  a[key][0]=num;//replacement is done
  a[i][0]=temp;
  for(j=0;j<MAX;j++)
   if(key==a[j][1])
   a[j][1]=i;
   flag=1;
  break;
  }
 }
 else //chain exists
 {
  for(j=0;j<MAX;j++)
  if(key==a[j][1])
  prev_ch=j;
  temp=a[key][0];
  ch=key;
  while(a[ch][1]!=-1)   //traversal for continuos chain
  ch=a[ch][1];
  for(i=0;i<key;i++)
  if(a[i][0]==-1)//actual replacement
   {
   a[i][0]=temp;
   a[ch][1]=i;
   a[key][0]=num;
   a[prev_ch][1]=a[key][1];
   a[key][1]=-1;
   flag=1;
   break;
   }
  }
 }
 }

 }
}
/*
--------------------------------------------------------------------------
The display function
--------------------------------------------------------------------------
*/
void W_chain::display()
{
 int i;
 cout<<"\n The Hash Table is...\n";
 for(i=0;i<MAX;i++)
 cout<<"\n "<<i<<"  "<<a[i][0]<<"  "<<a[i][1];
}
/*
--------------------------------------------------------------------------
The main function
--------------------------------------------------------------------------
*/
int main()
{
 int num,key;
 char ans;
 W_chain h;
 //clrscr();
 cout<<"\nChaining With Replacement";
 do
 {
  cout<<"\n Enter The Number";
  cin>>num;
  key=h.create(num); //create hash key
  h.chain(key,num);
  cout<<"\n Do U Wish To Continue?(y/n)";
  cin>>ans;
 }while(ans=='y');
 h.display();
 //getch();
}
