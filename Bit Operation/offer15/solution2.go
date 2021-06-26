/**
 *
 * File:    offer15/solution2.go
 *          二进制中1的个数
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/6/23
 *          
 **/


func hammingWeight(num uint32) int {
    var res int
    for i := 0; i < 32; i++ {
        if (num & (1 << i)) != 0 {
            res++
        }
    }
    return res
}