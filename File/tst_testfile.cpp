#include <QtTest>

// add necessary includes here
#include "comparefile.h"

class TestFile : public QObject
{
    Q_OBJECT

public:

private slots:
    void test_clearTestDir();
    void test_makeDirsForSourceBaseIni_1Base();
    void test_makeDirsForSourceBaseIni_manyBases();

    void test_absentFile();
    void test_absentFileNotError();
    void test_manyFiles();
    void test_zeroFileSize();
    //void test_zeroSize_source();
    //void test_zeroSize_baseDescription();
    //void test_zeroSize_base();
    //void test_zeroSize_ini();
    void test_multFileSize();
    //void test_constructor();
};

void TestFile::test_clearTestDir()
{
    CompareFile::clearTestDir();
}

void TestFile::test_makeDirsForSourceBaseIni_1Base()
{
    CompareFile::makeDirsForSourceBaseIni_1Base();
}

void TestFile::test_makeDirsForSourceBaseIni_manyBases()
{
    CompareFile::makeDirsForSourceBaseIni_manyBases();
}

void TestFile::test_absentFile()
{
    CompareFile::absentFile("file");
}

void TestFile::test_absentFileNotError()
{
    CompareFile::absentFileNotError("file");
}

void TestFile::test_manyFiles()
{
    CompareFile::manyFiles("file");
}

void TestFile::test_zeroFileSize()
{
    CompareFile::zeroFileSize("file");
}

/*void TestFile::test_zeroSize_source()
{
    TestPrepareFile::zeroSize();
    File file(TESTDIR + "/file.file", File::Type::Source);
    file.zeroSize();
    TestCompareFile::zeroSize(file, file.fileName());
    QVERIFY(checkCompareFile);
}*/

/*void TestFile::test_zeroSize_baseDescription()
{
    TestPrepareFile::zeroSize();
    File file(TESTDIR + "/file.file", File::Type::BaseDescription);
    file.zeroSize();
    TestCompareFile::zeroSize(file, file.fileName());
    QVERIFY(checkCompareFile);
}*/

/*void TestFile::test_zeroSize_base()
{
    TestPrepareFile::zeroSize();
    File file(TESTDIR + "/file.file", File::Type::Base);
    file.zeroSize();
    TestCompareFile::goodCondition(file);
    QVERIFY(checkCompareFile);
}*/

/*void TestFile::test_zeroSize_ini()
{
    QVERIFY(0);
}*/

void TestFile::test_multFileSize()
{
    CompareFile::multFileSize("file");
}

/*void TestFile::test_constructor()
{
    //File file(TESTDIR + "test.file", File::Type::Source);
    TestCompareFile testCompareFile;
    //testCompareFile.goodCondition(file);
    //QVERIFY(testCompareFile.getCheckCompareFile());
}*/

QTEST_APPLESS_MAIN(TestFile)

#include "tst_testfile.moc"
