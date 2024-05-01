#include "compareerror.h"

CompareError::CompareError()
{
}

void CompareError::absentFile(Error *error)
{
    SlotError slotError("absent.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::absentFile));
    error->absentFile("absent.file");
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::absentFileNotError(Error *error)
{
    SlotError slotError("create.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::absentFileNotError));
    error->absentFileNotError("create.file");
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::manyFiles(Error *error)
{
    SlotError slotError("many.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::manyFiles));
    error->manyFiles("many.file");
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::zeroFileSize(Error *error)
{
    SlotError slotError("zero.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::zeroFileSize));
    error->zeroFileSize("zero.file");
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::multFileSize(Error *error)
{
    SlotError slotError("mult.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::multFileSize));
    error->multFileSize("mult.file");
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::iniFormatError(Error *error)
{
    SlotError slotError("iniformaterror.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::iniFormatError));
    error->iniFormatError("iniformaterror.file");
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notAccessFile(Error *error, QString fileErrorString)
{
    SlotError slotError("notaccess.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notAccessFile));
    error->notAccessFile("notaccess.file", fileErrorString);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::createFile(Error *error)
{
    SlotError slotError("create.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::createFile));
    error->createFile("create.file");
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notCreateFile(Error *error, QString fileErrorString)
{
    SlotError slotError("notcreate.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notCreateFile));
    error->notCreateFile("notcreate.file", fileErrorString);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notReadFile(Error *error, QString fileErrorString)
{
    SlotError slotError("notread.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notReadFile));
    error->notReadFile("notread.file", fileErrorString);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValidDateTime(Error *error)
{
    SlotError slotError("notvaliddatetime.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValidDateTime));
    error->notValidDateTime("notvaliddatetime.file", 1);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRangeDateTime(Error *error)
{
    SlotError slotError("outofrangedatetime.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRangeDateTime));
    error->outOfRangeDateTime("outofrangedatetime.file", 1);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValidDateTimePeriodEqualDates(Error *error)
{
    SlotError slotError("notvaliddatetimeperiod.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValidDateTimePeriodEqualDates));
    error->notValidDateTimePeriodEqualDates("notvaliddatetimeperiod.file", 1, QDateTime(QDate(2023, 12, 25), QTime(12, 15, 29)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValidDateTimePeriodDifferentDatesSecondsNotEqualZero(Error *error)
{
    SlotError slotError("notvaliddatetimeperiod.file");
    QVERIFY(QObject::connect(error, &Error::journalOut,
                             &slotError, &SlotError::notValidDateTimePeriodDifferentDatesSecondsNotEqualZero));
    QDateTime prevDateTime(QDate(2023, 12, 25), QTime(13, 15, 29)), nextDateTime(QDate(2023, 12, 25), QTime(12, 15, 29));
    error->notValidDateTimePeriodDifferentDatesSecondsNotEqualZero("notvaliddatetimeperiod.file", 1, prevDateTime, nextDateTime);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValidDateTimePeriodDifferentDatesSecondsEqualZero(Error *error)
{
    SlotError slotError("notvaliddatetimeperiod.file");
    QVERIFY(QObject::connect(error, &Error::journalOut,
                             &slotError, &SlotError::notValidDateTimePeriodDifferentDatesSecondsEqualZero));
    QDateTime prevDateTime(QDate(2023, 12, 25), QTime(12, 16, 00)), nextDateTime(QDate(2023, 12, 25), QTime(12, 15, 29));
    error->notValidDateTimePeriodDifferentDatesSecondsEqualZero("notvaliddatetimeperiod.file", 1, prevDateTime, nextDateTime);
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValidDateTimePeriod(Error *error)
{
    notValidDateTimePeriodEqualDates(error);
    notValidDateTimePeriodDifferentDatesSecondsNotEqualZero(error);
    notValidDateTimePeriodDifferentDatesSecondsEqualZero(error);
}

void CompareError::notValid1ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid1ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 8, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValid2ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid2ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 12, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValid3ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid3ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 16, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValid4ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid4ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 20, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValid5ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid5ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 24, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValid6ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid6ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 28, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValid7ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid7ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 32, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValid8ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid8ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 36, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValid9ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid9ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 40, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValid10ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid10ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 44, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValid11ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid11ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 48, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValid12ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid12ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 52, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValid13ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid13ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 56, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValid14ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid14ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 60, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValid15ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid15ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 64, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValid16ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid16ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 68, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValid17ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid17ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 72, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValid18ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid18ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 76, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValid19ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid19ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 80, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValid20ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid20ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 84, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValid21ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid21ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 88, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValid22ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid22ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 92, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValid23ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid23ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 96, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValid24ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid24ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 100, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValid25ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid25ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 104, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValid26ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid26ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 108, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValid27ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid27ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 112, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValid28ChannelValue(Error *error)
{
    SlotError slotError("notvalidchannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::notValid28ChannelValue));
    error->notValidChannelValue("notvalidchannelvalue.file", 116, QDateTime(QDate(2024, 5, 6), QTime(5, 19, 52)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::notValidChannelValue(Error *error)
{
    notValid1ChannelValue(error);
    notValid2ChannelValue(error);
    notValid3ChannelValue(error);
    notValid4ChannelValue(error);
    notValid5ChannelValue(error);
    notValid6ChannelValue(error);
    notValid7ChannelValue(error);
    notValid8ChannelValue(error);
    notValid9ChannelValue(error);
    notValid10ChannelValue(error);
    notValid11ChannelValue(error);
    notValid12ChannelValue(error);
    notValid13ChannelValue(error);
    notValid14ChannelValue(error);
    notValid15ChannelValue(error);
    notValid16ChannelValue(error);
    notValid17ChannelValue(error);
    notValid18ChannelValue(error);
    notValid19ChannelValue(error);
    notValid20ChannelValue(error);
    notValid21ChannelValue(error);
    notValid22ChannelValue(error);
    notValid23ChannelValue(error);
    notValid24ChannelValue(error);
    notValid25ChannelValue(error);
    notValid26ChannelValue(error);
    notValid27ChannelValue(error);
    notValid28ChannelValue(error);
}

void CompareError::outOfRange1ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange1ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 8, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRange2ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange2ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 12, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRange3ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange3ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 16, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRange4ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange4ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 20, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRange5ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange5ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 24, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRange6ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange6ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 28, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRange7ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange7ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 32, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRange8ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange8ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 36, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRange9ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange9ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 40, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRange10ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange10ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 44, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRange11ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange11ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 48, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRange12ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange12ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 52, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRange13ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange13ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 56, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRange14ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange14ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 60, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRange15ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange15ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 64, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRange16ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange16ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 68, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRange17ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange17ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 72, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRange18ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange18ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 76, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRange19ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange19ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 80, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRange20ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange20ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 84, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRange21ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange21ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 88, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRange22ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange22ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 92, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRange23ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange23ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 96, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRange24ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange24ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 100, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRange25ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange25ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 104, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRange26ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange26ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 108, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRange27ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange27ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 112, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRange28ChannelValue(Error *error)
{
    SlotError slotError("outofrangechannelvalue.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::outOfRange28ChannelValue));
    error->outOfRangeChannelValue("outofrangechannelvalue.file", 116, QDateTime(QDate(2024, 5, 6), QTime(5, 36, 22)));
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::outOfRangeChannelValue(Error *error)
{
    outOfRange1ChannelValue(error);
    outOfRange2ChannelValue(error);
    outOfRange3ChannelValue(error);
    outOfRange4ChannelValue(error);
    outOfRange5ChannelValue(error);
    outOfRange6ChannelValue(error);
    outOfRange7ChannelValue(error);
    outOfRange8ChannelValue(error);
    outOfRange9ChannelValue(error);
    outOfRange10ChannelValue(error);
    outOfRange11ChannelValue(error);
    outOfRange12ChannelValue(error);
    outOfRange13ChannelValue(error);
    outOfRange14ChannelValue(error);
    outOfRange15ChannelValue(error);
    outOfRange16ChannelValue(error);
    outOfRange17ChannelValue(error);
    outOfRange18ChannelValue(error);
    outOfRange19ChannelValue(error);
    outOfRange20ChannelValue(error);
    outOfRange21ChannelValue(error);
    outOfRange22ChannelValue(error);
    outOfRange23ChannelValue(error);
    outOfRange24ChannelValue(error);
    outOfRange25ChannelValue(error);
    outOfRange26ChannelValue(error);
    outOfRange27ChannelValue(error);
    outOfRange28ChannelValue(error);
}

void CompareError::baseVersionError(Error *error)
{
    SlotError slotError("baseversionerror.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::baseVersionError));
    error->baseVersionError();
    QVERIFY(slotError.getCheckSlotError());
}

void CompareError::lockBase(Error *error)
{
    SlotError slotError("lockbase.file");
    QVERIFY(QObject::connect(error, &Error::journalOut, &slotError, &SlotError::lockBase));
    pid_t pid = 1234;
    QString dateTime = QDateTime(QDate(2023, 12, 7), QTime(16, 50)).toString("hh:mm:ss dd.MM.yyyy");
    error->lockBase(pid, dateTime);
    QVERIFY(slotError.getCheckSlotError());
}

