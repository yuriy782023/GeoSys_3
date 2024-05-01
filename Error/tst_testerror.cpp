#include <QtTest>

// add necessary includes here
#include "sloterror.h"
#include "error.h"
#include "compareerror.h"

class TestError : public QObject
{
    Q_OBJECT

public:
    TestError();
    ~TestError();

private slots:
    void test_absentFile();
    void test_absentFileNotError();
    void test_absentDescription();
    void test_absentBase();
    void test_absentSource();
    void test_absentAnySources();
    void test_absentSourcesForInput();
    void test_absentIni();
    void test_absentInputted();

    void test_manyFiles();
    void test_manyDescriptions();
    void test_manyBases();
    void test_manySources();
    void test_manyInies();
    void test_manyInputtedes();

    void test_zeroFileSize();
    void test_multFileSize();
    void test_notAccessFile();
    void test_createFile();
    void test_notCreateFile();

    void test_notReadFile();

    void test_notValidDateTime();
    void test_outOfRangeDateTime();
    void test_notValidDateTimePeriod();
    void test_notValidChannelValue();
    void test_outOfRangeChannelValue();

    void test_baseVersionError();
    void test_lockBase();

private:
};

TestError::TestError() {}

TestError::~TestError() {}

void TestError::test_absentFile()
{
    Error error;
    CompareError::absentFile(&error);
}

void TestError::test_absentFileNotError()
{
    Error error;
    CompareError::absentFileNotError(&error);
}

void TestError::test_absentDescription()
{
    SlotError slotError(TESTDIR + "/base/_abddata.abd");
    Error error;

    QVERIFY(connect(&error, SIGNAL(journalOut(Journal)), &slotError, SLOT(absentDescription(Journal))));
    error.absentFile(TESTDIR + "/base/_abddata.abd");
    QVERIFY(slotError.getCheckSlotError());
}

void TestError::test_absentBase()
{
    SlotError slotError(TESTDIR + "/base/base.abd");
    Error error;

    QVERIFY(connect(&error, SIGNAL(journalOut(Journal)), &slotError, SLOT(absentBase(Journal))));
    error.absentFileNotError(TESTDIR + "/base/base.abd");
    QVERIFY(slotError.getCheckSlotError());
}

void TestError::test_absentSource()
{
    SlotError slotError(TESTDIR + "/source/source.d");
    Error error;

    QVERIFY(connect(&error, SIGNAL(journalOut(Journal)), &slotError, SLOT(absentSource(Journal))));
    error.absentFile(TESTDIR + "/source/source.d");
    QVERIFY(slotError.getCheckSlotError());
}

void TestError::test_absentAnySources()
{
    SlotError slotError("testpath");
    Error error;

    QVERIFY(connect(&error, SIGNAL(journalOut(Journal)), &slotError, SLOT(absentAnySources(Journal))));
    error.absentAnySources("testpath");
    QVERIFY(slotError.getCheckSlotError());
}

void TestError::test_absentSourcesForInput()
{
    SlotError slotError("testpath");
    Error error;

    QVERIFY(connect(&error, SIGNAL(journalOut(Journal)), &slotError, SLOT(absentSourcesForInput(Journal))));
    error.absentSourcesForInput("testpath");
    QVERIFY(slotError.getCheckSlotError());
}

void TestError::test_absentIni()
{
    SlotError slotError(TESTDIR + "/ini/ini.ini");
    Error error;

    QVERIFY(connect(&error, SIGNAL(journalOut(Journal)), &slotError, SLOT(absentIni(Journal))));
    error.absentFile(TESTDIR + "/ini/ini.ini");
    QVERIFY(slotError.getCheckSlotError());
}

void TestError::test_absentInputted()
{
    SlotError slotError(TESTDIR + "/source/inputtedfiles.jrn");
    Error error;

    QVERIFY(connect(&error, SIGNAL(journalOut(Journal)), &slotError, SLOT(absentInputted(Journal))));
    error.absentFileNotError(TESTDIR + "/source/inputtedfiles.jrn");
    QVERIFY(slotError.getCheckSlotError());
}

void TestError::test_manyFiles()
{
    Error error;
    CompareError::manyFiles(&error);
}

void TestError::test_manyDescriptions()
{
    SlotError slotError(TESTDIR + "/base/_abddata.abd");
    Error error;

    QVERIFY(connect(&error, SIGNAL(journalOut(Journal)), &slotError, SLOT(manyDescriptions(Journal))));
    error.manyFiles(TESTDIR + "/base/_abddata.abd");
    QVERIFY(slotError.getCheckSlotError());
}

void TestError::test_manyBases()
{
    SlotError slotError(TESTDIR + "/base/base1.abd");
    Error error;

    QVERIFY(connect(&error, SIGNAL(journalOut(Journal)), &slotError, SLOT(manyBases(Journal))));
    error.manyFiles(TESTDIR + "/base/base1.abd");
    QVERIFY(slotError.getCheckSlotError());
}

void TestError::test_manySources()
{
    SlotError slotError(TESTDIR + "/source/source.d");
    Error error;

    QVERIFY(connect(&error, SIGNAL(journalOut(Journal)), &slotError, SLOT(manySources(Journal))));
    error.manyFiles(TESTDIR + "/source/source.d");
    QVERIFY(slotError.getCheckSlotError());
}

void TestError::test_manyInies()
{
    SlotError slotError(TESTDIR + "/ini/ini.ini");
    Error error;

    QVERIFY(connect(&error, SIGNAL(journalOut(Journal)), &slotError, SLOT(manyInies(Journal))));
    error.manyFiles(TESTDIR + "/ini/ini.ini");
    QVERIFY(slotError.getCheckSlotError());
}

void TestError::test_manyInputtedes()
{
    SlotError slotError(TESTDIR + "/source/inputtedfiles.jrn");
    Error error;

    QVERIFY(connect(&error, SIGNAL(journalOut(Journal)), &slotError, SLOT(manyInputtedes(Journal))));
    error.manyFiles(TESTDIR + "/source/inputtedfiles.jrn");
    QVERIFY(slotError.getCheckSlotError());
}

void TestError::test_zeroFileSize()
{
    Error error;
    CompareError::zeroFileSize(&error);
}

void TestError::test_multFileSize()
{
    Error error;
    CompareError::multFileSize(&error);
}

void TestError::test_notAccessFile()
{
    Error error;
    CompareError::notAccessFile(&error, "Permission denied");
}

void TestError::test_createFile()
{
    Error error;
    CompareError::createFile(&error);
}

void TestError::test_notCreateFile()
{
    Error error;
    CompareError::notCreateFile(&error, "Permission denied");
}

void TestError::test_notReadFile()
{
    Error error;
    CompareError::notReadFile(&error, "Unknown error");
}

void TestError::test_notValidDateTime()
{
    Error error;
    CompareError::notValidDateTime(&error);
}

void TestError::test_outOfRangeDateTime()
{
    Error error;
    CompareError::outOfRangeDateTime(&error);
}

void TestError::test_notValidDateTimePeriod()
{
    Error error;
    CompareError::notValidDateTimePeriod(&error);
}

void TestError::test_notValidChannelValue()
{
    Error error;
    CompareError::notValidChannelValue(&error);
}

void TestError::test_outOfRangeChannelValue()
{
    Error error;
    CompareError::outOfRangeChannelValue(&error);
}

void TestError::test_baseVersionError()
{
    Error error;
    CompareError::baseVersionError(&error);
}

void TestError::test_lockBase()
{
    Error error;
    CompareError::lockBase(&error);
}

QTEST_APPLESS_MAIN(TestError)

#include "tst_testerror.moc"
