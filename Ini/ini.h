#ifndef INI_H
#define INI_H

#include <QFile>
#include <QSettings>

#include "../File/file.h"

struct IniStruct {
    std::array<qreal, 28> voltageOffset;
    std::array<qreal, 28> voltageMultiple;
    std::array<qreal, 28> absoluteOffset;
    std::array<qreal, 28> absoluteMultiple;
    std::array<qreal, 28> minimumValue;
    std::array<qreal, 28> maximumValue;
};

class Ini : public File
{
public:
    Ini(QString iniName) : File(iniName), iniFile(iniName) {}
    ~Ini();
    bool openIni();

private:
    QFile iniFile;

};

#endif // INI_H
