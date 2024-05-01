#include "preparefile.h"

PrepareFile::PrepareFile()
{
}

void PrepareFile::clearTestDir()
{
    QDir dir(TESTDIR);

    dir.removeRecursively();
    dir.mkpath(TESTDIR);
}

void PrepareFile::makeDirsForSourceBaseIni()
{
    QDir().mkdir(TESTDIR + "/source");
    QDir().mkdir(TESTDIR + "/base");
    QDir().mkdir(TESTDIR + "/ini");
}

void PrepareFile::makeDirsForSourceBaseIni(int qntBases)
{
    for (int cntBases = 0; cntBases < qntBases; cntBases++) {
        QDir().mkdir(TESTDIR + "/source" + QString::number(cntBases));
        QDir().mkdir(TESTDIR + "/base" + QString::number(cntBases));
        QDir().mkdir(TESTDIR + "/ini" + QString::number(cntBases));
    }
}

void PrepareFile::goodFile(QString fileName, int size)
{
    clearTestDir();
    QByteArray data(size, 'a');
    QFile makeFile(fileName);
    makeFile.open(QIODevice::WriteOnly);
    makeFile.write(data);
    makeFile.close();
}

void PrepareFile::manyFiles(QString fileName1, QString fileName2)
{
    clearTestDir();
    QFile file1(fileName1), file2(fileName2);
    file1.open(QIODevice::WriteOnly);
    file1.close();
    file2.open(QIODevice::WriteOnly);
    file2.close();
}

void PrepareFile::zeroFileSize(QString fileName)
{
    clearTestDir();
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    file.close();
}



