#pragma once

#ifdef DLL_BUILD 
    #define DLL_EXPORT __declspec(dllexport) 
#else 
    #define DLL_EXPORT  __declspec(dllimport) 
#endif 

enum UMEYAMA_ERRORS {
	SET_OF_POINTS_A_IS_NULL    = -1,  //ptr to buf of src set of pts is null
	SET_OF_POINTS_B_IS_NULL    = -2,  //ptr to buf of dst set of pts is null
	SIZE_OF_SETS_IS_WRONG      = -3,  //size of sets is less than 1
	TRANSFORM_MATRIX_IS_NULL   = -4,  //ptr to buf of transform is null
};

DLL_EXPORT int umeyama(double* _setOfPointsA,          //ptr to begin of src set point
                       double* _setOfPointsB,          //ptr to begin of deas set point
					   unsigned int size,              //size of bufs
                       bool with_scaling,              //calc with scaling?
					   bool result_in_row_major_order, //return transform in row major order?
					   double* _transform);            //ptr to begin of buf to store transform