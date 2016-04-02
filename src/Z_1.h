/*
 * Z_1.h
 *
 *  Created on: 30 mai 2015
 *      Author: jfellus
 */

#ifndef Z_1_H_
#define Z_1_H_

#include <pg.h>
#include <matrix.h>

class Z_1 {
public:
	Matrix last;
	Matrix cur;

	OUTPUT(Matrix, last);

public:
	Z_1() {}

	void init() {}

	void process(Matrix& m) {
		if(!last) {	last.init(m.h, m.w);	cur.init(m.h, m.w);	}
		last = cur;
		cur = m;
	}

};



#endif /* Z_1_H_ */
