#include "ini.h"

Ini::~Ini()
{
    if (iniFile.isOpen())
        iniFile.close();
}

bool Ini::openIni()
{
    QSettings settings(iniFile.fileName(), QSettings::IniFormat);
    return true;
}


