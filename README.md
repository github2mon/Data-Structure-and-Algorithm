# Data-Structure-and-Algorithm
personal note of Data Structure and Algorithm

* Template definitions are special. Anything processed by  template <...> means that the compiler does not allocate storage for it at the time, and it waits until it is told by a template instance. Somewhere between the compiler and the connector, there is a mechanism to remove multiple definitions of a given template. So for ease of use, almost always place all the template declarations and definitions in the header file.  
>>模板定义很特殊。由template<…>处理的任何东西都意味着编译器在当时不为它分配存储空间，它一直处于等待状态直到被一个模板实例告知。在编译器和连接器的某一处，有一机制能去掉指定模板的多重定义。所以为了容易使用，几乎总是在头文件中放置全部的模板声明和定义。
