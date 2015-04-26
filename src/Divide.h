/*
 * Divide.h
 *
 *  Created on: 10 avr. 2015
 *      Author: jfellus
 */

#ifndef DIVIDE_H_
#define DIVIDE_H_

#include <pg.h>
#include <matrix.h>

class Divide {
public:
	Matrix out;
	OUTPUT(Matrix, out)

	float factor;

public:
	Divide() {factor = 1;}

	void init() {}


	void process(const Matrix& a, float s) {
		if(!out) out.init(a.h, a.w);
		for(size_t i=out.n; i--;) out[i] = a[i]/s;
	}

	void process(const Matrix& a) {process(a,factor);}

	void process(const Matrix& a, const Matrix& b) {
		if(!out) out.init(a.h, a.w);
		for(size_t i=out.n-1; i--;) out[i] = a[i]/b[i];
	}
};



#endif /* DIVIDE_H_ */
