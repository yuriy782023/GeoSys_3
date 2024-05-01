#include <QtTest>

// add necessary includes here
#include "compareini.h"

class tst_Ini : public QObject
{
    Q_OBJECT

public:
    tst_Ini();
    ~tst_Ini();

private slots:
    void test_openIni();
public:
    void test_readIni();

};

tst_Ini::tst_Ini()
{

}

tst_Ini::~tst_Ini()
{

}

void tst_Ini::test_openIni()
{
    CompareIni::openIni("ini");
}

void tst_Ini::test_readIni()
{
    QVERIFY(0);
}

QTEST_APPLESS_MAIN(tst_Ini)

#include "tst_ini.moc"
