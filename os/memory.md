# 内存
内存⽤的芯⽚和 CPU Cache 有所不同，它使⽤的是⼀种叫作 DRAM （Dynamic Random
Access Memory，动态随机存取存储器） 的芯⽚。
相⽐ SRAM，DRAM 的密度更⾼，功耗更低，有更⼤的容量，⽽且造价⽐ SRAM 芯⽚便宜很
多。


DRAM 存储⼀个 bit 数据，只需要⼀个晶体管和⼀个电容就能存储，但是因为数据会被存储在
电容⾥，电容会不断漏电，所以需要「定时刷新」电容，才能保证数据不会被丢失，这就是
DRAM 之所以被称为「动态」存储器的原因，只有不断刷新，数据才能被存储起来。
DRAM 的数据访问电路和刷新电路都⽐ SRAM 更复杂，所以访问的速度会更慢，内存速度⼤
概在 200~300 个 时钟周期之间。
