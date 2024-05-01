#ifndef PREPAREINI_H
#define PREPAREINI_H

#include "ini.h"
#include "../File/preparefile.h"

struct ChannelValues
{
    qreal voltageOffset;
    qreal voltageMultiple;
    qreal absoluteOffset;
    qreal absoluteMultiple;
    qreal minimum;
    qreal maximum;
};

struct ChannelStrings
{
    QString voltageOffset;
    QString voltageMultiple;
    QString absoluteOffset;
    QString absoluteMultiple;
    QString minimum;
    QString maximum;
};

class PrepareIni
{
public:
    PrepareIni();
    static ChannelValues fillChannelValue1Case();
    static ChannelValues fillChannelValue2Case();
    static ChannelStrings fill1Channel(int number, ChannelValues channelValues);
    static std::array<QString, 28> fillVoltageOffset(ChannelValues channelValues);
    static std::array<QString, 28> fillVoltageMultiple(ChannelValues channelValues);
    static std::array<QString, 28> fillAbsoluteOffset(ChannelValues channelValues);
    static std::array<QString, 28> fillAbsoluteMultiple(ChannelValues channelValues);
    static std::array<QString, 28> fillMinimum(ChannelValues channelValues);
    static std::array<QString, 28> fillMaximum(ChannelValues channelValues);
    static void writeIni(QString fileName, ChannelValues channelValues);
    static void notAccess();
};

#endif // PREPAREINI_H
