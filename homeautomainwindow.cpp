#include "homeautomainwindow.h"
#include "thermometer.h"
#include <QtWidgets>

class DataSourceInterface;

HomeAutoMainWindow::HomeAutoMainWindow(QWidget *parent)
    : QWidget(parent)
{

    QVBoxLayout *mainLayout = new QVBoxLayout;

    horizontalGroupBox = new QGroupBox(tr("Thermometers"));
    layout = new QBoxLayout(QBoxLayout::Direction::LeftToRight, this);

    m_data_sources = new QVector<DataSourceInterface*>();

    Thermometer* thermo = new Thermometer("Living room");
    Thermometer* thermo2 = new Thermometer("Bedroom");
    Thermometer* thermo3 = new Thermometer("Sauna");
    Thermometer* thermo4 = new Thermometer("Outdoor");
    Thermometer* thermo5 = new Thermometer("Laundry room");

    addDataSource(thermo);
    addDataSource(thermo2);
    addDataSource(thermo3);
    addDataSource(thermo4);
    addDataSource(thermo5);

    horizontalGroupBox->setLayout(layout);
    mainLayout->addWidget(horizontalGroupBox);
    QWidget *scrollAreaContent = new QWidget;
    scrollAreaContent->setLayout(mainLayout);

    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setFrameShape(QFrame::NoFrame);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setWidgetResizable(true);
    scrollArea->verticalScrollBar()->setStyleSheet("QScrollBar:vertical {width: 20px;}");

    scrollArea->setWidget(scrollAreaContent);

    QVBoxLayout *scrollLayout = new QVBoxLayout;
    scrollLayout->setContentsMargins(0,0,0,0);
    scrollLayout->addWidget(scrollArea);

    setLayout(scrollLayout);
    setWindowTitle(tr("Home automation display"));

    show();
}

HomeAutoMainWindow::~HomeAutoMainWindow()
{
    delete layout;
    for (int i = 0; i < m_data_sources->count(); i++) {
        m_data_sources->at(i)->deleteLater();
    }
    delete m_data_sources;
}

void HomeAutoMainWindow::addDataSource(DataSourceInterface* data_source) {
    m_data_sources->append(data_source);
    layout->addWidget(data_source);
    data_source->show();
}
