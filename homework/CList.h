#ifndef _CLIST_H_
#define _CLIST_H_
#include"CData.h"
//�ڵ���
class CNode
{
public:
	CNode();
	~CNode();
	void *pdata;  //���������ݵĵ�ַ ����ָ�����Ϳ��Ը�ֵ��void
	CNode *pnext; //ָ���� ��һ���ڵ�ĵ�ַ
};
class CList
{
public:
	CList();
	~CList();
	int getCount(); //��ȡ�ڵ����
	void append(void *data); //β��׷��
	void appendArr(void *Arr[]); //β��׷��
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