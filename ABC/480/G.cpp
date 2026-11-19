/* buxiangwanla
你紫名觉得是我的锅，那就是我的锅，为什么你知道吗？因为紫名说的话，就像是一个癌症晚期患者说的话一样。
他都已经这样了，你为什么不顺从他呢?你总要给人最后一段时间一个好的回忆吧，最后的时光里。
因为紫名这个段位很尴尬，紫名橙名再往上一点，grandmaster，可能说，欸，有点实力，能操作一下。
紫名往下，绿名，蓝名，啊，人家是纯属玩游戏的，因为太垃圾了，自己也知道自己没什么实力。
但紫名，上不去下不来的这个段位，他觉得，蓝名的人不配跟他一起玩儿，对吧？蓝名是最垃圾的。
但是呢他想上去，他又上不去，所以这个分段是最尴尬的，没办法，卡在这里了。
想操作，又操作不起来，掉下去吧，他又觉得不值得，对吧，我好不容易从蓝名打到紫名了，我为什么还要掉下去呢?
这个人说优越狗越说越起劲，为什么他会这么说?因为他是紫名。
他觉得你比我段位高，你说的任何话都是优越，我并不管你说的有没有道理。
我紫名，我最猛，我WF2017我上我能夺冠，那打比赛全是sb。你比我段位高你说话就是放屁，这就是这种人的想法。但是呢，他的想法是对的，为什么呢？
因为他癌症晚期。没办法，我同意，对不起，我优越了。可能是我膨胀了，不好意思啊，我膨胀了。我紫名是没操作，难道我就看不懂谁背锅吗？
不是，如果你看得懂的话，就不会在这里抬杠了，对吧。

If you Blue Name think it's my fault, it's my fault. Do you know why? Because what Blue Name says is like something a terminal cancer patient would say.
He's already like that. Why don't you just go along with it? You always have to give someone a good memory for the last period of time, right? In the last time.
Because the blue name of this rating is very awkward, blue name purple name a little further up, master, may say, hey, a little strength, can operate a little.
Blue name down, green name, ah, people are purely playing the game, because it is too trash, they also know that they do not have much strength.
But the blue name, can't go up or down in this rating, he thinks, the green name of the person does not deserve to play with him, right? Green name is the most trash.
But he wants to go up, he can not go up, so this rating is the most embarrassing, no way, stuck here.
I want to solve, but I can not solve the problems, fall down, he also think it is not worth it, right, it is not easy for me to fight from the green name to the blue name, why do I have to fall down?
This person said superior dog the more he said the more energized, why would he say so? Because he's blue.
He thinks you are higher than me, anything you say is superior, I don't care if what you say makes sense or not.
I'm not sure if there's any truth in what you're saying, but I'm not sure if there's any truth in what you're saying, and I'm not sure if there's any truth in what you're saying, and I'm not sure if there's any truth in what you're saying. But then, his idea is right, why?
Because he has terminal cancer. No way, I agree. I'm sorry, I'm superior. Maybe I'm bloated. I'm sorry, I'm bloated. My blue name is no operation. Can't I see who's taking the fall?
No, if you could see it, you wouldn't be here carrying the can, would you.
*/
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ULL;
using LL = long long;

mt19937_64 rd(time(0));
constexpr int N = 2e5 + 5, mod = 998244353, INF = 1e9;
constexpr double eps = 1e-8;

#define fi first
#define se second
// #define int long long
#define lowbit(x) (x & (-x))
#define PII pair<int, int>
#define mid ((l + r) >> 1)

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
void ckmin(int &a,int b) { if(b < a) a = b; }
void ckmax(int &a,int b) { if(b > a) a = b; }

