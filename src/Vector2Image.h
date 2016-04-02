/*
 * Vector2Image.h
 *
 *  Created on: 3 juin 2015
 *      Author: jfellus
 */

#ifndef VECTOR2IMAGE_H_
#define VECTOR2IMAGE_H_

#include <pg.h>

class Vector2Image {
public:
	Image out;
	OUTPUT(Image, out);

	uint w;

public:

	Vector2Image() {w=1;}

	void init() {}

	void process(const Matrix& in) {
		out.w = w;
		out.h = in.n/w;
		out.data = in.data;
		out.n = in.n;
	}
};

#endif /* VECTOR2IMAGE_H_ */
