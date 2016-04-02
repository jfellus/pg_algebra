/*
 * Float2Matrix.h
 *
 *  Created on: 31 mai 2015
 *      Author: jfellus
 */

#ifndef FLOAT2MATRIX_H_
#define FLOAT2MATRIX_H_


class Float2Matrix {
public:
	Matrix out;
	OUTPUT(Matrix, out);
public:
	Float2Matrix() {}

	void init() {out.init(1,1);}

	void process(float f) {
		out[0] = f;
	}
};


#endif /* FLOAT2MATRIX_H_ */
