#ifndef HOMEAUTOMAINWINDOW_H
#define HOMEAUTOMAINWINDOW_H

#include <QMainWindow>
#include <QBoxLayout>
#include <QtWidgets>
#include "DataSourceInterface.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class HomeAutoMainWindow;
}
QT_END_NAMESPACE

class HomeAutoMainWindow : public QWidget
{
    Q_OBJECT

public:
    HomeAutoMainWindow(QWidget *parent = nullptr);
    ~HomeAutoMainWindow();

public slots:
   void addDataSource(DataSourceInterface* data_source);

private:

    QBoxLayout *layout;
    //Ui::HomeAutoMainWindow *ui;
    QVector<DataSourceInterface*>* m_data_sources;

    QGroupBox* horizontalGroupBox;

};
#endif // HOMEAUTOMAINWINDOW_H
