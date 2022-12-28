#ifndef SAVEURLS_H
#define SAVEURLS_H

#include "SaveUrls_1228_global.h"

class SAVEURLS_1228_EXPORT SaveUrls
{
public:
    SaveUrls();

    void save(QStringList);
    QStringList load();
};

#endif // SAVEURLS_H
