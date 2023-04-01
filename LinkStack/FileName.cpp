#include<iostream>//输入输出流
#include<string>//STL字符容器
using namespace std;//标准命名空间
class Node//节点类
{
public://公共区域
	friend class LinkStack;//链栈类作节点类的友元，链栈类里的成员函数可以访问到节点类的私有区域
	Node()//构造函数
	{
		this->next = NULL;//节点类的next默认都为NULL
	}
	~Node() {}//构造函数
private://私有区域
	string elem;//数据域
	Node* next;//指针域
};
class LinkStack
{
public://公共区域
	LinkStack()//构造函数
	{
		this->initStack();//自动初始化
	}
	void initStack();//链栈初始化
	bool push(string&elem);//入栈（可引用，可不引用）
	bool pop(string& elem);//出栈（一定要引用，保证elem的值发生了改变）
	void printStack();//遍历
	int lengthStack();//链栈长度
private://私有区域
	Node* head;//头节点（直接指向首元节点）
};
void LinkStack::initStack()//链栈初始化
{
	this->head = NULL;//栈顶指向NULL
}
bool LinkStack::push(string& elem)//入栈
{
	Node* p = new Node;//创建一个新节点在堆区，并返回地址交给p保管
	if (p == NULL)//创建是否成功
	{
		return false;
	}
	p->elem = elem;//新节点先存入数据
	p->next = this->head;//新节点的next要指向上个节点（也就是原来的head）
	this->head = p;//更新head
	return true;//创建成功了
}
bool LinkStack::pop(string& elem)//出栈
{
	if (this->head == NULL)//判断链栈是否为空，为空直接返回
	{
		return false;
	}
	Node* p = head;//把要删的节点节点交给p保管
	elem = head->elem;//把要删的节点赋给elem,就是看一下要删节点的数据，这里必须要用引用或者地址传递才能改变实参
	head = head->next;//更新栈顶
	delete p;//此时，就可以删除原来的栈顶了
	return true;//删除成功
}
void LinkStack::printStack()//遍历
{
	if (head == NULL)
	{
		return;
	}
	Node* p = head;//让p代替栈顶不断向下迭代（防止栈顶地址丢失）
	while (p != NULL)//没有迭代到栈顶（栈底的指针域指向NULL）,就一直迭代
	{
		cout << p->elem << " ";//输出数据
		p = p->next;//迭代
	}
	cout << endl;//换行
}
int LinkStack::lengthStack()
{
	int i = 0;//计数器
	Node* p = head;//代替栈顶进行迭代
	while (p != NULL)
	{
		i++;//计数
		p = p->next;//迭代
	}
	return i;//返回长度
}
void showMenu()//菜单，方便用户操作
{
	cout << "  *****************" << endl;
	cout << "  *  链     栈   *"  << endl;
	cout << "  *  1、初始化    *" << endl;
	cout << "  *  2、入  栈    *" << endl;
	cout << "  *  3、出  栈    *" << endl;
	cout << "  *  4、遍  历    *" << endl;
	cout << "  *  5、长  度    *" << endl;
	cout << "  *  0、退  出    *" << endl;
	cout << "  *****************" << endl;
	cout << "请输入您的选项:";
}
int main()
{
	LinkStack s;//创建链栈对象
	int select;//存储用户选择
	while (true)//死循环，正确操作可退出
	{
		showMenu();//调用菜单函数
		cin >> select;//用户选择
		switch (select)
		{
		case 1:
			s.initStack();
			cout << "初始化成功！" << endl;
			system("pause");//停顿
			system("cls");//清屏
			break;
		case 2:
		{
			cout << "你想入栈哪个元素？" << endl;
			string elem;
			cin >> elem;
			if (s.push(elem))
			{
				cout << elem << "入栈成功！" << endl;
			}
			else
			{
				cout << "入栈失败！" << endl;
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
				cout << elem << " 已出栈！" << endl;
			}
			else
			{
				cout << "出栈失败！" << endl;
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
			cout << "链栈的长度为：" << s.lengthStack() << endl;
			system("pause");
			system("cls");
     		break;
		default:
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		}

	}
}