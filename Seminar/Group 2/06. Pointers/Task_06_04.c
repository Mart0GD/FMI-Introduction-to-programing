//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//#pragma warning(push)
//#pragma warning(disable: 4996)
//#define EPSILON 1e-9 
//
//void printMatrix(double** matrix, int size) {
//    for (int i = 0; i < size; i++) {
//        for (int j = 0; j < size; j++) {
//            printf("%.2f ", matrix[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");
//}
//
//double** createMatrix(int size) {
//    double** matrix = (double**)malloc(size * sizeof(double*));
//    for (int i = 0; i < size; i++) {
//        matrix[i] = (double*)malloc(size * sizeof(double));
//    }
//    return matrix;
//}
//
//void freeMatrix(double** matrix, int size) {
//    for (int i = 0; i < size; i++) {
//        free(matrix[i]);
//    }
//    free(matrix);
//}
//
//void readMatrix(double** matrix, int size) {
//    printf("Insert matrix:\n");
//    for (int i = 0; i < size; i++) {
//        for (int j = 0; j < size; j++) {
//            scanf("%lf", &matrix[i][j]);
//        }
//    }
//}
//
//double** identityMatrix(int size) {
//    double** identity = createMatrix(size);
//    for (int i = 0; i < size; i++) {
//        for (int j = 0; j < size; j++) {
//            identity[i][j] = (i == j) ? 1.0 : 0.0;
//        }
//    }
//    return identity;
//}
//
//int** copyDeterminant(const double** det, const unsigned size, const unsigned rowSkip, const unsigned colSkip) {
//    
//    int** newDet = createMatrix(size - 1);
//    
//    unsigned newX = 0, newY = 0;
//    for (int y = 0; y < size; y++) {
//    	newX = 0;
//    	for (int x = 0; x < size; x++) {
//    		if (y != rowSkip && x != colSkip) {
//    			newDet[newY][newX++] = det[y][x];
//    		}
//    	}
//    	newY += y == rowSkip ? 0 : 1;
//    }
//    return newDet;    
//}
//    
//int determinant(double** matrix, unsigned size) {
//    if (size == 1) return matrix[0][0];
//    if (size == 2) {
//    	int res = matrix[0][0] * matrix[1][1] - (matrix[0][1] * matrix[1][0]);
//    	return res;
//    }
//    
//    int sum = 0;
//    int** newDet = NULL;
//    for (int i = 0; i < size; i++)
//    {
//    	newDet = copyDeterminant(matrix, size, 0, i);
//    	sum += pow(-1, 2 + i) * matrix[0][i] * determinant(newDet, size - 1);
//    	freeMatrix(newDet, size - 1);
//    }
//    
//    return sum;
//}
//
//int inverseMatrix(double** matrix, double** inverse, int size) {
//    double** augmented = createMatrix(size);
//    for (int i = 0; i < size; i++) {
//        for (int j = 0; j < size; j++) {
//            augmented[i][j] = matrix[i][j]; 
//        }
//    }
//
//    double** identity = identityMatrix(size);
//    for (int i = 0; i < size; i++) {
//        for (int j = 0; j < size; j++) {
//            inverse[i][j] = identity[i][j]; 
//        }
//    }
//    freeMatrix(identity, size);
//
//    for (int i = 0; i < size; i++) {
//        double diag = augmented[i][i];
//
//        for (int j = 0; j < size; j++) {
//            augmented[i][j] /= diag;
//            inverse[i][j] /= diag;
//        }
//
//        for (int k = 0; k < size; k++) {
//            if (k != i) {
//                double factor = augmented[k][i];
//                for (int j = 0; j < size; j++) {
//                    augmented[k][j] -= factor * augmented[i][j];
//                    inverse[k][j] -= factor * inverse[i][j];
//                }
//            }
//        }
//    }
//
//    freeMatrix(augmented, size);
//    return 1;
//}
//
//int main() {
//    int size;
//    printf("Insert matrix size: ");
//    scanf("%d", &size);
//
//    double** matrix = createMatrix(size);
//    double** inverse = createMatrix(size);
//
//    readMatrix(matrix, size);
//
//    int determinantSum = determinant(matrix, size);
//    if (determinantSum != 0) {
//        inverseMatrix(matrix, inverse, size);
//        printMatrix(inverse, size);
//    }
//    else {
//        printf("The matrix has no inverse\n");
//    }
//
//    freeMatrix(matrix, size);
//    freeMatrix(inverse, size);
//    return 0;
//}
