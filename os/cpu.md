# CPU Command

### 查看CPU信息（型号）
cat /proc/cpuinfo | grep name | cut -f2 -d: | uniq -c

### 查看物理CPU个数
cat /proc/cpuinfo| grep "physical id"| sort| uniq| wc -l

### 查看每个物理CPU中core的个数(即核数)
cat /proc/cpuinfo| grep "cpu cores"| uniq

### 查看逻辑CPU的个数
cat /proc/cpuinfo| grep "processor"| wc -l

### 查看 CPU ⾥的 L1 Cache 「数据」缓存的容量⼤⼩
cat /sys/devices/system/cpu/cpu0/cache/index0/size
32K

### 查看 L1 Cache 「指令」缓存的容量⼤⼩
cat /sys/devices/system/cpu/cpu0/cache/index1/size

### 查看 CPU ⾥的 L2 Cache 的容量
cat /sys/devices/system/cpu/cpu0/cache/index2/size
256K

### 查看 CPU ⾥的 L3 Cache 的容量
cat /sys/devices/system/cpu/cpu0/cache/index3/size
3072K

### 查看 CPU 的 Cache Line
cat /sys/devices/system/cpu/cpu0/cache/index0/coherency_line_size
64

### 我们可以在启动任务的时候，可以指定 nice 的值，⽐如将 mysqld 以 -3 优先级：
nice -n -3 /usr/sbin/mysqld

### 如果想修改已经运⾏中的任务的优先级，则可以使⽤ renice 来调整 nice 值
renice -10 -p <process_id>

### 改变调度策略和优先级  调度策略 SCHED_FIFO  优先级1
chrt -f 1 -p <process_id>

### 「软中断」的运⾏情况
cat /proc/softirqs
    可以使⽤ watch -d cat /proc/softirqs 命令查看每个软中断类型的中断次数的变化速率

### 「硬中断」的运⾏情况
cat /proc/interrupts


https://www.cnblogs.com/bugutian/p/6138880.html



#   CPU basic 
(from book page 13)
CPU 内部组件，常⻅的有寄存器、控制单元和逻辑运算单元等。其中，控制单元负
责控制 CPU ⼯作，逻辑运算单元负责计算，⽽寄存器可以分为多种类，每种寄存器的功能⼜
不尽相同。

## 常⻅的寄存器种类：
1. 通⽤寄存器，⽤来存放需要进⾏运算的数据，⽐如需要进⾏加和运算的两个数据。
2. 程序计数器，⽤来存储 CPU 要执⾏下⼀条指令「所在的内存地址」，注意不是存储了下
⼀条要执⾏的指令，此时指令还在内存中，程序计数器只是存储了下⼀条指令的地址。
3. 指令寄存器，⽤来存放程序计数器指向的指令，也就是指令本身，指令被执⾏完成之前，
指令都存储在这⾥。

## 总线
地址总线，⽤于指定 CPU 将要操作的内存地址；
数据总线，⽤于读写内存的数据；
控制总线，⽤于发送和接收信号，⽐如中断、设备复位等信号，CPU 收到信号后⾃然进
⾏响应，这时也需要控制总线；

当 CPU 要读写内存数据的时候，⼀般需要通过两个总线：
⾸先要通过「地址总线」来指定内存的地址；
再通过「数据总线」来传输数据；

## 执⾏程序的过程

那 CPU 执⾏程序的过程如下：
第⼀步， CPU 读取「程序计数器」的值，这个值是指令的内存地址，然后 CPU 的「控
制单元」操作「地址总线」指定需要访问的内存地址，接着通知内存设备准备数据，数据
准备好后通过「数据总线」将指令数据传给 CPU，CPU 收到内存传来的数据后，将这个
指令数据存⼊到「指令寄存器」。
第⼆步， CPU 分析「指令寄存器」中的指令，确定指令的类型和参数，如果是计算类型
的指令，就把指令交给「逻辑运算单元」运算；如果是存储类型的指令，则交由「控制单
元」执⾏；
第三步， CPU 执⾏完指令后，「程序计数器」的值⾃增，表示指向下⼀条指令。这个⾃
增的⼤⼩，由 CPU 的位宽决定，⽐如 32 位的 CPU，指令是 4 个字节，需要 4 个内存地
址存放，因此「程序计数器」的值会⾃增 4；

