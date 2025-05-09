/**
 * @file 1.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2025-03-06
 *
 * @copyright Copyright (c) 2025
 *
 */

/**
result = []
def backtrack(路径, 选择列表):
   if 满足结束条件:
       result.add(路径)
       return

   for 选择 in 选择列表:
        # 做选择
        将该选择从选择列表移除
        路径.add(选择)

       backtrack(路径, 选择列表)

        # 撤销选择
        路径.remove(选择)
        将该选择再加入选择列表
 */