/*
Beginning with an empty binary search tree, Construct binary search tree by inserting the
values in the order given. After constructing a binary tree -
i. Insert new node
ii. Find number of nodes in longest path
iii. Minimum data value found in the tree
iv. Change a tree so that the roles of the left and right pointers are swapped at
every node
v. Search a value
*/
#include<iostream>
using namespace std;
struct node
{
	int data;
	node * left;
	node * right;
};
class bst
{
	public:
	node * newNode(int );
	node *create(node *);
	node *insert(node *,int);
	void In(node *);//To Print In Inorder Fashion
	int searchElement(node *,int);
	node *swapped(node *);//To swap the roles of left and right pointers
	node *minValue(node *);
	int cLongPath(node *);//To count the nodes in longest path
};
node * bst :: newNode(int d)
{
	node *p=new node;
	p->data=d;
	p->left=NULL;
	p->right=NULL;
	return p;
}
node * bst :: create(node * root)
{
	int d;
	while(1)
	{
		cout<<"Enter The Data To Be Inserted--->";
		cin>>d;
		if(d!=-1)
			root=insert(root,d);
		else 
			break;
	}
	return root;
}

node * bst :: insert(node * root,int d)
{
	if(root==NULL)
		return newNode(d);
	else
	{
		if(d < root->data)
			root->left=insert(root->left,d);
		else if(d > root->data)
			root->right=insert(root->right,d);
		return root;
	}
}
void bst :: In(node *root)
{
	if(root!=NULL)
	{
		In(root->left);
		cout<<root->data<<"\t";
		In(root->right);
	}
}
int bst :: searchElement(node * root,int search)
{
	if(root==NULL)
		return 0;
	else if(root->data==search)
		return 1;
	else
	{
		int b;
		if(search < root->data)
			b=searchElement(root->left,search);
		else
			b=searchElement(root->right,search);
		return b;
	}
}
node * bst :: swapped(node * root)
{
	node * temp;
	if(root==NULL)
		return NULL;
	else
	{
		temp=root->left;
		root->left=swapped(root->right);
		root->right=swapped(temp);
		return root;
	}
}
node * bst :: minValue(node * root)
{
	while(root->left!=NULL)
		root=root->left;
	return root;
}
int bst :: cLongPath(node * root)
{
	if(root==NULL)	
		return 0;
	if(root->left==NULL && root->right==NULL)
		return 1;
	return(max(cLongPath(root->left),cLongPath(root->right))+1);
}
int main()
{
	bst b;
	node *root=NULL,*min,*nRoot;
	int ch,res,search;
	do
	{
		cout<<"\t 1. Insert new node\n";
		cout<<"\t 2. Find number of nodes in longest path\n";
		cout<<"\t 3. Minimum data value found in the tree\n";
		cout<<"\t 4. Search a value\n";
		cout<<"\t 5. Change the roles of left and right node of tree\n";
		cout<<"\t 6. Exit\n";
		cout<<"Enter The Choice--->";
		cin>>ch;
		switch(ch)
		{
			case 1:
				root=b.create(root);
				cout<<"\t\t\tInorder Traversal Is:\n";
				b.In(root);
				cout<<endl;
				break;
			case 2:
				cout<<"Number Of Nodes In Longest Path="<<b.cLongPath(root)<<endl;
				break;
			case 3:
				cout<<"Minimum Value in the Tree is--->";
				min=b.minValue(root);
				cout<<min->data<<"\n";
				break;
			case 4:
				cout<<"\nEnter The Element To Be Searched--->";
				cin>>search;
				res=b.searchElement(root,search);
				if(res==1)
					cout<<"Element Found Successfully\n";
				else
					cout<<"Element Not Found\n";
				break;
			case 5:
				cout<<"Binary Search Tree After Roles Swapped\n";
				nRoot=b.swapped(root);
				b.In(nRoot);
				cout<<endl;
				break;
		}
	}while(ch!=6);
	return 0;
}
/*
*********************OUTPUT
	 1. Insert new node
	 2. Find number of nodes in longest path
	 3. Minimum data value found in the tree
	 4. Search a value
	 5. Change the roles of left and right node of tree
	 6. Exit
Enter The Choice--->1
Enter The Data To Be Inserted--->12
Enter The Data To Be Inserted--->23
Enter The Data To Be Inserted--->5
Enter The Data To Be Inserted--->67
Enter The Data To Be Inserted--->445
Enter The Data To Be Inserted--->78
Enter The Data To Be Inserted--->34
Enter The Data To Be Inserted--->-1
			Inorder Traversal Is:
5	12	23	34	67	78	445	
	 1. Insert new node
	 2. Find number of nodes in longest path
	 3. Minimum data value found in the tree
	 4. Search a value
	 5. Change the roles of left and right node of tree
	 6. Exit
Enter The Choice--->2
Number Of Nodes In Longest Path=5
	 1. Insert new node
	 2. Find number of nodes in longest path
	 3. Minimum data value found in the tree
	 4. Search a value
	 5. Change the roles of left and right node of tree
	 6. Exit
Enter The Choice--->3
Minimum Value in the Tree is--->5
	 1. Insert new node
	 2. Find number of nodes in longest path
	 3. Minimum data value found in the tree
	 4. Search a value
	 5. Change the roles of left and right node of tree
	 6. Exit
Enter The Choice--->4

Enter The Element To Be Searched--->67
Element Found Successfully
	 1. Insert new node
	 2. Find number of nodes in longest path
	 3. Minimum data value found in the tree
	 4. Search a value
	 5. Change the roles of left and right node of tree
	 6. Exit
Enter The Choice--->4

Enter The Element To Be Searched--->450
Element Not Found
	 1. Insert new node
	 2. Find number of nodes in longest path
	 3. Minimum data value found in the tree
	 4. Search a value
	 5. Change the roles of left and right node of tree
	 6. Exit
Enter The Choice--->5
Binary Search Tree After Roles Swapped
445	78	67	34	23	12	5	
	 1. Insert new node
	 2. Find number of nodes in longest path
	 3. Minimum data value found in the tree
	 4. Search a value
	 5. Change the roles of left and right node of tree
	 6. Exit
Enter The Choice--->6

*/
