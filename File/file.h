#ifndef FILEERRORS_H
#define FILEERRORS_H

#include <QFile>

#include "../Error/error.h"

class File : public Error
{
public:
    File(QString fn) { fileName = fn; }
    ~File();
    QString getFileName() { return fileName; }
    bool absentFile();
    void absentFileNotError();
    bool manyFiles();
    bool zeroFileSize();
    bool multFileSize(int multiple);
    bool openFile();
    bool read();
    bool write();

private:
    QString fileName;
};

#endif // FILEERRORS_H
