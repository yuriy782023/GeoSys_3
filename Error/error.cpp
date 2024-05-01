#include "error.h"

Error::Error(QObject *parent) : QObject(parent)
{
    Journal journal;
    journal.goodCondition = true;
    journal.tittle = "";
    journal.text = "";
    journal.type = Journal::Empty;

}

void Error::absentFile(QString fileName)
{
    Journal journal;
    journal.goodCondition = false;
    journal.tittle = "Фатальная ошибка";
    journal.text = "Файл <" + fileName + "> не найден!";
    journal.type = Journal::Critical;
    emit journalOut(journal);
}

void Error::absentFileNotError(QString fileName)
{
    Journal journal;
    journal.goodCondition = true;
    journal.tittle = "Информация";
    journal.text = "Файл <" + fileName + "> не найден! Будет создан новый!";
    journal.type = Journal::Information;
    emit journalOut(journal);
}

void Error::absentAnySources(QString filePath)
{
    Journal journal;
    journal.goodCondition = true;
    journal.tittle = "Информация";
    journal.text = "В каталоге <" + filePath + "исходные файлы отсутсвуют!";
    journal.type = Journal::Information;
    emit journalOut(journal);
}

void Error::absentSourcesForInput(QString filePath)
{
    Journal journal;
    journal.goodCondition = true;
    journal.tittle = "Информация";
    journal.text = "В каталоге <" + filePath + "все файлы введены!";
    journal.type = Journal::Information;
    emit journalOut(journal);
}

void Error::manyFiles(QString fileName)
{
    Journal journal;
    journal.goodCondition = false;
    journal.tittle = "Фатальная ошибка";
    journal.text = "Найдено несколько файлов с именем <" + fileName + ">!";
    journal.type = Journal::Critical;
    emit journalOut(journal);
}

void Error::zeroFileSize(QString fileName)
{
    Journal journal;
    journal.goodCondition = false;
    journal.tittle = "Фатальная ошибка";
    journal.text = "Размер файла <" + fileName + "> равен нулю!";
    journal.type = Journal::Critical;
    emit journalOut(journal);
}

void Error::multFileSize(QString fileName)
{
    Journal journal;
    journal.goodCondition = false;
    journal.tittle = "Фатальная ошибка";
    journal.text = "Размер файла <" + fileName + "> не кратен типу файла!";
    journal.type = Journal::Critical;
    emit journalOut(journal);
}

void Error::iniFormatError(QString fileName)
{
    Journal journal;
    journal.goodCondition = false;
    journal.tittle = "Фатальная ошибка";
    journal.text = "Ошибка формата файла <" + fileName + ">!";
    journal.type = Journal::Critical;
    emit journalOut(journal);
}

void Error::notAccessFile(QString fileName, QString fileErrorString)
{
    Journal journal;
    journal.goodCondition = false;
    journal.tittle = "Фатальная ошибка";
    journal.text = "Файл <" + fileName + "> не открывается! " + fileErrorString;
    journal.type = Journal::Critical;
    emit journalOut(journal);
}

void Error::createFile(QString fileName)
{
    Journal journal;
    journal.goodCondition = true;
    journal.tittle = "Информация";
    journal.text = "Создан файл <" + fileName + ">!";
    journal.type = Journal::Information;
    emit journalOut(journal);
}

void Error::notCreateFile(QString fileName, QString fileErrorString)
{
    Journal journal;
    journal.goodCondition = false;
    journal.tittle = "Фатальная ошибка";
    journal.text = "Файл <" + fileName + "> не создается! " + fileErrorString;
    journal.type = Journal::Critical;
    emit journalOut(journal);
}

void Error::notReadFile(QString fileName, QString fileErrorString)
{
    Journal journal;
    journal.goodCondition = false;
    journal.tittle = "Фатальная ошибка";
    journal.text = "Файл <" + fileName + "> не читается! " + fileErrorString;
    journal.type = Journal::Critical;
    emit journalOut(journal);
}

