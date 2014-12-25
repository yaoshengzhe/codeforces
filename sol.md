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

## [496C Removing Columns](496C_Removing_Columns/Solution.cc)

* 算法：将还未分出大小的行保存为一个组(初始为所有行)。对于每一列，如果没有排序则删除(结果+1)；如果已排序，将所有相同的行划为一个组，以后所有列，只要保证对于每个组都排序即可。(我中文一定是体育老师教的-_-|)
* 难点：

    1. 如果用char[][]，scanf要用%s (%c会导致接受回车和空格)
    2. 用vector，C自带数据结构不给力

## [496D Tennis Game](496D_Tennis_Game/Solution.cc)

* 算法：考虑枚举t, 对于一个给定的t, 最多只有一个合法的s，并且该s最多不超过n/t。所以枚举t时，最多有n/1 + n/2 + n/3 + ... = O(nlgn)。所以一共有O(nlgn)个set需要处理。下面考虑处理每个set的复杂度。已知当前set的开始位置，我们只需知道两位选手中最先赢得t场的位置，该位置就是当前set的结束位置。解法，为两位选手各自保存到i场时，赢得的场数。所以要计算当前set的结束位置时，只要用lower_bound (bsearch变种，找下限)找到两位选手从当前位置赢得t场所需要的场数，少的那个即为当前set的结束位置。复杂度是lgn。所以总复杂度为set总数O(nlgn) * O(lgn) = O(nlg^2(n))。
* 难点：

    1. 如果从s开始枚举，因为一个s可能对应多个t, 很难高效计算
    2. 在bsearch时，要找lower bound，因为一位选手可能赢得当前局后，很久没赢球，用一般bsearch所得结果错误
    3. 如果set确定后，那么赢得最后一场胜利的选手应该是最后赢家(否则比赛早就应该提前结束)。一种解决方法是，如果还有比赛没考虑，那么设s为当前赢球多的选手的set + 1。当考虑完最后一场时，其中一方赢球场数必须等于以上值。

## [499A Watching a movie](499A_Watching_a_movie/Solution.cc)

* 算法：如果当前位置为t, 那么跳到下一个精彩时刻[a, b]所需要看的时间为(a - t) % x；加上本身观看时间b - a + 1，所以对于每一组输入，需要观看(a - t) % x + b - a + 1。全部之和即为答案
* 难点：看清题目，以及每次处理完一组后将当前位置置为b+1即可。
