## [001A Theatre Square](001A_Theatre_Square/Solution.cc)

* 算法：简单算数，先看每行至少要几个。然后看每列要几个，之积即为结果。
* 难点：无

## [391A Genetic Engineering](391A_Genetic_Engineering/Solution.c)

* 算法：如果有奇数个连续相同的字符则加一
* 难点：循环后不要忘记处理最后一个连续字符串

## [462A Appleman and Easy Task](462A_Appleman_and_Easy_Task/Solution.c)

* 算法：逐个检查
* 难点：无

## [462B Appleman and Card Game](462B_Appleman_and_Card_Game/Solution.cc)

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

## [496E Distributing Parts](496E_Distributing_Parts/Solution.cc)

* 算法：将Note和Actor放在一起按开始时间排序。如果遇到Note和Actor开始时间相同的情况，将Actor放在前面(Note和Note, Actor和Actor之间顺序随意，可以按照他们的id)。定义一个actor set, 该set会将里面的actor按结束时间排序。扫一遍排完序的数组，如果遇到actor，放进actor set里。如果遇到Note, 在actor set找到大于等于该Note结束时间的actors中拥有最小结束时间的actor。将该actor的k减一。如果该actor的k变为0，则从actor set中删除。对于某次操作，如果actor set中找不到合适的actor，则结束，输出NO。否则，输出结果。
* 难点：

    1. 上述算法很巧妙的利用了排序（线段树可能可以做，但没有上述方法简单）
    2. 如果用C/C++，要用multiset，排序中的comparator必须实现严格less，64位数可以用<inttypes.h>

## [499A Watching a movie](499A_Watching_a_movie/Solution.cc)

* 算法：如果当前位置为t, 那么跳到下一个精彩时刻[a, b]所需要看的时间为(a - t) % x；加上本身观看时间b - a + 1，所以对于每一组输入，需要观看(a - t) % x + b - a + 1。全部之和即为答案
* 难点：看清题目，以及每次处理完一组后将当前位置置为b+1即可。

## [499B Lecture](499B_Lecture/Solution.cc)

* 算法：用一个map保存每个单词所对应的笔记单词，然后查询map就行
* 难点：string和map操作，不过如果用C++会很简单

## [500A New Year Transportation](500A_New_Year_Transportation/Solution.cc)

* 算法：用一个visited数组记录哪些cell已经被访问过。从第一个cell开始，一个一个跳，如果跳到访问过的cell则输出NO。否则如果跳到了正确的cell，则输出YES
* 难点：无

## [500B New Year Permutation](500B_New_Year_Permutation/Solution.cc)

* 算法：经过观察，发现最美得排列一定是按照升序排列的，换言之1,2,3...,n一定是最美的。下面就要找出根据已知的矩阵A，通过两两交换，能够得到的最小排列。可以用union-find做。如果i,j能够交换，那么认为i,j为一组。所以可知，如果i,j和j,k都可交换，那么i,j,k形成一组。通过union-find找出所有这样的组，对组内的数字排序(同时将这些数字占据的下标也排序)，最后对于每个组，按从小到大重新填即可。
* 难点：

    1. union-find实现
    2. 找规律

## [500C New Year Book Reading](500C_New_Year_Book_Reading/Solution.cc)

* 算法：模拟，复杂度O(mn)。注意观察，如果所要读的书没有重复，那么书的放置顺序(从上到下)，必然为给定的读书序列。这是因为，读完k本书后，栈顶的前k的元素必为k, k-1, k-2, ... 1，无论初始状态如何。所以一开始按照1, 2, ..., k的放置顺序能使总费用最小(以上1,2,...,k都是指读书顺序数组的下标)。下面考虑如果有重复读一本书的情况，设第一次读的天为k, 第二次读的天为k+x，那么在k+x-1天时，栈顶情况必为k+x-1, k+x-2, ..., k。注意以上顺序和初始书的放置顺序无关！因此总的费用为sum(w(b(k+x-1, k+x-2, ..., k+1)))。综上所述，扫一遍给定的读书序列，如果书是第一次出现，那么总费用加上目前已知所有书的总重量。如果书已经出现过，找到该书，放到顶部，并且将出现在该书之前的书的重量加到总费用中。
* 难点：找到规律。set, list应用。

## [500D New Year Santa Network](500D_New_Year_Santa_Network/Solution.cc)
* 算法：E(d(i,j)) = E(sum f(k)) = sum E(f(k)) = sum w_k * P(k)。然后用dfs计算P(k), 公式为x * (n-x) / C(n, 2)，其中x为删除路k后，某一component城市的数量。
* 难点：

    1. 如何计算Expection。比如表示E(d(i,j))，可以设f(k), f(k) = w_k如果第k条路在d(i,j)上，否则f(k)=0。所以E(d(i,j)) = E(sum f(k)) = sum E(f(k)) = sum w_k * P(k)
    2. 如何计算一条路被选中的概率。考虑到问题特殊性，如果删掉某条路，那么图就不连通。所以可以把路的选法转化为使图连通的选法。设删除路k后，图分为两块，一块有x个城市(另一块就有n-x)，那么选择路k的选法一共有x * (n-x)，总共选法为C(n, 2)，所以每条路的概率是x * (n-x) / C(n,2)
    3. 如何计算删除路k后，其中一块有多少城市。可以用dfs, 当回溯时，可知路k的某块大小。因为图的特殊性，此图其实为一棵树，所以当以某个节点u开始便利时，如果该节点的某个子节点v访问完成，则可知路(u, v)的某一块大小。
    4. 无向图的dfs。
