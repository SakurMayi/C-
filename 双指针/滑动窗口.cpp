双指针：包含左右指针和快慢指针
左右指针中常用的方法，滑动窗口。
此方法的应用关键词：
  满足XX条件（计算结果，出现次数，同时包含）
  最长/最短
  子数组/字串/子序列
  通常都是连续的
滑动窗口使用思路：
 1. 寻找最长：
  核心：左右指针（L,R）在起始点，R向右逐位滑动循环
  每次滑动过程中：
    如果窗内元素满足条件，R向右扩大窗口，并更新最优结果
    如果窗内元素不满足条件，L向右缩小窗口
  R到达结尾
 2. 寻找最短：
  核心：左右指针（L,R）在起始点，R向右逐位滑动循环
  每次滑动过程中：
    如果窗内元素满足条件，L向右缩小窗口，并更新最优结果
    如果窗内元素不满足条件，R向右扩大窗口
  R到达结尾
最长模板：
初始化int right,left,result,bestresult;
while(右指针没有到结尾){
      窗口扩大，加入right对应元素，更新当前的result
      while(result不满足要求){
          窗口缩小，移除left对应的元素，left右移
      }
      更新最优结果bestresult;
      right++
}
返回bestresult;
最短模板：
初始化int right,left,result,bestresult;
while(右指针没有到结尾){
      窗口扩大，加入right对应元素，更新当前的result
      while(result满足要求){
          更新最优结果bestresult;
          窗口缩小，移除left对应的元素，left右移
      }
      right++
}
返回bestresult;
