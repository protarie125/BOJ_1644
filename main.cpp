#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

ll n;
vb sieve;
vl primes;
vl acuprimes;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;

	sieve = vb(n + 1, true);
	sieve[0] = false;
	sieve[1] = false;
	for (auto i = 2; i <= n; ++i) {
		if (!sieve[i]) {
			continue;
		}

		primes.push_back(i);

		for (auto j = 2 * i; j <= n; j += i) {
			sieve[j] = false;
		}
	}

	acuprimes.push_back(0);
	for (auto i = 0; i < primes.size(); ++i) {
		acuprimes.push_back(acuprimes[i] + primes[i]);
	}

	auto liter = acuprimes.begin();
	auto riter = acuprimes.begin();
	auto ct = ll{ 0 };
	while (liter <= riter && riter < acuprimes.end()) {
		const auto& lv = *liter;
		const auto& rv = *riter;
		const auto& val = rv - lv;

		if (n < val) {
			++liter;
			continue;
		}

		if (n == val) {
			++ct;
			++riter;
			continue;
		}

		++riter;
	}

	cout << ct;

	return 0;
}