#include "prepareini.h"

PrepareIni::PrepareIni()
{
}

ChannelValues PrepareIni::fillChannelValue1Case()
{
    qreal voltageOffset = 11.11;
    qreal voltageMultiple = 22.22;
    qreal absoluteOffset = 33.33;
    qreal absoluteMultiple = 44.44;
    qreal minimum = 0.0;
    qreal maximum = 0.0;
    return { voltageOffset, voltageMultiple, absoluteOffset, absoluteMultiple, minimum, maximum };
}

ChannelValues PrepareIni::fillChannelValue2Case()
{
    qreal voltageOffset = 55.55;
    qreal voltageMultiple = 66.66;
    qreal absoluteOffset = 77.77;
    qreal absoluteMultiple = 88.88;
    qreal minimum = 0.0;
    qreal maximum = 0.0;
    return { voltageOffset, voltageMultiple, absoluteOffset, absoluteMultiple, minimum, maximum };
}

ChannelStrings PrepareIni::fill1Channel(int number, ChannelValues channelValues)
{
    QString voltageOffset = QString("VoltageOffset%1=%2\r\n").arg(number).arg(channelValues.voltageOffset).toUtf8(); // utf8 ???
    QString voltageMultiple = QString("VoltageMultiple%1=%2\r\n").arg(number).arg(channelValues.voltageMultiple).toUtf8();
    QString absoluteOffset = QString("AbsoluteOffset%1=%2\r\n").arg(number).arg(channelValues.absoluteOffset).toUtf8();
    QString absoluteMultiple = QString("AbsoluteMultiple%1=%2\r\n").arg(number).arg(channelValues.absoluteMultiple).toUtf8();
    QString minimum = QString("Minimum%1=%2\r\n").arg(number).arg(channelValues.minimum).toUtf8();
    QString maximum = QString("Maximum%1=%2\r\n").arg(number).arg(channelValues.maximum).toUtf8();
    return { voltageOffset, voltageMultiple, absoluteOffset, absoluteMultiple, minimum, maximum };
}

std::array<QString, 28> PrepareIni::fillVoltageOffset(ChannelValues channelValues)
{
    std::array<QString, 28> voltageOffset;
    voltageOffset[0] = fill1Channel(1, channelValues).voltageOffset;
    voltageOffset[1] = fill1Channel(2, channelValues).voltageOffset;
    voltageOffset[2] = fill1Channel(3, channelValues).voltageOffset;
    voltageOffset[3] = fill1Channel(4, channelValues).voltageOffset;
    voltageOffset[4] = fill1Channel(5, channelValues).voltageOffset;
    voltageOffset[5] = fill1Channel(6, channelValues).voltageOffset;
    voltageOffset[6] = fill1Channel(7, channelValues).voltageOffset;
    voltageOffset[7] = fill1Channel(8, channelValues).voltageOffset;
    voltageOffset[8] = fill1Channel(9, channelValues).voltageOffset;
    voltageOffset[9] = fill1Channel(10, channelValues).voltageOffset;
    voltageOffset[10] = fill1Channel(11, channelValues).voltageOffset;
    voltageOffset[11] = fill1Channel(12, channelValues).voltageOffset;
    voltageOffset[12] = fill1Channel(13, channelValues).voltageOffset;
    voltageOffset[13] = fill1Channel(14, channelValues).voltageOffset;
    voltageOffset[14] = fill1Channel(15, channelValues).voltageOffset;
    voltageOffset[15] = fill1Channel(16, channelValues).voltageOffset;
    voltageOffset[16] = fill1Channel(17, channelValues).voltageOffset;
    voltageOffset[17] = fill1Channel(18, channelValues).voltageOffset;
    voltageOffset[18] = fill1Channel(19, channelValues).voltageOffset;
    voltageOffset[19] = fill1Channel(20, channelValues).voltageOffset;
    voltageOffset[20] = fill1Channel(21, channelValues).voltageOffset;
    voltageOffset[21] = fill1Channel(22, channelValues).voltageOffset;
    voltageOffset[22] = fill1Channel(23, channelValues).voltageOffset;
    voltageOffset[23] = fill1Channel(24, channelValues).voltageOffset;
    voltageOffset[24] = fill1Channel(25, channelValues).voltageOffset;
    voltageOffset[25] = fill1Channel(26, channelValues).voltageOffset;
    voltageOffset[26] = fill1Channel(27, channelValues).voltageOffset;
    voltageOffset[27] = fill1Channel(28, channelValues).voltageOffset;
    return voltageOffset;
}

