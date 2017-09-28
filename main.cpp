//main.cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include "queueclass.h"
#include "queuestruct.h"

using namespace std;


void main(){
	

	queuestruct convo1[10];					//create array of questruct 10 elements long


	// Initial test data to a default packetnum for parameterised constructor
	for (int packet = 0; packet < 10; packet++)
	{
		convo1[packet].packetnum = -1;
	}

	convo1[0].str = "hello";			//populate instances of convo1
	convo1[0].source = 1;
	convo1[0].priority = 1;
	convo1[0].packetnum = 0;
	convo1[0].qconts = 1;

	convo1[1].str = "ryan";
	convo1[1].source = 1;
	convo1[1].priority = 1;
	convo1[1].packetnum = 2;
	convo1[1].qconts = 1;

	convo1[2].str = "im";
	convo1[2].source = 1;
	convo1[2].priority = 1;
	convo1[2].packetnum = 1;
	convo1[2].qconts = 1;

	queue queuea(convo1);

//check if there are contents in queue a
	queuea.QueueEmpty();

//check first position of queue for a specific source
	queuea.Firstposition();

//Change priority for source 1
	queuea.SetPriority();

//Display priority for a source
	queuea.DisplayPriority();

//dequeue from the front of based on priority
	queuea.DequeueFront();
	
	queue queueb = queuea;			//duplicating contents of queue

}
