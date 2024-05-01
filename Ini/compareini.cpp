#include "compareini.h"

CompareIni::CompareIni()
{
}

void CompareIni::openIni_error(QString testName)
{
    QVERIFY(0);
}

void CompareIni::openIni_goodCondition(QString testName)
{
    QVERIFY(0);
}

void CompareIni::openIni(QString testName)
{
    CompareFile::absentFile(testName);
    CompareFile::manyFiles(testName);
    CompareFile::zeroFileSize(testName);
    openIni_error(testName);
    //openIni_goodCondition(testName);
}


