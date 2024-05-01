#ifndef PREPARESOURCE_H
#define PREPARESOURCE_H

#include "source.h"
#include "../File/preparefile.h"

class PrepareSource
{
public:
    PrepareSource();
    static SourceString::DateTime fillSourceDateTime();
    static SourceString fillSourceString();

    static void writeSourceString(QString fileName, SourceString sourceString);

    static void notAccess(QString fileName);

    static SourceString notValidYear(QString fileName);
    static SourceString notValidMonth(QString fileName);
    static SourceString notValidDay(QString fileName);
    static SourceString notValidHour(QString fileName);
    static SourceString notValidMinute(QString fileName);
    static SourceString notValidSecond(QString fileName);

    static SourceString lessRangeDateTime(QString fileName);
    static SourceString moreRangeDateTime(QString fileName);

    static QPair<SourceString, SourceString> firstDateTimeEqualSecondDateTime(QString fileName);
    static QPair<SourceString, SourceString> firstDateTimeAfterSecondDateTime_secondsNotEqualZero(QString fileName);
    static QPair<SourceString, SourceString> firstDateTimeAfterSecondDateTime_secondsEqualZero(QString fileName);
    static QPair<SourceString, SourceString> firstDateTimeBeforeSecondDateTime(QString fileName); // good condition

    static SourceString notValid1Channel(QString fileName);
    static SourceString notValid2Channel(QString fileName);
    static SourceString notValid3Channel(QString fileName);
    static SourceString notValid4Channel(QString fileName);
    static SourceString notValid5Channel(QString fileName);
    static SourceString notValid6Channel(QString fileName);
    static SourceString notValid7Channel(QString fileName);
    static SourceString notValid8Channel(QString fileName);
    static SourceString notValid9Channel(QString fileName);
    static SourceString notValid10Channel(QString fileName);
    static SourceString notValid11Channel(QString fileName);
    static SourceString notValid12Channel(QString fileName);
    static SourceString notValid13Channel(QString fileName);
    static SourceString notValid14Channel(QString fileName);
    static SourceString notValid15Channel(QString fileName);
    static SourceString notValid16Channel(QString fileName);
    static SourceString notValid17Channel(QString fileName);
    static SourceString notValid18Channel(QString fileName);
    static SourceString notValid19Channel(QString fileName);
    static SourceString notValid20Channel(QString fileName);
    static SourceString notValid21Channel(QString fileName);
    static SourceString notValid22Channel(QString fileName);
    static SourceString notValid23Channel(QString fileName);
    static SourceString notValid24Channel(QString fileName);
    static SourceString notValid25Channel(QString fileName);
    static SourceString notValid26Channel(QString fileName);
    static SourceString notValid27Channel(QString fileName);
    static SourceString notValid28Channel(QString fileName);
};

#endif // PREPARESOURCE_H
