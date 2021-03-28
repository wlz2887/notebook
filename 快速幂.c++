long long fast_pow(long long a, long long b){
    if(b==0) return 1;
    int tmp = pow(a,b>>1);
    if(b&1){
        tmp = long long(tmp)*a%MOD;
    }
    return tmp%MOD;
}