std::array<QString, 28> PrepareIni::fillVoltageMultiple(ChannelValues channelValues)
{
    std::array<QString, 28> voltageMultiple;
    voltageMultiple[0] = fill1Channel(1, channelValues).voltageMultiple;
    voltageMultiple[1] = fill1Channel(2, channelValues).voltageMultiple;
    voltageMultiple[2] = fill1Channel(3, channelValues).voltageMultiple;
    voltageMultiple[3] = fill1Channel(4, channelValues).voltageMultiple;
    voltageMultiple[4] = fill1Channel(5, channelValues).voltageMultiple;
    voltageMultiple[5] = fill1Channel(6, channelValues).voltageMultiple;
    voltageMultiple[6] = fill1Channel(7, channelValues).voltageMultiple;
    voltageMultiple[7] = fill1Channel(8, channelValues).voltageMultiple;
    voltageMultiple[8] = fill1Channel(9, channelValues).voltageMultiple;
    voltageMultiple[9] = fill1Channel(10, channelValues).voltageMultiple;
    voltageMultiple[10] = fill1Channel(11, channelValues).voltageMultiple;
    voltageMultiple[11] = fill1Channel(12, channelValues).voltageMultiple;
    voltageMultiple[12] = fill1Channel(13, channelValues).voltageMultiple;
    voltageMultiple[13] = fill1Channel(14, channelValues).voltageMultiple;
    voltageMultiple[14] = fill1Channel(15, channelValues).voltageMultiple;
    voltageMultiple[15] = fill1Channel(16, channelValues).voltageMultiple;
    voltageMultiple[16] = fill1Channel(17, channelValues).voltageMultiple;
    voltageMultiple[17] = fill1Channel(18, channelValues).voltageMultiple;
    voltageMultiple[18] = fill1Channel(19, channelValues).voltageMultiple;
    voltageMultiple[19] = fill1Channel(20, channelValues).voltageMultiple;
    voltageMultiple[20] = fill1Channel(21, channelValues).voltageMultiple;
    voltageMultiple[21] = fill1Channel(22, channelValues).voltageMultiple;
    voltageMultiple[22] = fill1Channel(23, channelValues).voltageMultiple;
    voltageMultiple[23] = fill1Channel(24, channelValues).voltageMultiple;
    voltageMultiple[24] = fill1Channel(25, channelValues).voltageMultiple;
    voltageMultiple[25] = fill1Channel(26, channelValues).voltageMultiple;
    voltageMultiple[26] = fill1Channel(27, channelValues).voltageMultiple;
    voltageMultiple[27] = fill1Channel(28, channelValues).voltageMultiple;
    return voltageMultiple;
}

std::array<QString, 28> PrepareIni::fillAbsoluteOffset(ChannelValues channelValues)
{
    std::array<QString, 28> absoluteOffset;
    absoluteOffset[0] = fill1Channel(1, channelValues).absoluteOffset;
    absoluteOffset[1] = fill1Channel(2, channelValues).absoluteOffset;
    absoluteOffset[2] = fill1Channel(3, channelValues).absoluteOffset;
    absoluteOffset[3] = fill1Channel(4, channelValues).absoluteOffset;
    absoluteOffset[4] = fill1Channel(5, channelValues).absoluteOffset;
    absoluteOffset[5] = fill1Channel(6, channelValues).absoluteOffset;
    absoluteOffset[6] = fill1Channel(7, channelValues).absoluteOffset;
    absoluteOffset[7] = fill1Channel(8, channelValues).absoluteOffset;
    absoluteOffset[8] = fill1Channel(9, channelValues).absoluteOffset;
    absoluteOffset[9] = fill1Channel(10, channelValues).absoluteOffset;
    absoluteOffset[10] = fill1Channel(11, channelValues).absoluteOffset;
    absoluteOffset[11] = fill1Channel(12, channelValues).absoluteOffset;
    absoluteOffset[12] = fill1Channel(13, channelValues).absoluteOffset;
    absoluteOffset[13] = fill1Channel(14, channelValues).absoluteOffset;
    absoluteOffset[14] = fill1Channel(15, channelValues).absoluteOffset;
    absoluteOffset[15] = fill1Channel(16, channelValues).absoluteOffset;
    absoluteOffset[16] = fill1Channel(17, channelValues).absoluteOffset;
    absoluteOffset[17] = fill1Channel(18, channelValues).absoluteOffset;
    absoluteOffset[18] = fill1Channel(19, channelValues).absoluteOffset;
    absoluteOffset[19] = fill1Channel(20, channelValues).absoluteOffset;
    absoluteOffset[20] = fill1Channel(21, channelValues).absoluteOffset;
    absoluteOffset[21] = fill1Channel(22, channelValues).absoluteOffset;
    absoluteOffset[22] = fill1Channel(23, channelValues).absoluteOffset;
    absoluteOffset[23] = fill1Channel(24, channelValues).absoluteOffset;
    absoluteOffset[24] = fill1Channel(25, channelValues).absoluteOffset;
    absoluteOffset[25] = fill1Channel(26, channelValues).absoluteOffset;
    absoluteOffset[26] = fill1Channel(27, channelValues).absoluteOffset;
    absoluteOffset[27] = fill1Channel(28, channelValues).absoluteOffset;
    return absoluteOffset;
}

