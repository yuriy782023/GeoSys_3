#include <QtTest>

// add necessary includes here

class tst_Base : public QObject
{
    Q_OBJECT

public:
    tst_Base();
    ~tst_Base();

private slots:
    void test_case1();

};

tst_Base::tst_Base()
{

}

tst_Base::~tst_Base()
{

}

void tst_Base::test_case1()
{

}

QTEST_APPLESS_MAIN(tst_Base)

#include "tst_base.moc"
