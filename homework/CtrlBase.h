#ifndef _CTRLBASE_H_
#define _CTRLBASE_H_


enum CtrlType{
	LABEL=1,EDIT,BUTTON
};

class CtrlBase
{
public:
	CtrlBase(int x,int y,int width,int height,char*content,enum CtrlType ctrlType);
	virtual ~CtrlBase();//子类释放 
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	char *getContent();
	enum CtrlType getType();
	void setX(int x);
	void setY(int y);
	void setWidth(int width);
	void setHeight(int height);
	void setContent(char *content);
	void setType(enum CtrlType ctrlType);
    virtual void show(); //虚函数
	virtual void editKeyListen(int ch);
protected:
	int x,y,width,height;
	char content[30];
	enum CtrlType ctrlType;
private:
};


#endif