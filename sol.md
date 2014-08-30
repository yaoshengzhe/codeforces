## [462b Appleman and Card Game](462b_Appleman_and_Card_Game/Solution.c)

* 算法：贪心，将字母按照出现频率排序。然后按频率从大到小取，result += freq * freq，当k不够当前频率时，result += k * k
* 难点：注意数字范围，要用long long int
