/**
 *
 * File:    offer15/solution1.go
 *          二进制中1的个数
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/6/23
 *          
 **/



func hammingWeight(num uint32) int {
    var res int
    for num > 0 {
        num = num & (num - 1)
        res++;
    }
    return res
}