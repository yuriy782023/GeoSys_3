#ifndef ERROR_H
#define ERROR_H

#include <QObject>
#include <QTest>

struct Journal {
    Journal() { goodCondition = true; tittle = "Good condition"; text = "Absent any errors"; type = Empty; }
    bool goodCondition;
    QString tittle, text;
    int type;
    enum Type { Empty, Information, Warning, Critical, Question };
};

class Error : public QObject
{
    Q_OBJECT
public:
    explicit Error(QObject *parent = nullptr);
    void absentFile(QString fileName);
    void absentFileNotError(QString fileName);
    void absentAnySources(QString filePath);
    void absentSourcesForInput(QString filePath);
    void manyFiles(QString fileName);
    void zeroFileSize(QString fileName);
    void multFileSize(QString fileName);
    void iniFormatError(QString fileName);
    void notAccessFile(QString fileName, QString fileErrorString);
    void createFile(QString fileName);
    void notCreateFile(QString fileName, QString fileErrorString);
    void notReadFile(QString fileName, QString fileErrorString);
    void notValidDateTime(QString fileName, int byte);
    void outOfRangeDateTime(QString fileName, int byte);
    void notValidDateTimePeriodEqualDates(QString fileName, int byte, QDateTime dateTime);
    void notValidDateTimePeriodDifferentDatesSecondsNotEqualZero(QString fileName, int byte,
                                                                 QDateTime prevDateTime, QDateTime nextDateTime);
    void notValidDateTimePeriodDifferentDatesSecondsEqualZero(QString fileName, int byte, QDateTime prevDateTime,
                                                              QDateTime nextDateTime);
    void notValidChannelValue(QString fileName, int byte, QDateTime dateTime);
    void outOfRangeChannelValue(QString fileName, int byte, QDateTime dateTime);
    void baseVersionError();
    void lockBase(pid_t pid, QString dateTime);

signals:
    void journalOut(Journal);

private:
};

#endif // ERROR_H
