/*
 * Pow.h
 *
 *  Created on: 10 avr. 2015
 *      Author: jfellus
 */

#ifndef POW_H_
#define POW_H_

#include <pg.h>
#include <matrix.h>
#include <math.h>

class Pow {
public:

	float power;

	Matrix out;
	OUTPUT(Matrix, out)

	Pow() {power = 1;}

	void init() {}

	void process(const Matrix& a) {	process(a, power);	}

	void process(const Matrix& a, float power) {
		if(!out) out.init(a.h, a.w);
		if(power==1) out = a;
		else if(power==2) for(size_t i=out.n; i--;) out[i] = a[i]*a[i];
		else if(power==3) for(size_t i=out.n; i--;) out[i] = a[i]*a[i]*a[i];
		else if(power==0.5) for(size_t i=out.n; i--;) out[i] = sqrt(a[i]);
		else for(size_t i=out.n; i--;) out[i] = pow(a[i],power);
	}
};

class Square {
public:

	Matrix out;
	OUTPUT(Matrix, out)

	Square() {}

	void init() {}

	void process(const Matrix& a) {
		if(!out) out.init(a.h, a.w);
		for(size_t i=out.n; i--;) out[i] = a[i]*a[i];
	}
};

class Sqrt {
public:

	Matrix out;
	OUTPUT(Matrix, out)

	Sqrt() {}

	void init() {}

	void process(const Matrix& a) {
		if(!out) out.init(a.h, a.w);
		for(size_t i=out.n; i--;) out[i] = sqrt(a[i]);
	}
};

#endif /* POW_H_ */
