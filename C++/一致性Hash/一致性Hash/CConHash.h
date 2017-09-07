#include "CNode_s.h"
#include "CHashFun.h"
#include "CVirtualNode_s.h"
#include "util_rbtree.h"

#define _NULL(rbtree) (&((rbtree)->null))

class CConHash
{
public:
	/*���캯��*/
	CConHash(CHashFun * pFunc);

	/*����hash����*/
	void setFunc(CHashFun * pFunc);

	/*����ʵ���� , 0����ɹ� , -1����ʧ��*/
	int addNode_s(CNode_s * pNode);

	/*ɾ��ʵ���� , 0����ɹ� , -1����ʧ��*/
	int delNode_s(CNode_s * pNode);

	/*����ʵ����*/
	CNode_s * lookupNode_s(const char * object);

	/*��ȡһ����hash�ṹ����������������*/
	int getVNodes();
private:
	/*Hash����*/
	CHashFun * func;
	/*�������ܸ���*/
	int vNodes;
	/*�洢������ĺ����*/
	util_rbtree_t * vnode_tree;
};
/*����������������ת��Ϊ��������*/
util_rbtree_node_t* util_rbtree_lookup(util_rbtree_t *rbtree, long key)
{
	if ((rbtree != NULL) && !util_rbtree_isempty(rbtree))
	{
		util_rbtree_node_t *node = NULL;
		util_rbtree_node_t *temp = rbtree->root;
		util_rbtree_node_t *null = _NULL(rbtree);
		while (temp != null)
		{
			if (key <= temp->key)
			{
				node = temp; /* update node */
				temp = temp->left;
			}
			else if (key > temp->key)
			{
				temp = temp->right;
			}
		}
		/* if node==NULL return the minimum node */
		return ((node != NULL) ? node : util_rbtree_min(rbtree));
	}
	return NULL;
}