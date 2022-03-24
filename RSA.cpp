#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <bitset>
using namespace std;
typedef long long ill;
const int N = 1e2 + 7;
const int M = N;
const int OO = 1e9 + 7;
const ill OL = 1e18 + 7;
const int MOD = 1e9 + 7;
//const double PI = acos(-1);
inline int read() { int x; scanf("%d", &x); return x; }
inline ill readl() { ill x; scanf("%lld", &x); return x;}
inline double readd() { double x; scanf("%lf", &x); return x; }

class RSA {
	//�������㷨���� 
	long long p, q;
    long long n, e, d;
    long long f;
    long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); } //��ͨ��gcd���ж�e�Ƿ���� 
	void exgcd(long long a, long long b, long long &x, long long &y) { //��չŷ���������Ԫ 
        if (! b) { x = 1, y = 0; }
        else { exgcd(b, a % b, y, x); y -= (a / b) * x; }
    }	
    long long fpow(long long dd, long long vv) {  //������ 
    	long long res = 1;
    	for (; vv; vv >>= 1, dd = dd * dd % n) if (vv & 1) res = res * dd % n;
		return res;
	}
public :
    RSA() {}
    RSA(int pp, int qq) : p(pp), q(qq) , n(p * q), f((p - 1) * (q - 1)) {}
    /*
	RSA(int pp, int qq, int ee) : RSA(pp, qq) { //���ù��캯������e����Ȼ�����׳��쳣û�кð취�ж�e�Ƿ���� 
        sete(ee);
        work();
    }
    */
    bool sete(int ee) {
    	if (gcd(f, ee) != 1) return false; //���e�������򷵻�false 
		e = ee;  //����e��������ֵ 
		work(); 
		return true;
	}
    
	void work() {  //��Ҫ������Ԫ 
        long long sam;
        exgcd(e, f, d, sam);
    }
    
    friend ostream& operator << (ostream &out, RSA &t) {
		out << "[ K_{pub} = (n, e) = (" << t.n << ", " << t.e << ") \\mid K_{pr} = (d) = (" << t.d << ") ]";
        return out;
    }
    
	long long e_(long long x) //���� 
    	{ return fpow(x, e); }
    long long d_(long long x) //���� 
    	{ return fpow(x, d); }
};

int main() {
	//std::ios::sync_with_stdio(false);    cin.tie(0);    cout.tie(0);
	freopen("in.txt", "r", stdin);
	
	RSA sam(3, 11);
	sam.sete(3);
	
	cout << sam << endl;
	cout << sam.e_(11) << endl;
	cout << sam.d_(16) << endl;
	 
	return 0;
}
