/*
有一棵二叉树，树上每个点标有权值，权值各不相同，请设计一个算法算出权值最大的叶节点到权值最小的叶节点的距离。
二叉树每条边的距离为1，一个节点经过多少条边到达另一个节点为这两个节点之间的距离。
给定二叉树的根节点root，请返回所求距离。
*/

#include<iostream>
#include<deque>
#include<limits.h>
using namespace std;


struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};

class Tree {
public:
	int getDis(TreeNode* root) {
		if (root == nullptr || root->left == nullptr || root->right == nullptr)
			return 0;
		deque<TreeNode*>min, max, node;
		int maxNum = INT_MIN;
		int minNum = INT_MAX;
		traversal(root, min, max, node, minNum, maxNum);
		return get_distance(min, max);
	}
	void traversal(TreeNode *root, deque<TreeNode*>&min, deque<TreeNode*>&max, deque<TreeNode*>&node,int &maxNum,int &minNum) {
		if (root == nullptr)
			return;
		node.push_back(root);
		
		if (isleaf(root)) {
			if (min.size() == 0 || minNum > root->val)
			{
				min.clear();
				min.assign(node.begin(), node.end());
				minNum = root->val;
			}
			if (max.size() == 0 || maxNum < root->val)
			{
				max.clear();
				max.assign(node.begin(), node.end());
				maxNum = root->val;
			}
		}
		else
		{
			if (root->left)
				traversal(root->left, min, max, node, maxNum, minNum);
			if (root->right)
				traversal(root->right, min, max, node, maxNum, minNum);
		}
		node.pop_back();
		
	}
	bool isleaf(TreeNode*node) {
		if (node->left == nullptr&&node->right == nullptr)
			return true;
		return false;
	}
	int get_distance(deque<TreeNode*>&min, deque<TreeNode*>&max)
	{
		if (min.size() == 0 || max.size() == 0)
			return -1;
		int distance = 0;
		while (min.front() == max.front())
		{
			min.pop_front();
			max.pop_front();
		}
		distance = min.size() + max.size();
		return distance;
	}
};
