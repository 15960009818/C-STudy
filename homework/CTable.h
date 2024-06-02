#ifndef _CTABLE_H_
#define _CTABLE_H_ //∑¿÷π÷ÿ∏¥±‡“Î
//int «–ªªΩÁ√Ê±‡∫≈

class CTable
{
public:
	CTable();
	~CTable();
	static int count;
	static int openingTableId;
	static CTable* arr[10];
	int getId();
	int getStatus();
	void setStatus(int status);
private:
	int id;
	int status;

};


#endif