#include<iostream>//���������
#include<string>//STL�ַ�����
using namespace std;//��׼�����ռ�
class Node//�ڵ���
{
public://��������
	friend class LinkStack;//��ջ�����ڵ������Ԫ����ջ����ĳ�Ա�������Է��ʵ��ڵ����˽������
	Node()//���캯��
	{
		this->next = NULL;//�ڵ����nextĬ�϶�ΪNULL
	}
	~Node() {}//���캯��
private://˽������
	string elem;//������
	Node* next;//ָ����
};
class LinkStack
{
public://��������
	LinkStack()//���캯��
	{
		this->initStack();//�Զ���ʼ��
	}
	void initStack();//��ջ��ʼ��
	bool push(string&elem);//��ջ�������ã��ɲ����ã�
	bool pop(string& elem);//��ջ��һ��Ҫ���ã���֤elem��ֵ�����˸ı䣩
	void printStack();//����
	int lengthStack();//��ջ����
private://˽������
	Node* head;//ͷ�ڵ㣨ֱ��ָ����Ԫ�ڵ㣩
};
void LinkStack::initStack()//��ջ��ʼ��
{
	this->head = NULL;//ջ��ָ��NULL
}
bool LinkStack::push(string& elem)//��ջ
{
	Node* p = new Node;//����һ���½ڵ��ڶ����������ص�ַ����p����
	if (p == NULL)//�����Ƿ�ɹ�
	{
		return false;
	}
	p->elem = elem;//�½ڵ��ȴ�������
	p->next = this->head;//�½ڵ��nextҪָ���ϸ��ڵ㣨Ҳ����ԭ����head��
	this->head = p;//����head
	return true;//�����ɹ���
}
bool LinkStack::pop(string& elem)//��ջ
{
	if (this->head == NULL)//�ж���ջ�Ƿ�Ϊ�գ�Ϊ��ֱ�ӷ���
	{
		return false;
	}
	Node* p = head;//��Ҫɾ�Ľڵ�ڵ㽻��p����
	elem = head->elem;//��Ҫɾ�Ľڵ㸳��elem,���ǿ�һ��Ҫɾ�ڵ�����ݣ��������Ҫ�����û��ߵ�ַ���ݲ��ܸı�ʵ��
	head = head->next;//����ջ��
	delete p;//��ʱ���Ϳ���ɾ��ԭ����ջ����
	return true;//ɾ���ɹ�
}
void LinkStack::printStack()//����
{
	if (head == NULL)
	{
		return;
	}
	Node* p = head;//��p����ջ���������µ�������ֹջ����ַ��ʧ��
	while (p != NULL)//û�е�����ջ����ջ�׵�ָ����ָ��NULL��,��һֱ����
	{
		cout << p->elem << " ";//�������
		p = p->next;//����
	}
	cout << endl;//����
}
int LinkStack::lengthStack()
{
	int i = 0;//������
	Node* p = head;//����ջ�����е���
	while (p != NULL)
	{
		i++;//����
		p = p->next;//����
	}
	return i;//���س���
}
void showMenu()//�˵��������û�����
{
	cout << "  *****************" << endl;
	cout << "  *  ��     ջ   *"  << endl;
	cout << "  *  1����ʼ��    *" << endl;
	cout << "  *  2����  ջ    *" << endl;
	cout << "  *  3����  ջ    *" << endl;
	cout << "  *  4����  ��    *" << endl;
	cout << "  *  5����  ��    *" << endl;
	cout << "  *  0����  ��    *" << endl;
	cout << "  *****************" << endl;
	cout << "����������ѡ��:";
}
int main()
{
	LinkStack s;//������ջ����
	int select;//�洢�û�ѡ��
	while (true)//��ѭ������ȷ�������˳�
	{
		showMenu();//���ò˵�����
		cin >> select;//�û�ѡ��
		switch (select)
		{
		case 1:
			s.initStack();
			cout << "��ʼ���ɹ���" << endl;
			system("pause");//ͣ��
			system("cls");//����
			break;
		case 2:
		{
			cout << "������ջ�ĸ�Ԫ�أ�" << endl;
			string elem;
			cin >> elem;
			if (s.push(elem))
			{
				cout << elem << "��ջ�ɹ���" << endl;
			}
			else
			{
				cout << "��ջʧ�ܣ�" << endl;
			}
			system("pause");
			system("cls");
		}
			break;
		case 3:
		{
			string elem;
			if (s.pop(elem))
			{
				cout << elem << " �ѳ�ջ��" << endl;
			}
			else
			{
				cout << "��ջʧ�ܣ�" << endl;
			}
			system("pause");
			system("cls");
		}
			break;
		case 4:
			s.printStack();
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "��ջ�ĳ���Ϊ��" << s.lengthStack() << endl;
			system("pause");
			system("cls");
     		break;
		default:
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		}

	}
}