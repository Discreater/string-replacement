#pragma once
#include <iostream>
#include "replacement.h"

using namespace std;


namespace naive_string_replacement
{
    /**
     * @brief
     * 递归替换连续“01...1”序列为“100...-1”
     * 连续的“1”的数量必须大于2，否则没有优化效果甚至反作用
     * 当没有连续的1时我们认为算法结束
     * @param newLimb
     * 用来记录1，0，-1的三元组，相当于一个hash表
     * @param carry
     * 最高位是否要补1
     * @param oriLimb
     * 原始数字
     * @param size
     * 数字的长度
     */
    void replace(limbType *newLimb, bool carry, limbType *oriLimb, const int size, const int threshold);

    /**
     * @brief 
     * 判断是否有连续的1
     * @param Limb 
     * 目标Limb
     * @param size 
     * 数字的长度
     * @return true 
     * 有连续的1
     * @return false 
     * 没有连续的1
     */
    bool hasConsecutiveOnes(limbType *Limb, const int size, const int threshold);

    void powm(limbType &res, limbType g, limbType gInverse, limbType *e, bool carry, int size, limbType n);
};
