/*
 * LoadMatrix.h
 *
 *  Created on: 30 mai 2015
 *      Author: jfellus
 */

#ifndef LoadMatrix_H_
#define LoadMatrix_H_

#include <pg.h>
#include <matrix.h>

class LoadMatrix {
public:
	std::string filename;

	Matrix out;

	OUTPUT(Matrix, out);

public:
	LoadMatrix() {
		filename = "out.fvec";
	}

	void init() {
	}

	void process() {
		if(out) return;

		DBG("LOAD " << filename);
		read_matrix(filename.c_str(), out);
	}


};


#endif /* LoadMatrix_H_ */
