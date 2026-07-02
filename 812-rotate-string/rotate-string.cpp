class Solution {
public:
    bool rotateString(string s, string goal) {
        // if(s.length() != goal.length()){
        //     return false;
        // }
        //  sort(s.begin() , s.end());
        //  sort(goal.begin() , goal.end());

        // if(s==goal){
        //     return true;
        // }else{
        //     return false;
        // }
        if (s.length() != goal.length()) return false;
        
        // Concatenate s with itself and check if goal exists in it
        string doubledS = s + s;
        return doubledS.find(goal) != string::npos;
    }
};