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
	int inputType;//输入类型 1-数字 2-字母 3-数字字母 4-中文
	int mode;  //显示模式 1-明文  0-密文
	int maxLen; //允许输入最大长度

};
#endif