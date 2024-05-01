#include <QtTest>

// add necessary includes here

class tst_Sequence : public QObject
{
    Q_OBJECT

public:
    tst_Sequence();
    ~tst_Sequence();

private slots:
    void test_case1();

};

tst_Sequence::tst_Sequence()
{

}

tst_Sequence::~tst_Sequence()
{

}

void tst_Sequence::test_case1()
{

}

QTEST_APPLESS_MAIN(tst_Sequence)

#include "tst_sequence.moc"
