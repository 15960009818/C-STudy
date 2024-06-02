#ifndef _CDATA_H_
#define _CDATA_H_
#include "CStaff.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "list"
class CData {
public:
    static list<CStaff*> staffList;
    static void staffInit();
};

list<CStaff*> CData::staffList;
#endif