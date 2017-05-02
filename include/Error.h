#ifndef ERROR_H
#define ERROR_H

#include <iostream>
#include "stdlib.h"

using std::endl;

#define DEBUG 0
#define CONVERSAO_GRAUS_RADIANOS 57.324840764

#define Error(msg)std::cerr<<"[ERROR] "<<__FILE__<<" | "<<__func__<<":"<<__LINE__<<"\t\t"<<msg<< endl;exit(1);
#define ASSERT(exp)if(!(exp)){std::cerr<<"[ERROR] "<<__FILE__<<" | "<<__func__<<":"<<__LINE__<<"\t\tAssertion Failed."<< endl;exit(1);}
#define ASSERT2(exp,str)if(!(exp)){Error("Assertion Failed: "<<str);}
#define SDL_ASSERT(exp)if(!(exp)){std::cerr<<"[ERROR] "<<__FILE__<<" | "<<__func__<<":"<<__LINE__<<"\t\tAssertion Failed:" << SDL_GetError()<< endl;exit(1);}

#define WHERE __FILE__<<" | "<<__func__<<":"<<__LINE__

#define CHECK_SDL_ERROR std::cerr<<"[ERROR] "<<__FILE__<<" | "<<__func__<<":"<<__LINE__<<"\t\t"<<SDL_GetError()<< endl

#define REPORT_I_WAS_HERE if(DEBUG){std::cout <<"[DEBUG] I was here!\t"<<__FILE__<<" | "<<__func__<<":"<<__LINE__<<std::endl;}

#define TEMP_REPORT_I_WAS_HERE if(1){std::cout <<"[DEBUG] I was here!\t"<<__FILE__<<" | "<<__func__<<":"<<__LINE__<<std::endl;}

//void Error(char const * errMsg);

#endif // ERROR_H
