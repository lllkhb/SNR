#ifndef SNR_H_INCLUDED
#define SNR_H_INCLUDED

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

class PureSignals {
private:
    Signal m_signal;
    float m_snr;
public:
    PureSignals();
    PureSignals(Signal& signal);
    ~PureSignals();
    float getSNR();
    bool isPure();
};

class SignalManager {
private:
    ClearSignals* m_clearArray;
    int m_clearCount;

    PureSignals* m_pureArray;
    int m_pureCount;

public:
    SignalManager();
    ~SignalManager();

    void addClearSignal(ClearSignals& signal);
    void addPureSignal(PureSignals& signal);
    void printAll();
};


#endif // SNR_H_INCLUDED
