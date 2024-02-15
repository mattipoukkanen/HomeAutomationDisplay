#ifndef THERMOMETER_H
#define THERMOMETER_H

#include <QObject>
#include <QString>
#include <QLabel>
#include <QVBoxLayout>
#include <QGroupBox>
#include "workerthread.h"

#include "DataSourceInterface.h"

class Thermometer : public DataSourceInterface
{
    Q_OBJECT

public:
    Thermometer(QString name);


    QString getData(); // override DataSourceInterface::getData()

private:
    ~Thermometer();

    QString m_name;
    QLabel* m_label;
    QLabel* m_value;
    QVBoxLayout* m_layout;
    QGroupBox* m_groupBox;
    WorkerThread* valueUpdater;

public slots:
    void updateValue(const QString &s);

};

#endif // THERMOMETER_H
