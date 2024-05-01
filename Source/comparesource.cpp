#include "comparesource.h"

CompareSource::CompareSource()
{
}

void CompareSource::checkGoodSourceDateTime(SourceString::DateTime checkingSourceDateTime)
{
    SourceString::DateTime goodSourceDateTime = PrepareSource::fillSourceDateTime();
    QCOMPARE(checkingSourceDateTime.year.high, goodSourceDateTime.year.high);
    QCOMPARE(checkingSourceDateTime.year.low, goodSourceDateTime.year.low);
    QCOMPARE(checkingSourceDateTime.month, goodSourceDateTime.month);
    QCOMPARE(checkingSourceDateTime.day, goodSourceDateTime.day);
    QCOMPARE(checkingSourceDateTime.hour, goodSourceDateTime.hour);
    QCOMPARE(checkingSourceDateTime.minute, goodSourceDateTime.minute);
    QCOMPARE(checkingSourceDateTime.second, goodSourceDateTime.second);
}

void CompareSource::checkGoodSourceString(SourceString checkingSourceString)
{
    SourceString goodSourceString = PrepareSource::fillSourceString();
    checkGoodSourceDateTime(checkingSourceString.dateTime);

    QCOMPARE(checkingSourceString.channels.measure[0], goodSourceString.channels.measure[0]);
    QCOMPARE(checkingSourceString.channels.measure[1], goodSourceString.channels.measure[1]);
    QCOMPARE(checkingSourceString.channels.measure[2], goodSourceString.channels.measure[2]);
    QCOMPARE(checkingSourceString.channels.measure[3], goodSourceString.channels.measure[3]);
    QCOMPARE(checkingSourceString.channels.measure[4], goodSourceString.channels.measure[4]);
    QCOMPARE(checkingSourceString.channels.measure[5], goodSourceString.channels.measure[5]);
    QCOMPARE(checkingSourceString.channels.measure[6], goodSourceString.channels.measure[6]);
    QCOMPARE(checkingSourceString.channels.measure[7], goodSourceString.channels.measure[7]);
    QCOMPARE(checkingSourceString.channels.measure[8], goodSourceString.channels.measure[8]);
    QCOMPARE(checkingSourceString.channels.measure[9], goodSourceString.channels.measure[9]);
    QCOMPARE(checkingSourceString.channels.measure[10], goodSourceString.channels.measure[10]);
    QCOMPARE(checkingSourceString.channels.measure[11], goodSourceString.channels.measure[11]);
    QCOMPARE(checkingSourceString.channels.measure[12], goodSourceString.channels.measure[12]);
    QCOMPARE(checkingSourceString.channels.measure[13], goodSourceString.channels.measure[13]);
    QCOMPARE(checkingSourceString.channels.measure[14], goodSourceString.channels.measure[14]);
    QCOMPARE(checkingSourceString.channels.measure[15], goodSourceString.channels.measure[15]);
    QCOMPARE(checkingSourceString.channels.measure[16], goodSourceString.channels.measure[16]);
    QCOMPARE(checkingSourceString.channels.measure[17], goodSourceString.channels.measure[17]);
    QCOMPARE(checkingSourceString.channels.measure[18], goodSourceString.channels.measure[18]);
    QCOMPARE(checkingSourceString.channels.measure[19], goodSourceString.channels.measure[19]);
    QCOMPARE(checkingSourceString.channels.measure[20], goodSourceString.channels.measure[20]);
    QCOMPARE(checkingSourceString.channels.measure[21], goodSourceString.channels.measure[21]);
    QCOMPARE(checkingSourceString.channels.measure[22], goodSourceString.channels.measure[22]);
    QCOMPARE(checkingSourceString.channels.measure[23], goodSourceString.channels.measure[23]);
    QCOMPARE(checkingSourceString.channels.measure[24], goodSourceString.channels.measure[24]);
    QCOMPARE(checkingSourceString.channels.measure[25], goodSourceString.channels.measure[25]);
    QCOMPARE(checkingSourceString.channels.measure[26], goodSourceString.channels.measure[26]);
    QCOMPARE(checkingSourceString.channels.accumulator, goodSourceString.channels.accumulator);
}

