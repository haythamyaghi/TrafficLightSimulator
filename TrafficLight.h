/*
 * TrafficLight.h
 *
 *  Created on: May 13, 2017
 *      Author: haytham
 */

#ifndef TRAFFICLIGHT_H_
#define TRAFFICLIGHT_H_


class TrafficLight {

	void OutputAsciiArt();

	unsigned int redTime;
	unsigned int yellowTime;
	unsigned int greenTime;

	char currentState;

	void PrintCurrentState();
	void WaitForNextState();
	void TransitionState();

public:
	TrafficLight(unsigned int redTime, unsigned int yellowTime, unsigned int greenTime):
		redTime(redTime), yellowTime(yellowTime), greenTime(greenTime),
		currentState('R'){};

	void Run();
};

#endif /* TRAFFICLIGHT_H_ */
