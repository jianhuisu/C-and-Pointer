## 查找

在静态查找表中常用的查找方法

 - 静态查找表  表的操作只有`查找操作`的表称为静态查找表
 - 动态查找表  表的操作除`查找操作`还有其它操作如删除等操作的表称为动态查找表

以`顺序表`或者`线性链表`表示的静态查找表

 - 顺序查找   适用于所有的**以`顺序表`或者`线性链表`表示的静态查找表**
 - 二分查找/折半查找     仅适用于顺序存储结构有序表
 - 斐波那契查找         仅适用于顺序存储结构有序表
 - 插值查找             仅适用于顺序存储结构有序表
 
#### 如何实现链表的折半查找

答案是否定的.这是由链表的特性决定的。链表是很典型的顺序存取结构，
数据在链表中的位置只能通过从头到尾的顺序检索得到，即使是有序的，
要操作其中的某个数据也必须从头开始。这和数组有本质的不同。数组中的元素是通过下标来确定的，只要你知道了下标，就可以直接存储整个元素，比如a[5],是直接的。
链表没有这个，所以，折半查找只能在数组上进行。 