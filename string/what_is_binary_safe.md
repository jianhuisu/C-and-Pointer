## 二进制安全

> mei you  shu ju bian jie , lei si yu  tcp yu  udp de qu bie.

在看PHP手册的时候，经常看到一句话”该函数是二进制安全的”。

 - 二进制安全是什么呢？
 - 他是如何实现的？

先看一段代码：

    <?php
    
    $string1 = "Hello"; 
    $string2 = "Hello\0Hello"; 
    
    // 返回0, 由于内部函数非二进制安全，误判为相等 
    echo strcoll($string1, $string2); 
    
    // return -6 , 该内部函数二进制安全 ，
    echo strcmp($string1, $string2);  
    
    ?>
    
这是为什么呢？`PHP`是基于`C`实现的，`PHP`代码都会被`zend`引擎编译成`opcode`，最终作为`C`语言去执行。 
而对于`C`语言`‘\0’`是字符串的结束符，它读到`’\0’`就会默认字符读取已经结束，从而抛掉后面的字符串。

    main(){  
        char ab[] = "Hello";  
        char ac[] = "Hello\0Hello";  
        strcmp(ab, ac); /*返回0, 由于是非二进制安全，误判为相等 */
    }
     
有一个二进制安全的定义，我挺喜欢的：

**程序不会对其中的数据做任何限制、过滤、或者假设 —— 数据在写入时是什么样的， 它被读取时就是什么样。**

##### PHP是如何实现二进制安全的？

那么，既然`PHP`是基于`C`实现的，`C`字符串类型不是二进制安全的，`PHP`又是如何实现的呢？这就是数据结构的功劳了.`PHP`的内核中，是如此定义字符串类型的

    struct{
        char *val;
        int len;
    } str;
    
`val`是指向字符串内存的指针，`len`表示该字符串的长度，无论是否遇到`'\0'`字符，`C`都按照`len`长度读取该字符串.