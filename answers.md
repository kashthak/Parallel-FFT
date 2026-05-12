1.which pattern was easiest to parallelize, and why?
ans.. map pattern was easiest to parallelize because in it each itetration is independent of 
others (no dependency exist). so, its just about creating a parallel for loop in which many or
all the iterations happpens parallelly accoring to the no.of threads.

2.what dependency exist in reduction?
ans.. loop carried dependency exist in reduction. that means every iteration depends on its
previous update. since shared variable dependency exist,there will be race conditions among 
threads which leads to wrong answers if we create simple parallel for.

3.Why is a reduction clause needed?
ans.. in order to solve the issue of race condition in loop carried dependency. reduction clause 
creates a local sum variable for every thread and then those final sum varibales of each thread 
will be appied by the operation that is given in the syntax of reduction clause. ie., 
reduction(operation:the variable that is to be distributed to each thread)

4.Why does scan not work with a simple parallel for on the original loop?
ans.. why because there exist a liner chain dependency. whenever there is a data dependency then 
simple parallel for doesn't work.

5.How did the chunk-based scan change the dependency structure? 
ans.. Chunk-based scan changes the dependency structure by breaking one
long sequential dependency chain into smaller independent pieces. then,
since each chuck is independent they can be scanned parallelly leading
to a parallel work and then we find offsets of each chuck and we again
apply parallel work among the same chunks by addings offsets. that again
leads to a parallel work. which overally leads to much parallel work and 
therefore the speed increases.
