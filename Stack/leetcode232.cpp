/**
 *
 * File:    leetcode232.cpp
 *          用栈实现队列
 * 
 * Author:  yiluqingtai(1572236483@qq.com)
 *          Created on 21/4/22
 *          
 **/


class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> stk1;
    stack<int> stk2;
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stk1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }
        int val = stk2.top();
        stk2.pop();
        return val;    
    }
    
    /** Get the front element. */
    int peek() {
        if (!stk2.empty()) {
            return stk2.top();
        } else {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
            return stk2.top();
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk1.empty() && stk2.empty();
    }
};