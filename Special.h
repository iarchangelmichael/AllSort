// Standart includes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>
#include <new>

#include <vector>
#include <list>
#include <algorithm>    // std::sort

#ifndef WIN32
	#define memcpy memmove
#endif

#ifdef WIN32
	typedef __int64 int64;
	typedef unsigned __int64 uint64;
#else
	typedef long long int64;
	typedef unsigned long long uint64;
#endif

#define tbtime timeb ft, fte; int tbtime_sec, tbtime_millim, tbtime_result; ftime(&ft); // print("Time: ", itos(sec*1000+millitm), "ms.\r\n");
#define tctime ftime(&ft); // continue
#define tetime ftime(&fte); tbtime_sec=(int)(fte.time-ft.time); tbtime_millim=fte.millitm-ft.millitm; if(fte.millitm<ft.millitm){ tbtime_millim+=1000; tbtime_sec--; } tbtime_result = tbtime_sec * 1000 + tbtime_millim;


//unsigned int crc32(unsigned char *buf, unsigned long len){
//	unsigned long crc_table[256];
//	unsigned long crc;
//	for (int i = 0; i < 256; i++){
//		crc = i;
//		for (int j = 0; j < 8; j++)
//		crc = crc & 1 ? (crc >> 1) ^ 0xEDB88320UL : crc >> 1;
//		crc_table[i] = crc;
//	};
//	crc = 0xFFFFFFFFUL;
//	while (len--)
//		crc = crc_table[(crc ^ *buf++) & 0xFF] ^ (crc >> 8);
//	return crc ^ 0xFFFFFFFFUL;
//}

// Add to end (_p, _n);
#define OMatrixTemplateAdd(_a, _e, el)				\
	if(!_a){ _a=el; _e=el; el->_p=0; el->_n=0; }	\
	else {	el->_n=0; el->_p=_e; _e->_n=el; _e=el; }

// Add to end (only _n);
#define OMatrixTemplateAddO(_a, _e, el)				\
	if(!_a){ _a=el; _e=el; el->_n=0; }				\
	else {	el->_n=0; _e->_n=el; _e=el; }

// Add to end (Set _p, _n name);
#define OMatrixTemplateAddF(_a, _e, el, _p, _n)		\
	if(!_a){ _a=el; _e=el; el->_p=0; el->_n=0; }	\
	else {	el->_n=0; el->_p=_e; _e->_n=el; _e=el; }

// Add to before p;
#define OMatrixTemplateAddP(_a, _e, p, el)				\
	if(!_a){ _a=el; _e=el; el->_p=0; el->_n=0; }		\
	else if(!p){										\
		el->_p=0; el->_n=_a; _a->_p=el; _a=el;			\
	} else {											\
		el->_p=p; el->_n=p->_n;							\
		p->_n=el; if(el->_n) el->_n->_p=el; else _e=el;	\
	}

// Del
#define OMatrixTemplateDel(_a, _e, el)							\
	if(el->_n) el->_n->_p=el->_p; else if(el==_e) _e=el->_p;	\
	if(el->_p) el->_p->_n=el->_n; else if(el==_a) _a=el->_n;




#ifdef WIN32
	const char *tsr_os = "Win32";
#else
	const char *tsr_os = "Linux";
#endif

#ifdef DEBUG
	const char *tsr_rel = "Debug";
#else
	const char *tsr_rel = "Release";
#endif

#define TSR_TOSTRINGT(x) #x
#define TSR_TOSTRING(x) TSR_TOSTRINGT(x)