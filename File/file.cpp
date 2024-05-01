#include "file.h"

File::~File()
{
}

bool File::absentFile()
{
    if ( ! QFile::exists(fileName)) {
        Error::absentFile(fileName);
        return false;
    }

    return true;
}

void File::absentFileNotError()
{
    if ( ! QFile::exists(fileName)) {
        QFile file(fileName); // need check access
        file.open(QIODevice::WriteOnly);
        file.close();
        Error::absentFileNotError(fileName);
    }
}

bool File::manyFiles()
{
    QFileInfo fileInfo(fileName);
    QDir dir = fileInfo.absoluteDir();
    QStringList fileList = dir.entryList(QStringList(fileInfo.fileName()), QDir::Files);

    if (fileList.size() > 1) {
        Error::manyFiles(fileName);
        return false;
    }

    return true;
}

bool File::zeroFileSize()
{
    QFile file(fileName);

    if (file.size() == 0) {
        Error::zeroFileSize(fileName);
        return false;
    }

    return true;
}

bool File::multFileSize(int multiple)
{
    QFile file(fileName);

    if (file.size() % multiple > 0) {
        Error::multFileSize(fileName);
        return false;
    }

    return true;
}

bool File::openFile()
{}

bool File::read()
{}

bool File::write()
{}