std::array<QString, 28> PrepareIni::fillAbsoluteMultiple(ChannelValues channelValues)
{
    std::array<QString, 28> absoluteMultiple;
    absoluteMultiple[0] = fill1Channel(1, channelValues).absoluteMultiple;
    absoluteMultiple[1] = fill1Channel(2, channelValues).absoluteMultiple;
    absoluteMultiple[2] = fill1Channel(3, channelValues).absoluteMultiple;
    absoluteMultiple[3] = fill1Channel(4, channelValues).absoluteMultiple;
    absoluteMultiple[4] = fill1Channel(5, channelValues).absoluteMultiple;
    absoluteMultiple[5] = fill1Channel(6, channelValues).absoluteMultiple;
    absoluteMultiple[6] = fill1Channel(7, channelValues).absoluteMultiple;
    absoluteMultiple[7] = fill1Channel(8, channelValues).absoluteMultiple;
    absoluteMultiple[8] = fill1Channel(9, channelValues).absoluteMultiple;
    absoluteMultiple[9] = fill1Channel(10, channelValues).absoluteMultiple;
    absoluteMultiple[10] = fill1Channel(11, channelValues).absoluteMultiple;
    absoluteMultiple[11] = fill1Channel(12, channelValues).absoluteMultiple;
    absoluteMultiple[12] = fill1Channel(13, channelValues).absoluteMultiple;
    absoluteMultiple[13] = fill1Channel(14, channelValues).absoluteMultiple;
    absoluteMultiple[14] = fill1Channel(15, channelValues).absoluteMultiple;
    absoluteMultiple[15] = fill1Channel(16, channelValues).absoluteMultiple;
    absoluteMultiple[16] = fill1Channel(17, channelValues).absoluteMultiple;
    absoluteMultiple[17] = fill1Channel(18, channelValues).absoluteMultiple;
    absoluteMultiple[18] = fill1Channel(19, channelValues).absoluteMultiple;
    absoluteMultiple[19] = fill1Channel(20, channelValues).absoluteMultiple;
    absoluteMultiple[20] = fill1Channel(21, channelValues).absoluteMultiple;
    absoluteMultiple[21] = fill1Channel(22, channelValues).absoluteMultiple;
    absoluteMultiple[22] = fill1Channel(23, channelValues).absoluteMultiple;
    absoluteMultiple[23] = fill1Channel(24, channelValues).absoluteMultiple;
    absoluteMultiple[24] = fill1Channel(25, channelValues).absoluteMultiple;
    absoluteMultiple[25] = fill1Channel(26, channelValues).absoluteMultiple;
    absoluteMultiple[26] = fill1Channel(27, channelValues).absoluteMultiple;
    absoluteMultiple[27] = fill1Channel(28, channelValues).absoluteMultiple;
    return absoluteMultiple;
}

