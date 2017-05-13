/*
 * TrafficLight.cpp
 *
 *  Created on: May 13, 2017
 *      Author: haytham
 */

#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include "TrafficLight.h"

using namespace std;

void TrafficLight::Run()
{
	while (true)
	{
		PrintCurrentState();
		WaitForNextState();
		TransitionState();
	}
}

void TrafficLight::WaitForNextState()
{
	unsigned int sleepTime = 0;
	switch (currentState)
	{
	case 'R':
		sleepTime = (redTime);
		break;
	case 'Y':
		sleepTime = (yellowTime);
		break;
	case 'G':
		sleepTime = (greenTime);
		break;
	}

	sleep(sleepTime);
}

void TrafficLight::TransitionState()
{
	switch (currentState)
	{
	case 'R':
		currentState = 'G';
		break;
	case 'Y':
		currentState = 'R';
		break;
	case 'G':
		currentState = 'Y';
		break;
	}

}

void TrafficLight::PrintCurrentState()
{
	int printLoc;


	switch (currentState)
	{
	case 'R':
		printLoc = 0;
		break;
	case 'Y':
		printLoc = 1;
		break;
	case 'G':
		printLoc = 2;
		break;
	}

	system("clear");

	cout<<"Traffic Light Simulator (Press ctrl-c to quit)."<<endl;
	cout<<"\t___"<<endl;
	for (int i(0); i < 3; ++i)
	{
		char toPrint = (printLoc==i)? currentState : ' ';
		cout<<"\t|"<<toPrint<<'|'<<endl;
	}
	cout<<"\t___"<<endl;

}
