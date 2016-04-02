/*
 * Sin.h
 *
 *  Created on: 30 mai 2015
 *      Author: jfellus
 */

#ifndef SIN_H_
#define SIN_H_

#include <pg.h>

class Sin {
public:
	float freq;
	float SAMPLING_FREQ;
	float x;

	PARAM(float, freq, {});

	OUTPUT(float, x);

private:
	float ph;

public:
	Sin() {
		SAMPLING_FREQ = 48000;
		x = 0;
		freq = 1;
		ph = 0;
	}

	void init() {}

	void process() {process(freq);}

	void process(float freq) {
		x = sin(ph);
		ph += freq*2*M_PI/SAMPLING_FREQ;
		if(ph>600*M_PI) ph-=600*M_PI;
	}

};



#endif /* SIN_H_ */
