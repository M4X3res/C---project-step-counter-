#ifndef LABEL_H
#define LABEL_H

#include <QThread>
#include <QLabel>

class Label : public QThread
{
public:
    explicit Label(QObject *parent = nullptr);
    QLabel output;
};

#endif // LABEL_H
