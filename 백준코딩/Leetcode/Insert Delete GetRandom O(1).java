class RandomizedSet {
    static HashSet<Integer> set;
    
    public RandomizedSet() {
        set = new HashSet<>();
    }
    
    public boolean insert(int val) {
        if(set.contains(val)) return false;
        set.add(val);
        return true;
    }
    
    public boolean remove(int val) {
    	if(set.contains(val)) {
    		set.remove(val);
    		return true;
    	}
    	return false;
    }
    
    public int getRandom() {
    	Iterator<Integer> it = set.iterator();
    	int len = set.size();
        Random random = new Random();
        int randNum = random.nextInt(len);
        int result=0;
        while(randNum>=0) {
        	result = it.next();
        	randNum--;
        }
        return result;
    }
}
