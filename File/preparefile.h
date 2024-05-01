#ifndef TESTPREPAREFILE_H
#define TESTPREPAREFILE_H

#include <QDir>

#include "file.h"

#define TESTDIR QDir::currentPath() + "/test"

class PrepareFile
{
public:
    PrepareFile();
    static void clearTestDir();
    static void makeDirsForSourceBaseIni();
    static void makeDirsForSourceBaseIni(int qntBases);
    static void goodFile(QString fileName, int size);
    static void manyFiles(QString fileName1, QString fileName2);
    static void zeroFileSize(QString fileName);
};

#endif // TESTPREPAREFILE_H
