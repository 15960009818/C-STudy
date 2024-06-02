#ifndef _CEDIT_H_ 
#define _CEDIT_H_
#include"CtrlBase.h"

class CEdit:public CtrlBase
{
public:
	CEdit(int x,int y,int width,int height ,char*content ,int inputType,int mode,int maxLen);
	~CEdit();
	void show();
	void editKeyListen(int ch);
	int getInputType();
	int getMode();
	int getMaxLen();
	void setInputType(int inputType);
	void setMode(int mode);
	void setMaxLen(int maxlen);

protected:
private:
	int inputType;//�������� 1-���� 2-��ĸ 3-������ĸ 4-����
	int mode;  //��ʾģʽ 1-����  0-����
	int maxLen; //����������󳤶�

};
#endif