int ksm(int a, int b){
    a %= mod;
    int res = 1;
    while(b){
        if(b & 1)res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
int n, m;
void Sakuya()
{
    cin >> n;
    vector<int>a(n + 1);

    for(int i = 1; i <= n; ++ i)cin >> a[i];

    vector<vector<int>>stmin((n + 1), vector<int>(21)), stmax((n + 1), vector<int>(21));
    for(int i = 1; i <= n; ++ i)stmin[i][0] = stmax[i][0] = a[i];
    for(int j = 1; j <= 20; ++ j){
        for(int i = 1; i + (1 << j) - 1 <= n; ++ i){
            stmin[i][j] = min(stmin[i][j - 1], stmin[i + (1 << (j - 1))][j - 1]);
        }
    }
    for(int j = 1; j <= 20; ++ j){
        for(int i = 1; i + (1 << j) - 1 <= n; ++ i){
            stmax[i][j] = max(stmax[i][j - 1], stmax[i + (1 << (j - 1))][j - 1]);
        }
    }

    auto querymin = [&](int l, int r) -> int{
        int k = __lg(r - l + 1);
        return min(stmin[l][k], stmin[r - (1 << k) + 1][k]);
    };

    auto querymax = [&](int l, int r) -> int{
        int k = __lg(r - l + 1);
        return max(stmax[l][k], stmax[r - (1 << k) + 1][k]);
    };

    vector<int>dp(n + 1, INF);
    dp[0] = 0;

    auto get = [&](int l, int r) -> int{
        return querymax(l, r) - querymin(l, r);
    };

    vector<int>minn(n * 4 + 5, INF), tag(n * 4 + 5);

    auto pushdown = [&](int u) -> void{
        if(tag[u] != 0){
            minn[u << 1] += tag[u];
            minn[u << 1 | 1] += tag[u];
            tag[u << 1] += tag[u];
            tag[u << 1 | 1] += tag[u];
            tag[u] = 0;
        }
    };

    auto update = [&](auto self, int u, int l, int r, int x, int y, int z) -> void{
        if(x <= l && y >= r){
            minn[u] += z;
            tag[u] += z;
            return;
        }
        pushdown(u);
        if(x <= mid)self(self, u << 1, l, mid, x, y, z);
        if(y > mid) self(self, u << 1 | 1, mid + 1, r, x, y, z);
        minn[u] = min(minn[u << 1], minn[u << 1 | 1]);
    };

    auto to = [&](auto self, int u, int l, int r, int pos, int z) -> void{
        if(l == r){
            minn[u] = z;
            tag[u] = 0;
            return;
        }
        pushdown(u);
        if(pos <= mid)self(self, u << 1, l, mid, pos, z);
        else self(self, u << 1 | 1, mid + 1, r, pos, z);
        minn[u] = min(minn[u << 1], minn[u << 1 | 1]);
    };

    auto query = [&](auto self, int u, int l, int r, int x, int y) -> int{
        if(x <= l && y >= r)return minn[u];
        pushdown(u);
        int res = INF;
        if(x <= mid)res = min(res, self(self, u << 1, l, mid, x, y));
        if(y > mid)res = min(res, self(self, u << 1 | 1, mid + 1, r, x, y));
        return res;
    };

    vector<int>mx, mn;

    for(int i = 1; i <= n; ++ i){
        while(mx.size() && a[mx.back()] <= a[i]){
            int r = mx.back();
            mx.pop_back();
            int l = mx.empty() ? 1 : mx.back() + 1;
            update(update, 1, 1, n, l, r, a[i] - a[r]);
        }
        mx.emplace_back(i);

        while(mn.size() && a[mn.back()] >= a[i]){
            int r = mn.back();
            mn.pop_back();
            int l = mn.empty() ? 1 : mn.back() + 1;
            update(update, 1, 1, n, l, r, a[r] - a[i]);
        }
        mn.emplace_back(i);

        if(i >= 2)dp[i] = minn[1];

        to(to, 1, 1, n, i, dp[i - 1]);
    }

    cout << dp[n] << "\n";
    // dp[2] = get(1, 2);
    // dp[3] = get(1, 3);

    // for(int i = 4; i <= n; ++ i){
    //     dp[i] = get(1, i);
    //     for(int j = i - 2; j >= 1; -- j){
    //         dp[i] = min(dp[i], dp[j] + get(j + 1, i));
    //     }
    //     // cout << i << " " << dp[i] << "\n";
    // }
    // cout << dp[n] << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int T;
    // for (cin >> T; T -- ; )
        Sakuya();
}