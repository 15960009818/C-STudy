#include"CList.h"
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;



CNode::CNode()
{
	this->pdata=NULL;
	this->pnext=NULL;
}

CNode::~CNode()
{
}

CList::CList()
{
	this->head=new CNode();
	this->count=0;
}

CList::~CList()
{
}
CNode *CList::gethead()
{
	return this->head;
}
int CList::getCount()
{
	return this->count;
}

void CList::insert(CNode *node,int index)
{
	CNode*ptmp=this->head;
	int count=1;
	while(ptmp->pnext!=NULL)
	{
		ptmp=ptmp->pnext;
		if(count==index)
		{
			node->pnext=ptmp->pnext;
			ptmp->pnext=node;
			return ;
		}
		count++;
	}
}
void CList::deletebypos(CNode *node)
{
	
	CNode *ptmphead=this->head;
	CNode *ptmp=ptmphead->pnext;
	while(ptmp!=NULL)
	{
		if(ptmp==node)
		{
			ptmphead->pnext=ptmp->pnext;
			delete ptmp; 
		}
		ptmphead=ptmphead->pnext;
		ptmp=ptmp->pnext;
	}
}
CNode* CList::findbypos(int pos)
{

	CNode*ptmp=this->head;
	int count=1;
	while(ptmp->pnext!=NULL)
	{
		ptmp=ptmp->pnext;
		if(count==pos)
		{
			return ptmp;
		}
		count++;
	}
	return NULL;
}
void CList::append(void *data)
{
	CNode*ptmp=this->head;
	while(ptmp->pnext!=NULL)
	{
		ptmp=ptmp->pnext;
	}
	CNode*newNode= new CNode();
	ptmp->pnext=newNode;
	newNode->pdata=data;
	this->count++;
}	

void CList::appendArr(void *Arr[])
{
	CNode*ptmp=this->head;
	while(ptmp->pnext!=NULL)
	{
		ptmp=ptmp->pnext;
	} 
	for(int i=0;i<sizeof(Arr)/4;i++)
	{
		CNode*newNode= new CNode();
		ptmp->pnext=newNode;
		newNode->pdata=Arr[i];
		ptmp=ptmp->pnext;
	}
}
void CList::printList()
{
	CNode*ptmp=this->head;
	while(ptmp->pnext!=NULL)
	{
		ptmp=ptmp->pnext;
		cout<<1;
	}
}
void CList::free()
{
	CNode*ptmp=this->head;
	while(ptmp!=NULL)
	{
		this->head=this->head->pnext;
		delete ptmp->pdata;
		delete ptmp;
		this->count--;
		ptmp=head;
	}

}
/*
LIST_T* list_init()
{
	LIST_T*head=(LIST_T*)malloc(sizeof(LIST_T));
	if(head==NULL)
	{
		printf("open space error\n");
		exit(0);
	}
	head->pdata=NULL;//������
	head->pnext=NULL;//ָ����
	return head;
}


void list_append(LIST_T*head,void *data)
{
	LIST_T *ptmp=head,*newNode=NULL;
	while(ptmp->pnext!=NULL)
	{
		ptmp=ptmp->pnext;
		
	}
	newNode =(LIST_T*)malloc(sizeof(LIST_T));
	if(newNode==NULL)
	{
		printf("open space error\n");
		exit(0);
	}
	memset(newNode,0,sizeof(LIST_T));
	newNode->pdata=data;//������
	newNode->pnext=NULL;//ָ����
	ptmp->pnext=newNode;
}

//3.��ȡ�ڵ����
int list_count(LIST_T*head)
{
	int count=0;
	LIST_T *ptmp=head;
	while(ptmp->pnext!=NULL)
	{
		ptmp=ptmp->pnext;
		count++;
	}
	return count;
}
//4.��ȡ�ڵ���Ϣbyindex
void *list_index(LIST_T*head,int index)
{
	int count=0;
	LIST_T *ptmp=head;
	while(ptmp->pnext!=NULL)
	{
		ptmp=ptmp->pnext;
		count++;
		if(count==index)
		{
			return ptmp->pdata;//���ؽڵ��������
		}
	} 
	return NULL;

}
//5.����ڵ� pos
void list_insert(LIST_T*head,int index,void *data)
{
	int count=0;
	LIST_T *ptmp=head,*newNode=NULL;
	while(ptmp->pnext!=NULL)
	{
		ptmp=ptmp->pnext;
		count++;
		if(count==index)
		{
			
			newNode =(LIST_T*)malloc(sizeof(LIST_T));
			if(newNode==NULL)
			{
				printf("open space error\n");
				exit(0);
			}
			memset(newNode,0,sizeof(LIST_T));
			newNode->pdata=data;//������
			newNode->pnext=ptmp->pnext;//ָ����
			ptmp->pnext=newNode;
			return;
		}
	} 
}

//6.ɾ���ڵ� pos
void list_erase(LIST_T*head,int index)
{
	int count=0;
	LIST_T *pre=head,*ptmp=head->pnext;
	while(ptmp!=NULL)
	{
		count++;
		if(count==index)
		{
			pre->pnext=ptmp->pnext;
			free(ptmp->pdata);//�ͷ�������
			free(ptmp);		//�ͷŽڵ�
			return;
		}
		pre=pre->pnext;
		ptmp=ptmp->pnext;
	} 

}

//7.�ͷ����� free
void freeList(LIST_T*head)
{

	LIST_T *pre=head,*ptmp=head->pnext;
	while(ptmp!=NULL)
	{

		pre->pnext=ptmp->pnext;
		free(ptmp->pdata);//�ͷ�������
		free(ptmp);		//�ͷŽڵ�
		pre=pre->pnext;
		ptmp=ptmp->pnext;
	} 
}
*/