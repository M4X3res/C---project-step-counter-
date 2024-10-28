#ifndef STEPCOUNTERALGO_H
#define STEPCOUNTERALGO_H

#include "label.h"
#include <QObject>
#include <QtTest/QTest>
#include <QAccelerometer>
#include <cmath>
#include <QMainWindow>

class StepCounterAlgo : public QThread
{
private:
    QAccelerometer sensor;
    int steps;
    Label *output;

protected:
    void run() override;

public:
    StepCounterAlgo(Label*& output);
    int NumberOfSteps(){return steps;}
    bool checkButton;
    void reset(){steps = 0;}
};

#endif // STEPCOUNTERALGO_H