void CompareSource::openSource_error(QString testName)
{
    Source source(TESTDIR + "/opensource_error." + testName);
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notAccessFile));

    PrepareSource::notAccess(source.getFileName());
    QVERIFY( ! source.openSource());
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::openSource_goodCondition(QString testName)
{
    Source source(TESTDIR + "/opensource_good." + testName);
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notAccessFile));

    PrepareSource::writeSourceString(source.getFileName(), PrepareSource::fillSourceString());
    QVERIFY(source.openSource());
    QVERIFY( ! slotError.getCheckSlotError());
}

void CompareSource::openSource(QString testName)
{
    CompareFile::absentFile(testName);
    CompareFile::manyFiles(testName);
    CompareFile::zeroFileSize(testName);
    CompareFile::multFileSize(testName);
    openSource_error(testName);
    openSource_goodCondition(testName);
}

void CompareSource::readSourceString_error(QString testName)
{
    Source source(TESTDIR + "/readsource_error." + testName);
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notReadFile));

    PrepareSource::notAccess(source.getFileName());
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    QVERIFY( ! checkSourceString.second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::readSourceString_goodCondition(QString testName)
{
    Source source(TESTDIR + "/readsource_good." + testName);
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notReadFile));

    PrepareSource::writeSourceString(source.getFileName(), PrepareSource::fillSourceString());
    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    QVERIFY(checkSourceString.second);
    checkGoodSourceString(checkSourceString.first);
    QVERIFY( ! slotError.getCheckSlotError());
}

void CompareSource::readSourceString(QString testName)
{
    readSourceString_error(testName);
    readSourceString_goodCondition(testName);
}

void CompareSource::dateTimeByteNumber(QString testName)
{
    Source source(TESTDIR + "/datetimebytenumber" + testName);
    PrepareSource::writeSourceString(source.getFileName(), PrepareSource::fillSourceString());
    source.openSource();
    QCOMPARE(source.dateTimeByteNumber(), 1);
    source.channel(QDateTime(QDate(2024, 1, 1), QTime(1, 2, 3)), 0); // any numbers
    QCOMPARE(source.dateTimeByteNumber(), 118);
}

void CompareSource::channelByteNumber(QString testName)
{
    Source source(TESTDIR + "channelbytenumber" + testName);
    PrepareSource::writeSourceString(source.getFileName(), PrepareSource::fillSourceString());
    source.openSource();
    QCOMPARE(source.channelByteNumber(5), 28);
    source.channel(QDateTime(QDate(2024, 2, 2), QTime(5, 6, 7)), 5); // any numbers
    QCOMPARE(source.channelByteNumber(0), 125);
}

