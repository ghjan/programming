
typedef key_t char;
typedef data_t char[10];

class RBTree
{
	struct RBNode
	{
		bool color;
		RBNode *parent;
		RBNode *left;
		RBNode *right;
	};
public:
	static RBNode* rb_rotate_left(RBNode* node, RBNode* root)
	{
		RBNode* right = node->right;
	}
	static RBNode* rb_rotate_right(RBNode* node, RBNode* root)
	{
		RBNode* right = node->right;
	}
	//������������ҽ�� 
	static RBNode* rb_search_auxiliary(key_t key, RBNode *root, RBNode **save)
	{

	}
	//��������rb_search_auxiliary���ҽ��  
	RBNode* rb_search(key_t key, RBNode* root)
	{
		return rb_search_auxiliary(key, root, nullptr);
	}
	//�ġ�������Ĳ���  
	//---------------------------------------------------------  
	//������Ĳ�����  
	RBNode* rb_insert(key_t key, data_t data, RBNode* root)
	{

	}
	//�塢�������3�ֲ������
	//�������������ص������Ժ���������3������������е��޸�������  
	//--------------------------------------------------------------  
	//������޸������3�����  
	//Ϊ���������ע���б�ʾ���㣬ҲΪ���������������ҵĂzƪ�������Ӧ��  
	//��z��ʾ��ǰ��㣬p[z]��ʾ��ĸ��p[p[z]]��ʾ�游��y��ʾ���塣  
	//--------------------------------------------------------------  
	static RBNode* rb_insert_rebalance(RBNode *node, RBNode *root)
	{

	}
};