现代⼤多数 CPU 都使⽤来流⽔线的⽅式来执⾏指令，所谓的流⽔线就是把⼀个任务拆分成多
个⼩任务，于是⼀条指令通常分为 4 个阶段，称为 4 级流⽔线
四个阶段的具体含义：
1. CPU 通过程序计数器读取对应内存地址的指令，这个部分称为 Fetch（取得指令）；
2. CPU 对指令进⾏解码，这个部分称为 Decode（指令译码）；
3. CPU 执⾏指令，这个部分称为 Execution（执⾏指令）；
4. CPU 将计算结果存回寄存器或者将寄存器的值存⼊内存，这个部分称为 Store（数据回
写）；
上⾯这 4 个阶段，我们称为指令周期（Instrution Cycle）

## 时钟

⼀个时钟周期⼀定能执⾏完⼀条指令吗？答案是不⼀定的，⼤多数指令不能在⼀个时钟周期
完成，通常需要若⼲个时钟周期。不同的指令需要的时钟周期是不同的，加法和乘法都对应
着⼀条 CPU 指令，但是乘法需要的时钟周期就要⽐加法多。


对于 CPU 时钟周期数我们可以进⼀步拆解成：「指令数 x 每条指令的平均时钟周期数
（Cycles Per Instruction，简称 CPI CPI ）」
程序的CPU执行时间 = 指令数 * CPI* 时钟周期时间

1. 指令数，表示执⾏程序所需要多少条指令，以及哪些指令。这个层⾯是基本靠编译器来优
化，毕竟同样的代码，在不同的编译器，编译出来的计算机指令会有各种不同的表示⽅
式。
2. 每条指令的平均时钟周期数 CPI，表示⼀条指令需要多少个时钟周期数，现代⼤多数
CPU 通过流⽔线技术（Pipline），让⼀条指令需要的 CPU 时钟周期数尽可能的少；
3. 时钟周期时间，表示计算机主频，取决于计算机硬件。有的 CPU ⽀持超频技术，打开了
超频意味着把 CPU 内部的时钟给调快了，于是 CPU ⼯作速度就变快了，但是也是有代
价的，CPU 跑的越快，散热的压⼒就会越⼤，CPU 会很容易奔溃

## 存储器⾦字塔
CPU 内部也有存储数据的组件，这个应该⽐较少⼈注意到，⽐如寄存器、CPU
L1/L2/L3 Cache 也都是属于存储设备，只不过它们能存储的数据⾮常⼩，但是它们因为靠近
CPU 核⼼，所以访问速度都⾮常快，快过硬盘好⼏个数量级别

CPU Cache 通常会分为 L1、L2、L3 三层，其中 L1 Cache 通常分成「数据缓存」和「指令
缓存」，L1 是距离 CPU 最近的，因此它⽐ L2、L3 的读写速度都快、存储空间都⼩。我们⼤
脑中短期记忆，就好⽐ L1 Cache，⽽⻓期记忆就好⽐ L2/L3 Cache。

1. 寄存器的访问速度⾮常快，⼀般要求在半个 CPU 时钟周期内完成读写，CPU 时钟周期跟
CPU 主频息息相关，⽐如 2 GHz 主频的 CPU，那么它的时钟周期就是 1/2G，也就是 0.5ns
（纳秒）。

2. CPU Cache ⽤的是⼀种叫 SRAM（Static Random-Access Memory，静态随机存储器）
的芯⽚。
SRAM 之所以叫「静态」存储器，是因为只要有电，数据就可以保持存在，⽽⼀旦断电，数
据就会丢失了。

3. L1 ⾼速缓存的访问速度⼏乎和寄存器⼀样快，通常只需要 2~4 个时钟周期，⽽⼤⼩在⼏⼗
KB 到⼏百 KB 不等。 每个 CPU 核⼼都有⼀块属于⾃⼰的 L1 ⾼速缓存，指令和数据在 L1 是分开存放的，所以 L1
⾼速缓存通常分成指令缓存和数据缓存

