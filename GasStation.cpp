/*
There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.
Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique

Example 1:
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.

Example 2:
Input: gas = [2,3,4], cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
*/

/// O(n) time and O(1) space

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int start=0, netGas=0, gasDeficit=0;
        for(int i=0;i<n;i++){
            netGas+=gas[i]-cost[i];
            if(netGas<0){
                gasDeficit+=netGas;
                int nextStop=i+1;
                start=nextStop;
                netGas=0;
            }
        }
        int remainingGas=gasDeficit+netGas;
        if(remainingGas>=0){
            return start;
        }else{
            return -1;
        }
    }
};

/// O(n) time and O(n) space

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int ans=0, remainingFeul=0, total=0;
        for(int i=0;i<n;i++){
            remainingFeul+=gas[i]-cost[i];
            if(remainingFeul<0){
                ans=i+1;
                remainingFeul=0;
            }
            total+=gas[i]-cost[i];
        }
    return total<0 ? -1 : ans;
    }
};
