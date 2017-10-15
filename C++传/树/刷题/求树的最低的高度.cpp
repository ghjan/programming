class Solution {
public:
	int min(int a, int b)
	{
		return a<b ? a : b;
	}
	int run(TreeNode *root) {
		if (root == NULL)
			return 0;
		int left = run(root->left);
		int right = run(root->right);

		/*������Ǻ���߶ȵ������ˣ�����߻����ұ�Ϊ�յ�ʱ�򣬾Ͳ���ȡΪ�յ���һ����*/
		if (left == 0 || right == 0)
			return left + right + 1;

		return min(left, right) + 1;
	}
};