void Error::notValidDateTime(QString fileName, int byte)
{
    Journal journal;
    journal.goodCondition = false;
    journal.tittle = "Фатальная ошибка";
    journal.text = "Начиная с байта №" + QString::number(byte) + " в файле <" + fileName + "> неверная дата!";
    journal.type = Journal::Critical;
    emit journalOut(journal);
}

void Error::outOfRangeDateTime(QString fileName, int byte)
{
    Journal journal;
    journal.goodCondition = false;
    journal.tittle = "Фатальная ошибка";
    journal.text = "Начиная с байта №" + QString::number(byte) + " в файле <" + fileName + "> дата вне периода измерений!";
    journal.type = Journal::Critical;
    emit journalOut(journal);
}

void Error::notValidDateTimePeriodEqualDates(QString fileName, int byte, QDateTime dateTime)
{
    Journal journal;
    journal.goodCondition = false;
    journal.tittle = "Фатальная ошибка";
    journal.text = "Начиная с байта №" + QString::number(byte) + " в файле <" + fileName + "> две одинаковые даты " +
                   dateTime.toString("yyyy.MM.dd hh:mm:ss") + "!";
    journal.type = Journal::Critical;
    emit journalOut(journal);
}

void Error::notValidDateTimePeriodDifferentDatesSecondsNotEqualZero(QString fileName, int byte, QDateTime prevDateTime,
                                                                    QDateTime nextDateTime)
{
    Journal journal;
    journal.goodCondition = false;
    journal.tittle = "Фатальная ошибка";
    journal.text = "Начиная с байта №" + QString::number(byte) + " в файле <" + fileName + "> дата " +
                   prevDateTime.toString("yyyy.MM.dd hh:mm:ss") + " стоит раньше даты " +
                   nextDateTime.toString("yyyy.MM.dd hh:mm:ss") + "!";
    journal.type = Journal::Critical;
    emit journalOut(journal);
}

void Error::notValidDateTimePeriodDifferentDatesSecondsEqualZero(QString fileName, int byte,
                                                                 QDateTime prevDateTime, QDateTime nextDateTime)
{
    Journal journal;
    journal.goodCondition = false;
    journal.tittle = "Фатальная ошибка";
    journal.text = "Начиная с байта №" + QString::number(byte) + " в файле <" + fileName + "> дата " +
                   prevDateTime.toString("yyyy.MM.dd hh:mm:ss") + " стоит раньше даты " +
                   nextDateTime.toString("yyyy.MM.dd hh:mm:ss") + "!";
    journal.type = Journal::Empty;
    emit journalOut(journal);
}

void Error::notValidChannelValue(QString fileName, int byte, QDateTime dateTime)
{
    Journal journal;
    journal.goodCondition = false;
    journal.tittle = "Фатальная ошибка";
    journal.text = "Начиная с байта №" + QString::number(byte) + " даты " + dateTime.toString("yyyy.MM.dd hh:mm:ss") +
                   " в файле <" + fileName + "> несуществующее значение!";
    journal.type = Journal::Critical;
    emit journalOut(journal);
}

void Error::outOfRangeChannelValue(QString fileName, int byte, QDateTime dateTime)
{
    Journal journal;
    journal.goodCondition = false;
    journal.tittle = "Фатальная ошибка";
    journal.text = "Начиная с байта №" + QString::number(byte) + " даты " + dateTime.toString("yyyy.MM.dd hh:mm:ss") +
                   " в файле <" + fileName + "> значение вне диапазона измерений!";
    journal.type = Journal::Critical;
    emit journalOut(journal);
}

void Error::baseVersionError()
{
    Journal journal;
    journal.goodCondition = false;
    journal.tittle = "Фатальная ошибка";
    journal.text = "Неправильная версия ABD!";
    journal.type = Journal::Critical;
    emit journalOut(journal);
}

void Error::lockBase(pid_t pid, QString dateTime)
{
    Journal journal;
    journal.goodCondition = false;
    journal.tittle = "База занята";
    journal.text = "Базу использует процесс " + QString::number(pid) + ". База занята с " + dateTime;
    journal.type = Journal::Critical;
    emit journalOut(journal);
}