4. L2 ⾼速缓存同样每个 CPU 核⼼都有，但是 L2 ⾼速缓存位置⽐ L1 ⾼速缓存距离 CPU 核⼼
更远，它⼤⼩⽐ L1 ⾼速缓存更⼤，CPU 型号不同⼤⼩也就不同，通常⼤⼩在⼏百 KB 到⼏
MB 不等，访问速度则更慢，速度在 10~20 个时钟周期。

5. L3 ⾼速缓存通常是多个 CPU 核⼼共⽤的，位置⽐ L2 ⾼速缓存距离 CPU 核⼼ 更远，⼤⼩也
会更⼤些，通常⼤⼩在⼏ MB 到⼏⼗ MB 不等，具体值根据 CPU 型号⽽定。
访问速度相对也⽐较慢⼀些，访问速度在 20~60 个时钟周期。



## 存储器的层次关系
CPU 并不会直接和每⼀种存储器设备直接打交道，⽽是每⼀种存储器设备只和它相邻的存储
器设备打交道。
⽐如，CPU Cache 的数据是从内存加载过来的，写回数据的时候也只写回到内存，CPU
Cache 不会直接把数据写到硬盘，也不会直接从硬盘加载数据，⽽是先加载到内存，再从内
存加载到 CPU Cache 中。


每个存储器只和相邻的⼀层存储器设备打交道，并且存储设备为了追求更快的速度，
所需的材料成本必然也是更⾼，也正因为成本太⾼，所以 CPU 内部的寄存器、L1\L2\L3
Cache 只好⽤较⼩的容量，相反内存、硬盘则可⽤更⼤的容量，这就我们今天所说的存储器
层次结构。

另外，当 CPU 需要访问内存中某个数据的时候，如果寄存器有这个数据，CPU 就直接从寄
存器取数据即可，如果寄存器没有这个数据，CPU 就会查询 L1 ⾼速缓存，如果 L1 没有，则
查询 L2 ⾼速缓存，L2 还是没有的话就查询 L3 ⾼速缓存，L3 依然没有的话，才去内存中取
数据



程序执⾏时，会先将内存中的数据加载到共享的 L3 Cache 中，再加载到每个核⼼独有的 L2
Cache，最后进⼊到最快的 L1 Cache，之后才会被 CPU 读取。越靠近 CPU 核⼼的缓存其访问速度越快，CPU 访问 L1 Cache 只需要 2~4 个时钟周期，访问 L2 Cache ⼤约 10~20 个时钟周期，访问 L3 Cache ⼤约 20~60 个时钟周期，⽽访问内
存速度⼤概在 200~300 个 时钟周期之间


## CPU Cache 的数据结构和访问逻辑
1. 直接映射 Cache（Direct Mapped Cache）  CPU 访问内存数据时，是⼀⼩块⼀⼩块数据读取的，具体这⼀⼩块数据的⼤
⼩，取决于 coherency_line_size 的值，⼀般 64 字节。在内存中，这⼀块的数据我们称为
内存块（Block），读取的时候我们要拿到数据所在内存块的地址。


    直接映射 Cache 采⽤的策略，就是把内存块的地址始终「映射」在⼀个 CPU Line（缓
存块） 的地址，⾄于映射关系实现⽅式，则是使⽤「取模运算」，取模运算的结果就是内存
块地址对应的 CPU Line（缓存块） 的地址

    使⽤取模⽅式映射的话，就会出现多个内存块对应同⼀个 CPU Line,为了区别不同的内存块，在对应的 CPU Line 中我们还会存储⼀个组标记（Tag）。这个组标记会记录当前 CPU Line 中存储的数据对应的内存块，我们可以⽤这个组标记来区分不同的内存块。

    除了组标记信息外，CPU Line 还有两个信息：
⼀个是，从内存加载过来的实际存放数据（Data）。
另⼀个是，有效位（Valid bit），它是⽤来标记对应的 CPU Line 中的数据是否是有效
的，如果有效位是 0，⽆论 CPU Line 中是否有数据，CPU 都会直接访问内存，重新加
载数据。

    CPU 在从 CPU Cache 读取数据的时候，并不是读取 CPU Line 中的整个数据块，⽽是读取
CPU 所需要的⼀个数据⽚段，这样的数据统称为⼀个字（Word）。那怎么在对应的 CPU
Line 中数据块中找到所需的字呢？答案是，需要⼀个偏移量（Offset）。

    因此，⼀个内存的访问地址，包括组标记、CPU Line 索引、偏移量这三种信息，于是 CPU
