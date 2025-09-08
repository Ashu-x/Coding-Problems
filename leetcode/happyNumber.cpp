bool isHappy(int n) {
        unordered_set<int> s;
        while(s.find(n) == s.end()){
            s.insert(n);
            n = getNext(n);
            if(n==1) return true;
        }
        return false;
    }

    int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n = n / 10;
        }
        return sum;
    }