void CompareSource::dateTimeValid_notValidYear(QString testName)
{
    Source source(TESTDIR + "/notvalidyear." + testName);
    PrepareSource::notValidYear(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValidDateTime));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    QPair<QDateTime, bool> checkDateTime = source.isDateTimeValid(checkSourceString.first);
    QVERIFY( ! checkDateTime.second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::dateTimeValid_notValidMonth(QString testName)
{
    Source source(TESTDIR + "/notvalidmonth." + testName);
    PrepareSource::notValidMonth(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValidDateTime));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    QPair<QDateTime, bool> checkDateTime = source.isDateTimeValid(checkSourceString.first);
    QVERIFY( ! checkDateTime.second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::dateTimeValid_notValidDay(QString testName)
{
    Source source(TESTDIR + "/notvalidday." + testName);
    PrepareSource::notValidDay(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValidDateTime));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    QPair<QDateTime, bool> checkDateTime = source.isDateTimeValid(checkSourceString.first);
    QVERIFY( ! checkDateTime.second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::dateTimeValid_notValidHour(QString testName)
{
    Source source(TESTDIR + "/notvalidhour." + testName);
    PrepareSource::notValidHour(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValidDateTime));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    QPair<QDateTime, bool> checkDateTime = source.isDateTimeValid(checkSourceString.first);
    QVERIFY( ! checkDateTime.second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::dateTimeValid_notValidMinute(QString testName)
{
    Source source(TESTDIR + "/notvalidminute" + testName);
    PrepareSource::notValidMinute(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValidDateTime));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    QPair<QDateTime, bool> checkDateTime = source.isDateTimeValid(checkSourceString.first);
    QVERIFY( ! checkDateTime.second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::dateTimeValid_notValidSecond(QString testName)
{
    Source source(TESTDIR + "/notvalidsecond" + testName);
    PrepareSource::notValidSecond(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValidDateTime));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    QPair<QDateTime, bool> checkDateTime = source.isDateTimeValid(checkSourceString.first);
    QVERIFY( ! checkDateTime.second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::dateTimeValid_goodCondition(QString testName)
{
    Source source(TESTDIR + "/datetimevalid_good." + testName);
    PrepareSource::writeSourceString(source.getFileName(), PrepareSource::fillSourceString());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValidDateTime));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    QPair<QDateTime, bool> checkDateTime = source.isDateTimeValid(checkSourceString.first);
    QVERIFY( checkDateTime.second);
    QCOMPARE(checkDateTime.first, QDateTime(QDate(2023, 12, 25), QTime(12, 15, 29)));
}

void CompareSource::dateTimeValid(QString testName)
{
    dateTimeValid_notValidYear(testName);
    dateTimeValid_notValidMonth(testName);
    dateTimeValid_notValidDay(testName);
    dateTimeValid_notValidHour(testName);
    dateTimeValid_notValidMinute(testName);
    dateTimeValid_notValidSecond(testName);
    dateTimeValid_goodCondition(testName);
}

void CompareSource::dateTimeRange_lessOfRange(QString testName)
{
    Source source(TESTDIR + "/datetime_lessrange." + testName);
    PrepareSource::lessRangeDateTime(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::outOfRangeDateTime));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    QPair<QDateTime, bool> checkDateTime = source.isDateTimeValid(checkSourceString.first);
    QVERIFY( ! source.isDateTimeInRange(checkDateTime.first));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::dateTimeRange_moreOfRange(QString testName)
{
    Source source(TESTDIR + "/datetime_morerange." + testName);
    PrepareSource::moreRangeDateTime(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::outOfRangeDateTime));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    QPair<QDateTime, bool> checkDateTime = source.isDateTimeValid(checkSourceString.first);
    QVERIFY( ! source.isDateTimeInRange(checkDateTime.first));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::dateTimeRange_inRange(QString testName)
{
    Source source(TESTDIR + "/datetime_inrange." + testName);
    PrepareSource::writeSourceString(source.getFileName(), PrepareSource::fillSourceString());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::outOfRangeDateTime));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    QPair<QDateTime, bool> checkDateTime = source.isDateTimeValid(checkSourceString.first);
    QVERIFY( ! source.isDateTimeInRange(checkDateTime.first));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::dateTimeRange(QString testName)
{
    dateTimeRange_lessOfRange(testName);
    dateTimeRange_moreOfRange(testName);
    dateTimeRange_inRange(testName);
}

void CompareSource::dateTimePeriodValid_firstEqualSecond(QString testName)
{
    Source source(TESTDIR + "/datetime_firstequalsecond." + testName);
    PrepareSource::firstDateTimeEqualSecondDateTime(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValidDateTimePeriodEqualDates));

    source.openSource();
    QPair<SourceString, bool> checkSourceString1 = source.readSourceString();
    QPair<SourceString, bool> checkSourceString2 = source.readSourceString();
    QPair<QDateTime, bool> checkDateTime1 = source.isDateTimeValid(checkSourceString1.first);
    QPair<QDateTime, bool> checkDateTime2 = source.isDateTimeValid(checkSourceString2.first);
    QVERIFY( ! source.isDateTimePeriodValid(checkDateTime1.first, checkDateTime2.first));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::dateTimePeriodValid_firstAfterSecond_secondsNotEqualZero(QString testName)
{
    Source source(TESTDIR + "/datetime_firstaftersecond_secondsnotequalzero." + testName);
    PrepareSource::firstDateTimeAfterSecondDateTime_secondsNotEqualZero(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError,
                             &SlotError::notValidDateTimePeriodDifferentDatesSecondsNotEqualZero));

    source.openSource();
    QPair<SourceString, bool> checkSourceString1 = source.readSourceString();
    QPair<SourceString, bool> checkSourceString2 = source.readSourceString();
    QPair<QDateTime, bool> checkDateTime1 = source.isDateTimeValid(checkSourceString1.first);
    QPair<QDateTime, bool> checkDateTime2 = source.isDateTimeValid(checkSourceString2.first);
    QVERIFY( ! source.isDateTimePeriodValid(checkDateTime1.first, checkDateTime2.first));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::dateTimePeriodValid_firstAfterSecond_secondsEqualZero(QString testName)
{
    Source source(TESTDIR + "/datetime_firstaftersecond_secondsequalzero." + testName);
    PrepareSource::firstDateTimeAfterSecondDateTime_secondsEqualZero(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError,
                             &SlotError::notValidDateTimePeriodDifferentDatesSecondsEqualZero));

    source.openSource();
    QPair<SourceString, bool> checkSourceString1 = source.readSourceString();
    QPair<SourceString, bool> checkSourceString2 = source.readSourceString();
    QPair<QDateTime, bool> checkDateTime1 = source.isDateTimeValid(checkSourceString1.first);
    QPair<QDateTime, bool> checkDateTime2 = source.isDateTimeValid(checkSourceString2.first);
    QVERIFY(source.isDateTimePeriodValid(checkDateTime1.first, checkDateTime2.first)); // not critical error
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::dateTimePeriodValid_goodPeriod(QString testName)
{
    Source source(TESTDIR + "/datetime_goodperiod." + testName);
    PrepareSource::firstDateTimeBeforeSecondDateTime(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValidDateTimePeriodEqualDates));
    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError,
                             &SlotError::notValidDateTimePeriodDifferentDatesSecondsNotEqualZero));
    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError,
                             &SlotError::notValidDateTimePeriodDifferentDatesSecondsEqualZero));

    source.openSource();
    QPair<SourceString, bool> checkSourceString1 = source.readSourceString();
    QPair<SourceString, bool> checkSourceString2 = source.readSourceString();
    QPair<QDateTime, bool> checkDateTime1 = source.isDateTimeValid(checkSourceString1.first);
    QPair<QDateTime, bool> checkDateTime2 = source.isDateTimeValid(checkSourceString2.first);
    QVERIFY(source.isDateTimePeriodValid(checkDateTime1.first, checkDateTime2.first));
    QVERIFY( ! slotError.getCheckSlotError());
}

