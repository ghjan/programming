class Base
{
	virtual void A(float = 0.0);
	virtual void B() const;
	virtual void C();
	void D();
};
class Derived : public Base
{
	virtual void A(int = 0) override; //���岻һ�£��������
	virtual void B() override;        //�������Ͳ���const���������
	virtual void C() override;        //��ȷ
	void D() override;                //�����麯�����������
};
