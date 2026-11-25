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
template <typename T>  T power(T a, LL b) {
    T c{1}; for (; b; b /= 2, a *= a) if (b & 1) c *= a;
    return c;
}
template <int P> struct MInt {
    int x;
    MInt() : x{} {}
    MInt(LL x_) : x{norm(x_ % getMod())} {}
    static int Mod;
    static int getMod() { return P > 0 ? P : Mod; }
    static void setMod(int Mod_) { Mod = Mod_; }
    int up(int x) const {
        if (x < 0) x += getMod();
        return x;
    }
    int down(int x) const {
        if (x >= getMod()) x -= getMod();
        return x;
    }
    int norm(int x) const {
        return up(down(x));
    }
    int val() const { return x; }
    explicit  operator int() const { return x; }
    MInt operator-() const {
        MInt res; res.x = norm(getMod() - x); return res;
    }
    MInt inv() const {
        // assert(x != 0);
        return power(*this, getMod() - 2);
    }
    MInt &operator+=(MInt rhs) & { return x = down(x + rhs.x), *this; }
    MInt &operator-=(MInt rhs) & { return x = up(x - rhs.x), *this; }
    MInt &operator*=(MInt rhs) & { return x = 1ll * x * rhs.x % getMod(), *this; }
    MInt &operator/=(MInt rhs) & { return *this *= rhs.inv(); }
    friend MInt operator+(MInt lhs, MInt rhs) { return lhs += rhs; }
    friend MInt operator-(MInt lhs, MInt rhs) { return lhs -= rhs; }
    friend MInt operator*(MInt lhs, MInt rhs) { return lhs *= rhs; }
    friend MInt operator/(MInt lhs, MInt rhs) { return lhs /= rhs; }
    friend bool operator==(MInt lhs, MInt rhs) { return lhs.val() == rhs.val(); }
    friend  bool operator!=(MInt lhs, MInt rhs) { return lhs.val() != rhs.val(); }
    friend  std::istream &operator>>(std::istream &is, MInt &a) {
        LL x = 0; is >> x, a = MInt(x); return is;
    }
    friend  std::ostream &operator<<(std::ostream &os, const MInt &a) {
        return os << a.val();
    }
};
 
using Z = MInt<mod>;

int n, m;
void Sakuya()
{
    cin >> n;

    vector g(n + 1, vector<int>());

    for(int i = 1; i < n; ++ i){
        int u, v;cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    if(n == 2){
        cout << 1 << "\n";
        return;
    }

    vector<int>dep(n + 1, 0);
    vector<int>fa(n + 1);

    auto dfs = [&](auto self, int u, int f) -> void{
        dep[u] = dep[f] + 1;
        fa[u] = f;
        for(auto v : g[u]){
            if(v == f)continue;
            self(self, v, u);
        }
    };

    dfs(dfs, 1, 0);

    int aim = 0;
    for(int i = 1; i <= n; ++ i){
        if(dep[i] > dep[aim]){
            aim = i;
        }
    }
    for(int i = 1; i <= n; ++ i)dep[i] = 0;
    dfs(dfs, aim, 0);

    int aim2 = 0;
    for(int i = 1; i <= n; ++ i){
        if(dep[i] > dep[aim2]){
            aim2 = i;
        }
    }

    int len = dep[aim2] - dep[aim];

    vector<bool>vis(n + 1, false);
    for(int i = aim2; i; i = fa[i])vis[i] = true;

    if(len & 1){
        int aimlen1 = dep[aim] + len / 2;
        int aimlen2 = dep[aim] + len / 2 + 1;

        int pos1 = -1, pos2 = -1;
        for(int i = 1; i <= n; ++ i){
            if(vis[i] == true){
                if(dep[i] == aimlen1)pos1 = i;
                if(dep[i] == aimlen2)pos2 = i;
            }
        }

        auto dfs2 = [&](auto self, int u, int f, int no) -> void{
            dep[u] = dep[f] + 1;
            fa[u] = f;
            for(auto v : g[u]){
                if(v == f || v == no)continue;
                self(self, v, u, no);
            }
        };
        for(int i = 1; i <= n; ++ i)dep[i] = 0;
        dfs2(dfs2, pos1, 0, pos2);
        int cnt1 = 0, cnt2 = 0;
        for(int i = 1; i <= n; ++ i)if(dep[i] == 1 + len / 2)cnt1 += 1;
        for(int i = 1; i <= n; ++ i)dep[i] = 0;
        dfs2(dfs2, pos2, 0, pos1);
        for(int i = 1; i <= n; ++ i)if(dep[i] == 1 + len / 2)cnt2 += 1;
        cout << cnt1 * cnt2 % mod << "\n";
        // Z ans = (ksm(2, cnt1) - 1) * (ksm(2, cnt2) - 1);
        // cout << ans << "\n";
    }else {
        int aimlen = dep[aim] + len / 2;
        int pos = -1;
        for(int i = 1; i <= n; ++ i){
            if(vis[i] == true && dep[i] == aimlen){
                pos = i;
                break;
            }
        }
        for(int i = 1; i <= n; ++ i)dep[i] = 0;
        dfs(dfs, pos, 0);

        int cnt = 0;

        auto dfs2 = [&](auto self, int u, int f, int no) -> void{
            if(dep[u] == aimlen)cnt += 1;
            for(auto v : g[u]){
                if(f == v)continue;
                if(v == no)continue;
                self(self, v, u, no);
            }
        };
        Z ans = 1;
        vector<int>res;
        for(auto v : g[pos]){
            cnt = 0;
            dfs2(dfs2, v, pos, pos);
            if(cnt != 0)
            res.emplace_back(cnt);
        }
        
        for(auto i : res){
            ans *= (i + 1);
        }
        // ans -= 1 + (int)res.size();
        for(auto i : res){
            ans -= i;
        }
        ans -= 1;
        
        cout << ans << "\n";
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int T;
    // for (cin >> T; T -- ; )
        Sakuya();
}