# zstu浙江理工大学2022年信息安全基础大作业——RSA密码体制的实现
+ `.cpp`文件是随手写的，算法应该是对的，没怎么测，用的是`long long`觉得实际上应该用不了，于是用`pyhton`写了一份，而且C++版本的异常机制也不好，对于不合法的输入，在此就是比如RSA算法最开始的两个素数不是素数，还有选择的公开指数$e$和$\phi{n = p \times q}$并不是互素的，只是简单的返回false和停止程序。
+ python版本的应该挺能用的，python自带的高精度可以应对实际应用中比较长的数字，然后设置了比较多的异常机制
