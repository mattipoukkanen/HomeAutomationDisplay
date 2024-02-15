#include "thermometer.h"


Thermometer::Thermometer(QString name) : DataSourceInterface(name) {
    m_name = name;

    m_groupBox = new QGroupBox(tr(name.toStdString().c_str()));
    m_layout = new QVBoxLayout;
    m_label = new QLabel(name);
    m_value = new QLabel();

    m_layout->addWidget(m_label);
    m_layout->addWidget(m_value);
    m_groupBox->setLayout(m_layout);
    m_label->show();
    m_value->show();
    this->setLayout(m_layout);
    valueUpdater = new WorkerThread(this);
    valueUpdater->start();

    QObject::connect(valueUpdater, SIGNAL(resultReady(QString)), this, SLOT(updateValue(QString)));
}

QString Thermometer::getData() {
    return m_name;
}

Thermometer::~Thermometer() {
    valueUpdater->terminate();
    valueUpdater->deleteLater();
    delete m_groupBox;
    delete m_layout;
    delete m_label;
    delete m_value;
}

void Thermometer::updateValue(const QString &s) {
    qInfo() << "update " << s;
    m_value->setText(s);
}
