#include "preparesource.h"

PrepareSource::PrepareSource()
{
}

SourceString::DateTime PrepareSource::fillSourceDateTime()
{
    SourceString::DateTime sourceDateTime;
    sourceDateTime.year.high = 2023 / 256;
    sourceDateTime.year.low = 2023 % 256;
    sourceDateTime.month = 12;
    sourceDateTime.day = 25;
    sourceDateTime.hour = 12;
    sourceDateTime.minute = 15;
    sourceDateTime.second = 29;
    return sourceDateTime;
}

SourceString PrepareSource::fillSourceString()
{
    SourceString sourceString;
    sourceString.dateTime = fillSourceDateTime();

    sourceString.channels.measure[0]  = { 0, 0, 0, 1 }; // Motorola byte order
    sourceString.channels.measure[1]  = { 0, 0, 0, 2 }; // Motorola byte order
    sourceString.channels.measure[2]  = { 0, 0, 0, 3 }; // Motorola byte order
    sourceString.channels.measure[3]  = { 0, 0, 0, 4 }; // Motorola byte order
    sourceString.channels.measure[4]  = { 0, 0, 0, 5 }; // Motorola byte order
    sourceString.channels.measure[5]  = { 0, 0, 0, 6 }; // Motorola byte order
    sourceString.channels.measure[6]  = { 0, 0, 0, 7 }; // Motorola byte order
    sourceString.channels.measure[7]  = { 0, 0, 0, 8 }; // Motorola byte order
    sourceString.channels.measure[8]  = { 0, 0, 0, 9 }; // Motorola byte order
    sourceString.channels.measure[9]  = { 0, 0, 0, 10 }; // Motorola byte order
    sourceString.channels.measure[10] = { 0, 0, 0, 11 }; // Motorola byte order
    sourceString.channels.measure[11] = { 0, 0, 0, 12 }; // Motorola byte order
    sourceString.channels.measure[12] = { 0, 0, 0, 13 }; // Motorola byte order
    sourceString.channels.measure[13] = { 0, 0, 0, 14 }; // Motorola byte order
    sourceString.channels.measure[14] = { 0, 0, 0, 15 }; // Motorola byte order
    sourceString.channels.measure[15] = { 0, 0, 0, 16 }; // Motorola byte order
    sourceString.channels.measure[16] = { 0, 0, 0, 17 }; // Motorola byte order
    sourceString.channels.measure[17] = { 0, 0, 0, 18 }; // Motorola byte order
    sourceString.channels.measure[18] = { 0, 0, 0, 19 }; // Motorola byte order
    sourceString.channels.measure[19] = { 0, 0, 0, 20 }; // Motorola byte order
    sourceString.channels.measure[20] = { 0, 0, 0, 21 }; // Motorola byte order
    sourceString.channels.measure[21] = { 0, 0, 0, 22 }; // Motorola byte order
    sourceString.channels.measure[22] = { 0, 0, 0, 23 }; // Motorola byte order
    sourceString.channels.measure[23] = { 0, 0, 0, 24 }; // Motorola byte order
    sourceString.channels.measure[24] = { 0, 0, 0, 25 }; // Motorola byte order
    sourceString.channels.measure[25] = { 0, 0, 0, 26 }; // Motorola byte order
    sourceString.channels.measure[26] = { 0, 0, 0, 27 }; // Motorola byte order
    sourceString.channels.accumulator = { 0, 28 };  // Motorola byte order
    return sourceString;
}

void PrepareSource::writeSourceString(QString fileName, SourceString sourceString)
{
    PrepareFile::clearTestDir();
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    file.write(reinterpret_cast<char*>(&sourceString), 117);
    file.close();
}

void PrepareSource::notAccess(QString fileName)
{
    writeSourceString(fileName, fillSourceString());
    QFile::setPermissions(fileName, 0);
}