就能通过这些信息，在 CPU Cache 中找到缓存的数据。⽽对于 CPU Cache ⾥的数据结构，
则是由索引 + 有效位 + 组标记 + 数据块组成。

2. 如果内存中的数据已经在 CPU Cahe 中了，那 CPU 访问⼀个内存地址的时候，会经历这 4
个步骤：
   1. 根据内存地址中索引信息，计算在 CPU Cahe 中的索引，也就是找出对应的 CPU Line
的地址；
   2. 找到对应 CPU Line 后，判断 CPU Line 中的有效位，确认 CPU Line 中数据是否是有效
的，如果是⽆效的，CPU 就会直接访问内存，并重新加载数据，如果数据有效，则往下
执⾏；
   3. 对⽐内存地址中组标记和 CPU Line 中的组标记，确认 CPU Line 中的数据是我们要访问
的内存数据，如果不是的话，CPU 就会直接访问内存，并重新加载数据，如果是的话，
则往下执⾏；
   4. 根据内存地址中偏移量信息，从 CPU Line 的数据块中，读取对应的字。
1. 除了直接映射 Cache 之外，还有
其他通过内存地址找到 CPU Cache 中的数据的策略，⽐如全相连 Cache （Fully Associative
Cache）、组相连 Cache （Set Associative Cache）等，这⼏种策策略的数据结构都⽐较相
似，



## 如何写出让 CPU 跑得更快的代码

CPU Cache 的数据是从内存中读取过来的，它是以⼀⼩块⼀⼩块读取数据的，⽽不是按照单
个数组元素来读取数据的，在 CPU Cache 中的，这样⼀⼩块⼀⼩块的数据，称为 Cache
Line（缓存块）


CPU 读取数据的时候，⽆论数据是否存放到 Cache 中，CPU 都是先访问 Cache，
只有当 Cache 中找不到数据时，才会去访问内存，并把内存中的数据读⼊到 Cache 中，
CPU 再从 CPU Cache 读取数据

「如何写出让 CPU 跑得更快的代码？」这个问题，可以改成「如何写出 CPU 缓存命
中率⾼的代码？」。
在前⾯我也提到， L1 Cache 通常分为「数据缓存」和「指令缓存」，这是因为 CPU 会别处
理数据和指令，⽐如 1+1=2 这个运算， + 就是指令，会被放在「指令缓存」中，⽽输⼊数
字 1 则会被放在「数据缓存」⾥。

1. 如何提升数据缓存的命中率:  遍历数组的情况时，按照内存布局顺序访问，将可以有效的利⽤ CPU Cache
带来的好处，这样我们代码的性能就会得到很⼤的提升
2. 如何提升指令缓存的命中率:  先遍历再排序速度快，还是先排序再遍历速度快:  在回答这个问题之前，我们先了解 CPU 的分⽀预测器。对于 if 条件语句，意味着此时⾄少可
以选择跳转到两段不同的指令执⾏，也就是 if 还是 else 中的指令。那么，如果分⽀预测可以
预测到接下来要执⾏ if ⾥的指令，还是 else 指令的话，就可以「提前」把这些指令放在指令
缓存中，这样 CPU 可以直接从 Cache 读取到指令，于是执⾏速度就会很快。
    因此，先排序再遍历速度会更快，这是因为排序之后，数字是从⼩到⼤的，那么前⼏次循环
命中 if < 50 的次数会⽐较多，于是分⽀预测就会缓存 if ⾥的 array[i] = 0 指令到
Cache 中，后续 CPU 执⾏该指令就只需要从 Cache 读取就好了。


## 提升多核 CPU 的缓存命中率
在单核 CPU，虽然只能执⾏⼀个进程，但是操作系统给每个进程分配了⼀个时间⽚，时间⽚
⽤完了，就调度下⼀个进程，于是各个进程就按时间⽚交替地占⽤ CPU，从宏观上看起来各
个进程同时在执⾏。

