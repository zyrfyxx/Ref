#include "Matrix.hpp"


// 功能： 矩阵/向量的转置,注意源和目标矩阵/向量不能是同一个 
void MatrixTran(F32 *tran,const F32 *mat,U8 nrow,U8 ncol){
	// 注意源和目标矩阵/向量不能是同一个 
    U8 i ;		// 矩阵行循环变量 
    U8 j ;		// 矩阵列循环变量 

   // tran:目标矩阵 
   // mat: 源矩阵 
   // nrow:矩阵行数 
   // ncol:矩阵列数 

    for ( i=0 ; i<nrow ; i++ )                              // 行循环 
    {
        for ( j=0 ; j<ncol ; j++ )                          // 列循环 
        {
            *(tran + j * nrow + i) = *(mat + i * ncol + j) ;
        }
    }

    return ;
}

// 功能：两个矩阵/向量相乘 
void MatrixMulti(F32 *product,const F32 *faciend,const F32 *multiplier,U8 nrow,U8 nrc,U8 ncol){
    U8 ir ;			                                // 行循环变量 
    U8 jc ;			                                // 列循环变量 
    U8 nk ;			                                // 求积后做加个数 
    U8 index ;			                                // 矩阵计算结果位置 

    // product:求和结果矩阵指针 
    // faciend:求和矩阵 
    // multiplier:被求和矩阵 
    // nrow:矩阵行数 
    // nrc:求积后做加个数 
    // ncol:矩阵列数 

    for (ir=0 ; ir<nrow ; ir++)                             // 行循环 
    {
        for (jc=0 ; jc<ncol ; jc++)                         // 列循环 
        {
            index = ir * ncol + jc ;		                // 矩阵计算结果位置 

            product[index] = 0.0f ;			                // 乘积结果默认取0 

            for (nk=0 ; nk<nrc ; nk++)                      // 求积后做加个数循环 
            {
                product[index] = product[index] + faciend[ir * nrc + nk] * multiplier[nk * ncol + jc] ;
            }
        }
    }

    return ;
}

// 功能：单精度3×3矩阵求逆
U8 MatrixInv33F(F32 *inv, const F32 *src)
{
    I8 i;
    F32 rank;
    U8 bAbleInv;   // TRUE32:矩阵可逆 

    // inv:输出结果矩阵指针 
    // src:输如计算矩阵指针 

    // 默认不可逆 
    bAbleInv = FALSE32;

    inv[0] = src[4] * src[8] - src[5] * src[7];             // 第1行第1列 
    inv[1] = src[2] * src[7] - src[1] * src[8];             // 第1行第2列 
    inv[2] = src[1] * src[5] - src[2] * src[4];             // 第1行第3列 
    inv[3] = src[5] * src[6] - src[3] * src[8];             // 第2行第1列 
    inv[4] = src[0] * src[8] - src[2] * src[6];             // 第2行第2列 
    inv[5] = src[2] * src[3] - src[0] * src[5];             // 第2行第3列 
    inv[6] = src[3] * src[7] - src[4] * src[6];             // 第3行第1列 
    inv[7] = src[1] * src[6] - src[0] * src[7];             // 第3行第2列 
    inv[8] = src[0] * src[4] - src[1] * src[3];             // 第3行第3列 

    // 求矩阵的行列式值 
    rank = src[0] * inv[0] + src[1] * inv[3] + src[2] * inv[6];


    if ((FLT32_ZERO < rank) || (rank < -FLT32_ZERO))         // 不等于浮点数0 
    {

        bAbleInv = TRUE32;                                   // 矩阵可逆 

        for (i=0; i<9; i++)                                  // 行列式 
        {
            inv[i] = inv[i] / rank;
        }
    }
    else
    {
        /* 矩阵不可逆时与原矩阵一致 */
        for (i=0; i<9; i++)
        {
            inv[i] = src[i];
        }
    }

    return bAbleInv;
}

F32 ModPNHP(F32 x,F32 halfperiod){
    // 周期
    F32 period;
    // 限幅后的返回值
    F32 npp2;

    // 计算周期值
    period = 2.0f * halfperiod;
    // 限幅并返回
    npp2 = x - floor((x + halfperiod) / period) * period;
    return npp2;
}

// 功能:求三个单精度浮点数中绝对值最大的数 
F32 TripleFabsMax(F32 fx1, F32 fy2, F32 fz3)
{
    F32 fabsfx1 ;			                            // 参数1的绝对值 
    F32 fabsfy2 ;			                            // 参数2的绝对值 
    F32 fabsfz3 ;			                            // 参数3的绝对值 
    F32 tmax ;				                            // 最大值 

    // 默认为正 
    fabsfx1 = fx1;                                          // 赋初值1 
    fabsfy2 = fy2;                                          // 赋初值2 
    fabsfz3 = fz3;                                          // 赋初值3 

    // 取绝对值1 
    if (fx1 < 0.0f)
    {
        fabsfx1 = -fx1;                                     // 参数1为负 
    }

    // 取绝对值2 
    if (fy2 < 0.0f)
    {
        fabsfy2 = -fy2;                                     // 参数2为负 
    }

    // 取绝对值3 
    if (fz3 < 0.0f)
    {
        fabsfz3 = -fz3;                                     // 参数3为负 
    }

    // 求数1与数2绝对值的最大值 
    if (fabsfx1 > fabsfy2)
    {
        tmax = fabsfx1 ;	                                // 1绝对值大 
    }
    else
    {
        tmax = fabsfy2 ;	                                // 2绝对值大 
    }

    // 求数1数2最大值与数3绝对值的最大值 
    if (fabsfz3 > tmax)
    {
        tmax = fabsfz3 ;	                                // 3绝对值大 
    }

    return tmax ;
}