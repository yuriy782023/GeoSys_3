#include <QtTest>

// add necessary includes here

class tst_InputtedFiles : public QObject
{
    Q_OBJECT

public:
    tst_InputtedFiles();
    ~tst_InputtedFiles();

private slots:
    void test_case1();

};

tst_InputtedFiles::tst_InputtedFiles()
{

}

tst_InputtedFiles::~tst_InputtedFiles()
{

}

void tst_InputtedFiles::test_case1()
{

}

QTEST_APPLESS_MAIN(tst_InputtedFiles)

#include "tst_inputtedfiles.moc"
