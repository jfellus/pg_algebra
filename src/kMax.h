/*
 * kMax.h
 *
 *  Created on: 20 avr. 2015
 *      Author: jfellus
 */

#ifndef KMAX_H_
#define KMAX_H_

#include <pg.h>
#include <matrix.h>
#include <float.h>

class kMax {
public:
	uint K;
	Matrix* out;
	OUTPUT(Matrix, *out)
public:

	kMax() { K = 3; out = 0;}

	void init() {}

	void process(Matrix& in) {
		out = &in;
		for(uint i=0; i<in.h; i++) {
			float oldmax = FLT_MAX;
			float max = -FLT_MAX;
			for(uint k=0; k<K; k++) {
				for(uint j=0; j<in.w; j++) {
					float v = in(i,j);
					if(v > max && v < oldmax) max = v;
				}
				oldmax = max;
			}
			for(uint j = 0; j<in.w; j++) if(in(i,j)<max) in(i,j) = 0;
		}
	}
};



#endif /* KMAX_H_ */