void CompareSource::dateTimePeriodValid(QString testName)
{
    dateTimePeriodValid_firstEqualSecond(testName);
    dateTimePeriodValid_firstAfterSecond_secondsNotEqualZero(testName);
    dateTimePeriodValid_firstAfterSecond_secondsEqualZero(testName);
    dateTimePeriodValid_goodPeriod(testName);
}

void CompareSource::channelValid_1ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/1channelnotvalid." + testName);
    PrepareSource::notValid1Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid1ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_2ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/2channelnotvalid." + testName);
    PrepareSource::notValid2Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid2ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_3ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/3channelnotvalid." + testName);
    PrepareSource::notValid3Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid3ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_4ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/4channelnotvalid." + testName);
    PrepareSource::notValid4Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid4ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_5ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/5channelnotvalid." + testName);
    PrepareSource::notValid5Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid5ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_6ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/6channelnotvalid." + testName);
    PrepareSource::notValid6Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid6ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_7ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/7channelnotvalid." + testName);
    PrepareSource::notValid7Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid7ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_8ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/8channelnotvalid." + testName);
    PrepareSource::notValid8Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid8ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_9ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/9channelnotvalid." + testName);
    PrepareSource::notValid9Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid9ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_10ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/10channelnotvalid." + testName);
    PrepareSource::notValid10Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid10ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_11ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/11channelnotvalid." + testName);
    PrepareSource::notValid11Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid11ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_12ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/12channelnotvalid." + testName);
    PrepareSource::notValid12Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid12ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_13ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/13channelnotvalid." + testName);
    PrepareSource::notValid13Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid13ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_14ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/14channelnotvalid." + testName);
    PrepareSource::notValid14Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid14ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_15ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/15channelnotvalid." + testName);
    PrepareSource::notValid15Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid15ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_16ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/16channelnotvalid." + testName);
    PrepareSource::notValid16Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid16ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_17ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/17channelnotvalid." + testName);
    PrepareSource::notValid17Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid17ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_18ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/18channelnotvalid." + testName);
    PrepareSource::notValid18Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid18ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_19ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/19channelnotvalid." + testName);
    PrepareSource::notValid19Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid19ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_20ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/20channelnotvalid." + testName);
    PrepareSource::notValid20Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid20ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_21ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/21channelnotvalid." + testName);
    PrepareSource::notValid21Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid21ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_22ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/22channelnotvalid." + testName);
    PrepareSource::notValid22Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid22ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_23ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/23channelnotvalid." + testName);
    PrepareSource::notValid23Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid23ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_24ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/24channelnotvalid." + testName);
    PrepareSource::notValid24Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid24ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_25ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/25channelnotvalid." + testName);
    PrepareSource::notValid25Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid25ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_26ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/26channelnotvalid." + testName);
    PrepareSource::notValid26Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid26ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_27ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/27channelnotvalid." + testName);
    PrepareSource::notValid27Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid27ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_28ChannelNotValidValue(QString testName)
{
    Source source(TESTDIR + "/28channelnotvalid." + testName);
    PrepareSource::notValid28Channel(source.getFileName());
    SlotError slotError(source.getFileName());

    QVERIFY(QObject::connect(&source, &Source::journalOut, &slotError, &SlotError::notValid28ChannelValue));

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    SourceString::Channels channels = sourceString.channels;
    QVERIFY( ! source.isChannelsValid(channels, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52))).second);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareSource::channelValid_connectionVerify(Source *source, SlotError *slotError)
{
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid1ChannelValue));
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid2ChannelValue));
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid3ChannelValue));
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid4ChannelValue));
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid5ChannelValue));
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid6ChannelValue));
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid7ChannelValue));
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid8ChannelValue));
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid9ChannelValue));
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid10ChannelValue));
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid11ChannelValue));
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid12ChannelValue));
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid13ChannelValue));
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid14ChannelValue));
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid15ChannelValue));
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid16ChannelValue));
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid17ChannelValue));
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid18ChannelValue));
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid19ChannelValue));
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid20ChannelValue));
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid21ChannelValue));
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid22ChannelValue));
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid23ChannelValue));
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid24ChannelValue));
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid25ChannelValue));
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid26ChannelValue));
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid27ChannelValue));
    QVERIFY(QObject::connect(source, &Source::journalOut, slotError, &SlotError::notValid28ChannelValue));
}

