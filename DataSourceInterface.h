#ifndef DATASOURCEINTERFACE_H
#define DATASOURCEINTERFACE_H

#include <QWidget>
class QString;

class DataSourceInterface : public QWidget {

    protected:
        QString name;

    DataSourceInterface(QString name){ name = name; };
    virtual QString getData() = 0;

};

#endif // DATASOURCEINTERFACE_H
