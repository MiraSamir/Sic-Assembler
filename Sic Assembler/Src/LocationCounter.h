//
// Created by me on 5/20/2017.
//

#ifndef SICASSEMBLERV2_LOCATIONCOUNTER_H
#define SICASSEMBLERV2_LOCATIONCOUNTER_H


class LocationCounter {
public:
    LocationCounter();
private:
public:
    int getLocationCounter();
    void setLocationCounter(int locationCounter);
    bool isWithinRange();

private:
    int locationCounter;
    static const int LIMIT = 0X7FFF;
};


#endif //SICASSEMBLERV2_LOCATIONCOUNTER_H
