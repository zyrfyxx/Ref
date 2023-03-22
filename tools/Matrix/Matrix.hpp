#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include "Fw/Types/BasicTypes.hpp"

#include <math.h>

#define ABS(a)                  	(((a) > 0) ? (a) : -(a))
#define MIN(a, b)                   (((a) > (b)) ? (b) : (a))


F32 TripleFabsMax(F32 fx1, F32 fy2, F32 fz3);

F32 ModPNHP(F32 x,F32 halfperiod);

void MatrixTran(F32 *tran,const F32 *mat,U8 nrow,U8 ncol);
void MatrixMulti(F32 *product,const F32 *faciend,const F32 *multiplier,U8 nrow,U8 nrc,U8 ncol);
U8 MatrixInv33F(F32 *inv, const F32 *src);

#define  FLT32_ZERO                 1.0E-6


#endif

#ifndef  TRUE32
#define  TRUE32                     0x90  /* 返回布尔真定义 */
#endif

#ifndef  FALSE32
#define  FALSE32                    0x00  /* 返回布尔假定义 */
#endif
