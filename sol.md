## [391A Genetic Engineering](391A_Genetic_Engineering/Solution.c)

* 算法：如果有奇数个连续相同的字符则加一
* 难点：循环后不要忘记处理最后一个连续字符串

## [462A Appleman and Easy Task](462A_Appleman_and_Easy_Task/Solution.c)

* 算法：逐个检查
* 难点：无

## [462B Appleman and Card Game](462B_Appleman_and_Card_Game/Solution.c)

* 算法：贪心，将字母按照出现频率排序。然后按频率从大到小取，result += freq * freq，当k不够当前频率时，result += k * k
* 难点：注意数字范围，要用long long int

## [495A Digital Counter](495A_Digital_Counter/Solution.cc)

* 算法：建一个table, table[i]记录数字i可以由多少的数字经过去掉若干笔画后形成
* 难点：弄清题目

## [495B Modular Equations](495B_Modular_Equations/Solution.cc)

* 算法：a mod x = b => nx = a - b, 所以，找出数字(a-b)有多少因数大于b，所得即答案
* 难点：

    1. a == b 时要输出infinity
    2. 数因数的时候，要从1开始到sqrt(a-b)，所以复杂度是O(sqrt(a-b))
    3. 如果遇到c*c = a-b并且c > b的情况，只能算一个

## [496A Minimum Difficulty](496A_Minimum_Difficulty/Solution.cc)

* 算法：扫一遍，得到相邻两数的最大间距x，以及如果删除a[i], a[i+1] - a[i-1]的最小值y。max(x, y)即为解。
* 难点：想清楚就行，很简单。

## [496B Secret Combination](496B_Secret_Combination/Solution.cc)

* 算法：扫一遍，对于每个digit，如果使之为0，计算所能得到的最小数。所有可能之中最小的即为答案。
* 难点：不能用整形来接受输入，要用char[]，因为n在[1, 1000]
