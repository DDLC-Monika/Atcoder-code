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

#undef int

namespace NTT {
    const int MOD = 998244353;
    const int G = 3;

    int power(int a, int b) {
        int res = 1;
        for (; b; b >>= 1, a = 1LL * a * a % MOD)
            if (b & 1) res = 1LL * res * a % MOD;
        return res;
    }

    int get_inv(int n) { return power(n, MOD - 2); }

    void ntt(vector<int>& a, bool inv) {
        int n = a.size();
        static vector<int> rev;
        if ((int)rev.size() != n) {
            rev.resize(n);
            for (int i = 0; i < n; i++)
                rev[i] = (rev[i >> 1] >> 1) | ((i & 1) ? (n >> 1) : 0);
        }
        for (int i = 0; i < n; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);

        for (int half = 1; half < n; half <<= 1) {
            int unit = power(G, (MOD - 1) / (half << 1));
            if (inv) unit = get_inv(unit);
            for (int i = 0; i < n; i += (half << 1)) {
                long long w = 1;
                for (int j = 0; j < half; j++, w = w * unit % MOD) {
                    int x = a[i + j], y = w * a[i + j + half] % MOD;
                    a[i + j] = (x + y) % MOD;
                    a[i + j + half] = (x - y + MOD) % MOD;
                }
            }
        }
        if (inv) {
            int n_inv = get_inv(n);
            for (int& x : a) x = 1LL * x * n_inv % MOD;
        }
    }

    vector<int> mul(const vector<int>& a, const vector<int>& b) {
        int n = 1, total = a.size() + b.size() - 1;
        while (n < total) n <<= 1;
        vector<int> f = a, g = b;
        f.resize(n); g.resize(n);
        ntt(f, false); ntt(g, false);
        for (int i = 0; i < n; i++) f[i] = 1LL * f[i] * g[i] % MOD;
        ntt(f, true);
        f.resize(total);
        return f;
    }

    vector<int> inv_num;

    void init_inverse(int len) {
        inv_num.assign(len + 1, 0);
        inv_num[1] = 1;
        for(int i = 2; i <= len; ++ i) {
            inv_num[i] = MOD - 1LL * (MOD / i) * inv_num[MOD % i] % MOD;
        }
    }

    vector<int> poly_mul(vector<int> a, vector<int> b, int limit) {
        if(a.empty() || b.empty() || limit == 0) return {};
        if((int)a.size() > limit) a.resize(limit);
        if((int)b.size() > limit) b.resize(limit);

        int len = min(limit, (int)a.size() + (int)b.size() - 1);
        if(min(a.size(), b.size()) <= 32) {
            vector<int> res(len);
            for(int i = 0; i < (int)a.size(); ++ i) {
                for(int j = 0; j < (int)b.size() && i + j < len; ++ j) {
                    res[i + j] = (res[i + j] + 1LL * a[i] * b[j]) % MOD;
                }
            }
            return res;
        }

        vector<int> res = NTT::mul(a, b);
        res.resize(len);
        return res;
    }

    vector<int> poly_inv(const vector<int>& a, int len) {
        vector<int> res(1, power(a[0], MOD - 2));
        while((int)res.size() < len) {
            int nlen = min(len, (int)res.size() * 2);
            vector<int> f(a.begin(), a.begin() + min((int)a.size(), nlen));
            vector<int> g = poly_mul(f, res, nlen);
            g.resize(nlen);

            for(auto &x : g) {
                if(x) x = MOD - x;
            }
            g[0] = (g[0] + 2) % MOD;

            res = poly_mul(res, g, nlen);
            res.resize(nlen);
        }
        return res;
    }

    vector<int> poly_derivative(const vector<int>& a) {
        if(a.size() <= 1) return {};
        vector<int> res(a.size() - 1);
        for(int i = 1; i < (int)a.size(); ++ i) {
            res[i - 1] = 1LL * a[i] * i % MOD;
        }
        return res;
    }
    vector<int> poly_integral(const vector<int>& a) {
        vector<int> res(a.size() + 1);
        for(int i = 0; i < (int)a.size(); ++ i) {
            res[i + 1] = 1LL * a[i] * inv_num[i + 1] % MOD;
        }
        return res;
    }
    vector<int> poly_ln(const vector<int>& a, int len) {
        if(len == 1) return vector<int>(1);
        vector<int> ia = poly_inv(a, len);
        vector<int> res = poly_mul(poly_derivative(a), ia, len - 1);
        res.resize(len - 1);
        return poly_integral(res);
    }
    vector<int> poly_exp(const vector<int>& a, int len) {
        vector<int> res(1, 1);
        while((int)res.size() < len) {
            int nlen = min(len, (int)res.size() * 2);
            vector<int> ln_res = poly_ln(res, nlen);
            vector<int> g(nlen);

            for(int i = 0; i < nlen; ++ i) {
                g[i] = ((i < (int)a.size() ? a[i] : 0) - ln_res[i] + MOD) % MOD;
            }
            g[0] = (g[0] + 1) % MOD;

            res = poly_mul(res, g, nlen);
            res.resize(nlen);
        }
        return res;
    }
    vector<int> poly_pow(const vector<int>& a, long long exponent, int len) {
        vector<int> res = poly_ln(a, len);
        exponent %= MOD;
        for(auto &x : res) x = 1LL * x * exponent % MOD;
        return poly_exp(res, len);
    }
}

int n, m;
void Sakuya()
{
    cin >> n >> m;

    if(m < n || m >= 2 * n){
        cout << 0 << "\n";
        return;
    }

    int d = m - n;
    int cnt = n - d;
    int len = d + 1;
    NTT::init_inverse(len);

    vector<int>f(len);
    for(int i = 0; i < len; ++ i) {
        f[i] = NTT::inv_num[i + 1];
    }
    vector<int> pw = NTT::poly_pow(f, cnt, len);
    int fac = 1;
    for(int i = 1; i <= cnt; ++ i) fac = 1LL * fac * i % mod;
    cout << 1LL * pw[d] * ksm(fac, mod - 2) % mod << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int T;
    // for (cin >> T; T -- ; )
        Sakuya();
}
