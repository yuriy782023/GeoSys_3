#ifndef BASEDATETIME_H
#define BASEDATETIME_H

#include <QtGlobal>
#include <QDateTime>

class BaseDateTime
{
public:
    BaseDateTime();
    BaseDateTime(QDateTime dateTime);

private:
    quint64 year;
    quint32 month;
    quint32 day;
    quint32 hour;
    quint32 minute;
    quint32 second;
    quint32 dummy;
    quint64 millisec;

};

#endif // BASEDATETIME_H
