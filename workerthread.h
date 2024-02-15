#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>
#include <QString>

class WorkerThread : public QThread
{
    Q_OBJECT

public:
    WorkerThread(QObject* obj);

    void run() override;


signals:
    void resultReady(const QString &s);
};

#endif // WORKERTHREAD_H
