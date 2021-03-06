# Parallel Problems

* Sum of two vectors: POSIX Threads Parallelization
* Stencil: POSIX Threads Parallelization
* Matrix Multiplication: OpenMP Parallelization
* Stencil: OpenMP Parallelization

### Compilation

```
cd $PROJECT_DIRECTORY$
cmake .
make alll
```

### Execution

```
./$PROJECT_DIRECTORY$/build/parallel_problems -p <problem> -t <num_threads>;
```
<code>
  &lt;problem&gt;
</code>

 * 	0: Sum of vectors
 * 	1: Stencil PThreads
 * 	2: Matrix multiplication
 *  3: Stencil OpenMP
 
### Machine Description
* CPU: Intel(R) Core(TM) i7-3610QM CPU @ 2.30GHz
* Thread(s) per core: 2
* Core(s) per socket: 4
* Socket(s): 1
* L1d cache: 32K
* L1i cache: 32K
* L2 cache: 256K
* L3 cache: 6144K
