#include"CTable.h"
#include<iostream>
#include"COrder.h"
int CTable::count=0;
int CTable::openingTableId=-1;

CTable* CTable::arr[10]={
	new CTable(),
	new CTable(),
	new CTable(),
	new CTable(),};
using namespace std;
CTable::CTable()
{
	this->id=1001+CTable::count;
	this->status=0;
	CTable::count++;
}

CTable::~CTable()
{

}
int CTable::getId()
{
	return this->id;
}
int CTable::getStatus()
{
	return this->status;
}

void CTable::setStatus(int status)
{
	this->status=status;
}