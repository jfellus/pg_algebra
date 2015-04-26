/*
 * NormalizeMinMax.h
 *
 *  Created on: 20 avr. 2015
 *      Author: jfellus
 */

#ifndef NORMALIZEMINMAX_H_
#define NORMALIZEMINMAX_H_


#include <pg.h>
#include <matrix.h>

class NormalizeMinMax {
public:
	float min, max;
	Matrix* out;
	OUTPUT(Matrix, *out);

public:
	NormalizeMinMax() {min=0; max=1; out = 0;}

	void init() {}

	void process(Matrix& in) {
		out = &in;
		for(uint i=in.n; i--;) {
			if(in[i]<min) in[i] = min;
			else if(in[i]>max) in[i] = max;
			else in[i] = (in[i]-min)/(max-min);
		}
	}
};

#endif /* NORMALIZEMINMAX_H_ */
