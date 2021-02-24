#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QObject>

class mypushbutton : public QObject
{
    Q_OBJECT
public:
    explicit mypushbutton(QObject *parent = nullptr);

signals:

};

#endif // MYPUSHBUTTON_H
