/*
 * Inverse.h
 *
 *  Created on: 10 avr. 2015
 *      Author: jfellus
 */

#ifndef INVERSE_H_
#define INVERSE_H_

#include <pg.h>
#include <matrix.h>

class Inverse {
public:
	Matrix out;
	OUTPUT(Matrix, out)

	Inverse() {}

	void init() {}

	void process(const Matrix& a) {
		if(!out) out.init(a.h, a.w);
		for(size_t i=out.n; i--;) out[i] = 1.0/a[i];
	}
};



#endif /* INVERSE_H_ */
