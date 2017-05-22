#ifndef ERROR_H
#define ERROR_H

#include <iostream>
#include "stdlib.h"

using std::endl;

#define DEBUG 0
#define CONVERSAO_GRAUS_RADIANOS 57.324840764

//#define FORCE_FLUSH

#ifdef FORCE_FLUSH
	#define END_LINE std::endl
#elif _WIN32
	#define END_LINE "\r\n"
#else
	#define END_LINE "\n"
#endif


#define Error(msg)std::cerr<<"[ERROR] "<<__FILE__<<" | "<<__func__<<":"<<__LINE__<<"\t\t"<<msg<< END_LINE;exit(1);
#define ASSERT(exp)if(!(exp)){std::cerr<<"[ERROR] "<<__FILE__<<" | "<<__func__<<":"<<__LINE__<<"\t\tAssertion Failed."<< END_LINE;exit(1);}
#define SDL_ASSERT(exp)if(!(exp)){std::cerr<<"[ERROR] "<<__FILE__<<" | "<<__func__<<":"<<__LINE__<<"\t\tAssertion Failed:" << SDL_GetError()<< END_LINE;exit(1);}

#define WHERE __FILE__<<" | "<<__func__<<":"<<__LINE__

#define CHECK_SDL_ERROR std::cerr<<"[ERROR] "<<__FILE__<<" | "<<__func__<<":"<<__LINE__<<"\t\t"<<SDL_GetError()<< END_LINE

#define REPORT_I_WAS_HERE if(DEBUG){std::cout <<"[DEBUG] I was here!\t"<<__FILE__<<" | "<<__func__<<":"<<__LINE__<<END_LINE;}

#define TEMP_REPORT_I_WAS_HERE if(1){std::cout <<"[DEBUG] I was here!\t"<<__FILE__<<" | "<<__func__<<":"<<__LINE__<<END_LINE;}

//void Error(char const * errMsg);

#endif // ERROR_H
