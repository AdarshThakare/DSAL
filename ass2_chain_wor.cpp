/************************************************************************
Program to create hash table and to handle the collision using chaining
without replacement.In this program hash function is (number %10)
*************************************************************************/
#include<iostream>

#include<stdlib.h>
#define MAX 10
using namespace std;
class WO_chain
{
  private:
  int a[MAX][2];
  public:
  WO_chain();
  int create(int);
  void chain(int,int),display();
};
/*
--------------------------------------------------------------------------
The constructor defined
--------------------------------------------------------------------------
*/
WO_chain::WO_chain()
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
The create function is for generating the hash key
Input:the num means the number which we want to place in the hash table
Output:returns the hash key
Calls:none
Called By:main
--------------------------------------------------------------------------
*/

int WO_chain::create(int num)
{
 int key;
 key=num%10;
 return key;
}
/*
--------------------------------------------------------------------------
The chain function handles the collision without replacement of numbers
Input:the num,hash key and hash table by array a[]
Output:none
Calls:none
Called By:main
--------------------------------------------------------------------------
*/

void WO_chain::chain(int key,int num)
{
 int flag,i,count=0,ch;
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
 else //if collision occurs
 {
  ch=a[key][1];//taking the chain
  //If only one number in hash table with current obtained key
  if(ch==-1)
  {
 for(i=key+1;i<MAX;i++)//performing linear probing
 {
  if(a[i][0]==-1) //at immediate empty slot
  {
   a[i][0]=num;//placiing number
   a[key][1]=i; //setting the chain
   flag=1;
   break;
  }
 }
  }
  //if many numbers are already in the hash table
  //we will find the next empty slot to place number
  else
  {
 while((a[ch][0]!=-1)&&(a[ch][1]!=-1))//traversing thro chain till empty slot is found*/
  ch=a[ch][1];
 for(i=ch+1;i<MAX;i++)
 {
  if(a[i][0]==-1)
  {
   a[i][0]=num;//placing the number
   a[ch][1]=i; //setting chain
   flag=1;
   break;
  }
 }
  }
//If the numbers are occupied somewhere from middle and are stored upto
//the MAX then we will search for the empty slot upper half of the array
if(flag!=1)
{
if(ch==-1)
  {
 for(i=0;i<key;i++)//performing linear probing
 {
  if(a[i][0]==-1) //at immediate empty slot
  {
   a[i][0]=num;//placiing number
   a[key][1]=i; //setting the chain
   flag=1;
   break;
  }
 }
  }
  //if many numbers are already in the hash table
  //we will find the next empty slot to place number
  else
  {
 //traversing thro chain till empty slot is found
 while((a[ch][0]!=-1)&&(a[ch][1]!=-1))
  ch=a[ch][1];
 for(i=ch+1;i<key;i++)
 {
  if(a[i][0]==-1)
  {
   a[i][0]=num;//placing the number
   a[ch][1]=i; //setting chain
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
The display function displays the hash table and chain table
Input:hash table by array a[]
Output:none
Calls:none
Called By:main
--------------------------------------------------------------------------
*/
void WO_chain::display()
{
 int i;
 cout<<"\n The Hash Table is...\n";
 for(i=0;i<MAX;i++)
  cout<<"\n  "<<i<<" "<<a[i][0]<<" "<<a[i][1];
}
/*
--------------------------------------------------------------------------
The main function
Calls:create,chain,display
Called By:O.S.
--------------------------------------------------------------------------
*/
int main()
{

 int num,key,i;
 char ans;
 WO_chain h;
 //clrscr();
 cout<<"\nChaining Without Replacement";
 do
 {
  cout<<"\n Enter The Number";
  cin>>num;
  key=h.create(num);//returns hash key
  h.chain(key,num);//collision handled by chaining without replacement
  cout<<"\n Do U Wish To Continue?(y/n)";
  cin>>ans;
 }while(ans=='y');
 h.display();//displays hash table
 //getch();
}
