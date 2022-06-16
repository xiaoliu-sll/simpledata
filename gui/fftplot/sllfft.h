#ifndef SLLFFT_H
#define SLLFFT_H

#include <QObject>
#include "fftw3.h"
#include <QtMath>
#include <QVector>
class sllFFT : public QObject
{
#define DATA_SAMPLING_FREQ 1000
    Q_OBJECT
public:
    explicit sllFFT(qint16 len);
    void pushdata(QVector<double> valueVector);
signals:
    void processCompleted(QVector<double> t_vectorX, QVector<double> t_vectorY);
private:
    qint16 nLen;
    QVector<QVector<double>> outvaluetemp;
    QVector<double> outvalue;
     QVector<double> xAxis;
    fftw_plan plan_fft;
    fftw_complex *out_fft;
    void fftInit(qint16 len);
    void fftunit(QVector<double> Value,qint16 len);
   char AddData(double value);

};

#endif // SLLFFT_H
