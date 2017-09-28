//queuestruct.h
#ifndef queuestruct_h
#define queuestruct_h

#include <string>
using namespace std;

struct queuestruct{
	string str;
	unsigned int source;
	signed int priority;
	unsigned int packetnum;
	bool qconts;
};

#endif