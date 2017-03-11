#ifndef ERROR_H
#define ERROR_H

#include <iostream>
#include "stdlib.h"

using std::endl;

#define Error(msg)std::cerr<<"[ERROR] "<<__FILE__<<" | "<<__func__<<":"<<__LINE__<<"\t\t"<<msg<< endl;exit(1);
//#define ERROR_PREFIX  "[ERROR] "<< __FILE__<<" | "<< __func__ <<":"<< __LINE__ <<"\t\t"

//void Error(char const * errMsg);

#endif // ERROR_H
