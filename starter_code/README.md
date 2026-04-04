1.Did performance improve after parallelization?
ans. yes, after paralellizing both the scale_vector and sum_vector there is an inprovement in
runtime

2.Was the speedup linear?
ans. yes, it was nearly linear, as the no.of threads are increased exponentially, the runtime
would decrease logarithmic to the no.of threads and therefore ideally it should be linear. but, 
because of some other factors like thread_overhead.. the runtime is not exactly linear

3.Why did the naive parallel sum fail?
ans. because fo the race condition that is been created among the multiple threads accessing 
and modifying the shared variable sum 

4.What limits the speedup?
ans. there can be many factors for the speedup limitation, but the main two reasons are 
1. thread overheat
	it means that the unimportant is higher than important work, unimportant work means
	distributing work among multiple threads and collecing it,combining it is taking more
	work which is not optimal for this simple task.
2. thread competetion
	when no of threads are higher than no.of cpu core units. then cpu will go on switching
	between the threads which leads to consumption of some time, leading to more runtime


