/*Consider telephone book database of N clients. 
Make use of a hash table implementation to
quickly look up client‘s telephone number.*/
#include<iostream>
using namespace std;
struct teldir
{
char name;
long number;
};
class dir
{
teldir book[25];
public:
    dir()
    {
    for(int i=0;i<25;i++)   
    {
    book[i].name=' ';
    book[i].number=0;
    }
    }
    void createdir(int i,char p,long n);
    void display();
    void search(char p,int i);
};

void dir::search(char p,int i)
{
int flag=0,count=1;
    if(book[i].name==p)
    {
    cout<<"found at "<<i;
        cout<<endl<<"no of comparision"<<count;   
    }
    else
    {
        for(int j=i+1;j<25;j++)
        {
        count++;
          if(book[j].name==p)
         {
            cout<<"found at "<<j;
           cout<<endl<<"no of comparision"<<count;   
           flag=1;
         break;
         }
        }
        if(flag==0)
        {
        for(int j=0;j<i;j++)
        {
          count++;
          if(book[j].name==p)
           {
            cout<<"found at "<<j;
           cout<<endl<<"no of comparision"<<count;   
          flag=1;
           }
        }
        }
        if(flag==0)
        {   
        cout<<"not found";
        }
    }

}
void dir::display()
{
for(int i=0;i<25;i++)
  cout<<endl<<book[i].name<<" "<<book[i].number;
}



void dir::createdir(int i,char p, long n)
{
    int flag=0;
    if(book[i].name==' ')
    {
      book[i].name=p;
      book[i].number=n;
    }
    else
    {
        for(int j=i+1;j<25;j++)
        {
          if(book[j].name==' ')
         {
          book[j].name=p;
          book[j].number=n;
          flag=1;
            break;
         }
        }
        if(flag==0)
        {
        for(int j=0;j<i;j++)
        {
          if(book[j].name==' ')
           {
          book[j].name=p;
          book[j].number=n;
          flag=1;
            break;
           }        }
        }
        if(flag==0)
        {   
        cout<<"overflow";
        }
    }

}
int main()
{
int ch,cont,total,tmp;
char p;
long n;
dir d1;
do
{
cout<<endl<<"Menu";
cout<<endl<<"1.Create Telephone book ";
cout<<endl<<"2.Display";
cout<<endl<<"3.Look up";
cout<<endl<<"Enter Choice";
cin>>ch;
switch(ch)
{
case 1:
     cout<<"How many entries??";
     cin>>total;
     for(int i=0;i<total;i++)
     {
        cout<<"Enter Name";
        cin>>p;
        cout<<"Enter number";
        cin>>n;
          tmp=p;
        tmp=tmp%25;
        d1.createdir(tmp,p,n);
      }
    break;
case 2:
    d1.display();
    break;
case 3:
    cout<<"Enter Name to search";
    cin>>p;
  	tmp=p;
    tmp=tmp%25;
   	d1.search(p,tmp);
    break;

}
cout<<endl<<"Do u want to continue?(1 for continue)";
cin>>cont;
}while(cont==1);
return 0;
}
/*Menu
1.Create Telephone book 
2.Display
3.Look up
Enter Choice1
How many entries??2
Enter Namea
Enter number123
Enter Nameb
Enter number321

Do u want to continue?(1 for continue)1

Menu
1.Create Telephone book 
2.Display
3.Look up
Enter Choice2

  0
  0
  0
  0
  0
  0
  0
  0
  0
  0
  0
  0
  0
  0
  0
  0
  0
  0
  0
  0
  0
  0
a 123
b 321
  0
Do u want to continue?(1 for continue)
*/
