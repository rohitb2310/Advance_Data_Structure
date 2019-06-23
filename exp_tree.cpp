
#include<iostream>

using namespace std;

typedef struct node
{
	char cOp;
	struct node *pLf, *pRt;
}NODE;

class stack
{
	private: NODE *s[20];
			 int top;

	public:
		stack()
		{
			top = -1;
		}
		void push(NODE *pNode)
		{
			top++;
			s[top] = pNode;
		}
		NODE* pop()
		{
			NODE *pNode;
			pNode = s[top];
			top--;
			return(pNode);
		}
		int isEmpty()
		{
			if( top==-1)
				return 1;
			else
				return 0;
		}
		char getTopChar()
		{
			return(s[top]->cOp);
		}

};

class cTree
{
	private:

	public:
		NODE* fCreate();
		//void fInOrder(NODE*);
		//void fNonRecInOrder(NODE*);
		//void fPreOrder(NODE*);
		//void fPostOrder(NODE*);
		void fNonRecPostOrder(NODE *);
};

int priority(char ch)
{
	switch(ch)
	{
		case '+' : return 1; break;
		case '-' : return 1; break;
		case '*' : return 2; break;
		case '/' : return 2; break;

	}
}

NODE* cTree::fCreate()
{
	NODE *pNew, *pCurr ;
	stack oOperator, oOperand;
	char cExpr[20];
	int i;

	cout<< "\nEnter Expression :";
	cin >> cExpr;

	for( i=0; cExpr[i]!='\0' ; i++)
	{
		pNew= new NODE;
		pNew->cOp = cExpr[i];

		if (pNew->cOp=='+' || pNew->cOp=='-' || pNew->cOp=='*' || pNew->cOp=='/')
		{
			char stackChar = oOperator.getTopChar();
			if( priority(stackChar) > priority(pNew->cOp) )
			{
				pCurr = oOperator.pop();
				pCurr->pRt = oOperand.pop();
				pCurr->pLf = oOperand.pop();
				oOperand.push(pCurr);
			}
			oOperator.push(pNew);
		}
		else
			oOperand.push(pNew);
	}//for
	while(oOperator.isEmpty()==0)
	{
		pCurr = oOperator.pop();
		pCurr->pRt = oOperand.pop();
		pCurr->pLf = oOperand.pop();
		oOperand.push(pCurr);
	}
	return(pCurr);
}

void cTree::fNonRecPostOrder(NODE *pCurr)
{
	stack oOne, oTwo;
	//NODE *pParent;
	oOne.push(pCurr);
	while(oOne.isEmpty()==0)
	{
		pCurr = oOne.pop();
		if (pCurr->pLf!=NULL)
			oOne.push(pCurr->pLf);
		if(pCurr->pRt!=NULL)
			oOne.push(pCurr->pRt);
		oTwo.push(pCurr);
	}
	while(oTwo.isEmpty()==0)
	{
		pCurr = oTwo.pop();
		cout<<pCurr->cOp;
	}
}



int main()
{
	cTree oMain;
	NODE *pRoot;
	string sUpdateWord;

	pRoot = oMain.fCreate();
cout<< "\n Non-Recursive Postorder Traversal \n";
	oMain.fNonRecPostOrder(pRoot);

	return 0;
}


