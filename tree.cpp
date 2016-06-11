#include<vector>

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
	vector<BinTree>	S;
	vector<int>	tag;
	BinTree p =BT;
	while( p!=NULL || !S.empty())
	{
		while(p!=NULL)
		{
			S.push_back(p);
			tag.push_back(0);
			p = p->lchild;
		}
		if( tag.back()==1)
		{
			deep	= deep>S.capacity()? deep:S.capacity();
			S.pop_back();
			tag.pop_back();
			p 	= NULL;
		}
		else
		{
			p = S.back();
			p = p->rchild;
			tag.pop_back();
			tag.push_back(1);
		}
	}
	return deep;
}
