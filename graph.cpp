#include<iostream>
using namespace std;
struct node
{
	int vertex;
	node *next;
};

class adj_list
{
	int v;
	node *hn[10];
	int m[10][10];
public:
	adj_list()
	{
		v=0;
		for(int i=0;i<9;i++)
		{
				hn[i]=NULL;
		}

		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
						m[i][j]=0;
			}
		}
	}
	void create_list();
	void create_mat();
	void add_edge(int, int);
	void display_list();
	void display_mat();
};

void adj_list :: create_mat()
{
	int i,j;
	char n;
	cout<<"\nEnter the number of vertex";
		cin>>v;
	do
	{
		cout<<"\nPair of vertices";
		cin>>i>>j;
		m[i][j]=m[j][i]=1;
		cout<<"\nDo you want to continue";
		cin>>n;
	}while(n=='y'||n=='Y');
}

void adj_list :: display_mat()
{
	for(int i=0;i<v;i++)
	{
		cout<<"\n";
		for(int j=0;j<v;j++)
		{
			cout<<m[i][j]<<"\t";
		}
		cout<<"\n";
	}
	cout<<"\n";
}
void adj_list :: create_list()
{
	int i,j;
	char ch;
	cout<<"\nEnter the number of vertex";
	cin>>v;
	do
	{
		cout<<"\nEnter the edges in pair";
		cin>>i>>j;
		add_edge(i,j);
		add_edge(j,i);
		cout<<"\nDo you want to continue";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
}

void adj_list :: add_edge(int i, int j)
{
	node *nn,*cn;
	nn=new node;
	nn->vertex=j;
	nn->next=NULL;
	if(hn[i]==NULL)
		hn[i]=nn;
	else
	{
		cn=hn[i];
		while(cn->next!=NULL)
		{
			cn=cn->next;

		}
		cn->next=nn;
	}
}

void adj_list :: display_list()
{
	node *cn;
	for(int i=0;i<=v;i++)
	{
		cn=hn[i];
		//cout<<i<<"->";
		while(cn!=NULL)
		{
			cout<<i<<"->";
			cout<<cn->vertex<<"\t";
			cn=cn->next;
		}
		cout<<"\n";
	}
}
int main()
{
	adj_list a;
	int ch;
	do
	{
		cout<<"\n1.Creation of matrix";
		cout<<"\n2.Creation of list";
		cout<<"\n3.Display list";
		cout<<"\n4.Display matrix";
		cout<<"\n5.Exit";
		cout<<"\nEnter your choice";
		cin>>ch;
		switch(ch)
		{
		case 1:a.create_mat();
				break;
		case 2:a.create_list();
				break;
		case 3:a.display_list();
				break;
		case 4:a.display_mat();
				break;
		case 5: break;
		}
		
	}while(ch!=5);
	return 0;
}
