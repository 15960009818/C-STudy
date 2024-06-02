#ifndef _CLIST_H_
#define _CLIST_H_
#include"CData.h"
//节点类
class CNode
{
public:
	CNode();
	~CNode();
	void *pdata;  //数据域：数据的地址 任意指针类型可以赋值给void
	CNode *pnext; //指针域 下一个节点的地址
};
class CList
{
public:
	CList();
	~CList();
	int getCount(); //获取节点个数
	void append(void *data); //尾部追加
	void appendArr(void *Arr[]); //尾部追加
	void insert(CNode *node,int index);
	void deletebypos(CNode *node);
	CNode* findbypos(int pos);
	void printList();
	void free();
	CNode *gethead();
private:
	CNode *head;
	int count;

};

#endif