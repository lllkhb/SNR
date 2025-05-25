#ifndef SNR_H_INCLUDED
#define SNR_H_INCLUDED

class Signal{
private:
    float m_signalAmplitude;
    float m_noiseAmplitude;
public:
    Signal();
    ~Signal();
    void setValue();
    float get();
    void toString();
    void editVlue();
    bool access();
    void SNR();

};


#endif // SNR_H_INCLUDED
