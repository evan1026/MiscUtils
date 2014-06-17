#include "MiscUtils.hpp"

int delay(long milliseconds){
    struct timespec tim,tim2;
    tim.tv_sec = milliseconds / 1000;
    tim.tv_nsec = (milliseconds % 1000) * 1000000;
    return nanosleep(&tim,&tim2);
}
