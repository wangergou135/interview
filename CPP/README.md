# CPP

https://www.cnblogs.com/talenth/p/5820028.html
# New #
1 new operator，也叫new表达式；new表达式比较常见，也最常用，例如：

string* ps = new string("abc");

上面这个new表达式完成了两件事情：申请内存和初始化对象。

2 operator new，也叫new操作符。这两个英文名称起的也太绝了，很容易搞混，那就记中文名称吧。new操作符类似于C语 言中的malloc，只是负责申请内存，例如：

void* buffer = operator new(sizeof(string));

注意: 这里多了一个operator。这是new的第二个用法，也算比较常见吧。

3 placement new，它用于在给定的内存中初始化对象，也就是说你手中已有一块闲置的内存，例如：

void* buffer = operator new(sizeof(string));//那么现在buffer是你所拥有闲置内存的指针

buffer = new(buffer) string("abc"); //调用了placement new，在buffer所指向的内存中初始化string类型的对象，初始值是"abc"

事实上，placement new也是new表达式的一种，但是比普通的new表达式多了一个参数，当然完成的操作和返回值也不同。

因此上面new的第一种用法可以分解两个 动作，分别为后面的两种用法。