⽽现代 CPU 都是多核⼼的，进程可能在不同 CPU 核⼼来回切换执⾏，这对 CPU Cache 不
是有利的，虽然 L3 Cache 是多核⼼之间共享的，但是 L1 和 L2 Cache 都是每个核⼼独有
的，如果⼀个进程在不同核⼼来回切换，各个核⼼的缓存命中率就会受到影响，相反如果进
程都在同⼀个核⼼上执⾏，那么其数据的 L1 和 L2 Cache 的缓存命中率可以得到有效提⾼，
缓存命中率⾼就意味着 CPU 可以减少访问 内存的频率。


当有多个同时执⾏「计算密集型」的线程，为了防⽌因为切换到不同的核⼼，⽽导致缓存命
中率下降的问题，我们可以把线程绑定在某⼀个 CPU 核⼼上，这样性能可以得到⾮常可观的
提升。


在 Linux 上提供了 sched_setaffinity ⽅法，来实现将线程绑定到某个 CPU 核⼼这⼀功
能。

## CPU Cache 的数据写⼊
在什么时机才把 Cache 中的数据写回到内存呢？为了应对这个问题，下⾯介绍
两种针对写⼊数据的⽅法：
1. 写直达（Write Through）      保持内存与 Cache ⼀致性最简单的⽅式是，把数据同时写⼊内存和 Cache 中，这种⽅法称
为写直达（Write Through）       
    写⼊前会先判断数据是否已经在 CPU Cache ⾥⾯了：
如果数据已经在 Cache ⾥⾯，先将数据更新到 Cache ⾥⾯，再写⼊到内存⾥⾯；
如果数据没有在 Cache ⾥⾯，就直接把数据更新到内存⾥⾯。

2. 写回（Write Back）           既然写直达由于每次写操作都会把数据写回到内存，⽽导致影响性能，于是为了要减少数据
写回内存的频率，就出现了写回（Write Back）的⽅法。
    在写回机制中，当发⽣写操作时，新的数据仅仅被写⼊ Cache Block ⾥，只有当修改过的
Cache Block「被替换」时才需要写到内存中，减少了数据写回内存的频率，这样便可以提
⾼系统的性能。
    可以发现写回这个⽅法，在把数据写⼊到 Cache 的时候，只有在缓存不命中，同时数据对应
的 Cache 中的 Cache Block 为脏标记的情况下，才会将数据写到内存中，⽽在缓存命中的情
况下，则在写⼊后 Cache 后，只需把该数据对应的 Cache Block 标记为脏即可，⽽不⽤写到
内存⾥

## 缓存⼀致性问题
需要⼀种机制，来同步两个不同核⼼⾥⾯的缓存数据。要实现的
这个机制的话，要保证做到下⾯这 2 点：
1. 某个 CPU 核⼼⾥的 Cache 数据更新时，必须要传播到其他核⼼的 Cache，这
个称为写传播（Wreite Propagation）；
2. 某个 CPU 核⼼⾥对数据的操作顺序，必须在其他核⼼看起来顺序是⼀样的，这
个称为事务的串形化（Transaction Serialization）。
    要实现事务串形化，要做到 2 点：
CPU 核⼼对于 Cache 中数据的操作，需要同步给其他 CPU 核⼼；
要引⼊「锁」的概念，如果两个 CPU 核⼼⾥有相同数据的 Cache，那么对于这个 Cache
数据的更新，只有拿到了「锁」，才能进⾏对应的数据更新。


写传播的原则就是当某个 CPU 核⼼更新了 Cache 中的数据，要把该事件⼴播通知到其他核
⼼。最常⻅实现的⽅式是总线嗅探（Bus Snooping）

总线嗅探⽅法很简单， CPU 需要每时每刻监听总线上的⼀切活动，但是不管别的
核⼼的 Cache 是否缓存相同的数据，都需要发出⼀个⼴播事件，这⽆疑会加重总线的负载。
另外，总线嗅探只是保证了某个 CPU 核⼼的 Cache 更新数据这个事件能被其他 CPU 核⼼知
道，但是并不能保证事务串形化。
于是，有⼀个协议基于总线嗅探机制实现了事务串形化，也⽤状态机机制降低了总线带宽压
⼒，这个协议就是 MESI 协议，这个协议就做到了 CPU 缓存⼀致性。


MESI 协议其实是 4 个状态单词的开头字⺟缩写，分别是：
    Modified，已修改
    Exclusive，独占
    Shared，共享
    Invalidated，已失效
