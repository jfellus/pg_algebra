/*
 * Substract.h
 *
 *  Created on: 30 mai 2015
 *      Author: jfellus
 */

#ifndef SUBSTRACT_H_
#define SUBSTRACT_H_

#include <pg.h>
#include <matrix.h>

class Substract {
public:
	Matrix out;

	OUTPUT(Matrix, out);

public:
	Substract() {}

	void init() {

	}

	void process(const Matrix& m1, const Matrix& m2) {
		if(!out) out.init(m1.h,m1.w);
		for(uint i=out.n; i--;) out[i] = m1[i] - m2[i];
	}
};



#endif /* SUBSTRACT_H_ */
