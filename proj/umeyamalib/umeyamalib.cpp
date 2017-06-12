#include "umeyamalib.h"
#include <Eigen/Geometry>

int umeyama(double* _setOfPointsA,
            double* _setOfPointsB,
            unsigned int size,
			bool with_scaling,
			bool result_in_row_major_order,
            double* _transform)
{
	if (_setOfPointsA == nullptr) return UMEYAMA_ERRORS::SET_OF_POINTS_A_IS_NULL;
	if (_setOfPointsA == nullptr) return UMEYAMA_ERRORS::SET_OF_POINTS_B_IS_NULL;
	if (size < 1)                 return UMEYAMA_ERRORS::SIZE_OF_SETS_IS_WRONG;
	if (_transform == nullptr)    return UMEYAMA_ERRORS::TRANSFORM_MATRIX_IS_NULL;

	Eigen::MatrixXd setOfPointsA = Eigen::Map<Eigen::MatrixXd>(_setOfPointsA, size / 3, 3);
	Eigen::MatrixXd setOfPointsB = Eigen::Map<Eigen::MatrixXd>(_setOfPointsB, size / 3, 3);

	typedef Eigen::Matrix<double, 4, 4, Eigen::RowMajor> Eigen4x4MatrixRowMajor;
	typedef Eigen::Matrix<double, 4, 4, Eigen::ColMajor> Eigen4x4MatrixColMajor;

	if (result_in_row_major_order)
	{
		Eigen4x4MatrixRowMajor transform = Eigen::umeyama(setOfPointsA, setOfPointsB, with_scaling);
		memmove(_transform, transform.data(), 16 * sizeof(double));
		return 1;
	}
	
	Eigen4x4MatrixColMajor transform = Eigen::umeyama(setOfPointsA, setOfPointsB, with_scaling);
	memmove(_transform, transform.data(), 16 * sizeof(double));
	return 1;
}