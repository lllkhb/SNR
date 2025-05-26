#include <iostream>
#include <cmath>
#include "SNR.h"

using namespace std;

Signal::Signal():
    m_signalAmplitude(0),
    m_noiseAmplitude(0){}

Signal::~Signal(){}

void Signal::setValue(float signal, float noise){
    m_signalAmplitude = signal;
    m_noiseAmplitude = noise;
}

float Signal::getSNR(){
    return 20 * log10(m_signalAmplitude / m_noiseAmplitude);
}

void Signal::toString(){
    cout << "Amplitude of signal: " << m_signalAmplitude << endl;
    cout << "Amplitude of noise: " << m_noiseAmplitude << endl;
}



ClearSignals::ClearSignals():
    m_signal(),
    m_snr(0){}

ClearSignals::ClearSignals(Signal& signal):
    m_signal(signal),
    m_snr(signal.getSNR()){}

ClearSignals::~ClearSignals(){}

float ClearSignals::getSNR(){
    return m_snr;
}

bool ClearSignals::isClear(){
    if(m_snr >= 20)
        return true;
    else
        return false;
}



PureSignals::PureSignals():
    m_signal(),
    m_snr(0){}

PureSignals::PureSignals(Signal& signal):
    m_signal(signal),
    m_snr(signal.getSNR()){}

PureSignals::~PureSignals(){}

float PureSignals::getSNR(){
    return m_snr;
}

bool PureSignals::isPure(){
    if(m_snr < 20)
        return true;
    else
        return false;
}



SignalManager::SignalManager():
    m_clearArray(nullptr),
    m_clearCount(0),
    m_pureArray(nullptr),
    m_pureCount(0){}

SignalManager::~SignalManager(){
    delete[] m_clearArray;
    delete[] m_pureArray;
}

void SignalManager::addClearSignal(ClearSignals& signal){
    if(signal.isClear()){
        ClearSignals* temp = new ClearSignals[m_clearCount + 1];
        for(int i = 0; i < m_clearCount; ++i){
            temp[i] = m_clearArray[i];
        }
        temp[m_clearCount] = signal;
        delete[] m_clearArray;
        m_clearArray = temp;
        m_clearCount++;
    }
}

void SignalManager::addPureSignal(PureSignals& signal){
    if(signal.isPure()){
        PureSignals* temp = new PureSignals[m_pureCount + 1];
        for(int i = 0; i < m_pureCount; ++i){
            temp[i] = m_pureArray[i];
        }
        temp[m_pureCount] = signal;
        delete[] m_pureArray;
        m_pureArray = temp;
        m_pureCount++;
    }
}

void SignalManager::printAll(){
    cout << "Clear Signals (" << m_clearCount << ")" << endl;
    for(int i = 0; i < m_clearCount; ++i){
        cout << "[" << i + 1 << "] SNR = " << m_clearArray[i].getSNR() << " dB" << endl;
    }

    cout << "Pure Signals (" << m_pureCount << ")" << endl;
    for(int i = 0; i < m_pureCount; ++i){
        cout << "[" << i + 1 << "] SNR = " << m_pureArray[i].getSNR() << " dB" << endl;
    }
}
