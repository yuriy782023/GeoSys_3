#include "sloterror.h"

SlotError::SlotError(QString fdn, QObject *parent) : QObject(parent)
{
    fileDirName = fdn;
    checkSlotError = false;
}

bool SlotError::getCheckSlotError()
{
    return checkSlotError;
}

void SlotError::absentFile(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Файл <" + fileDirName + "> не найден!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::absentFileNotError(Journal journal)
{
    QCOMPARE(journal.goodCondition, true);
    QCOMPARE(journal.tittle, "Информация");
    QCOMPARE(journal.text, "Файл <" + fileDirName + "> не найден! Будет создан новый!");
    QCOMPARE(journal.type, Journal::Information);
    checkSlotError = true;
}

void SlotError::absentDescription(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Файл <" + TESTDIR + "/base/_abddata.abd> не найден!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::absentBase(Journal journal)
{
    QCOMPARE(journal.goodCondition, true);
    QCOMPARE(journal.tittle, "Информация");
    QCOMPARE(journal.text, "Файл <" + TESTDIR + "/base/base.abd> не найден! Будет создан новый!");
    QCOMPARE(journal.type, Journal::Information);
    checkSlotError = true;
}

void SlotError::absentSource(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Файл <" + TESTDIR + "/source/source.d> не найден!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::absentAnySources(Journal journal)
{
    QCOMPARE(journal.goodCondition, true);
    QCOMPARE(journal.tittle, "Информация");
    QCOMPARE(journal.text, "В каталоге <" + fileDirName + "исходные файлы отсутсвуют!");
    QCOMPARE(journal.type, Journal::Information);
    checkSlotError = true;
}

void SlotError::absentSourcesForInput(Journal journal)
{
    QCOMPARE(journal.goodCondition, true);
    QCOMPARE(journal.tittle, "Информация");
    QCOMPARE(journal.text, "В каталоге <" + fileDirName + "все файлы введены!");
    QCOMPARE(journal.type, Journal::Information);
    checkSlotError = true;
}

void SlotError::absentIni(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Файл <" + TESTDIR + "/ini/ini.ini> не найден!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::absentInputted(Journal journal)
{
    QCOMPARE(journal.goodCondition, true);
    QCOMPARE(journal.tittle, "Информация");
    QCOMPARE(journal.text, "Файл <" + TESTDIR + "/source/inputtedfiles.jrn> не найден! Будет создан новый!");
    QCOMPARE(journal.type, Journal::Information);
    checkSlotError = true;
}

void SlotError::manyFiles(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Найдено несколько файлов с именем <" + fileDirName + ">!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::manyDescriptions(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Найдено несколько файлов с именем <" + TESTDIR + "/base/_abddata.abd>!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::manyBases(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Найдено несколько файлов с именем <" + TESTDIR + "/base/base1.abd>!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::manySources(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Найдено несколько файлов с именем <" + TESTDIR + "/source/source.d>!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::manyInies(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Найдено несколько файлов с именем <" + TESTDIR + "/ini/ini.ini>!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::manyInputtedes(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Найдено несколько файлов с именем <" + TESTDIR + "/source/inputtedfiles.jrn>!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::zeroFileSize(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Размер файла <" + fileDirName + "> равен нулю!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::multFileSize(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Размер файла <" + fileDirName + "> не кратен типу файла!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::iniFormatError(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Ошибка формата файла <" + fileDirName + ">!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notAccessFile(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Файл <" + fileDirName + "> не открывается! Permission denied");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::createFile(Journal journal)
{
    QCOMPARE(journal.goodCondition, true);
    QCOMPARE(journal.tittle, "Информация");
    QCOMPARE(journal.text, "Создан файл <" + fileDirName + ">!");
    QCOMPARE(journal.type, Journal::Information);
    checkSlotError = true;
}

void SlotError::notCreateFile(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Файл <" + fileDirName + "> не создается! Permission denied");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notReadFile(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Файл <" + fileDirName + "> не читается! Unknown error");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValidDateTime(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №1 в файле <" + fileDirName + "> неверная дата!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRangeDateTime(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №1 в файле <" + fileDirName + "> дата вне периода измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValidDateTimePeriodEqualDates(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №1 в файле <" + fileDirName + "> две одинаковые даты 2023.12.25 12:15:29!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValidDateTimePeriodDifferentDatesSecondsNotEqualZero(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №1 в файле <" + fileDirName + "> дата 2023.12.25 13:15:29" +
             " стоит раньше даты 2023.12.25 12:15:29!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValidDateTimePeriodDifferentDatesSecondsEqualZero(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №1 в файле <" + fileDirName + "> дата 2023.12.25 12:16:00" +
             " стоит раньше даты 2023.12.25 12:15:29!");
    QCOMPARE(journal.type, Journal::Empty);
    checkSlotError = true;
}

void SlotError::notValid1ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №8 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValid2ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №12 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValid3ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №16 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValid4ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №20 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValid5ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №24 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValid6ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №28 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValid7ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №32 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValid8ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №36 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValid9ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №40 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValid10ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №44 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValid11ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №48 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValid12ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №52 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValid13ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №56 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValid14ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №60 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValid15ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №64 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValid16ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №68 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValid17ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №72 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValid18ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №76 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValid19ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №80 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValid20ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №84 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValid21ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №88 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValid22ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №92 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValid23ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №96 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValid24ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №100 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValid25ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №104 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValid26ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №108 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValid27ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №112 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::notValid28ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №116 даты 2024.05.06 05:19:52 в файле <" + fileDirName + "> несуществующее значение!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange1ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №8 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange2ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №12 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange3ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №16 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange4ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №20 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange5ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №24 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange6ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №28 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange7ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №32 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange8ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №36 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange9ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №40 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange10ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №44 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange11ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №48 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange12ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №52 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange13ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №56 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange14ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №60 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange15ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №64 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange16ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №68 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange17ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №72 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange18ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №76 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange19ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №80 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange20ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №84 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange21ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №88 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange22ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №92 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange23ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №96 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange24ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №100 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange25ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №104 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange26ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №108 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange27ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №112 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::outOfRange28ChannelValue(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Начиная с байта №116 даты 2024.05.06 05:36:22 в файле <" + fileDirName +
             "> значение вне диапазона измерений!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::baseVersionError(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "Фатальная ошибка");
    QCOMPARE(journal.text, "Неправильная версия ABD!");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}

void SlotError::lockBase(Journal journal)
{
    QCOMPARE(journal.goodCondition, false);
    QCOMPARE(journal.tittle, "База занята");
    QCOMPARE(journal.text, "Базу использует процесс 1234. База занята с 16:50:00 07.12.2023");
    QCOMPARE(journal.type, Journal::Critical);
    checkSlotError = true;
}





