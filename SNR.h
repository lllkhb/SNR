#ifndef SNR_H_INCLUDED
#define SNR_H_INCLUDED

class Signal{
private:
    float m_signalAmplitude;
    float m_noiseAmplitude;
public:
    Signal(float signal, float noise);
    ~Signal();
    void setValue();
    float getSNR();
    void toString();
};

class ClearSignals{
private:
    Signal m_signal;
    float m_snr;
public:
    ClearSignals(Signal &signal);
    ~ClearSignals();
    bool isClear();
    void addSignal();
    void printType();
};

class PureSignals{
private:
    Signal m_signal;
    float m_snr;
public:
    PureSignals(Signal &signal);
    ~PureSignals();
    bool access();
    void addSignal();
    void printType();
};

#endif // SNR_H_INCLUDED
