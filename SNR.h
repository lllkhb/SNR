#ifndef SNR_H_INCLUDED
#define SNR_H_INCLUDED
#include <string>

using namespace std;

class Signal{
private:
    float m_signalAmplitude;
    float m_noiseAmplitude;

public:
    Signal();
    ~Signal();
    void setValue(float signal, float noise);
    float getSNR();
    void toString();
};

class ClearSignals {
private:
    Signal m_signal;
    float m_snr;
public:
    ClearSignals();
    ClearSignals(Signal& signal);
    ~ClearSignals();
    float getSNR();
    bool isClear();
};

class WeakSignals {
private:
    Signal m_signal;
    float m_snr;
public:
    WeakSignals();
    WeakSignals(Signal& signal);
    ~WeakSignals();
    float getSNR();
    bool isWeak();
};

class SignalManager {
private:
    ClearSignals* m_clearArray;
    int m_clearCount;

    WeakSignals* m_weakArray;
    int m_weakCount;

public:
    SignalManager();
    ~SignalManager();

    void addClearSignal(ClearSignals& signal);
    void addWeakSignal(WeakSignals& signal);
    void printAll();
};

void logMessage(const string& message);

#endif // SNR_H_INCLUDED
