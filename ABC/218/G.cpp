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
I'm not sure if there's any truth in what you're saying, but I'm not sure if there's any truth in what you're saying, and I'm not sure if there's any truth in what you're saying, and I'm not sure if there's any truth in what you're saying, and I'm not sure if there's any truth in what you're saying. But then, his idea is right, why?
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
#define int long long
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
    vector<int>b;
    for(int i = 1; i <= n; ++ i)cin >> a[i], b.emplace_back(a[i]);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    
    auto get = [&](int x) -> int{
        return lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
    };

    int siz = b.size() + 1;

    vector<int>tr(siz * 4 + 5);

    auto update = [&](auto self, int u, int l, int r, int pos, int z) -> void{
        if(l == r){
            tr[u] += z;
            return;
        }
        if(pos <= mid)self(self, u << 1, l, mid, pos, z);
        else self(self, u << 1 | 1, mid + 1, r, pos, z);
        tr[u] = tr[u << 1] + tr[u << 1 | 1];
    };

    auto query_k = [&](auto self, int u, int l, int r, int k) -> int{
        if(l == r)return l;
        if(tr[u << 1] >= k)return self(self, u << 1, l, mid, k);
        else return self(self, u << 1 | 1, mid + 1, r, k - tr[u << 1]);
    };
    vector g(n + 1, vector<int>());
    for(int i = 1; i < n; ++ i){
        int u, v;cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    for(int i = 1; i <= n; ++ i){
        a[i] = get(a[i]);
    }

    vector<int>dp(n + 1);

    auto dfs = [&](auto self, int u, int f) -> void{
        
        update(update, 1, 1, siz, a[u], 1);
        
        if(u != 1 && g[u].size() == 1){
            int tot = tr[1];
            if(tot & 1){
                int k = tot / 2 + 1;

                int val = query_k(query_k, 1, 1, siz, k);
                dp[u] = b[val - 1];
            }else {
                int k1 = tot / 2;
                int k2 = k1 + 1;

                int val1 = query_k(query_k, 1, 1, siz, k1);
                int val2 = query_k(query_k, 1, 1, siz, k2);
                dp[u] = (b[val1 - 1] + b[val2 - 1]) / 2;
            }
        }else {
            for(auto v : g[u]){
                if(v == f)continue;
                self(self, v, u);
            }

            int tot = tr[1];
            if(tot & 1)dp[u] = 0;
            else dp[u] = 1e18;

            for(auto v : g[u]){
                if(v == f)continue;

                if(tot & 1){
                    dp[u] = max(dp[u], dp[v]);
                }else {
                    dp[u] = min(dp[u], dp[v]);
                }
            }
        }

        update(update, 1, 1, siz, a[u], -1);
    };

    dfs(dfs, 1, 0);

    cout << dp[1] << "\n";
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int T;
    // for (cin >> T; T -- ; )
        Sakuya();
}