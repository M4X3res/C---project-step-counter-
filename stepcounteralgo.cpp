#include "stepcounteralgo.h"

StepCounterAlgo::StepCounterAlgo(Label*& output)
    : QThread{nullptr}, steps(0)
{
    this->output=output;
    sensor.connectToBackend();
    sensor.setProperty("alwaysOn",true);
    sensor.start();
}

void StepCounterAlgo::run()
{
    checkButton = true;

    while(checkButton)
    {
        std::vector<qreal> aFinalMax;
        qreal eps,aXmax, aYmax, aZmax, aXavg=0,aYavg=0,aZavg=0, aAllAvg=0;

        for(int j =0;j<5;j++)
        {
            std::vector<qreal> aX,aY,aZ,aAll,aFinal;
            for(int i =0;i<10;i++)
            {
                aX.push_back(sensor.reading()->x());
                aY.push_back(sensor.reading()->y());
                aZ.push_back(sensor.reading()->z());
                aAll.push_back(sqrt(aX[i]*aX[i]+aY[i]*aY[i]+aZ[i]*aZ[i]));
                aAllAvg+=aAll[i];
                QTest::qSleep(40);
            }
            aAllAvg/=10;

            for(int i=0;i<10;i++)
                aFinal.push_back(aAll[i] - aAllAvg);

            aFinalMax.push_back(*std::max_element(aFinal.begin(),aFinal.end()));

            aXmax=*std::max_element(aX.begin(),aX.end());
            aXavg+=aXmax;

            aYmax=*std::max_element(aY.begin(),aY.end());
            aYavg+=aYmax;

            aZmax=*std::max_element(aZ.begin(),aZ.end());
            aZavg+=aZmax;

        }

        aXavg/=5;aYavg/=5;aZavg/=5;

        eps = (((abs(aXavg)+abs(aYavg)+abs(aZavg))/3)-3);

        for(int i =0;i<5;i++)
            if(aFinalMax[i]>eps)
                steps++;

        output->output.setText(QString::number(steps));
    }
}
