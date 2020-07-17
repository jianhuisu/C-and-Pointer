## QPS 与 TPS 

#### TPS/吞吐量

TPS：`Transactions Per Second`，意思是每秒事务数，具体事务的定义，都是人为的，可以一个接口、多个接口、一个业务流程等等。
一个事务是指事务内第一个请求发送到接收到最后一个请求的响应的过程，以此来计算使用的时间和完成的事务个数。

以单接口定义为事务为例，每个事务包括了如下3个过程：

 1. 向服务器发请求
 1. 服务器自己的内部处理（包含应用服务器、数据库服务器等）
 1. 服务器返回结果给客户端

如果每秒能够完成N次这三个过程,`tps`就是`N`；

如果多个接口定义为一个事务，那么，会重复执行abc，完成一次这几个请求，算做一个tps。

#### QPS

QPS：Queries Per Second，意思是每秒查询率，是一台服务器每秒能够响应的查询次数（数据库中的每秒执行查询sql的次数），
显然，这个不够全面，不能描述增删改，所以，**不建议用qps来作为系统性能指标**。

#### 区别

 - 如果是对一个查询接口（单场景）压测，且这个接口内部不会再去请求其它接口，那么`tps=qps`，否则`tps≠qps`
 - 如果是容量场景，假设n个接口都是查询接口，且这个接口内部不会再去请求其它接口，`qps=n*tps`

QPS是数据库中的概念,被引申到压测中来了，但是不包括插入、更新、删除操作，**所以不建议用qps来描述系统整体的性能**；
建议用tps，这个t，你可以随意的定义，可以是一个接口，也可以是一个业务流程等等.