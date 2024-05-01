#ifndef BASE_H
#define BASE_H

#include "../BaseDateTime/basedatetime.h"
#include "../File/file.h"

struct BaseStruct
{
    char version[8];            //Version[8];       // Метка версии базы данных                 :000
    quint32 sequenceQuantity;   //Nf;               // Фактическое число рядов в БД             :008
    quint32 Cursor;                                 // Позиция курсора (номер ряда)             :012
    quint32 Nmin;                                   // Номер первого ряда, видимого на экране   :016
    quint16 i1Year;                                 // Дата (год-80) и месяц                    :020
    quint16 i1Month;                                // обновления данных                        :022
    quint64 Disk;                                   // Максимальный доступный размер в байтах   :024
    quint64 N1_10;                                  // Контрольная сумма                        :032
    quint64 Code1;                                  // Код-1 (четность)                         :040
    quint32 DB_reg;                                 // Признак проверки базы данных             :048
    quint32 Dummy4;                                 // Доступная память                         :056

    quint64 Code2;                                  // Код-2                                    :060
    char Label[256];                                // Имя базы данных                          :064
    char Description[512];                          // Описание базы данных                     :320
    quint64 Code3;                                  // Код-3                                    :832
    quint64 D1;                                     // Резерв                                   :840
    quint64 pid;                //PID;              // Текущий "хозяин" БД                      :848
    BaseDateTime pidDate;        //PID_date;         // дата присвоения БД                       :856
    char dummy_128[128];                            // Резерв                                   :896
};

class Base : public File
{
public:
    Base(QString baseName) : File(baseName), baseFile(baseName) {}
    ~Base();
private:
    QFile baseFile;
};

#endif // BASE_H
