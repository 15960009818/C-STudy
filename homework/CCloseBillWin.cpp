#include"CCloseBillWin.h"
#include"CList.h"
#include"COrder.h"
#include"CMenu.h"
#include"CTools.h"
CCloseBillWin::CCloseBillWin(int x,int y,int width,int height):CWindow(x,y,width,height)
{
	this->title=new CLabel(40,7,0,0,"����");
	this->Label=new CLabel(30,9,0,0,"�����붩��id��");
	this->idEdit=new CEdit(44,9,20,3,"",1,1,8);
	this->orderBtn=new CButton(65,9,7,3,"����");
	this->escBtn=new CButton(78,9,7,3,"����");
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
                cout << "�ö���������" << endl;
                return CLOSEBILLWIN;
            }

            cout << "�������˳ɹ���������" << porder->sum << "Ԫ" << endl;
            cout << "�ö����У�";
            porder->status = 1;
            for (i = 0; i < porder->num; i++) {
                CMenu *pmenu = CMenu::menuJugde(porder->arr[i]);
                cout << porder->numArr[i] << "������Ϊ��" << pmenu->getPrice() << "��" << pmenu->getName() << endl;
            }
            return WAITERWIN;
        case 4:
            return WAITERWIN;

        default:
            return CLOSEBILLWIN;
    }
}