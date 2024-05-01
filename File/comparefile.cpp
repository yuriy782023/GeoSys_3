#include "comparefile.h"

CompareFile::CompareFile()
{

}

void CompareFile::clearTestDir()
{
    PrepareFile::clearTestDir();
    QFile clearTestDirFile(TESTDIR + "/clearTestDirFile.tst");
    clearTestDirFile.open(QIODevice::WriteOnly);
    clearTestDirFile.close();
    QCOMPARE(QFile::exists(TESTDIR + "/clearTestDirFile.tst"), true);

    PrepareFile::clearTestDir();
    QCOMPARE(QFile::exists(TESTDIR + "/clearTestDirFile.tst"), false);
}

void CompareFile::makeDirsForSourceBaseIni_1Base()
{
    PrepareFile::clearTestDir();

    QDir makeDirs;
    QCOMPARE(makeDirs.exists(TESTDIR + "/source"), false);
    QCOMPARE(makeDirs.exists(TESTDIR + "/base"), false);
    QCOMPARE(makeDirs.exists(TESTDIR + "/ini"), false);

    PrepareFile::makeDirsForSourceBaseIni();
    QCOMPARE(makeDirs.exists(TESTDIR + "/source"), true);
    QCOMPARE(makeDirs.exists(TESTDIR + "/base"), true);
    QCOMPARE(makeDirs.exists(TESTDIR + "/ini"), true);
}

void CompareFile::makeDirsForSourceBaseIni_manyBases()
{
    PrepareFile::clearTestDir();

    QDir makeDirs;
    QCOMPARE(makeDirs.exists(TESTDIR + "/source0"), false);
    QCOMPARE(makeDirs.exists(TESTDIR + "/base0"), false);
    QCOMPARE(makeDirs.exists(TESTDIR + "/ini0"), false);
    QCOMPARE(makeDirs.exists(TESTDIR + "/source1"), false);
    QCOMPARE(makeDirs.exists(TESTDIR + "/base1"), false);
    QCOMPARE(makeDirs.exists(TESTDIR + "/ini1"), false);
    QCOMPARE(makeDirs.exists(TESTDIR + "/source2"), false);
    QCOMPARE(makeDirs.exists(TESTDIR + "/base2"), false);
    QCOMPARE(makeDirs.exists(TESTDIR + "/ini2"), false);

    PrepareFile::makeDirsForSourceBaseIni(3);
    QCOMPARE(makeDirs.exists(TESTDIR + "/source0"), true);
    QCOMPARE(makeDirs.exists(TESTDIR + "/base0"), true);
    QCOMPARE(makeDirs.exists(TESTDIR + "/ini0"), true);
    QCOMPARE(makeDirs.exists(TESTDIR + "/source1"), true);
    QCOMPARE(makeDirs.exists(TESTDIR + "/base1"), true);
    QCOMPARE(makeDirs.exists(TESTDIR + "/ini1"), true);
    QCOMPARE(makeDirs.exists(TESTDIR + "/source2"), true);
    QCOMPARE(makeDirs.exists(TESTDIR + "/base2"), true);
    QCOMPARE(makeDirs.exists(TESTDIR + "/ini2"), true);
}

void CompareFile::absentFile_error(QString testName)
{
    File file(TESTDIR + "/absentfile_error." + testName);
    SlotError slotError(file.getFileName());

    QVERIFY(QObject::connect(&file, &File::journalOut, &slotError, &SlotError::absentFile));

    PrepareFile::clearTestDir();
    QVERIFY( ! file.absentFile());
    QVERIFY(slotError.getCheckSlotError());
}

void CompareFile::absentFile_goodCondition(QString testName)
{
    File file(TESTDIR + "/absentfile_good." + testName);
    SlotError slotError(file.getFileName());

    QVERIFY(QObject::connect(&file, &File::journalOut, &slotError, &SlotError::absentFile));

    PrepareFile::goodFile(file.getFileName(), 1);
    QVERIFY(file.absentFile());
    QVERIFY( ! slotError.getCheckSlotError());
}

