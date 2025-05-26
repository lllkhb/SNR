#include <iostream>
#include <cmath>
#include <string>
#include "SNR.h"

using namespace std;

Signal::Signal():
    m_signalAmplitude(0),
    m_noiseAmplitude(0)
{
logMessage("Signal was created");
}

Signal::~Signal(){
logMessage("Signal was deleted");
}

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
    m_snr(signal.getSNR())
{
 logMessage("Clear Signal was created");
}

ClearSignals::~ClearSignals(){
logMessage("Clear Signal was deleted");
}

float ClearSignals::getSNR(){
    return m_snr;
}

bool ClearSignals::isClear(){
    if(m_snr >= 20)
        return true;
    else
        return false;
}



WeakSignals::WeakSignals():
    m_signal(),
    m_snr(0){}

WeakSignals::WeakSignals(Signal& signal):
    m_signal(signal),
    m_snr(signal.getSNR())
{
logMessage("Weak Signal was created");
}

WeakSignals::~WeakSignals(){
logMessage("Weak Signal was deleted");
}

float WeakSignals::getSNR(){
    return m_snr;
}

bool WeakSignals::isWeak(){
    if(m_snr < 20)
        return true;
    else
        return false;
}



SignalManager::SignalManager():
    m_clearArray(nullptr),
    m_clearCount(0),
    m_weakArray(nullptr),
    m_weakCount(0){}

SignalManager::~SignalManager(){
    delete[] m_clearArray;
    logMessage("Array of Clear Signal was deleted");
    delete[] m_weakArray;
    logMessage("Array of Weak Signal was deleted");
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
        logMessage("Added Clear Signal with SNR = " + to_string(signal.getSNR()));
    } else
    logMessage("Signal with SNR = " + to_string(signal.getSNR()) + " is not Clear");
}

void SignalManager::addWeakSignal(WeakSignals& signal){
    if(signal.isWeak()){
        WeakSignals* temp = new WeakSignals[m_weakCount + 1];
        for(int i = 0; i < m_weakCount; ++i){
            temp[i] = m_weakArray[i];
        }
        temp[m_weakCount] = signal;
        delete[] m_weakArray;
        m_weakArray = temp;
        m_weakCount++;
        logMessage("Added Weak Signal with SNR = " + to_string(signal.getSNR()));
    } else
    logMessage("Signal with SNR = " + to_string(signal.getSNR()) + " is not Weak");
}

void SignalManager::printAll(){
    cout << "Clear Signals (" << m_clearCount << ")" << endl;
    for(int i = 0; i < m_clearCount; ++i){
        cout << "[" << i + 1 << "] SNR = " << m_clearArray[i].getSNR() << " dB" << endl;
    }

    cout << "Weak Signals (" << m_weakCount << ")" << endl;
    for(int i = 0; i < m_weakCount; ++i){
        cout << "[" << i + 1 << "] SNR = " << m_weakArray[i].getSNR() << " dB" << endl;
    }
}

void logMessage(const string& message){
    cout << "[LOG] " << message << endl;
}
