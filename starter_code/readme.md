1. Why does increasing threads not give linear speedup?
ans. it is due to many reasons like memory limits, computational limits and false sharing of data etc..
memory bus width limit: in this case since a bus can move limited bits of data per clock cycle.
if more than that limit of data is supposed to be sent at once then the memory has to was for the bus to send
the intial data which limits its speed
memory bandwidth: it is almost same as memory bus width limit, (memory bandwith = memory bus width * clockspeed)
false sharing : in this case if the data in two adjacent cores is stored very near it each other then while accessing that in each core the data of other core may also be accessed which leads to a false share of data and at this time only one core can work at once and the other core has to wait for the provious core to finish its comptation.
shared bus bottleneck: it seems very similar to false sharing, but it is quiet different, in this case multiple cores try to send access or send the data to memory at once but the bus has its limits so sometimes it wont be possible for all those cores to access data at a time which leads to small time delay overally.
pipeline bubbles : in accessing instructions from memory the busses follow a method called pipeline method, in this method the cores fetch data contiously and it will passed to its next worker. but if the cores are supposed to store some data in memory then they have to send the data throught the same bus which stops the fetching units for a while, until the data is sent to memory. 
this gap leads to a bubble throughout the units which stops the program to speedup linearly as the threads are increased.
2.Which program is limited by memory?
ans. memory_bound program is limited by memory, the observations are the as the threads are increased the time doesnt speedup effective because memory bounds are due to busyness of bus or latency not becuase of CPU, therefore increasing more threads leads to more cpu cores but doesnt help to busses. so the speedup will be less compared to computatonal bounded program
3.Which program is limited by computation?
ans. computation_bound program. observations are more speedup can be observed as the no of threads are increased. in this case speedup almost reaches ideal case speedup for some number of threads and then as the no.of threads are increased false sharing can happen more frequently leading to very less speedup even sometimes it get more worse
4.What is false sharing in your own words?
ans. false sharing means two completely independent cores sharing their data in a single cache line.
due to this at a single time only one cpu core can access that cache line leading to delay in computation.
5.How was false sharing fixed?
ans. the simple way to avoid false sharing is padding. paddings means inserting unused bytes between the variables which will help data to go in different cache line and different cores can access them individually.

