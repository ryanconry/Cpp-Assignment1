queueclass.cpp
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include "queuestruct.h"
#include "queueclass.h"

using namespace std;

queue::queue()
{
	getid();													//get id value for queue
	cout << "Queue " << queueid << " initialised." << endl;		
}

queue::queue(queuestruct initPackets[])
{
	getid();

	for (int packet = 0; initPackets[packet].packetnum != -1; packet++)
		Enqueue(initPackets[packet]);							//enque struct to vector

	cout << "Queue " << queueid << " initialised." << endl;
}

queue::~queue()
{
	cout << "Queue " << queueid << " destructed." << endl;		//alert user of destruction

}

void queue::getid()
{
	queueid = nextid();											//call function to assign value for id
}

void queue::Enqueue(queuestruct packet)
{
	Queue.push_back(packet);									//enque struct to vector using push back
}

void queue::QueueEmpty()			//function to perform checks if there is data in the queue
{
	if (Queue[0].qconts || Queue[1].qconts || Queue[2].qconts)
		cout << "queue has contents" << endl;
	else
		cout << "queue is empty" << endl;


}

void queue::Firstposition()    //depending on priority, will display where the first message is in
{							   //the queue

	unsigned int temp;
	int i;
	if (Queue[0].priority > 0)
	{ 
		i = 0;
		temp = Queue[i].packetnum;
		for (i = 1; i < 3; i++)
		if (temp < Queue[i].packetnum)
				i = 3;
	}

	if (Queue[0].priority < 0)
	{

		{
			i = 2;
			temp = Queue[i].packetnum;
			for (i = 1; i = 0; i--)
			{
				if (temp < Queue[i].packetnum)
					temp = Queue[i].packetnum;
				else
					i = 0;
			}
		}

	}
	cout << "Position " << temp << " is the first position for source " << Queue[0].source << endl;
}

void queue::SetPriority()		//depending on the incoming priority, function to
{								//flip priority
	if (Queue[0].priority ==-1 && Queue[1].priority ==-1 && Queue[2].priority==-1)
	{
		Queue[0].priority=1, Queue[1].priority =1, Queue[2].priority = 1;
		cout << "Priority has been changed to High" << endl;
	}
	if (Queue[0].priority == 1 && Queue[1].priority == 1 && Queue[2].priority == 1)
	{
		Queue[0].priority =-1, Queue[1].priority =-1, Queue[2].priority = -1;
		cout << "Priority has been changed to Low" << endl;
	}
	else
		cout << "Priorities were not matching, could not change";

}

void queue::DisplayPriority()		//display priority for a given source
{
	if (Queue[0].priority > 0)
	{
		cout << "Source " << Queue[0].source << " has a high priority" << endl;
	}

	if (Queue[0].priority < 0)
	{
		cout << "Source " << Queue[0].source << " has a low priority" << endl;
	}
}

void queue::DequeueFront()		//if there is priority, deque based on priority,
{								//otherwise dequeue by FIFO
	string output[10];

	if (Queue[0].priority)
		DequeuePriority();
	else
		for (int i = 0; i < 3; i++)
		{
			output[i] = Queue[i].str;
			cout << "Packet " << Queue[i].packetnum << "contains " << output[i] << endl;
		}
	//Queue.erase;
	
}


void queue::DequeuePriority()		//sorting the messages in the queue based on priority
{
	string output[3];
	int temp;
	int length = Queue.size();

	if (Queue[0].priority > 0)
	{
		for (int i = 0; i < length - 1; i++)
		{
			if (Queue[i].packetnum > Queue[i + 1].packetnum)
				temp = i;
			else
				temp = temp;
		}

		output[0]=Queue[temp].str;
		temp = Queue[temp].packetnum-1;

		for (int k = 0; k < length; k++)
		{
			if (Queue[k].packetnum == temp)
				output[1]=Queue[k].str;

		}

		temp = temp - 1;
		for (int z = 0; z < length; z++)
		{
			if (Queue[z].packetnum == temp)
				output[2]=Queue[z].str;

		}
	}


	if (Queue[0].priority < 0)
	{
		for (int i = 0; i < length - 1; i++)
		{
			if (Queue[i].packetnum < Queue[i + 1].packetnum)
				temp = i;
			else
				temp = temp;
		}

		output[0] = Queue[temp].str;
		temp = Queue[temp].packetnum + 1;

		for (int k = 0; k < length; k++)
		{
			if (Queue[k].packetnum == temp)
				output[1] = Queue[k].str;

		}

		temp = temp + 1;
		for (int z = 0; z < length; z++)
		{
			if (Queue[z].packetnum == temp)
				output[2] = Queue[z].str;

		}

	}

	for (int a = 0; a < length;a++)
	{
		cout << output[a] << " ";
	}
}
