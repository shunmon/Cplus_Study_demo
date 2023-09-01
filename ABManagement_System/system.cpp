#include <iostream>
using namespace std;
#include <string>
#define N 1000
struct people {
	string name;
	string gender;
	int age;
	string phone;
	string address;
};
struct  Addressbooks {
	struct people p[N];
	int m_size;
};
// 添加用户
void add_p(Addressbooks *ads, string name, string gender, int age, string phone, string address) {
	if (ads->m_size == N) {
		cout << "通讯录满了" << endl;
		return;
	}
	ads->p[ads->m_size].name = name;
	ads->p[ads->m_size].gender = gender;
	ads->p[ads->m_size].age = age;
	ads->p[ads->m_size].phone = phone;
	ads->p[ads->m_size].address = address;
	ads->m_size++;
}


//查询1全部
void selectAll(Addressbooks *ads) {
	
	for (int i = 0; i < ads->m_size; i++)
	{
		cout << "姓名：" << ads->p[i].name << "性别:" << ads->p[i].gender << "年龄：" << ads->p[i].age << "电话：" << ads->p[i].phone << "地址：" << ads->p[i].address << endl;
	}
}
// 按姓名删除
void delete_p(Addressbooks* ads, string name) {
	int count = 0;
	for (int i = 0; i < ads->m_size; i++)
	{
		if (ads->p[i].name == name) {
			for (int j = i; j < ads->m_size; j++)
			{
				ads->p[j] = ads->p[j + 1];
				ads->m_size--;
				count++;
			}
		}
	}
	if (count > 0) cout << "删除成功,数量为:" << count << endl;
	else cout << "不存在该用户" << endl;
}
//按姓名查询
int selectName(Addressbooks *ads, string name) {
	int i = 0;
	int count = 0;
	for ( i = 0; i < ads->m_size; i++)
	{
		if (ads->p[i].name == name) {
			cout << "姓名：" << ads->p[i].name << "性别:" << ads->p[i].gender << "年龄：" << ads->p[i].age << "电话：" << ads->p[i].phone << "地址：" << ads->p[i].address << endl;
			count ++ ;
		}
	}
	if (count == 0) {
		cout << "不存在该用户" << endl;
		return -1;
	}
	else return  1;
}
// 按姓名修改
void edittName(Addressbooks *ads) {
	string name;
	string gender;
	int age;
	string phone;
	string address;
	cout << "输入需要修改的名字" << endl;
	cin >> name;
	for (int i = 0; i < ads->m_size; i++)
	{
		if (ads->p[i].name == name) {
			cout << "请输入性别：" << endl;
			cin >> gender;
			ads->p[i].gender = gender;
			cout << "请输入年龄：" << endl;
			cin >> age;
			ads->p[i].age = age;
			cout << "请输入手机号：" << endl;
			cin >> phone;
			ads->p[i].phone = phone;
			cout << "请输入地址：" << endl;
			cin >> address;
			ads->p[i].address = address;
		}
	}
	
		

}
//删除所有
void deleteAll(Addressbooks *ads) {
	ads->m_size = 0;
}
void mulu() {
	cout << "通讯录管理系统" << endl;
	cout << "添加用户输入1" << endl;
	cout << "删除指定人信息2" << endl;
	cout << "显示全部联系人3" << endl;
	cout << "查找指定联系人4" << endl;
	cout << "修改指定联系人5" << endl;
	cout << "清空所有联系人6" << endl;
	cout << "退出通讯录0" << endl;
}
int main() 
{
	Addressbooks ads;
	ads.m_size = 0;
	int a = 0;
	string name;
	string gender;
	int age;
	string phone;
	string address;
	Flag:
	mulu();
	cin>> a;
	switch (a)
	{
	case 0:
		return 0;
	case 1:
		cout << "请输入姓名：" << endl;
		cin >> name;
		cout << "请输入性别：" << endl;
		cin >> gender;
		cout << "请输入年龄：" << endl;
		cin >> age;
		cout << "请输入电话：" << endl;
		cin >> phone;
		cout << "请输入地址：" << endl;
		cin >> address;
		cout << "添加成功" << endl;
		add_p(&ads, name, gender, age, phone, address);
		break;
	case 2:
		cout << "输入姓名" << endl;
		cin >> name;
		delete_p(&ads, name);
		break;
	case 3:
		selectAll(&ads);
		break;
	case 4:
		cout << "输入查询姓名" << endl;
		cin >> name;
		selectName(&ads,name);
		break;
	case 5: 
		edittName(&ads);
		break;
	case 6:
		deleteAll(&ads);
	}
	selectAll(&ads);
	cout << "返回目录,输入0" << endl;
	cin >> a;
	if (a == 0) {
		system("cls");
		goto Flag;
	}
	system("pause");
	return 0;

}