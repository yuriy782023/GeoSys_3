#ifndef SOURCE_H
#define SOURCE_H

#include <QDateTime>

#include "../File/file.h"

;
#pragma pack(push, 1) // alignment in sructure is off for file reading
    struct SourceString {
        struct DateTime {
            struct Year {
                quint8 high;
                quint8 low;
            } year;
            quint8 month;
            quint8 day;
            quint8 hour;
            quint8 minute;
            quint8 second;
        } dateTime;
        struct Channels {
            std::array<std::array<quint8, 4>, 27> measure;
            std::array<quint8, 2> accumulator;
        } channels;
    };
#pragma pack(pop) // alignment in structure is on

class Source : public File
{
public:
    Source(QString sourceName) : File(sourceName), sourceFile(sourceName) {}
    ~Source();
    bool openSource();
    QPair<SourceString, bool> readSourceString();
    int dateTimeByteNumber() { return stringCounter * 117 + 1; }
    int channelByteNumber(int channelNumber) { return stringCounter * 117 + channelNumber * 4 + 8; }
    QPair<QDateTime, bool> isDateTimeValid(SourceString sourceString);
    bool isDateTimeInRange(QDateTime dateTime);
    bool isDateTimePeriodValid(QDateTime prevDateTime, QDateTime nextDateTime);
    QPair<std::array<quint32, 28>, bool> isChannelsValid(SourceString::Channels channels, QDateTime dateTime);
    bool isChannelsInRange(std::array<quint32, 28> channels, QDateTime dateTime);
    int channel(QDateTime dateTime, int channelNumber);

private:
    QFile sourceFile;
    int stringCounter;
    QDateTime currentDateTime, previousDateTime;
};

#endif // SOURCE_H
