#ifndef COMPAREERROR_H
#define COMPAREERROR_H

#include <QObject>
#include <QTest>

#include "sloterror.h"

class CompareError
{
public:
    CompareError();
    static void absentFile(Error *error);
    static void absentFileNotError(Error *error);
    static void manyFiles(Error *error);

    static void zeroFileSize(Error *error);
    static void multFileSize(Error *error);
    static void iniFormatError(Error *error);

    static void notAccessFile(Error *error, QString fileErrorString);
    static void createFile(Error *error);
    static void notCreateFile(Error *error, QString fileErrorString);

    static void notReadFile(Error *error, QString fileErrorString);
    static void notValidDateTime(Error *error);
    static void outOfRangeDateTime(Error *error);
    static void notValidDateTimePeriodEqualDates(Error *error);
    static void notValidDateTimePeriodDifferentDatesSecondsNotEqualZero(Error *error);
    static void notValidDateTimePeriodDifferentDatesSecondsEqualZero(Error *error);
    static void notValidDateTimePeriod(Error *error);

    static void notValid1ChannelValue(Error *error);
    static void notValid2ChannelValue(Error *error);
    static void notValid3ChannelValue(Error *error);
    static void notValid4ChannelValue(Error *error);
    static void notValid5ChannelValue(Error *error);
    static void notValid6ChannelValue(Error *error);
    static void notValid7ChannelValue(Error *error);
    static void notValid8ChannelValue(Error *error);
    static void notValid9ChannelValue(Error *error);
    static void notValid10ChannelValue(Error *error);
    static void notValid11ChannelValue(Error *error);
    static void notValid12ChannelValue(Error *error);
    static void notValid13ChannelValue(Error *error);
    static void notValid14ChannelValue(Error *error);
    static void notValid15ChannelValue(Error *error);
    static void notValid16ChannelValue(Error *error);
    static void notValid17ChannelValue(Error *error);
    static void notValid18ChannelValue(Error *error);
    static void notValid19ChannelValue(Error *error);
    static void notValid20ChannelValue(Error *error);
    static void notValid21ChannelValue(Error *error);
    static void notValid22ChannelValue(Error *error);
    static void notValid23ChannelValue(Error *error);
    static void notValid24ChannelValue(Error *error);
    static void notValid25ChannelValue(Error *error);
    static void notValid26ChannelValue(Error *error);
    static void notValid27ChannelValue(Error *error);
    static void notValid28ChannelValue(Error *error);
    static void notValidChannelValue(Error *error);

    static void outOfRange1ChannelValue(Error *error);
    static void outOfRange2ChannelValue(Error *error);
    static void outOfRange3ChannelValue(Error *error);
    static void outOfRange4ChannelValue(Error *error);
    static void outOfRange5ChannelValue(Error *error);
    static void outOfRange6ChannelValue(Error *error);
    static void outOfRange7ChannelValue(Error *error);
    static void outOfRange8ChannelValue(Error *error);
    static void outOfRange9ChannelValue(Error *error);
    static void outOfRange10ChannelValue(Error *error);
    static void outOfRange11ChannelValue(Error *error);
    static void outOfRange12ChannelValue(Error *error);
    static void outOfRange13ChannelValue(Error *error);
    static void outOfRange14ChannelValue(Error *error);
    static void outOfRange15ChannelValue(Error *error);
    static void outOfRange16ChannelValue(Error *error);
    static void outOfRange17ChannelValue(Error *error);
    static void outOfRange18ChannelValue(Error *error);
    static void outOfRange19ChannelValue(Error *error);
    static void outOfRange20ChannelValue(Error *error);
    static void outOfRange21ChannelValue(Error *error);
    static void outOfRange22ChannelValue(Error *error);
    static void outOfRange23ChannelValue(Error *error);
    static void outOfRange24ChannelValue(Error *error);
    static void outOfRange25ChannelValue(Error *error);
    static void outOfRange26ChannelValue(Error *error);
    static void outOfRange27ChannelValue(Error *error);
    static void outOfRange28ChannelValue(Error *error);
    static void outOfRangeChannelValue(Error *error);

    static void baseVersionError(Error *error);
    static void lockBase(Error *error);
};

#endif // COMPAREERROR_H