这四个状态来标记 Cache Line 四个不同的状态。

「已修改」状态就是我们前⾯提到的脏标记，代表该 Cache Block 上的数据已经被更新过，
但是还没有写到内存⾥。⽽「已失效」状态，表示的是这个 Cache Block ⾥的数据已经失效
了，不可以读取该状态的数据。

「独占」和「共享」状态都代表 Cache Block ⾥的数据是⼲净的，也就是说，这个时候
Cache Block ⾥的数据和内存⾥⾯的数据是⼀致性的。

「独占」和「共享」的差别在于，独占状态的时候，数据只存储在⼀个 CPU 核⼼的 Cache
⾥，⽽其他 CPU 核⼼的 Cache 没有该数据。这个时候，如果要向独占的 Cache 写数据，就
可以直接⾃由地写⼊，⽽不需要通知其他 CPU 核⼼，因为只有你这有这个数据，就不存在缓
存⼀致性的问题了，于是就可以随便操作该数据。

「共享」状态代表着相同的数据在多个 CPU 核⼼的 Cache ⾥都有，所以当我们要更
新 Cache ⾥⾯的数据的时候，不能直接修改，⽽是要先向所有的其他 CPU 核⼼⼴播⼀个请
求，要求先把其他核⼼的 Cache 中对应的 Cache Line 标记为「⽆效」状态，然后再更新当
前 Cache ⾥⾯的数据

我们举个具体的例⼦来看看这四个状态的转换：
1. 当 A 号 CPU 核⼼从内存读取变量 i 的值，数据被缓存在 A 号 CPU 核⼼⾃⼰的 Cache ⾥
⾯，此时其他 CPU 核⼼的 Cache 没有缓存该数据，于是标记 Cache Line 状态为「独
占」，此时其 Cache 中的数据与内存是⼀致的；
2. 然后 B 号 CPU 核⼼也从内存读取了变量 i 的值，此时会发送消息给其他 CPU 核⼼，由
于 A 号 CPU 核⼼已经缓存了该数据，所以会把数据返回给 B 号 CPU 核⼼。在这个时
候， A 和 B 核⼼缓存了相同的数据，Cache Line 的状态就会变成「共享」，并且其
Cache 中的数据与内存也是⼀致的；
3. 当 A 号 CPU 核⼼要修改 Cache 中 i 变量的值，发现数据对应的 Cache Line 的状态是共
享状态，则要向所有的其他 CPU 核⼼⼴播⼀个请求，要求先把其他核⼼的 Cache 中对
应的 Cache Line 标记为「⽆效」状态，然后 A 号 CPU 核⼼才更新 Cache ⾥⾯的数据，
同时标记 Cache Line 为「已修改」状态，此时 Cache 中的数据就与内存不⼀致了。
4. 如果 A 号 CPU 核⼼「继续」修改 Cache 中 i 变量的值，由于此时的 Cache Line 是「已
修改」状态，因此不需要给其他 CPU 核⼼发送消息，直接更新数据即可。
5. 如果 A 号 CPU 核⼼的 Cache ⾥的 i 变量对应的 Cache Line 要被「替换」，发现 
Cache Line 状态是「已修改」状态，就会在替换前先把数据同步到内存。
所以，可以发现当 Cache Line 状态是「已修改」或者「独占」状态时，修改更新其数据不需
要发送⼴播给其他 CPU 核⼼，这在⼀定程度上减少了总线带宽压⼒。


##  Cache 伪共享
这种因为多个线程同时读写同⼀个 Cache Line 的不同变量时，⽽导致 CPU Cache 失
效的现象称为伪共享（False Sharing）。

对于多个线程共享的热点数据，即经常会修改的数据，应该避免这些数据刚好在同⼀
个 Cache Line 中，否则就会出现为伪共享的问题

#ifdef CONFIG_SMP
#define __cacheline_aligned_in_smp __cacheline_aligned
#else 
#define __cachline_aligned_in_smp
#endif


## CPU 如何选择线程的
在 Linux 内核中，进程和线程都是⽤ tark_struct 结构体表示的，区别在于线程的
tark_struct 结构体⾥部分资源是共享了进程已创建的资源，⽐如内存地址空间、代码段、⽂
件描述符等，所以 Linux 中的线程也被称为轻量级进程，因为线程的 tark_struct 相⽐进程的
tark_struct 承载的 资源⽐较少，因此以「轻」得名。

