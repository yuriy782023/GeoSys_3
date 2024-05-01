#include "source.h"

Source::~Source()
{
    if (sourceFile.isOpen())
        sourceFile.close();
}

bool Source::openSource()
{
    if ( ! absentFile() ||
         ! manyFiles() ||
         ! zeroFileSize() ||
         ! multFileSize(117) ) {
        return false;
    }

    if ( ! sourceFile.open(QIODevice::ReadOnly)) {
        notAccessFile(sourceFile.fileName(), sourceFile.errorString());
        return false;
    }

    stringCounter = 0;
    return true;
}

QPair<SourceString, bool> Source::readSourceString()
{
    QPair<SourceString, bool> sourceString;

    if ( sourceFile.read(reinterpret_cast<char*>(&sourceString.first), 117) < 117) {
        notReadFile(sourceFile.fileName(), sourceFile.errorString());
        sourceString.second = false;
    } else
        sourceString.second = true;

    return sourceString;
}

QPair<QDateTime, bool> Source::isDateTimeValid(SourceString sourceString)
{
    QPair<QDateTime, bool> dateTime;

    if ( ! QDate::isValid(sourceString.dateTime.year.high * 256 + sourceString.dateTime.year.low,
                          sourceString.dateTime.month, sourceString.dateTime.day) ||
         ! QTime::isValid(sourceString.dateTime.hour, sourceString.dateTime.minute, sourceString.dateTime.second)) {
        notValidDateTime(sourceFile.fileName(), stringCounter * 117 + 1);
        dateTime.second = false;
    } else {
        dateTime.first = QDateTime(
                    QDate(sourceString.dateTime.year.high * 256 + sourceString.dateTime.year.low,
                          sourceString.dateTime.month, sourceString.dateTime.day),
                    QTime(sourceString.dateTime.hour, sourceString.dateTime.minute, sourceString.dateTime.second));
        dateTime.second = true;
    }

    return dateTime;
}

bool Source::isDateTimeInRange(QDateTime dateTime)
{
    QDateTime startDateTime(QDate(2006, 1, 1), QTime(0, 0, 0)); // 01.01.2006 is start date
    QDateTime finishDateTime(QDateTime::currentDateTime().addDays(1)); // plus 1 day if use different time zones

    if (startDateTime.daysTo(dateTime) >= 0 || finishDateTime.daysTo(dateTime) < 0) {
        outOfRangeDateTime(sourceFile.fileName(), dateTimeByteNumber());
        return false;
    }

    return true;
}

bool Source::isDateTimePeriodValid(QDateTime prevDateTime, QDateTime nextDateTime)
{
    if (prevDateTime == nextDateTime) {
        notValidDateTimePeriodEqualDates(sourceFile.fileName(), dateTimeByteNumber(), nextDateTime);
        return false;
    }

    if (prevDateTime > nextDateTime) {

        if (prevDateTime.time().second() != 0) {
            notValidDateTimePeriodDifferentDatesSecondsNotEqualZero(sourceFile.fileName(), dateTimeByteNumber(),
                                                                    prevDateTime, nextDateTime);
            return false;
        } else
            notValidDateTimePeriodDifferentDatesSecondsEqualZero(sourceFile.fileName(), dateTimeByteNumber(),
                                                                 prevDateTime, nextDateTime);
    }

    return true;
}

QPair<std::array<quint32, 28>, bool> Source::isChannelsValid(SourceString::Channels channels, QDateTime dateTime) // all channels
{
    QPair<std::array<quint32, 28>, bool> checkChannels;

    for (int i = 0; i < 27; i++) {

        if (channels.measure[i][0] > 0) { // sourceString.channel > 16777215
            notValidChannelValue(sourceFile.fileName(), channelByteNumber(i), dateTime);
            checkChannels.second = false;
            return checkChannels;
        } else {
            // converting from Motorola byte order to Intel byte order
            checkChannels.first[i] = channels.measure[i][1];
            checkChannels.first[i] <<= 8;
            checkChannels.first[i] += channels.measure[i][2];
            checkChannels.first[i] <<= 8;
            checkChannels.first[i] += channels.measure[i][3];
        }
    }

    if (channels.accumulator[0] > 4) { // sourceString.accumulator > 1023
        notValidChannelValue(sourceFile.fileName(), channelByteNumber(27), dateTime);
        checkChannels.second = false;
        return checkChannels;
    } else {
        // converting from Motorola byte order to Intel byte order
        checkChannels.first[27] = channels.accumulator[0];
        checkChannels.first[27] <<= 8;
        checkChannels.first[27] += channels.accumulator[1];
    }

    checkChannels.second = true;
    return checkChannels;
}

bool Source::isChannelsInRange(std::array<quint32, 28> channels, QDateTime dateTime) // all channels
{
    return false;
}

int Source::channel(QDateTime dateTime, int channelNumber)
{
    stringCounter++;
}