std::array<QString, 28> PrepareIni::fillMinimum(ChannelValues channelValues)
{
    std::array<QString, 28> minimum;
    minimum[0] = fill1Channel(1, channelValues).minimum;
    minimum[1] = fill1Channel(2, channelValues).minimum;
    minimum[2] = fill1Channel(3, channelValues).minimum;
    minimum[3] = fill1Channel(4, channelValues).minimum;
    minimum[4] = fill1Channel(5, channelValues).minimum;
    minimum[5] = fill1Channel(6, channelValues).minimum;
    minimum[6] = fill1Channel(7, channelValues).minimum;
    minimum[7] = fill1Channel(8, channelValues).minimum;
    minimum[8] = fill1Channel(9, channelValues).minimum;
    minimum[9] = fill1Channel(10, channelValues).minimum;
    minimum[10] = fill1Channel(11, channelValues).minimum;
    minimum[11] = fill1Channel(12, channelValues).minimum;
    minimum[12] = fill1Channel(13, channelValues).minimum;
    minimum[13] = fill1Channel(14, channelValues).minimum;
    minimum[14] = fill1Channel(15, channelValues).minimum;
    minimum[15] = fill1Channel(16, channelValues).minimum;
    minimum[16] = fill1Channel(17, channelValues).minimum;
    minimum[17] = fill1Channel(18, channelValues).minimum;
    minimum[18] = fill1Channel(19, channelValues).minimum;
    minimum[19] = fill1Channel(20, channelValues).minimum;
    minimum[20] = fill1Channel(21, channelValues).minimum;
    minimum[21] = fill1Channel(22, channelValues).minimum;
    minimum[22] = fill1Channel(23, channelValues).minimum;
    minimum[23] = fill1Channel(24, channelValues).minimum;
    minimum[24] = fill1Channel(25, channelValues).minimum;
    minimum[25] = fill1Channel(26, channelValues).minimum;
    minimum[26] = fill1Channel(27, channelValues).minimum;
    minimum[27] = fill1Channel(28, channelValues).minimum;
    return minimum;
}

std::array<QString, 28> PrepareIni::fillMaximum(ChannelValues channelValues)
{
    std::array<QString, 28> maximum;
    maximum[0] = fill1Channel(1, channelValues).maximum;
    maximum[1] = fill1Channel(2, channelValues).maximum;
    maximum[2] = fill1Channel(3, channelValues).maximum;
    maximum[3] = fill1Channel(4, channelValues).maximum;
    maximum[4] = fill1Channel(5, channelValues).maximum;
    maximum[5] = fill1Channel(6, channelValues).maximum;
    maximum[6] = fill1Channel(7, channelValues).maximum;
    maximum[7] = fill1Channel(8, channelValues).maximum;
    maximum[8] = fill1Channel(9, channelValues).maximum;
    maximum[9] = fill1Channel(10, channelValues).maximum;
    maximum[10] = fill1Channel(11, channelValues).maximum;
    maximum[11] = fill1Channel(12, channelValues).maximum;
    maximum[12] = fill1Channel(13, channelValues).maximum;
    maximum[13] = fill1Channel(14, channelValues).maximum;
    maximum[14] = fill1Channel(15, channelValues).maximum;
    maximum[15] = fill1Channel(16, channelValues).maximum;
    maximum[16] = fill1Channel(17, channelValues).maximum;
    maximum[17] = fill1Channel(18, channelValues).maximum;
    maximum[18] = fill1Channel(19, channelValues).maximum;
    maximum[19] = fill1Channel(20, channelValues).maximum;
    maximum[20] = fill1Channel(21, channelValues).maximum;
    maximum[21] = fill1Channel(22, channelValues).maximum;
    maximum[22] = fill1Channel(23, channelValues).maximum;
    maximum[23] = fill1Channel(24, channelValues).maximum;
    maximum[24] = fill1Channel(25, channelValues).maximum;
    maximum[25] = fill1Channel(26, channelValues).maximum;
    maximum[26] = fill1Channel(27, channelValues).maximum;
    maximum[27] = fill1Channel(28, channelValues).maximum;
    return maximum;
}

void PrepareIni::writeIni(QString fileName, ChannelValues channelValues)
{
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    file.write("[Coefficients]\r\n");
    std::array<QString, 28> voltageOffset = PrepareIni::fillVoltageOffset(channelValues);
    file.write(reinterpret_cast<char*>(&voltageOffset), sizeof (voltageOffset));
    std::array<QString, 28> voltageMultiple = PrepareIni::fillVoltageMultiple(channelValues);
    file.write(reinterpret_cast<char*>(&voltageMultiple), sizeof (voltageMultiple));
    std::array<QString, 28> absoluteOffset = PrepareIni::fillAbsoluteOffset(channelValues);
    file.write(reinterpret_cast<char*>(&absoluteOffset), sizeof (absoluteOffset));
    std::array<QString, 28> absoluteMultiple = PrepareIni::fillAbsoluteMultiple(channelValues);
    file.write("[Range]\r\n");
    std::array<QString, 28> minimum = PrepareIni::fillMinimum(channelValues);
    file.write(reinterpret_cast<char*>(&minimum));
    std::array<QString, 28> maximum = PrepareIni::fillMaximum(channelValues);
    file.write(reinterpret_cast<char*>(&maximum));
    file.close();
}

void PrepareIni::notAccess()
{
    //writeIni()
}