void CompareSource::channelValid_checkChannelValues(std::array<quint32, 28> channels)
{
    QCOMPARE(channels[0], 1);
    QCOMPARE(channels[1], 2);
    QCOMPARE(channels[2], 3);
    QCOMPARE(channels[3], 4);
    QCOMPARE(channels[4], 5);
    QCOMPARE(channels[5], 6);
    QCOMPARE(channels[6], 7);
    QCOMPARE(channels[7], 8);
    QCOMPARE(channels[8], 9);
    QCOMPARE(channels[9], 10);
    QCOMPARE(channels[10], 11);
    QCOMPARE(channels[11], 12);
    QCOMPARE(channels[12], 13);
    QCOMPARE(channels[13], 14);
    QCOMPARE(channels[14], 15);
    QCOMPARE(channels[15], 16);
    QCOMPARE(channels[16], 17);
    QCOMPARE(channels[17], 18);
    QCOMPARE(channels[18], 19);
    QCOMPARE(channels[19], 20);
    QCOMPARE(channels[20], 21);
    QCOMPARE(channels[21], 22);
    QCOMPARE(channels[22], 23);
    QCOMPARE(channels[23], 24);
    QCOMPARE(channels[24], 25);
    QCOMPARE(channels[25], 26);
    QCOMPARE(channels[26], 27);
    QCOMPARE(channels[27], 28);
}

void CompareSource::channelValid_allChannelsValidValue(QString testName)
{
    Source source(TESTDIR + "/allchannelsvalid." + testName);
    PrepareSource::writeSourceString(source.getFileName(), PrepareSource::fillSourceString());
    SlotError slotError(source.getFileName());

    channelValid_connectionVerify(&source, &slotError);

    source.openSource();
    QPair<SourceString, bool> checkSourceString = source.readSourceString();
    SourceString sourceString = checkSourceString.first;
    QDateTime dateTime(QDate(2023, 12, 25), QTime(12, 15, 29));
    QPair<std::array<quint32, 28>, bool> checkChannels = source.isChannelsValid(sourceString.channels, dateTime);

    channelValid_checkChannelValues(checkChannels.first);

    QVERIFY(checkChannels.second);
    QVERIFY( ! slotError.getCheckSlotError());
}