SourceString PrepareSource::notValidYear(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.dateTime.year.high = 0;
    sourceString.dateTime.year.low = 0;
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValidMonth(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.dateTime.month = 56;
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValidDay(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.dateTime.day = 78;
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValidHour(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.dateTime.hour = 45;
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValidMinute(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.dateTime.minute = 83;
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValidSecond(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.dateTime.second = 93;
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::lessRangeDateTime(QString fileName)
{
    SourceString sourcestring = fillSourceString();
    sourcestring.dateTime.year.high = 2000 / 256;
    sourcestring.dateTime.year.low = 2000 % 256;
    writeSourceString(fileName, sourcestring);
    return sourcestring;
}

SourceString PrepareSource::moreRangeDateTime(QString fileName)
{
    SourceString sourcestring = fillSourceString();
    sourcestring.dateTime.year.high = 3000 / 256;
    sourcestring.dateTime.year.low = 3000 % 256;
    writeSourceString(fileName, sourcestring);
    return sourcestring;
}

QPair<SourceString, SourceString> PrepareSource::firstDateTimeEqualSecondDateTime(QString fileName)
{
    SourceString firstSourceString, secondSourceString;
    firstSourceString = secondSourceString = fillSourceString();
    PrepareFile::clearTestDir();
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    file.write(reinterpret_cast<char*>(&firstSourceString), 117);
    file.write(reinterpret_cast<char*>(&secondSourceString), 117);
    file.close();
    return { firstSourceString, secondSourceString };
}

QPair<SourceString, SourceString> PrepareSource::firstDateTimeAfterSecondDateTime_secondsNotEqualZero(QString fileName)
{
    SourceString firstSourceString, secondSourceString;
    firstSourceString = secondSourceString = fillSourceString();
    firstSourceString.dateTime.hour++; // 13
    PrepareFile::clearTestDir();
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    file.write(reinterpret_cast<char*>(&firstSourceString), 117);
    file.write(reinterpret_cast<char*>(&secondSourceString), 117);
    file.close();
    return { firstSourceString, secondSourceString };
}

QPair<SourceString, SourceString> PrepareSource::firstDateTimeAfterSecondDateTime_secondsEqualZero(QString fileName)
{
    SourceString firstSourceString, secondSourceString;
    firstSourceString = secondSourceString = fillSourceString();
    firstSourceString.dateTime.minute++; // 16
    firstSourceString.dateTime.second = 0;
    PrepareFile::clearTestDir();
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    file.write(reinterpret_cast<char*>(&firstSourceString), 117);
    file.write(reinterpret_cast<char*>(&secondSourceString), 117);
    file.close();
    return { firstSourceString, secondSourceString };
}

QPair<SourceString, SourceString> PrepareSource::firstDateTimeBeforeSecondDateTime(QString fileName) // good condition
{
    SourceString firstSourceString, secondSourceString;
    firstSourceString = secondSourceString = fillSourceString();
    firstSourceString.dateTime.second--; // 28
    PrepareFile::clearTestDir();
    QFile file(fileName);
    file.open(QIODevice::WriteOnly);
    file.write(reinterpret_cast<char*>(&firstSourceString), 117);
    file.write(reinterpret_cast<char*>(&secondSourceString), 117);
    file.close();
    return { firstSourceString, secondSourceString };
}

SourceString PrepareSource::notValid1Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.measure[0] = { 1, 0, 0, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValid2Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.measure[1] = { 2, 0, 0, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValid3Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.measure[2] = { 3, 0, 0, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValid4Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.measure[3] = { 4, 0, 0, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValid5Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.measure[4] = { 5, 0, 0, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValid6Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.measure[5] = { 6, 0, 0, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValid7Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.measure[6] = { 7, 0, 0, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValid8Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.measure[7] = { 8, 0, 0, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValid9Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.measure[8] = { 9, 0, 0, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValid10Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.measure[9] = { 10, 0, 0, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValid11Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.measure[10] = { 11, 0, 0, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValid12Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.measure[11] = { 12, 0, 0, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValid13Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.measure[12] = { 13, 0, 0, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValid14Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.measure[13] = { 14, 0, 0, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValid15Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.measure[14] = { 15, 0, 0, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValid16Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.measure[15] = { 16, 0, 0, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValid17Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.measure[16] = { 17, 0, 0, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValid18Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.measure[17] = { 18, 0, 0, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValid19Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.measure[18] = { 19, 0, 0, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValid20Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.measure[19] = { 20, 0, 0, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValid21Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.measure[20] = { 21, 0, 0, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValid22Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.measure[21] = { 22, 0, 0, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValid23Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.measure[22] = { 23, 0, 0, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValid24Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.measure[23] = { 24, 0, 0, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValid25Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.measure[24] = { 25, 0, 0, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValid26Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.measure[25] = { 26, 0, 0, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValid27Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.measure[26] = { 27, 0, 0, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}

SourceString PrepareSource::notValid28Channel(QString fileName)
{
    SourceString sourceString = fillSourceString();
    sourceString.channels.accumulator = { 255, 0 };
    writeSourceString(fileName, sourceString);
    return sourceString;
}


