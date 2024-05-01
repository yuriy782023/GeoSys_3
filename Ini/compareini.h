#ifndef COMPAREINI_H
#define COMPAREINI_H

#include "prepareini.h"
#include "../Error/sloterror.h"
#include "../File/comparefile.h"

class CompareIni
{
public:
    CompareIni();

    static void openIni_error(QString testName);
    static void openIni_goodCondition(QString testName);
    static void openIni(QString testName);
};

#endif // COMPAREINI_H
