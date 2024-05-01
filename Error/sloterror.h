#ifndef TESTSLOTERROR_H
#define TESTSLOTERROR_H

#include <QObject>
#include <QtTest>
#include "error.h"

#define TESTDIR QDir::currentPath() + "/test"

class SlotError : public QObject
{
    Q_OBJECT
public:
    explicit SlotError(QString fdn, QObject *parent = nullptr);
    bool getCheckSlotError();

signals:

public slots:
    void absentFile(Journal journal);
    void absentFileNotError(Journal journal);
    void absentDescription(Journal journal);
    void absentBase(Journal journal);
    void absentSource(Journal journal);
    void absentAnySources(Journal journal);
    void absentSourcesForInput(Journal journal);
    void absentIni(Journal journal);
    void absentInputted(Journal journal);

    void manyFiles(Journal journal);
    void manyDescriptions(Journal journal);
    void manyBases(Journal journal);
    void manySources(Journal journal);
    void manyInies(Journal journal);
    void manyInputtedes(Journal journal);

    void zeroFileSize(Journal journal);
    void multFileSize(Journal journal);
    void iniFormatError(Journal journal);

    void notAccessFile(Journal journal);
    void createFile(Journal journal);
    void notCreateFile(Journal journal);
    void notReadFile(Journal journal);

    void notValidDateTime(Journal journal);
    void outOfRangeDateTime(Journal journal);
    void notValidDateTimePeriodEqualDates(Journal journal);
    void notValidDateTimePeriodDifferentDatesSecondsNotEqualZero(Journal journal);
    void notValidDateTimePeriodDifferentDatesSecondsEqualZero(Journal journal);

    void notValid1ChannelValue(Journal journal);
    void notValid2ChannelValue(Journal journal);
    void notValid3ChannelValue(Journal journal);
    void notValid4ChannelValue(Journal journal);
    void notValid5ChannelValue(Journal journal);
    void notValid6ChannelValue(Journal journal);
    void notValid7ChannelValue(Journal journal);
    void notValid8ChannelValue(Journal journal);
    void notValid9ChannelValue(Journal journal);
    void notValid10ChannelValue(Journal journal);
    void notValid11ChannelValue(Journal journal);
    void notValid12ChannelValue(Journal journal);
    void notValid13ChannelValue(Journal journal);
    void notValid14ChannelValue(Journal journal);
    void notValid15ChannelValue(Journal journal);
    void notValid16ChannelValue(Journal journal);
    void notValid17ChannelValue(Journal journal);
    void notValid18ChannelValue(Journal journal);
    void notValid19ChannelValue(Journal journal);
    void notValid20ChannelValue(Journal journal);
    void notValid21ChannelValue(Journal journal);
    void notValid22ChannelValue(Journal journal);
    void notValid23ChannelValue(Journal journal);
    void notValid24ChannelValue(Journal journal);
    void notValid25ChannelValue(Journal journal);
    void notValid26ChannelValue(Journal journal);
    void notValid27ChannelValue(Journal journal);
    void notValid28ChannelValue(Journal journal);

    void outOfRange1ChannelValue(Journal journal);
    void outOfRange2ChannelValue(Journal journal);
    void outOfRange3ChannelValue(Journal journal);
    void outOfRange4ChannelValue(Journal journal);
    void outOfRange5ChannelValue(Journal journal);
    void outOfRange6ChannelValue(Journal journal);
    void outOfRange7ChannelValue(Journal journal);
    void outOfRange8ChannelValue(Journal journal);
    void outOfRange9ChannelValue(Journal journal);
    void outOfRange10ChannelValue(Journal journal);
    void outOfRange11ChannelValue(Journal journal);
    void outOfRange12ChannelValue(Journal journal);
    void outOfRange13ChannelValue(Journal journal);
    void outOfRange14ChannelValue(Journal journal);
    void outOfRange15ChannelValue(Journal journal);
    void outOfRange16ChannelValue(Journal journal);
    void outOfRange17ChannelValue(Journal journal);
    void outOfRange18ChannelValue(Journal journal);
    void outOfRange19ChannelValue(Journal journal);
    void outOfRange20ChannelValue(Journal journal);
    void outOfRange21ChannelValue(Journal journal);
    void outOfRange22ChannelValue(Journal journal);
    void outOfRange23ChannelValue(Journal journal);
    void outOfRange24ChannelValue(Journal journal);
    void outOfRange25ChannelValue(Journal journal);
    void outOfRange26ChannelValue(Journal journal);
    void outOfRange27ChannelValue(Journal journal);
    void outOfRange28ChannelValue(Journal journal);

    void baseVersionError(Journal journal);
    void lockBase(Journal journal);

private:
    QString fileDirName;
    bool checkSlotError;
};

#endif // TESTSLOTERROR_H
