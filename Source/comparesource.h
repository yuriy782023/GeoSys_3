#ifndef COMPARESOURCE_H
#define COMPARESOURCE_H

//#include <QThread>
#include <QPair>

#include "preparesource.h"
#include "../Error/sloterror.h"
#include "../File/comparefile.h"

class CompareSource
{
public:
    CompareSource();

    static void checkGoodSourceDateTime(SourceString::DateTime checkingSourceDateTime);
    static void checkGoodSourceString(SourceString checkingSourceString);

    static void openSource_error(QString testName);
    static void openSource_goodCondition(QString testName);
    static void openSource(QString testName);

    static void readSourceString_error(QString testName);
    static void readSourceString_goodCondition(QString testName);
    static void readSourceString(QString testName);

    static void dateTimeByteNumber(QString testName);
    static void channelByteNumber(QString testName);

    static void dateTimeValid_notValidYear(QString testName);
    static void dateTimeValid_notValidMonth(QString testName);
    static void dateTimeValid_notValidDay(QString testName);
    static void dateTimeValid_notValidHour(QString testName);
    static void dateTimeValid_notValidMinute(QString testName);
    static void dateTimeValid_notValidSecond(QString testName);
    static void dateTimeValid_goodCondition(QString testName);
    static void dateTimeValid(QString testName);

    static void dateTimeRange_lessOfRange(QString testName);
    static void dateTimeRange_moreOfRange(QString testName);
    static void dateTimeRange_inRange(QString testName);
    static void dateTimeRange(QString testName);

    static void dateTimePeriodValid_firstEqualSecond(QString testName);
    static void dateTimePeriodValid_firstAfterSecond_secondsNotEqualZero(QString testName);
    static void dateTimePeriodValid_firstAfterSecond_secondsEqualZero(QString testName);
    static void dateTimePeriodValid_goodPeriod(QString testName);
    static void dateTimePeriodValid(QString testName);

    static void channelValid_1ChannelNotValidValue(QString testName);
    static void channelValid_2ChannelNotValidValue(QString testName);
    static void channelValid_3ChannelNotValidValue(QString testName);
    static void channelValid_4ChannelNotValidValue(QString testName);
    static void channelValid_5ChannelNotValidValue(QString testName);
    static void channelValid_6ChannelNotValidValue(QString testName);
    static void channelValid_7ChannelNotValidValue(QString testName);
    static void channelValid_8ChannelNotValidValue(QString testName);
    static void channelValid_9ChannelNotValidValue(QString testName);
    static void channelValid_10ChannelNotValidValue(QString testName);
    static void channelValid_11ChannelNotValidValue(QString testName);
    static void channelValid_12ChannelNotValidValue(QString testName);
    static void channelValid_13ChannelNotValidValue(QString testName);
    static void channelValid_14ChannelNotValidValue(QString testName);
    static void channelValid_15ChannelNotValidValue(QString testName);
    static void channelValid_16ChannelNotValidValue(QString testName);
    static void channelValid_17ChannelNotValidValue(QString testName);
    static void channelValid_18ChannelNotValidValue(QString testName);
    static void channelValid_19ChannelNotValidValue(QString testName);
    static void channelValid_20ChannelNotValidValue(QString testName);
    static void channelValid_21ChannelNotValidValue(QString testName);
    static void channelValid_22ChannelNotValidValue(QString testName);
    static void channelValid_23ChannelNotValidValue(QString testName);
    static void channelValid_24ChannelNotValidValue(QString testName);
    static void channelValid_25ChannelNotValidValue(QString testName);
    static void channelValid_26ChannelNotValidValue(QString testName);
    static void channelValid_27ChannelNotValidValue(QString testName);
    static void channelValid_28ChannelNotValidValue(QString testName);
    static void channelValid_connectionVerify(Source *source, SlotError *slotError);
    static void channelValid_checkChannelValues(std::array<quint32, 28> channels);
    static void channelValid_allChannelsValidValue(QString testName);
    static void channelValid(QString testName);

    static void channelRange_1ChannelOutOfRangeValue(QString testName);
    static void channelRange_2ChannelOutOfRangeValue(QString testName);
    static void channelRange_3ChannelOutOfRangeValue(QString testName);
    static void channelRange_4ChannelOutOfRangeValue(QString testName);
    static void channelRange_5ChannelOutOfRangeValue(QString testName);
    static void channelRange_6ChannelOutOfRangeValue(QString testName);
    static void channelRange_7ChannelOutOfRangeValue(QString testName);
    static void channelRange_8ChannelOutOfRangeValue(QString testName);
    static void channelRange_9ChannelOutOfRangeValue(QString testName);
    static void channelRange_10ChannelOutOfRangeValue(QString testName);
    static void channelRange_11ChannelOutOfRangeValue(QString testName);
    static void channelRange_12ChannelOutOfRangeValue(QString testName);
    static void channelRange_13ChannelOutOfRangeValue(QString testName);
    static void channelRange_14ChannelOutOfRangeValue(QString testName);
    static void channelRange_15ChannelOutOfRangeValue(QString testName);
    static void channelRange_16ChannelOutOfRangeValue(QString testName);
    static void channelRange_17ChannelOutOfRangeValue(QString testName);
    static void channelRange_18ChannelOutOfRangeValue(QString testName);
    static void channelRange_19ChannelOutOfRangeValue(QString testName);
    static void channelRange_20ChannelOutOfRangeValue(QString testName);
    static void channelRange_21ChannelOutOfRangeValue(QString testName);
    static void channelRange_22ChannelOutOfRangeValue(QString testName);
    static void channelRange_23ChannelOutOfRangeValue(QString testName);
    static void channelRange_24ChannelOutOfRangeValue(QString testName);
    static void channelRange_25ChannelOutOfRangeValue(QString testName);
    static void channelRange_26ChannelOutOfRangeValue(QString testName);
    static void channelRange_27ChannelOutOfRangeValue(QString testName);
    static void channelRange_28ChannelOutOfRangeValue(QString testName);
    static void channelRange_allChannelsInRangeValue(QString testName);
    static void channelRange(QString testName);
};

#endif // COMPARESOURCE_H
