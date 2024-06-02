#include"CCloseBillWin.h"
#include"CList.h"
#include"COrder.h"
#include"CMenu.h"
#include"CTools.h"
CCloseBillWin::CCloseBillWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	this->title=new CLabel(40,7,0,0,"结账");
	this->Label=new CLabel(30,9,0,0,"请输入订单id：");
	this->idEdit=new CEdit(44,9,20,3,"",1,1,8);
	this->orderBtn=new CButton(65,9,7,3,"结账");
	this->escBtn=new CButton(78,9,7,3,"返回");
	this->addCtrl(this->title);//0
	this->addCtrl(this->Label);//1
	this->addCtrl(this->idEdit);//2
	this->addCtrl(this->orderBtn);//3
	this->addCtrl(this->escBtn);//4
}

CCloseBillWin::~CCloseBillWin()
{

}

int CCloseBillWin::doAction() {
    int id = atoi(this->idEdit->getContent());
    int flag = 0;
    int i = 0;
    CNode *ptmp = COrder::head->gethead();
    COrder *porder = NULL;
    switch (this->ctrl_index) {
        case 3:

            while (ptmp->pnext != NULL) {
                ptmp = ptmp->pnext;
                porder = static_cast<COrder *>(ptmp->pdata);
                if (porder->getId() == id && porder->getStatus() == 0) {
                    flag = 1;
                    break;
                }
            }
            CTools::gotoxy(30, 20);
            if (flag == 0) {
                cout << "该订单不存在" << endl;
                return CLOSEBILLWIN;
            }

            cout << "订单结账成功，消费了" << porder->sum << "元" << endl;
            cout << "该订单有：";
            porder->status = 1;
            for (i = 0; i < porder->num; i++) {
                CMenu *pmenu = CMenu::menuJugde(porder->arr[i]);
                cout << porder->numArr[i] << "个单价为：" << pmenu->getPrice() << "的" << pmenu->getName() << endl;
            }
            return WAITERWIN;
        case 4:
            return WAITERWIN;

        default:
            return CLOSEBILLWIN;
    }
}