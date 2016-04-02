/*
 * MatrixAppend.h
 *
 *  Created on: 30 mai 2015
 *      Author: jfellus
 */

#ifndef MatrixAppend_H_
#define MatrixAppend_H_

#include <pg.h>
#include <matrix.h>

class MatrixAppend {
public:
	size_t nbMax;

	Matrix out;

	OUTPUT(Matrix, out);
	inline operator uint() {return out.h;}

public:
	MatrixAppend() {
		nbMax = 1e6;
	}

	void init() {}

	void process(Matrix& m) {
		if(out.h>=nbMax) return;
		if(!out) { out.init(nbMax, m.w); out.h = out.n = 0; }
		if(out.w != m.w) ERROR("Matrix dimensions must agree !");
		uint hh = m.h;
		if(out.h+hh >= nbMax) { DBG("nbMax reached : trim to " << nbMax); hh = nbMax-out.h;}
		memcpy(&out(out.h,0),m.data, hh*out.w*sizeof(float));
		out.h += hh;
		out.n = out.w * out.h;
	}

};



#endif /* MatrixAppend_H_ */
