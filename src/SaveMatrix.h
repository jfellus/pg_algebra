/*
 * SaveMatrix.h
 *
 *  Created on: 30 mai 2015
 *      Author: jfellus
 */

#ifndef SaveMatrix_H_
#define SaveMatrix_H_

#include <pg.h>
#include <matrix.h>

class SaveMatrix {
public:
	std::string filename;
	size_t i=0;
public:
	SaveMatrix() {
		filename = "out.fvec";
	}

	void init() {
		mkdir(str_dirname(filename));
	}

	void process(Matrix& m) {
		char fn[256]; sprintf(fn, filename.c_str(), i++);
		write_matrix(fn, m);
	}

};

class SaveMatrixWhenFull {
public:
	std::string filename;
public:
	SaveMatrixWhenFull() {
		filename = "out.fvec";
	}

	void init() {
		mkdir(str_dirname(filename));
	}

	void process(MatrixAppend& ma) {
		if(ma.out.h < ma.nbMax) return;
		Matrix& m = ma;
		write_matrix(filename.c_str(), m);
		ERROR("DONE !");
	}

};


#endif /* SaveMatrix_H_ */
