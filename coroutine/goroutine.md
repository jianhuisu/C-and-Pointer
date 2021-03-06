## golang的协程

Go语言是怎样调度成千上万的协程的呢？为此，go语言设计了三种概念，代号分别为M、P和G，其中

 - M代表一个真实的操作系统中的线程概念，
 - P是代表一个真正可以并发的单元，即真实的CPU核心
 - G代表一个工作任务，即这里的协程（goroutine）

在Go语言程序启动的时候，会先启动go语言的runtime，这个runtime是会被编译器编译到所有的go语言程序中的。
Go语言runtime在启动的时候，会创建和CPU核心数相同的P结构。
但是P结构终归是要附着在真实的操作系统线程M上才能运行的，所以在P结构创建的时候也会创建相应数量的M结构。
任何任务G都必须依赖于P运行，P是真正的并发单元，这种设计可以使得同一时刻使用CPU的操作系统级别的线程只有P的数量个，
这样操作系统的线程切换频率几乎为0（因为可以直接把这么多的P直接扔到不同的CPU里面执行就可以了）。
这样Go语言就可以托管所有的任务切换，从而使得在用户态完成协程的切换。
但是要运行的任务是G结构中保存的（一个完整的协程），所以P会带上一个局部任务队列来保存可以被运行的G.

o的设计是为成千上万的G同时执行而准备的,所以G初始的时候只有一个很小（2KB）的栈，当G需要更多栈的时候就要进行扩容，扩容是2x、4x、8x这样进行的。所以当扩容时，G也会被抢占。

协程可以简化为三个状态：运行态、就绪态和休眠态。
**同一个线程中最多只会存在一个处于运行态的协程**。就绪态协程是指那些具备了运行能力但是还没有得到运行机会的协程，
它们随时会被调度到运行态；休眠态的协程还不具备运行能力，它们是在等待某些条件的发生，比如 IO 操作的完成、睡眠时间的结束等。

##### channel

在GO里，不同的并行协程之间交流的方式有两种，一种是通过共享变量，另一种是通过通道。Go 语言鼓励使用通道的形式来交流。
通过channel的形式来通信，可以大程度上避免data race的可能性.

##### 结论

go的协程调度是抢占式的
go的协程是可以利用多核的，并且是从语言层面上支持.不同于swoole的协程模型,swoole如何要利用cpu多核，需要依赖于swoole的多进程模型.

##### 参考资料

https://blog.csdn.net/inszva/article/details/54081605