字符串字面量
    "Hello, world.\n" 这种由双引号（Double Quote）引起来的一串字符称为字符串字面值（String Literal）或者简称字符串

常量 Constant

常量是程序中最基本的元素，有字符（Character）常量、整数（Integer）常量、浮点数（Floating Point）常量和枚举常量
(我理解为一个具体的值即为常量)

    1 字符常量要用单引号括起来，例如上面的'}'，注意单引号只能括一个字符而不能像双引号那样括一串字符
    2 字符常量也可以是一个转义序列，例如'\n'，这时虽然单引号括了两个字符，但实际上只表示一个字符
    3 转义序列是编译时处理的，而转换说明是在运行时调用printf函数处理的

变量

    变量是计算机存储器中的一块命名的空间，可以在里面存储一个值（Value），这个值随时可能变化，变量的名字叫 Identifier 标示符
    常量有不同的类型，因此变量也有不同的类型，变量的类型也决定了它所占的存储空间的大小。
    这样编译器才知道如何读写这块存储空间。

    定义一个变量，就是分配一块存储空间并给它命名；
    给一个变量赋值，就是把一个值保存到这块存储空间中。
    变量的定义和赋值也可以一步完成，这称为变量的初始化（Initialization），初始化是一种特殊的声明，而不是一种赋值语句

    【在C语言中char型变量占一个字节】，其它类型的变量占多少字节在不同平台上有不同的规定

声明和定义

    C语言中的声明（Declaration）有三种

        变量声明
        函数声明
        类型声明

    如果一个变量或函数的声明要求编译器为它分配存储空间，那么也可以称为定义（Definition），因此定义是声明的一种。
    变量声明不分配存储空间因而不是定义。分配存储空间的函数声明可以称为函数定义。
    类型声明，声明一个类型是不分配存储空间的，但似乎叫“类型定义”听起来也不错，所以可以理解为“类型定义”和“类型声明”表示相同的含义。
    【声明和语句类似，也是以;号结尾的，但是在语法上声明和语句是有区别的】，语句只能出现在{}括号中，而声明既可以出现在{}中也可以出现在所有{}之外。

表达式

常量和变量都可以参与加减乘除运算，例如1+1、hour-1、hour * 60 + minute、minute/60等。

    + - * / 称为运算符（Operator）
    参与运算的常量和变量称为操作数（Operand）
    上面四个由运算符和操作数所组成的算式称为表达式（Expression）

    任何表达式都有值和类型两个基本属性。
    C语言规定等号运算符的计算结果就是等号左边被赋予的那个值，
    所以表达式的值与hour * 60 + minute的值相同，也与total_minute的值相同
    ！！如果一个表达式中出现多个等号，不是从左到右计算而是从右到左计算

    minute + 10 = sec  (错误示范)
    todo 这里没理解 后续得继续啃
    ！！！表达式所表示的存储位置称为左值（lvalue）（允许放在等号左边）
    目前我们学过的表达式中只有变量可以做左值
    有的表达式既可以做左值也可以做右值，而有的表达式只能做右值

    整数除法结果按照 truncate to zero
     3 / 2 = 1
    -3 / 2 = -1