void CompareFile::absentFile(QString testName)
{
    absentFile_error(testName);
    absentFile_goodCondition(testName);
}

void CompareFile::absentFileNotError(QString testName)
{
    File file(TESTDIR + "/create." + testName);
    SlotError slotError(file.getFileName());

    QVERIFY(QObject::connect(&file, &File::journalOut, &slotError, &SlotError::absentFileNotError));

    PrepareFile::clearTestDir();
    file.absentFileNotError();
    QVERIFY(slotError.getCheckSlotError());
}

void CompareFile::manyFiles_error(QString testName)
{
    File file(TESTDIR + "/manyfiles_error." + testName);
    SlotError slotError(file.getFileName());

    QVERIFY(QObject::connect(&file, &File::journalOut, &slotError, &SlotError::manyFiles));

    PrepareFile::manyFiles(TESTDIR + "/Manyfiles_error." + testName, TESTDIR + "/manyfiles_error." + testName);
    QVERIFY( ! file.manyFiles());
    QVERIFY(slotError.getCheckSlotError());
}

void CompareFile::manyFiles_goodCondition(QString testName)
{
    File file(TESTDIR + "/manyfiles_good." + testName);
    SlotError slotError(file.getFileName());

    QVERIFY(QObject::connect(&file, &File::journalOut, &slotError, &SlotError::manyFiles));

    PrepareFile::goodFile(file.getFileName(), 1);
    QVERIFY(file.manyFiles());
    QVERIFY( ! slotError.getCheckSlotError());
}

void CompareFile::manyFiles(QString testName)
{
    manyFiles_error(testName);
    manyFiles_goodCondition(testName);
}

void CompareFile::zeroFileSize_error(QString testName)
{
    File file(TESTDIR + "/zerofilesize_error." + testName);
    SlotError slotError(file.getFileName());

    QVERIFY(QObject::connect(&file, &File::journalOut, &slotError, &SlotError::zeroFileSize));

    PrepareFile::zeroFileSize(file.getFileName());
    QVERIFY( ! file.zeroFileSize());
    QVERIFY(slotError.getCheckSlotError());
}

void CompareFile::zeroFileSize_goodCondition(QString testName)
{
    File file(TESTDIR + "/zerofilesize_good." + testName);
    SlotError slotError(file.getFileName());

    QVERIFY(QObject::connect(&file, &File::journalOut, &slotError, &SlotError::zeroFileSize));

    PrepareFile::goodFile(file.getFileName(), 1);
    QVERIFY(file.zeroFileSize());
    QVERIFY( ! slotError.getCheckSlotError());
}

void CompareFile::zeroFileSize(QString testName)
{
    zeroFileSize_error(testName);
    zeroFileSize_goodCondition(testName);
}

void CompareFile::multFileSize_error(QString testName)
{
    File file(TESTDIR + "/multfilesize_error." + testName);
    SlotError slotError(file.getFileName());

    QVERIFY(QObject::connect(&file, &File::journalOut, &slotError, &SlotError::multFileSize));

    PrepareFile::goodFile(file.getFileName(), 7);
    QVERIFY( ! file.multFileSize(2));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareFile::multFileSize_goodCondition(QString testName)
{
    File file(TESTDIR + "/multfilesize_good." + testName);
    SlotError slotError(file.getFileName());

    QVERIFY(QObject::connect(&file, &File::journalOut, &slotError, &SlotError::multFileSize));

    PrepareFile::goodFile(file.getFileName(), 2);
    QVERIFY(file.multFileSize(2));
    QVERIFY( ! slotError.getCheckSlotError());
}

void CompareFile::multFileSize(QString testName)
{
    multFileSize_error(testName);
    multFileSize_goodCondition(testName);
}

