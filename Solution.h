#pragma once
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* BuildTree(uint8_t s[], int size);

class Solution 
{
    public:        
        string mergeAlternately(string word1, string word2);
        void moveZeroes(vector<int>& nums);
        double findMaxAverage(vector<int>& nums, int k);
        int largestAltitude(vector<int>& gain);
        vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2);
        string removeStars(string s);        
        ListNode* deleteMiddle(ListNode* head);
        int maxDepth(TreeNode* root);
        vector<int> rightSideView(TreeNode* root);
        TreeNode* searchBST(TreeNode* root, int val);
        bool canVisitAllRooms(vector<vector<int>>& rooms);
        int nearestExit(vector<vector<char>>& maze, vector<int>& entrance);
        int findKthLargest(vector<int>& nums, int k);
        int guessNumber(int n);
        vector<string> letterCombinations(string digits);
        int tribonacci(int n);
        int uniquePaths(int m, int n);
        vector<int> countBits(int n);
        void ImplementTrie();
        int eraseOverlapIntervals(vector<vector<int>>& intervals);
        vector<int> dailyTemperatures(vector<int>& temperatures);
        string gcdOfStrings(string str1, string str2);
        bool isSubsequence(string s, string t);
        int maxVowels(string s, int k);
        int pivotIndex(vector<int>& nums);
        bool uniqueOccurrences(vector<int>& arr);
        vector<int> asteroidCollision(vector<int>& asteroids);
        string predictPartyVictory(string senate);
        ListNode* oddEvenList(ListNode* head);
        bool leafSimilar(TreeNode* root1, TreeNode* root2);
        int maxLevelSum(TreeNode* root);
        TreeNode* deleteNode(TreeNode* root, int key);
        int findCircleNum(vector<vector<int>>& isConnected);
        int orangesRotting(vector<vector<int>>& grid);
        vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success);
        vector<vector<int>> combinationSum3(int k, int n);
        int longestCommonSubsequence(string text1, string text2);
        int rob(vector<int>& nums);
        int singleNumber(vector<int>& nums);
        vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord);
        int findMinArrowShots(vector<vector<int>>& points);
};
