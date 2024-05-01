#include <QtTest>

// add necessary includes here

class tst_BaseDateTime : public QObject
{
    Q_OBJECT

public:
    tst_BaseDateTime();
    ~tst_BaseDateTime();

private slots:
    void test_case1();

};

tst_BaseDateTime::tst_BaseDateTime()
{

}

tst_BaseDateTime::~tst_BaseDateTime()
{

}

void tst_BaseDateTime::test_case1()
{

}

QTEST_APPLESS_MAIN(tst_BaseDateTime)

#include "tst_basedatetime.moc"
