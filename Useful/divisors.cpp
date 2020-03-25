vector<int> divisors(int n) {
    vector<int> div;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i){
                div.push_back(i);
            } else { 
                div.push_back(i);
                div.push_back(n / i);
            }
        }
    }
    return div;
}