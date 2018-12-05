class Solution {
public:
    int nthMagicalNumber(int N, int A, int B) {
 		LL n = N, a = A, b = B;
 		if (a > b) {
 			LL t = a;
 			a = b;
 			b = t;
 		} 
 		if (a == 0 || a == b) {
 			return (b * n) % MODULO;
 		}

 		LL gcd = getGCD(b, a);
 		LL lcm = a * b / gcd;
 		LL numa = lcm / a - 1, numb = lcm / b - 1;
 		LL num = numa + numb + 1;
 		LL numLcm = n / num;
 		LL base = (lcm * numLcm) % MODULO;
 		n %= num;
 		LL suma = a, sumb = b, ans = 0;
 		while (n > 0) {
 			--n;
 			if (suma < sumb) {
 				ans = suma;
 				suma = suma + a;
 			} else {
 				ans = sumb;
 				sumb = sumb + b;
 			}
 		}
 		return (ans + base) % MODULO;
    }
private:
	using LL = long long;
	const LL MODULO = 1000000007;

	LL getGCD(LL a, LL b) {
		if (b == 0) {
			return a;
		}
		return getGCD(b, a % b);
	}
};