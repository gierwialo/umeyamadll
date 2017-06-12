#include <vector>
#include <iostream>
#include "../umeyamalib/umeyamalib.h"

typedef struct point_t { double x, y, z; 
                         point_t(double _x, double _y, double _z) : x(_x),y(_y),z(_z) {}
                       } point_t;

void main(void)
{
	std::cout << "Test Umeyama Eigen Wrapper" << std::endl;

	std::vector<point_t> src,dst;
	std::vector<double>  t(16,0.f);

	src.emplace_back(point_t(1, 1, 1));
	src.emplace_back(point_t(2, 2, 2));
	src.emplace_back(point_t(3, 3, 3));

	dst.emplace_back(point_t(6, 6, 6));
	dst.emplace_back(point_t(7, 7, 7));
	dst.emplace_back(point_t(8, 8, 8));
	
	int status = umeyama(&src.front().x,     //ptr to begin of src set point
                         &dst.front().x,     //ptr to begin of deas set point
                         (int)src.size()*3,  //size of bufs
                         true,             //with scaling?
						 true,             //return transform in row major order?
                         &t[0]);           //ptr to begin of buf to store transform
}