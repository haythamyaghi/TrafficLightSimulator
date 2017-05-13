/*
 * main.cpp
 *
 *  Created on: May 13, 2017
 *      Author: haytham
 */

#include <iostream>
#include <limits>
#include <csignal>
#include <cstdlib>
#include "TrafficLight.h"

using namespace std;

void my_handler(int){
	cout<<"\nExiting Traffic Light Simulator"<<endl;
	exit(1);

}

int ParseInput()
{
	int n;
	cin >> n;
	if(cin.fail())
	{
		cout<<"Invalid input."<<endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return -1;
	}
	else if (n<=0)
	{
		cout<<"Invalid input."<<endl;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return -1;

	}

	cout<<"Entered value is: "<<n<<endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return n;
}

int LoopOnInput (const string & color)
{
	int time;
	do {
		cout<<"Enter time for "<<color<<" light in seconds (a positive non-zero integer), or ctrl-c to quit:"<<endl;
		if ((time = ParseInput()) > 0)
			break;
	}
	while (true);

	return time;

}

int main (int argc, char* argv[])
{

	signal (SIGINT, my_handler);
	signal (SIGTERM, my_handler);

	int redTime = LoopOnInput("red");
	int yellowTime = LoopOnInput("yellow");
	int greenTime = LoopOnInput("green");

	TrafficLight trafficLight(redTime, yellowTime, greenTime);

	trafficLight.Run();

	return 0;
}
