/*
 * Multiply.h
 *
 *  Created on: 10 avr. 2015
 *      Author: jfellus
 */

#ifndef MULTIPLY_H_
#define MULTIPLY_H_

#include <pg.h>
#include <matrix.h>

class Multiply {
public:
	float factor;

	Matrix out;
	OUTPUT(Matrix, out)

public:
	Multiply() {factor = 1;}

	void init() {}

	void process(const Matrix& a, float s) {
		if(!out) out.init(a.h, a.w);
		for(size_t i=out.n; i--;) out[i] = a[i]*s;
	}

	void process(const Matrix& a) { process(a, factor); }

	void process(const Matrix& a, const Matrix& b) {
		if(!out) out.init(a.h, a.w);
		for(size_t i=out.n; i--;) out[i] = a[i]*b[i];
	}

	void process(const Matrix& a, const Matrix& b, const Matrix& c) {
		if(!out) out.init(a.h, a.w);
		for(size_t i=out.n; i--;) out[i] = a[i]*b[i]*c[i];
	}

	void process(const Matrix& a, const Matrix& b, const Matrix& c, const Matrix& d) {
		if(!out) out.init(a.h, a.w);
		for(size_t i=out.n; i--;) out[i] = a[i]*b[i]*c[i]*d[i];
	}

	void process(const Matrix& a, const Matrix& b, const Matrix& c, const Matrix& d, const Matrix& e) {
		if(!out) out.init(a.h, a.w);
		for(size_t i=out.n; i--;) out[i] = a[i]*b[i]*c[i]*d[i]*e[i];
	}

	void process(const Matrix& a, const Matrix& b, const Matrix& c, const Matrix& d, const Matrix& e, const Matrix& f) {
		if(!out) out.init(a.h, a.w);
		for(size_t i=out.n; i--;) out[i] = a[i]*b[i]*c[i]*d[i]*e[i]*f[i];
	}
};



#endif /* MULTIPLY_H_ */
