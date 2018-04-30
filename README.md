# Some Traditional Parallel Problems

* Sum of two vectors: POSIX Threads Parallelization
* Stencil: POSIX Threads Parallelization
* Matrix Multiplication: OpenMP 

### Compilation

```
cd $PROJECT_DIRECTORY$
cmake .
make alll
```

### Execution

<code>
./$PROJECT_DIRECTORY$/build/parallel_problems -p &lt;problem&gt; -t &lt;num_threads&gt;
</code>

<br/>

<code>
  &lt;problem&gt;
</code>

 * 	0: Sum of vectors
 * 	1: Stencil
 * 	2: Matrix multiplication
 
### Machine Description
* CPU: Intel(R) Core(TM) i7-3610QM CPU @ 2.30GHz
* Thread(s) per core: 2
* Core(s) per socket: 4
* Socket(s): 1
* L1d cache: 32K
* L1i cache: 32K
* L2 cache: 256K
* L3 cache: 6144K
