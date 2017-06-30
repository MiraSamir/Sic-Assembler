

#include "LocationCounter.h"

LocationCounter::LocationCounter() {
    this->locationCounter = 0;
}
int LocationCounter::getLocationCounter() {
    return locationCounter;
}

void LocationCounter::setLocationCounter(int locationCounter) {
    LocationCounter::locationCounter = locationCounter;
}


bool LocationCounter::isWithinRange(){
    return (this->locationCounter <= LIMIT);
}
