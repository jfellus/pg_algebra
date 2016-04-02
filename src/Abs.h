/*
 * Abs.h
 *
 *  Created on: 31 mai 2015
 *      Author: jfellus
 */

#ifndef ABS_H_
#define ABS_H_


#include <pg.h>
#include <matrix.h>


class Abs {
public:
	Matrix out;

	OUTPUT(Matrix, out);

public:
	Abs() {}

	void init() {}

	void process(Matrix& in) {
		if(!out) out.init(in.h,in.w);
		for(uint i=in.n; i--;) out[i] = fabs(in[i]);
	}
};


#endif /* ABS_H_ */
