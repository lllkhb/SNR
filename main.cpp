#include <iostream>
#include "SNR.h"

int main() {
    SignalManager manager;

    Signal s1;
    s1.setValue(4.00, 2.00); // SNR=6 dB

    ClearSignals cs1(s1);
    WeakSignals ws1(s1);

    manager.addClearSignal(cs1);
    manager.addWeakSignal(ws1);

    Signal s2;
    s2.setValue(10.00, 0.50); // SNR=26 dB

    ClearSignals cs2(s2);
    WeakSignals ws2(s2);

    manager.addClearSignal(cs2);
    manager.addWeakSignal(ws2);

    Signal s3;
    s3.setValue(17.00, 0.38); // SNR=33 dB

    ClearSignals cs3(s3);
    WeakSignals ws3(s3);

    manager.addClearSignal(cs3);
    manager.addWeakSignal(ws3);

    manager.printAll();

    return 0;
}
