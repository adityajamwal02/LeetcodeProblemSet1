class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr.size();j++){
                if((2*arr[j])==arr[i] and i!=j)
                    return true;
            }
        }
    return false;
    }
};
