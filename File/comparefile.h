#ifndef COMPAREFILE_H
#define COMPAREFILE_H

#include "preparefile.h"
#include "../Error/sloterror.h"

class CompareFile
{
public:
    CompareFile();
    static void clearTestDir();
    static void makeDirsForSourceBaseIni_1Base();
    static void makeDirsForSourceBaseIni_manyBases();

    static void absentFile_error(QString testName);
    static void absentFile_goodCondition(QString testName);
    static void absentFile(QString testName);

    static void absentFileNotError(QString testName);

    static void manyFiles_error(QString testName);
    static void manyFiles_goodCondition(QString testName);
    static void manyFiles(QString testName);

    static void zeroFileSize_error(QString testName);
    static void zeroFileSize_goodCondition(QString testName);
    static void zeroFileSize(QString testName);

    static void multFileSize_error(QString testName);
    static void multFileSize_goodCondition(QString testName);
    static void multFileSize(QString testName);
};

#endif // COMPAREFILE_H
