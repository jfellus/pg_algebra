/*
 * Vector.h
 *
 *  Created on: 20 avr. 2015
 *      Author: jfellus
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include <pg.h>
#include <matrix.h>

class RowVector {
public:
	Matrix out;
	OUTPUT(Matrix, out)
public:
	RowVector() {}

	void init() {
		out.h = 1;
	}

	void process(Matrix& in) {
		out.data = in;
		out.n = out.w = in.n;
	}
};

class ColVector {
public:
	Matrix out;
	OUTPUT(Matrix, out)
public:
	ColVector() {}

	void init() {
		out.w = 1;
	}

	void process(Matrix& in) {
		out.data = in;
		out.n = out.h = in.n;
	}
};

#endif /* VECTOR_H_ */
