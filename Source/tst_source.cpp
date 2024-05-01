#include <QtTest>

// add necessary includes here
#include "comparesource.h"

class tst_Source : public QObject
{
    Q_OBJECT

public:
    tst_Source();
    ~tst_Source();

private slots:
    void test_openSource();
    void test_readSourceString();
    void test_dateTimeByteNumber();
    void test_channelByteNumber();
    void test_dateTimeValid();
    void test_dateTimeRange();
    void test_dateTimePeriodValid();
    void test_channelsValid(); // all channels
    void test_isChannelsInRange(); // all channels
public:
    void test_channel(); // 1 channel
};

tst_Source::tst_Source()
{

}

tst_Source::~tst_Source()
{

}

void tst_Source::test_openSource()
{
    CompareSource::openSource("source");
}

void tst_Source::test_readSourceString()
{
    CompareSource::readSourceString("source");
}

void tst_Source::test_dateTimeByteNumber()
{
    CompareSource::dateTimeByteNumber("source");
}

void tst_Source::test_channelByteNumber()
{
    CompareSource::channelByteNumber("source");
}

void tst_Source::test_dateTimeValid()
{
    CompareSource::dateTimeValid("source");
}

void tst_Source::test_dateTimeRange()
{
    CompareSource::dateTimeRange("source");
}

void tst_Source::test_dateTimePeriodValid()
{
    CompareSource::dateTimePeriodValid("source");
}

void tst_Source::test_channelsValid()
{
    CompareSource::channelValid("source");
}

void tst_Source::test_isChannelsInRange()
{
    CompareSource::channelRange("source");
}

void tst_Source::test_channel()
{
    QVERIFY(0);
}

QTEST_APPLESS_MAIN(tst_Source)

#include "tst_source.moc"
