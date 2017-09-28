//queueclass.h
#include <numeric>
#include <algorithm>
#include "queuestruct.h"

#ifndef queueclass_h
#define queueclass_h

using namespace std;

class queue{
	vector <queuestruct> Queue;

	unsigned int queueid;
	void getid();
	
	static int nextid()
	{
			static int nextid =-1;
			nextid++;
			return nextid;
	}

public:
	queue();
	queue::queue(queuestruct[]);
	~queue();

	void Enqueue(queuestruct );
	void QueueEmpty();
	void SetPriority();
	void Firstposition();
	void DisplayPriority();
	void DequeueFront();
	void DequeuePriority();

};
#endif