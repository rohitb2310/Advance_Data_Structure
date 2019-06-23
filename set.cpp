#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node *next;
};
class Sets
{
	Node *hn;
public:
	Sets()
	{
		hn=NULL;
	}
	void create()
	{
		Node *nn,*pn;
		nn=new Node();
		nn->next=NULL;
		cout<<"\nEnter the element:";
		cin>>nn->data;
		if(hn==NULL)
				{
					hn=nn;

				}
				else
				{
					pn=hn;
										while(pn->next!=NULL)
										{
											pn=pn->next;
										}
										pn->next=nn;
				}


	}

	void Contents()
	{   Node *t;int c=0;
		t=hn;
		cout<<"\n(";
		while(t!=NULL)
		{
			c++;
			cout<<t->data<<" ";
			t=t->next;
		}
		cout<<")";
		cout<<"\n\nTotal count of SET:"<<c;
	}


	void search()
	{
		int n;
		cout<<"Enter the Element to be Searched:";cin>>n;
		Node *t;
		t=hn;
		while(t!=NULL)
		{
			if(t->data==n)
			{
				cout<<"\nElement found";return;
			}
			t=t->next;
		}

		cout<<"\nNot found";

	}

	void remove()
	{
		int n;
		cout<<"\nEnter the element to be deleted:";
		cin>>n;
		Node *t,*cn;
		t=hn;
		cn=t->next;
		while(t!=NULL)
		{
			if(hn->data==n)
			{
				cout<<"\ndeleted:"<<hn->data;
				hn=hn->next;

				return;
			}
			else
			{
				if(cn->data==n)
				{
					cout<<"\ndeleted:"<<cn->data;
					t->next=cn->next;

					return;
				}

				t=cn;
				cn=cn->next;

			}
		}


	}

	void intersection(Sets s1, Sets s2)
	{
		int flag;
		Node *cn1,*cn2,*cn3;
		cn1=s1.hn;
		hn=NULL;
		cn3=hn;
		cn2=s2.hn;
		while(cn1!=NULL)
		{
			flag=0;
			cn2=s2.hn;
			while(cn2!=NULL)
			{
				if(cn1->data==cn2->data)
				{
					flag=1;
					break;
				}
				cn2=cn2->next;
			}

			if(flag==1)
			{
				 Node *nn;
				nn=new Node();
				nn->data=cn2->data;
				nn->next=NULL;
				if(hn==NULL)
				{
					hn=nn;
				}
				else
				{
					cn3=hn;
					while(cn3->next!=NULL)
					{
						cn3=cn3->next;
					}
					cn3->next=nn;

				}
			}

			cn1=cn1->next;
		}
	}

	void unin(Sets s2,Sets s3)
	{

		int flag=0;
			 Node *cn1,*cn2,*cn3;

			 cn2=s2.hn;
			 s3.hn=hn;
			 cn3=s3.hn;
			 while(cn2!=NULL)
			 {	cn1=hn;
			 flag=0;
				 while(cn1!=NULL)
				 {
					 if(cn1->data==cn2->data)
					 {
						 flag=1;
						 break;
					 }
					 cn1=cn1->next;
				 }
				 if( flag==0)
				 {
					 Node *nn;
					 nn=new Node();
					 nn->data=cn2->data;
					 nn->next=NULL;
					 while(cn3->next!=NULL)
					 {
						 cn3=cn3->next;
					 }
					 cn3->next=nn;
				 }
				 cn2=cn2->next;
			 }
			 s3.Contents();

	}


	void difference(Sets s1,Sets inter)
	{
		int flag=0;
		Node *cn1,*cn2,*cn3;
		hn=NULL;
		cn1=hn;
		cn2=s1.hn;
		cn3=inter.hn;
		while(cn2!=NULL)
				{
					flag=0;
					cn3=inter.hn;

						while(cn3!=NULL)
						{
							if(cn2->data==cn3->data)
							{
								flag=1;
								break;
							}

							cn3=cn3->next;
						}


					if(flag==0)
					{
						Node *nn;
						nn=new Node();
						nn->data=cn2->data;
						nn->next=NULL;
						if(hn==NULL)
							{
								hn=nn;
							}
						else
							{
								cn1=hn;
								while(cn1->next!=NULL)
								{
									cn1=cn1->next;
								}
								cn1->next=nn;

							}
					}

					cn2=cn2->next;
				}
	}

	void subset(Sets s2)
	{
		int flag=0;
					 Node *cn1,*cn2;
					 cn2=s2.hn;
					 while(cn2!=NULL)
					 {	cn1=hn;
					 flag=0;
						 while(cn1!=NULL)
						 {
							 if(cn1->data==cn2->data)
							 {
								flag=1;

								break;
							}
							 cn1=cn1->next;
						 }
						 cn2=cn2->next;
					 }
					 if(flag==1)
					 {
						 cout<<"The given set is subset ";
					 }
					 else
						 cout<<"\nNot Subset";
	}
};

int main()
{
	Sets s1,s2,inter,uni,diff;
	char ch;int op;	int op1;
			do{
				cout<<"\n\nMAIN MENU: \n1.Insert \n2.Display \n3.Delete \n4.Search \n5.Intersection \n6.Union \n7.Difference \n8.Subset \n Enter your choice : ";
				cin>>op;
				switch(op)
				{

				case 1:		cout<<"\nIn which SET you want to enter: \n1.In 1st SET \n2.In 2nd SET";
							cin>>op1;
							switch(op1)
							{
							case 1:s1.create();break;
							case 2:s2.create();break;
							default: cout<<"You have entered wrong choice";break;
							}
							break;
				case 2:

							cout<<"\n1.Display Set_1 \n2.Display Set_2";
							cin>>op1;
							switch(op1)
							{
							case 1: s1.Contents();
									break;
							case 2: s2.Contents();
									break;
							}
							break;
				case 3:
					cout<<"\n1.Delete in 1st set \n2.Delete in 2nd set";
						cin>>op1;

											switch(op1)
											{
											case 1: s1.remove();
													break;
											case 2: s2.remove();
													break;
											}
											break;


				case 4:
						cout<<"\n1.Search in 1st set \n2.Search in 2nd set";
						cin>>op1;

						switch(op1)
						{
						case 1: s1.search();
								break;
						case 2: s2.search();
								break;
						}
						break;

				case 5:
							cout<<"\nIntersection of the SETS is:";
							inter.intersection(s1,s2);
							inter.Contents();
							break;

				case 6:
							cout<<"\nUnion of the SETs is:";
							s1.unin(s2,uni);
							//uni.Contents();
							break;

				case 7:		int n;
							cout<<"\nSelect 1.A-B 2.B-A : ";
							cin>>n;
							cout<<"\nDifference is:";
							switch(n)
							{
							case 1:	diff.difference(s1,inter);
								diff.Contents();break;
							case 2: diff.difference(s2,inter);
								diff.Contents();break;
							}
							break;
				case 8:
						int m;
						cout<<"\nTo Check whether 1.B is subset of A 2.A is subset of B : ";
						cin>>m;

						switch(m)
						{
				case 1:	s1.subset(s2);
						break;
				case 2: s2.subset(s1);
						break;
						}


							break;
				default: cout<<"\nYou have entered wrong choice";break;
				}
				cout<<"\n\nDo you want Continue with Main Menu:";
				cin>>ch;
			}while(ch!='n');
}
