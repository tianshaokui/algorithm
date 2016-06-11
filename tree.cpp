#include<stack>
#include<iostream>
using namespace std;

typedef struct
{
	BinTree	*lchild;
	BinTree	*rchild;
	int	value;
}BinTNode, *BinTree;
/*
int FindTreedeep(BinTree BT)
{
	if deep = 0;
	if(BT != NULL)
	{
		int leftdeep	= FindTreedeep(BT->lchild);
		int rightdeep	= FindTreeDeep(BT->rchild);
		deep = leftdeep>rightdeep?leftdeep+1:rightdeep+1;
	}
	return deep;
}
*/
int FindTreedeep(BinTree BT)
{
	int	deep = 0;
	stack<BinTree>	S;
	stack<int>	tag;
	BinTree p =BT;
	while( p!=NULL || !S.empty())
	{
		while(p!=NULL)
		{
			S.push(p);
			tag.push(0);
			p = p->lchild;
		}
		if( tag.back()==1)
		{
			deep	= deep>S.size()? deep:S.size();
			S.pop();
			tag.pop();
			p 	= NULL;
		}
		else
		{
			p = S.top();
			p = p->rchild;
			tag.pop();
			tag.push(1);
		}
	}
	return deep;
}

void PreOrder(BinTree BT)
{
	stack<BinTree>	S;
	BinTree		p = BT;
	while( p!=NULL || !S.empty())
	{
		if( p!=NULL)
		{
			S.push(p);
			cout<<p->value<<endl;
			p = p->lchild;
		}
		else
		{
			p = S.top();
			S.pop();
			p = p->rchild;
		}

	}
}
void InOrder(BinTree BT)
{
	stack<BinTree>	S;
	BinTree		p = BT;
	while( p!=NULL || !S.empty())
	{
		if(p!=NULL)
		{
			S.push(p);
			p = p->lchild;
		}
		else
		{
			p = S.top();
			cout<<p->value<<endl;
			S.pop();
			p = p->rchild;
		}
	}
}

void PostOrder(BinTree BT)
{
	struct BiNodePost
	{
		BiNodePost(BinTree b, char t): biTree(b), tag(t) {}
		BinTree biTree;
		char tag;
	};
	stack<BiNodePost> S;
	BinTree		p = BT;
	BiNodePost	post;
	
	while( p!=NULL || !S.empty())
	{
		while(p != NULL)
		{
			S.push(BiNodePost(p, 'L'));
			p = p->lchild;
		}
		while( !S.empty() && S.top().tag=='R')
		{
			post = S.top();
			S.pop();
			cout<<post.biTree->value<<endl;
		}
		if( !S.empty())
		{
			post = S.top();
			post.tag = 'R';
			p = post.biTree;
			p = p->rchild;
		}
	}
}











