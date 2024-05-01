#ifndef INPUTTEDFILES_H
#define INPUTTEDFILES_H

#include <QFile>
#include "../File/file.h"

class InputtedFiles : public File
{
public:
    InputtedFiles(QString inputtedFilesName) : File(inputtedFilesName), inputtedFilesFile(inputtedFilesName) {}
private:
    QFile inputtedFilesFile;
};

#endif // INPUTTEDFILES_H
