class Solution {

    static long gcd(long a,long b){
        if(b == 0)return a;

        return gcd(b,a%b);
    }
    public long solution(int w, int h) {

        long wl = (long)w;
        long hl = (long)h;
        long g = gcd(w,h);

        long x = wl/g; //비율
        long y = hl/g;

        long count = (x+y - 1);
        long answer = count*(wl/x);
        long max = wl*hl;

        return max - answer;
    }
}