Linux 内核⾥的调度器，调度的对象就是 tark_struct ，接下来我们就把这个数据结
构统称为任务


在 Linux 系统中，根据任务的优先级以及响应要求，主要分为两种，其中优先级的数值越
⼩，优先级越⾼：
实时任务，对系统的响应时间要求很⾼，也就是要尽可能快的执⾏实时任务，优先级在
0~99 范围内的就算实时任务；
普通任务，响应时间没有很⾼的要求，优先级在 100~139 范围内都是普通任务级别；


1. 完全公平调度（Completely Fair Scheduling） : 这个算法的理念是想让分配给每个任务的 CPU 时间是⼀样，于是它为每个任务安排⼀个虚拟
运⾏时间 vruntime，如果⼀个任务在运⾏，其运⾏的越久，该任务的 vruntime ⾃然就会越
⼤，⽽没有被运⾏的任务，vruntime 是不会变化的。
那么，在 CFS 算法调度的时候，会优先选择 vruntime 少的任务，以保证每个任务的公平
性。



## CPU 运⾏队列

每个 CPU 都有⾃⼰的运⾏队列（Run Queue, rq），⽤于描述在此 CPU 上所运⾏
的所有进程，其队列包含三个运⾏队列，Deadline 运⾏队列 dl_rq、实时任务运⾏队列 rt_rq
和 CFS 运⾏队列 csf_rq，其中 csf_rq 是⽤红⿊树来描述的，按 vruntime ⼤⼩来排序的，最
左侧的叶⼦节点，就是下次会被调度的任务

这⼏种调度类是有优先级的，优先级如下：Deadline > Realtime > Fair，这意味着 Linux 选择
下⼀个任务执⾏的时候，会按照此优先级顺序进⾏选择，也就是说先从 dl_rq ⾥选择任务，
然后从 rt_rq ⾥选择任务，最后从 csf_rq ⾥选择任务。因此，实时任务总是会⽐普通任
务优先被执⾏。

如果你想让某个普通任务有更多的执⾏时间，可以调整任务的 nice 值，从⽽让优先级⾼⼀
些的任务执⾏更多时间。nice 的值能设置的范围是 -20～19 ， 值越低，表明优先级越⾼，因
此 -20 是最⾼优先级，19 则是最低优先级，默认优先级是 0。

事实上，nice 值并不是表示优先级，⽽是表示优先级的修
正数值，它与优先级（priority）的关系是这样的：priority(new) = priority(old) + nice。内核
中，priority 的范围是 0~139，值越低，优先级越⾼，其中前⾯的 0~99 范围是提供给实时任
务使⽤的，⽽ nice 值是映射到 100~139，这个范围是提供给普通任务⽤的，因此 nice 值调
整的是普通任务的优先级。


## 中断
中断是⼀种异步的事件处理机制，可以提⾼系统的并发处理能
⼒。
    操作系统收到了中断请求，会打断其他进程的运⾏，所以中断请求的响应程序，也就是中断
处理程序，要尽可能快的执⾏完，这样可以减少对正常进程运⾏调度地影响。
    ⽽且，中断处理程序在响应中断时，可能还会「临时关闭中断」，这意味着，如果当前中断
处理程序没有执⾏完之前，系统中其他的中断请求都⽆法被响应，也就说中断有可能会丢
失，所以中断处理程序要短且快。

 Linux 系统为了解决中断处理程序执⾏过⻓和中断丢失的问题，将中断过程分成了两个阶
段，分别是「上半部和下半部分」。

1. 上半部⽤来快速处理中断，⼀般会暂时关闭中断请求，主要负责处理跟硬件紧密相关或者
时间敏感的事情。上半部直接处理硬件请求，也就是硬中断，主要是负责耗时短的⼯作，特点是快速执⾏；
2. 下半部⽤来延迟处理上半部未完成的⼯作，⼀般以「内核线程」的⽅式运⾏。下半部是由内核触发，也就说软中断，主要是负责上半部未完成的⼯作，通常都是耗时⽐
较⻓的事情，特点是延迟执⾏；


