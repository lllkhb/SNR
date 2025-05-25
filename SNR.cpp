#include <iostream>
#include "SNR.h"
#include <math.h>

using namespace std;

Signal::Signal(){
    m_signalAmplitude = 0;
    m_noiseAmplitude = 0;
};

ClearSignals::ClearSignals(Signal &signal):
    m_signal(signal)
{
    m_snr = m_signal.getSNR();
}

PureSignals::PureSignals(Signal &signal):
    m_signal(signal)
{
    m_snr = m_signal.getSNR();
}

Signal::~Signal(){

}

ClearSignals::~ClearSignals(){

}

PureSignals::~PureSignals(){

}

void Signal::setValue(int signal, int noise){
    m_signalAmplitude = signal;
    m_noiseAmplitude = noise;
}

float Signal::getSNR(){
    float SNR = 20*log10(m_signalAmplitude/m_noiseAmplitude);
    return SNR;
}

void Signal::toString(){
    cout << "Amplitude of signal: " << m_signalAmplitude << endl;
    cout << "Amplitude of noise: " << m_noiseAmplitude << endl;
}
