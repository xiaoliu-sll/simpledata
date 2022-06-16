#include "sllfft.h"
#include <QDebug>
sllFFT::sllFFT(qint16 len)
{
        nLen = len;
    fftInit(nLen);
}

void sllFFT::pushdata(QVector<double> valueVector)
{
    static QVector<double> fft_In;
    for (int i=0; i<valueVector.size(); i++) {
        fft_In.append(valueVector[i]);

        if(fft_In.size() >= nLen){
            fftunit(fft_In,nLen);
            emit processCompleted(this->xAxis, this->outvalue);
//            qDebug() << outvalue.size();
            fft_In.resize(0);
          // qDebug()<<""<<"t_vector"<<t_vector.size()<<time.elapsed()/1000.0<<"s";//测试时间ms级别
        }
//        qDebug()<<fft_In.size()<<valueVector.size();
    }
}
void sllFFT::fftInit(qint16 len)
{

    out_fft = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * len);

    xAxis.resize(len/2);
        for (quint16 i=0;i<len/2;i++)
        {
            xAxis[i] = i * (DATA_SAMPLING_FREQ/nLen);
        }
//        xAxis.remove(0, 2);
}

void sllFFT::fftunit(QVector<double> Value,qint16 len)
{
    QVector<double> psd_amp(len);
      for (quint16 i = 0;i < len;i ++)
      {
          psd_amp[i] = 0.5*(1-qCos(2*M_PI*i/(len-1)))*qSqrt(1.633);
          Value[i]=Value[i]*psd_amp[i];
      }
      plan_fft = fftw_plan_dft_r2c_1d(len, &Value[0], out_fft, FFTW_ESTIMATE);
      fftw_execute(plan_fft);// 执行变换

      QVector<double> psd_amptemp(len/2);

      for (quint16 i = 0;i < len/2;i ++)
      {
          psd_amptemp[i] = qSqrt(((out_fft[i][0]*out_fft[i][0]+out_fft[i][1]*out_fft[i][1]))
                  /(len*DATA_SAMPLING_FREQ/4));
      }
//      psd_amptemp.remove(0,2);
//      psd_amp.remove(0,2);
      fftw_destroy_plan(plan_fft);
//      outvaluetemp.push_back(psd_amptemp);

      outvalue.resize(psd_amptemp.size());
//    qDebug() << xAxis.size() << outvalue.size();
      for (int i=0;i<outvalue.size();i++)
      {
//          if (bAverageFlag)
//          {
//              double sum = 0.0;
//              for (int j = 0;j<vvPSD.size();j++)
//              {
//                  sum += vvPSD[j][i];
//              }
//              vPsdOut[i] = sum / vvPSD.size();
//          }
//          else
          {
              outvalue[i] = psd_amptemp[i];
          }
      }

}

