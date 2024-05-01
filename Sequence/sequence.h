#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <QObject>

#include "../BaseDateTime/basedatetime.h"

struct SequenceStruct
{
    char name[256];             //Name[256];        // Уникальное имя ряда данных               :000
    char Text[512];                                 // Текст = описание ряда данных             :256
    char Txty[32];                                  // Текст = ед.изм.                          :768
    quint32 dataType;           //Fmode;            // Тип ряда: 0-указатель; i*2/r*4/r*8       :800
    float minSequenceValue;     //Rmin;             //Мин.                                      :804
    float maxSequenceValue;     //Rmax;             //макс.                                     :808
    float empty;                //Prop;             //код пропуска                              :812
    BaseDateTime sequenceDateTime;//Fstart;          // Дата начала ряда                         :816
    quint64 sequenceLength;     //Len;              // Длина ряда В ТОЧКАХ                      :856
    quint32 surveyFrequency;    //Series_Type;      // Частота опроса данных задана в:          :864
    //       Вариант 4.31:           ! 11-годах; 12-месяцах; 13-сутках; 14-часах;
    //                                ! 15-минутах; 16-секундах; 17-милисекундах; 18-микросекундах;
    quint32 Series_Step;                            // Частота набл. в единицах series_type     :868
    quint64 Record;                                 // Текущая запись                           :872
    float Scri,Scir;                                // Параметры запаковки данных               :880
    char Form[8];                                   // Формат печати значений,                  :888
    quint32 Marked;                                 // Пометка: .T-ряд помечен                  :896
    //       Сведения о методе создания ряда (список вариантов см. ниже):
    quint32 F_init;                                 // признак происхождения ряда               :900
    quint32 F_num;                                  // Дополнительная информация к F_init       :904
    //       Параметры для спектров, сохраненных "как временной ряд"
    quint32 S_int_type, S_int_step;                 //  ! параметры "выборки спектра":          :908
    quint32 S_type, S_smooth;                       //        ! вид и сглаживание спектра:      :916
    quint32 isw;                                    // число элементов даты в редакторе и др., 1-8.:924
    quint64 N_prop;                                 // Число пропусков или -1 если неизвестно   :928
    char Dummy_88[88];                              //             ! Зарезервировано            :936
};

class Sequence : public QObject
{
    Q_OBJECT
public:
    explicit Sequence(QObject *parent = nullptr);

signals:

};

#endif // SEQUENCE_H