void CompareSource::channelValid(QString testName)
{
    channelValid_1ChannelNotValidValue(testName);
    channelValid_2ChannelNotValidValue(testName);
    channelValid_3ChannelNotValidValue(testName);
    channelValid_4ChannelNotValidValue(testName);
    channelValid_5ChannelNotValidValue(testName);
    channelValid_6ChannelNotValidValue(testName);
    channelValid_7ChannelNotValidValue(testName);
    channelValid_8ChannelNotValidValue(testName);
    channelValid_9ChannelNotValidValue(testName);
    channelValid_10ChannelNotValidValue(testName);
    channelValid_11ChannelNotValidValue(testName);
    channelValid_12ChannelNotValidValue(testName);
    channelValid_13ChannelNotValidValue(testName);
    channelValid_14ChannelNotValidValue(testName);
    channelValid_15ChannelNotValidValue(testName);
    channelValid_16ChannelNotValidValue(testName);
    channelValid_17ChannelNotValidValue(testName);
    channelValid_18ChannelNotValidValue(testName);
    channelValid_19ChannelNotValidValue(testName);
    channelValid_20ChannelNotValidValue(testName);
    channelValid_21ChannelNotValidValue(testName);
    channelValid_22ChannelNotValidValue(testName);
    channelValid_23ChannelNotValidValue(testName);
    channelValid_24ChannelNotValidValue(testName);
    channelValid_25ChannelNotValidValue(testName);
    channelValid_26ChannelNotValidValue(testName);
    channelValid_27ChannelNotValidValue(testName);
    channelValid_28ChannelNotValidValue(testName);
    channelValid_allChannelsValidValue(testName);
}

void CompareSource::channelRange_1ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_2ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_3ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_4ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_5ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_6ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_7ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_8ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_9ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_10ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_11ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_12ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_13ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_14ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_15ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_16ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_17ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_18ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_19ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_20ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_21ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_22ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_23ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_24ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_25ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_26ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_27ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_28ChannelOutOfRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange_allChannelsInRangeValue(QString testName)
{
    QVERIFY(0);
}

void CompareSource::channelRange(QString testName)
{
    channelRange_1ChannelOutOfRangeValue(testName);
    channelRange_2ChannelOutOfRangeValue(testName);
    channelRange_3ChannelOutOfRangeValue(testName);
    channelRange_4ChannelOutOfRangeValue(testName);
    channelRange_5ChannelOutOfRangeValue(testName);
    channelRange_6ChannelOutOfRangeValue(testName);
    channelRange_7ChannelOutOfRangeValue(testName);
    channelRange_8ChannelOutOfRangeValue(testName);
    channelRange_9ChannelOutOfRangeValue(testName);
    channelRange_10ChannelOutOfRangeValue(testName);
    channelRange_11ChannelOutOfRangeValue(testName);
    channelRange_13ChannelOutOfRangeValue(testName);
    channelRange_14ChannelOutOfRangeValue(testName);
    channelRange_15ChannelOutOfRangeValue(testName);
    channelRange_16ChannelOutOfRangeValue(testName);
    channelRange_17ChannelOutOfRangeValue(testName);
    channelRange_18ChannelOutOfRangeValue(testName);
    channelRange_19ChannelOutOfRangeValue(testName);
    channelRange_20ChannelOutOfRangeValue(testName);
    channelRange_21ChannelOutOfRangeValue(testName);
    channelRange_22ChannelOutOfRangeValue(testName);
    channelRange_23ChannelOutOfRangeValue(testName);
    channelRange_24ChannelOutOfRangeValue(testName);
    channelRange_25ChannelOutOfRangeValue(testName);
    channelRange_26ChannelOutOfRangeValue(testName);
    channelRange_27ChannelOutOfRangeValue(testName);
    channelRange_28ChannelOutOfRangeValue(testName);
    channelRange_allChannelsInRangeValue(testName);
}


