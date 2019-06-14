//
// Created by Jasper Leann on 2019-06-04.
//

#ifndef PRINT_FLOAT_FLOATS_H
#define PRINT_FLOAT_FLOATS_H

#define F_MANT 23
#define D_MANT 52
#define LD_MANT 63

typedef union {
	float f;
	struct {
		unsigned int mant : F_MANT;
		unsigned int exp : 8;
		unsigned int sign : 1;
	} parts;
} float_cast;

typedef union {
	double f;
	struct {
		unsigned long mant : D_MANT;
		unsigned long exp : 11;
		unsigned int sign : 1;
	} parts;
} double_cast;

typedef union {
	long double f;
	struct {
		unsigned long mant : LD_MANT;
		unsigned long exp : 15;
		unsigned int sign : 1;
	} parts;
} ldouble_cast;


#define F_MASK 0x00400000
#define D_MASK 0x0008000000000000
#define LD_MASK 0x4000000000000000

#endif //PRINT_FLOAT_FLOATS_H
