#include "workerthread.h"
#include "thermometer.h"
#include <QDebug>
#include <QRandomGenerator>

WorkerThread::WorkerThread(QObject *parent)
    : QThread{parent}
{

}

void WorkerThread::run() {

    if (!qobject_cast<Thermometer*>(this->parent())) {
        // was not Thermometer, exit
        return;
    }

    /**
     * @brief This is a stub implementation for a thermometer.
     * In actual implementation this thread could eg. poll thermometer for value updates.
     */

    Thermometer* thermo = qobject_cast<Thermometer*>(this->parent());
    QString name = thermo->getData();
    qInfo() << name;
    float base_temp = 0.0;
    int high = 0;

    if (name.contains("room")) {
        // room temperatures
        base_temp = 19.5;
        high = 4;
    } else if (name == "Sauna"){
        // high sauna temperatures
        base_temp = 85.0;
        high = 6;
    } else if (name == "Outdoor") {
        // freezing cold
        base_temp = -35.2;
        high = 2;
    }

    while (!this->isInterruptionRequested()) {
        double change = QRandomGenerator::global()->generateDouble() * high;
        emit resultReady(QString::number(base_temp + change, 'f', 1)+" °C");
        sleep(5+(int)change);
    }
}

